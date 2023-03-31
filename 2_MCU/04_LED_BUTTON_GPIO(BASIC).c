#include "stm32f4xx.h"
#include <stdio.h>

void delay(int T)
{
	int i;
	while(T--){
	for(i=0;i<5000;i++);}
}

int main()
{
	RCC->AHB1ENR |= 7; //ENABLING CLOCK FOR PORT A,B AND C
	GPIOA->MODER |= 0X10000; //CONFIGURING PIN PA8 IN OUTPUT MODE
	GPIOB->MODER |= 0X10000; //CONFIGURING PIN PB8 IN OUTPUT MODE
	GPIOC->MODER |= 0X0;     //CONFIGURING PIN PC9 IN INPUT MODE
	GPIOC->PUPDR |= 0x40000;
	while(1)
	{
		if(GPIOC->IDR & 0x200)  //READING THE STATUS OF IDR BIT 9 FOR PC9
		{
			GPIOA->ODR &= ~0x100; // 0000 0001 0000 0000 TURNING OFF LED 1 AT PIN PA8
			GPIOB->ODR &= ~0x100; // 0000 0001 0000 0000 TURNING OFF BUZZER AT PIN PB8

		}
		else
		{
			printf("Button Pressed!\n");
			GPIOA->ODR |= 0x100; // 0000 0001 0000 0000 TURNING ON LED 1 AT PIN PA8
			GPIOB->ODR |= 0x100; // 0000 0001 0000 0000 TURNING ON BUZZER AT PIN PB8
		}
	}
}
