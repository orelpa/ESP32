#include "WiFi.h" //библиоткеа

//глобальные переменные для хранения имени сети и пароля
const char* ssid = "home";
const char* password = "12345678";

void setup() {
//откроем соединение, что бы выводить результат работы программы
Serial.begin(115200);

//Вызываем метод begin для объекта WiFi передавая в качестве аргументов SSID и переменную пароля
WiFi.begin(ssid, password);

//Выполняем цикл пока соединение не будет установлено.
//Вызываем метод status для объекта WiFi и ждем, пока результат не совпадет с WL_CONNECTED
//между каждой итерацией выыводим небольшую задержку
while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.println("Connecting to WiFi..");
}
}
void loop(){}