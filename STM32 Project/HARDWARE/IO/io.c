#include "stm32f10x.h"
#include "io.h"
#include "sys.h" 
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//按键驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  
								    
//按键初始化函数
void IO_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOF,ENABLE);    //使能时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_2| GPIO_Pin_4|GPIO_Pin_6;				
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
  GPIO_Init(GPIOF, &GPIO_InitStructure);					 
  GPIO_ResetBits(GPIOF,GPIO_Pin_0|GPIO_Pin_2| GPIO_Pin_4|GPIO_Pin_6);						 

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_2| GPIO_Pin_4|GPIO_Pin_6;	    		 
  GPIO_Init(GPIOE, &GPIO_InitStructure);	  				 
  GPIO_ResetBits(GPIOE,GPIO_Pin_0|GPIO_Pin_2| GPIO_Pin_4|GPIO_Pin_6); 						

}

void Config_io(u8 num)
{
   if(num&0x01)
	 {IO_0=0;}
	 else
   {IO_0=1;}
   if(num&0x02)
	 {IO_1=0;}
	 else
   {IO_1=1;}
   if(num&0x04)
	 {IO_2=0;}
	 else
   {IO_2=1;}
   if(num&0x08)
	 {IO_3=0;}
	 else
   {IO_3=1;}
   if(num&0x10)
	 {IO_4=0;}
	 else
   {IO_4=1;}
   if(num&0x20)
	 {IO_5=0;}
	 else
   {IO_5=1;}
   if(num&0x40)
	 {IO_6=0;}
	 else
   {IO_6=1;}
   if(num&0x80)
	 {IO_7=0;}
	 else
   {IO_7=1;}	 
}
