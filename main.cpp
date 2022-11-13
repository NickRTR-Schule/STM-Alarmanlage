#include "PinNamesTypes.h"
#include "mbed.h"
#include "platform/mbed_thread.h"

#define SIRENE_DELAY 500

int main()
{
    DigitalOut sirene(PC_0);
    DigitalOut test(PC_3);

    DigitalIn button(PB_0);
    button.mode(PullDown);

    DigitalIn magnet(PB_1);
    magnet.mode(OpenDrain);

    DigitalIn lichtschranke(PB_3);
    lichtschranke.mode(PullDown);

    DigitalIn mikrofon(PB_2);
    mikrofon.mode(OpenDrain);

    DigitalOut gelb(PC_1);
    DigitalOut rot(PC_2);
    DigitalOut blau(PC_3);

    DigitalOut status(LED1);

    bool scharf = false;

    while (true) {
        if (button == 0) {
            scharf = !scharf;
            thread_sleep_for(20);
        }

        while (button == 0) {}

        if (scharf == true) {
            status = true;
            if (magnet == 0 || lichtschranke == 1 || mikrofon == 0) {
                sirene = true;
            }
        } else {
            status = false;
            sirene = false;
        }
    }
}

