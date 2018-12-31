
const uint8_t button_pin = 2;
const uint8_t eyes_pin = PIN_B1;
const uint8_t led_pin = PIN_B3; // or B3? // PB4;
const uint8_t motor_pin = PIN_B4;

bool button_triggered = false;
bool walking = false;
uint8_t breathe_n = 0;
unsigned long button_press_time = 0;
const uint16_t MILLIS_APPROX = 145; // since attinycore doesn't give the right count

bool ascend = true;
void breathe() {
  int _add = 15;
  int _sub = 8;
  if (ascend == false && breathe_n > _add) {
    breathe_n -= _sub;

  } else if ( (breathe_n + _add) > 250) {
    ascend = false;
    breathe_n -= _sub;
  } else {
    ascend = true;
    breathe_n += _add;  
  }
  
  analogWrite(eyes_pin, breathe_n);
}

void button_press() {
  button_triggered = true;
}

void setup() {
  pinMode(eyes_pin, OUTPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(motor_pin, OUTPUT);

  pinMode(button_pin, INPUT_PULLUP);
  attachInterrupt(button_pin, button_press, FALLING);
  Serial.begin(9600);
}

unsigned long last_breathe = 0;
unsigned long last_motor = 0;


bool motor_on = false;
void loop() {
  unsigned long now = millis();
  bool led_val = true;
  bool is_breathing = false;
  
  unsigned long button_delta = now-button_press_time;

  if ( button_press_time > 0 && button_delta < 60*MILLIS_APPROX) {
    if ( (now-last_breathe) > 4) {
      breathe();
      last_breathe = now;
    }
    is_breathing = true;
    led_val = false;
  } else {
    analogWrite(eyes_pin, 0);
    //led_val = true;
  }

  if ( button_press_time > 0 && button_delta < 10*MILLIS_APPROX && button_delta > 1*MILLIS_APPROX) {
    int slope = constrain((button_delta/(float)MILLIS_APPROX) * 50, 0, 255); // abs(5.0-button_delta/MILLIS_APPROX) * 50;
    Serial.print(slope);
    analogWrite(motor_pin, slope);
  } else if (motor_on) {
    digitalWrite(motor_pin, false);
    motor_on = false;
  }


  if (button_triggered) {
    button_triggered = false;
    //if ((button_press_time - now) > 100) {
      button_press_time = now;
    //}
  }

  if (digitalRead(button_pin)) {

  } else {
    analogWrite(eyes_pin, 200);
    button_press_time = now;
  }

  if (led_val) digitalWrite(led_pin, led_val);

}

