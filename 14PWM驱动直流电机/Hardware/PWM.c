#include "stm32f10x.h"                  // Device header


void PWM_Init()
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//开启时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//开启GPIOA
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//开启AFIO重映射
    GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);//部分重映射1  PA = 0 ——> PA = 15
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
  
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//选择复用推挽输出，将输出控制权转移给片上外设
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    TIM_InternalClockConfig(TIM2);//选择内部时钟
    
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;//指定时钟分频
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//计数器模式
    TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;//ARR自动重装器的值
    TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1;//PSC预分频器的值
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;//重复计数器的值
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);//配置时基单元
    
//    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//使能更新中断到NVIC的通路
//    
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//NVIC优先级分组选择
//    
//    NVIC_InitTypeDef NVIC_InitStructure;
//    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;//选择定时器在NVIC里的通道
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;//抢占优先级
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;//响应优先级
//    NVIC_Init(&NVIC_InitStructure);
    
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCStructInit(&TIM_OCInitStructure);//给结构体赋初始值
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//设置输出比较的模式
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//设置输出比较的极性
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//设置输出使能
    TIM_OCInitStructure.TIM_Pulse = 0;//设置CCR
    TIM_OC3Init(TIM2, &TIM_OCInitStructure);//初始化输出比较单元
    
    TIM_Cmd(TIM2, ENABLE);//启动定时器
}    

void PWM_SetCompare3(uint16_t Compare)
{
    TIM_SetCompare3(TIM2, Compare);
}