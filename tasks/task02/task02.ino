const int INTERRUPT_PIN = 18;   
const int SAMPLE_BATCH_SIZE = 1000; 

volatile uint32_t pulseCounter = 0;        
volatile uint32_t intervalSum = 0;        
volatile uint32_t previousPulseTime = 0;   
volatile uint32_t pulseIntervals[SAMPLE_BATCH_SIZE]; 

void setup() {
  Serial.begin(9600); 
  while (!Serial); 

  pinMode(INTERRUPT_PIN, INPUT); 
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), pulseDetectedISR, HIGH);

  Serial.println("System Initialized. Waiting for pulses on Pin 18...");
}

void loop() {
  if (pulseCounter >= SAMPLE_BATCH_SIZE) { 
    noInterrupts();

    uint32_t capturedCount = pulseCounter;
    uint32_t capturedSum = intervalSum;
    uint32_t localDeltas[SAMPLE_BATCH_SIZE]; 
    for (int i = 0; i < SAMPLE_BATCH_SIZE; i++) {
         localDeltas[i] = pulseIntervals[i];
    }
    pulseCounter = 0;
    intervalSum = 0;
    interrupts();

    if (capturedCount > 0) {
      float average = (float)capturedSum / capturedCount;
      float sumSqDiff = 0.0;
      for (int i = 0; i < capturedCount; i++) {
        float difference = (float)localDeltas[i] - average;
        sumSqDiff += difference * difference; 
      }
      
      float stdDeviation = sqrt(sumSqDiff / capturedCount);
      Serial.print("Mean Interval: ");
      Serial.print(average, 2); 
      Serial.print(" us, Std. Deviation: ");
      Serial.print(stdDeviation, 2); 
      Serial.println(" us");

    } else {
       Serial.println("Error: Batch processed with zero samples."); 
    }
  }
}

void pulseDetectedISR() {
  uint32_t currentTime = micros(); 
  uint32_t duration = currentTime - previousPulseTime;
  
  if (pulseCounter < SAMPLE_BATCH_SIZE) {
    pulseIntervals[pulseCounter] = duration;
    intervalSum += duration; 
    pulseCounter++;         
  }
  previousPulseTime = currentTime;
}
