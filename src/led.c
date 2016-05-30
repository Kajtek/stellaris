#include "lm4f120h5qr.h"

void enableLed() {
    // Enable clock gating for GPIO F.
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    // Set direction of 4th pin (LED) as output.
    GPIO_PORTF_DIR_R = 0x08;

    // Enable 4th pin of GPIO F.
    GPIO_PORTF_DEN_R = 0x08;
}

void lightOnLed() {
    // Assert 4th pin of GPIO F. Light the LED.
    GPIO_PORTF_DATA_R |= 0x08;
}
