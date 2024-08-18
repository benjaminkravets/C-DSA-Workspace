#include <stm32f10x.h>
#include <stdint.h> 

void Init_USART(uint32_t sys_clk, uint32_t baud_rate) { 
    /* Enable the system clock for USART1 module */
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN; //Clock enable usart1
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; //Clock enable port A

    /* Setup the RX/TX pins for USART1 */ 
    GPIOA->CRH |= GPIO_CRH_MODE9;   //Output mode, max 50 MHz
    GPIOA->CRH &= ~GPIO_CRH_CNF9;   //Clear bits
    GPIOA->CRH |= GPIO_CRH_CNF9_1;  //Alternate function push-pull
    GPIOA->CRH &= ~GPIO_CRH_MODE10; //Input mode
    GPIOA->CRH &= ~GPIO_CRH_CNF10;  //Clear bits
    GPIOA->CRH |= GPIO_CRH_CNF10_0; //Floating input 

    /* Set the baudrate for USART1 */
    USART1->BRR = sys_clk/baud_rate;

    /* Enable USART1 and its RX- and TX-component */
    USART1->CR1 |= USART_CR1_UE // Usart enable
        | USART_CR1_TE          // Transmitter enable
        | USART_CR1_RE          // Receiver enable 
        | USART_CR1_RXNEIE;     // RXNE interrupt enable
}

uint32_t USART_Receive(void) {
    /* Wait until the data is ready to be received. */
    while ((USART1->SR & USART_SR_RXNE) == 0) { 
        /* Do nothing */
    } 
    /* read a maximum of 9 bits of RX data */
    return USART1->DR & 0x1FF;
}

void USART_Send_Char(int data) {
    /* Load the data into the register to send it */
    USART1->DR = data; 

    /* Wait until transmit completes */
    while ((USART1->SR & USART_SR_TXE) == 0) {
        /* Do nothing until transmitted */
    }
}

void USART_Send_Str(char *str) {
    uint8_t i = 0; 
    /* Keep sending characters until null-byte is encountered */
    while(str[i] != 0) {
        USART_Send_Char(str[i++]);
    }
} 

void USART_Clear_Screen(void) {
    USART_Send_Str("\033[2J");
}
