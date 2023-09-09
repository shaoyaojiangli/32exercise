#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIO_InitTypeDef GPIO_Initstructure;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_Initstructure);
    
    //GPIO_ResetBits(GPIOA, GPIO_Pin_0);
    //GPIO_SetBits(GPIOA, GPIO_Pin_0);
    //GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
    //GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
    
    while(1)
    {
        GPIO_ResetBits(GPIOB, GPIO_Pin_12);
        Delay_ms(100);
        GPIO_SetBits(GPIOB, GPIO_Pin_12);
        Delay_ms(100);
         GPIO_ResetBits(GPIOB, GPIO_Pin_12);
        Delay_ms(100);
        GPIO_SetBits(GPIOB, GPIO_Pin_12);
        Delay_ms(700);
        
       
    }
}

