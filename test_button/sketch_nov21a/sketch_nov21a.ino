const int buttonPin = 12; // номер контака кнопки
const int ledPin = 33; //pin вспышки

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT); // кнопка входное устройство
  pinMode(ledPin, OUTPUT); //светодиод выходное устройство
  Serial.begin(115200);
}

void loop() {

  buttonState = digitalRead(buttonPin); //считываем состояние кнопки, и записываем в переменную buttonState;

  //проверяем значение кнопки на HIGH
  Serial.println(buttonState);
  if (buttonState == HIGH){
    //ключаем светодиод
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }

}
