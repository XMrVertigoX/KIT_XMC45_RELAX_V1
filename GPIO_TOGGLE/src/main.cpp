#include <xmc_gpio.h>

#define TICKS_PER_SECOND 1000
#define TICKS_WAIT 500

#define LED1 P1_1
#define LED2 P1_0

extern "C" void SysTick_Handler(void) {
    static uint32_t ticks = 0;

    ticks++;

    if (ticks == TICKS_WAIT) {
        XMC_GPIO_ToggleOutput(LED1);
        XMC_GPIO_ToggleOutput(LED2);
        ticks = 0;
    }
}

int main() {
    XMC_GPIO_CONFIG_t config;

    config.mode            = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;
    config.output_level    = XMC_GPIO_OUTPUT_LEVEL_HIGH;
    config.output_strength = XMC_GPIO_OUTPUT_STRENGTH_MEDIUM;

    XMC_GPIO_Init(LED1, &config);

    config.output_level = XMC_GPIO_OUTPUT_LEVEL_LOW;
    XMC_GPIO_Init(LED2, &config);

    /* System timer configuration */
    SysTick_Config(SystemCoreClock / TICKS_PER_SECOND);

    for (;;) {
    }
}
