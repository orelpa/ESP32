#include "WiFi.h" //библиоткеа  wi-fi
#include <Weberver.h> //библиотке WebServera

//глобальные переменные для хранения имени сети и пароля
const char* ssid = "home";
const char* password = "12345678";

byte tries = 10; // попыток подключения

//объявление пинов
uint8_t LED1pin = 16;
bool LED1status = LOW;
uint8_t LED2pin = 17;
bool LED2status = LOW;


void setup() {
//откроем соединение, что бы выводить результат работы программы
Serial.begin(115200);

//режим работы пинов
pinMode (LED1pin, OUTPUT);
pinMode (LED2pin, OUTPUT);

//Вызываем метод begin для объекта WiFi передавая в качестве аргументов SSID и переменную пароля
WiFi.begin(ssid, password);

//Выполняем цикл пока соединение не будет установлено.
//Вызываем метод status для объекта WiFi и ждем, пока результат не совпадет с WL_CONNECTED
//между каждой итерацией выыводим небольшую задержку
while ( --tries && WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.println(".");
}
if (WiFi.status() != WL_CONNECTED){
  Serial.println("Non Connecting to WiFi..");
}
else
{
  //Иначе  удалось подключиться и выводим адрес
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
}
server.on("/", handle_OnConnect);
server.on("/led1on", handle_led1on);
server.on("/led1off", nandle_led1off);
server.on("/led2on", handle_led2on);
server.on("/led2off", handle_led2off);
server.begin();
Serial.println("HTTP server started");
}
void loop(){
}