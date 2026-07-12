#include <Arduino.h>
#define PIN_DC_1 24
#define PIN_DC_2 25
#define PIN_DC_3 26
#define PIN_DC_4 27
int PIN_DC[4] = {PIN_DC_1, PIN_DC_2, PIN_DC_3, PIN_DC_4};
void Chaydongco(int DONGCO, int VANTOC)
{
    // Ví dụ tính toán vận tốc về lại PWM
    int PWM = (VANTOC / 200) * 255;
    switch (DONGCO)
    {
    case 1:
        analogWrite(PIN_DC[0], PWM);
        break;
    case 2:
        analogWrite(PIN_DC[1], PWM);
        break;
    case 3:
        analogWrite(PIN_DC[2], PWM);
        break;
    case 4:
        analogWrite(PIN_DC[3], PWM);
        break;

    default:
        break;
    }
}
void setup()
{
    for (int i = 0; i < 4; i++)
    {
        pinMode(PIN_DC[i], OUTPUT);
        analogWrite(PIN_DC[i], 0);
    }
}