#include <stdint.h>

#define PERIPH_BASE        (0x40000000UL)
#define APB2PERIPH_BASE    (PERIPH_BASE + 0x10000UL)
#define AHBPERIPH_BASE     (PERIPH_BASE + 0x20000UL)

#define RCC_BASE           (AHBPERIPH_BASE + 0x1000UL)
#define GPIOC_BASE         (APB2PERIPH_BASE + 0x1000UL)

#define RCC_APB2ENR        (*(volatile uint32_t *)(RCC_BASE + 0x18UL))
#define GPIOC_CRH          (*(volatile uint32_t *)(GPIOC_BASE + 0x04UL))
#define GPIOC_ODR          (*(volatile uint32_t *)(GPIOC_BASE + 0x0CUL))

#define RCC_IOPCEN_Pos     (4U)
#define LED_PIN            (13U)

static void delay(volatile uint32_t count)
{
    while (count--) {
        __asm volatile ("nop");
    }
}

int main(void)
{
    /* Enable GPIOC clock */
    RCC_APB2ENR |= (1UL << RCC_IOPCEN_Pos);

    /* Configure PC13 as push-pull output, max speed 2 MHz
       CRH controls pins 8..15. Each pin uses 4 bits.
       PC13 field bits are CRH[23:20].
       MODE13 = 10 (2 MHz), CNF13 = 00 (GP push-pull) => 0b0010 */
    GPIOC_CRH &= ~(0xFUL << 20);
    GPIOC_CRH |=  (0x2UL << 20);

    /* Blue Pill onboard LED on PC13 is active-low */
    while (1) {
        GPIOC_ODR ^= (1UL << LED_PIN);
        delay(600000UL);
    }
}
