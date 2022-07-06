#include "stm32f10x.h"
#include "io.h"
#include "sys.h" 
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  
								    
//������ʼ������
void IO_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOF,ENABLE);    //ʹ��ʱ��
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
