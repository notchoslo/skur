bool GOING_OUT = false;

// 30 sec = 300000
const unsigned long SECONDS_BETWEEN_SWITCH = 30000;


// Accuator
const int OUTPINS[] = {2, 4};
const int INPINS[] = {3, 5};

unsigned long LAST_SWITCH = 0;

void setup() {
  Serial.begin(9600);

  // Acuators
  for (int i = 0; i < 2; i = i + 1) {
    pinMode(OUTPINS[i], HIGH);
    pinMode(INPINS[i], HIGH);
    pinMode(OUTPINS[i], OUTPUT);
    pinMode(INPINS[i], OUTPUT);
  }
  
}

void loop() {
  if ((millis()-LAST_SWITCH) > SECONDS_BETWEEN_SWITCH) {
    if (GOING_OUT) {
      pullInn();
    }
    else {
      pushOut();
    }

    LAST_SWITCH = millis();
  }
}

void pushOut() {
  Serial.print("pushOut");
  GOING_OUT = true;
  for (int i = 0; i < 2; i = i + 1) {
    digitalWrite(OUTPINS[i], LOW);
    digitalWrite(INPINS[i], HIGH);
  }
}

void pullInn() {
  Serial.print("pullIn");
  GOING_OUT = false;
  for (int i = 0; i < 2; i = i + 1) {
    digitalWrite(OUTPINS[i], HIGH);
    digitalWrite(INPINS[i], LOW);
  }
}
