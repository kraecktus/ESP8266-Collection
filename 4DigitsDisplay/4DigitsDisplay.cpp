// Needs TM1637 Library
#include <Arduino.h>
#include <TM1637Display.h>

const int CLK = 4;                              // Set the CLK pin connection to the display
const int DIO = 0;                              // Set the DIO pin connection to the display
TM1637Display display(CLK, DIO);                // set up the 4-Digit Display.
uint8_t Segments[4] = {0x00, 0x00, 0x00, 0x00}; // blank on start
int Count[4] = {0, 0, 0, 0};

void SetDisplay()
{
    display.setSegments(Segments);
}
uint8_t ConvertNum(int number)
{
    return display.encodeDigit(number);
}
void setup()
{
    display.clear();
    display.setBrightness(0x0f);
    SetDisplay();
}

void loop()
{
    Count[3] += 1;
    for (int i = 3; i > 0; i--)
    {
        if (Count[i] == 9)
        {
            Count[i - 1] += 1;
            Count[i] = 0;
        }
    }
    Segments[0] = ConvertNum(Count[0]);
    Segments[1] = ConvertNum(Count[1]);
    Segments[2] = ConvertNum(Count[2]);
    Segments[3] = ConvertNum(Count[3]);
    SetDisplay();
    delay(100);
}
