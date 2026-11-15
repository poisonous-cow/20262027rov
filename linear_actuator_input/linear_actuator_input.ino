const int en1 = 6;
const int en2 = 7;

int button_a = 0;
int button_b = 0;

void setup() {
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
}

void extend() {
  digitalWrite(en1, HIGH);
  digitalWrite(en2, LOW);
}

void retract() {
  digitalWrite(en1, LOW);
  digitalWrite(en2, HIGH);
}

void stop() {
  digitalWrite(en1, LOW);
  digitalWrite(en2, LOW);
}

void loop() {
  if (button_a && !button_b) extend();
  if (button_b && !button_a) retract();
  if (!button_a && !button_b) stop();
}
