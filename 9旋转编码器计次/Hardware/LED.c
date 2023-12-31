#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
}


void LED_Set (uint8_t which, uint8_t mode)
{
    uint8_t i;
    switch(which)
    {
        case 1: i = GPIO_Pin_1;
        break;
        case 2: i = GPIO_Pin_2;
        break;
    }
    if(mode == 0)
    {
        GPIO_SetBits(GPIOA, i);
    }
    else if(mode == 1)
    {
        GPIO_ResetBits(GPIOA, i);
    }
}

void LED1_Turn(void)
{
    if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_1);
    }
    else
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_1);
    }
}

void LED2_Turn(void)
{
    if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 0)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_2);
    }
    else
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_2);
    }
}

