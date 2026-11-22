const int en1 = 6;
const int en2 = 7;

int button_a = 8;
int button_b = 9;

int a_val = 0;
int b_val = 0;

void setup() {
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(button_a, INPUT);
  pinMode(button_b, INPUT);
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
  a_val = digitalRead(button_a);
  b_val = digitalRead(button_b);

  if (a_val && !b_val) extend();
  if (b_val && !a_val) retract();
  if (!a_val && !b_val) stop();
}
