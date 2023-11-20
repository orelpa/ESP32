#include "WiFi.h" //библиотека
#include "WebServer.h" //библиотека для веб-сервера
//глобальные переменные для хранения имени сети и пароля
const char* ssid = "WIFI_VOIP";
const char* password = "@watermelon@33";

byte tries = 10; // попыток подключения

//пины светодиодов
uint8_t LED1pin = 4;
bool LED1status = LOW;
uint8_t LED2pin = 33;
bool LED2status = LOW;

//порт работы web server
WebServer server(80);

void setup(){
    //откроем соединение, что бы выводить результат работы программы
    Serial.begin(115200);
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
    pinMode(LED1pin, OUTPUT);
    pinMode(LED2pin, OUTPUT);

}

void loop(){
}