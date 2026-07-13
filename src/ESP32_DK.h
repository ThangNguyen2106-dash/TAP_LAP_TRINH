/*
 ESp32_DK Là ví dụ đây là bộ điều khiển
 thực hiện đọc nút nhấn hay vặn ga từ người dùng
 sau khi xử lý dữ liệu sẽ gửi dữ liệu cho ESP_TT
*/
#include <Arduino.h>
#include <KHAIBAO_PIN.h>
void setup()
{
    Serial.begin(115200);                        // Khai báo giao tiếp với máy tính
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2); // Khai báo giao tiếp với ESP32_TT
    for (int i = 0; i < 3; i++)
    {
        pinMode(BUTTON[i], INPUT);
    }
    pinMode(SENSOR1, INPUT); // Khai báo chân đọc tín hiệu cho biến trở vặn ga
}
int adc = 0;
int lastadc = 0;
int power = 0;
void Send_DATA()
{
    int docnutnhan_1 = digitalRead(BUTTON1);
    int docnutnhan_2 = digitalRead(BUTTON2);
    int docnutnhan_3 = digitalRead(BUTTON3);
    // Kiểm tra nút nhấn
    if (docnutnhan_1 == HIGH)
        Serial2.print('A'); // nếu nút 1 được nhấn gửi kí tự A
    if (docnutnhan_2 == HIGH)
        Serial2.print('B'); // nếu nút 2 được nhấn gửi kí tự B
    if (docnutnhan_3 == HIGH)
        Serial2.print('C'); // nếu nút 3 được nhấn gửi kí tự C

    // Đọc giá trị biến trở vặn ga
    adc = analogRead(SENSOR1); // Đọc ADC
    if (adc != lastadc)        // Chỉ thực hiện gửi giá trị tốc độ mỗi khi nó bị thay đổi
    {
        power = (adc * 100) / 4095; // Chuyển độ bộ ADC sang giá trị % công suất
        Serial2.print(power);
        Serial2.print('e'); // Gửi giá trị công suất với kí tự kết thúc là e
        lastadc = adc;
    }
}
void loop()
{
    Send_DATA();
    delay(5);
}