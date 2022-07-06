#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "adc.h"
#include "io.h"
#include "math.h"

#define Res 142
#define Un 380
#define In 100
u16 P_target_setting;  //����Ŀ�깦��
u8 Sys_sta;      //ϵͳ��ʱ��״̬
u8 Rate_uart;
u8 P_target;     //Ŀ�깦��
u8 flash;        //ˢ������

void scan_usart_2(void);
u16 caculat_p(void);
u8 caulat_bit(u16 p);
float filter(u16 data);
int main(void)
 {	 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart1_init(115200);	   //����1��ʼ��Ϊ115200
	uart2_init(9600);  //����2��ʼ��Ϊ9600   
 	LED_Init();			     //LED�˿ڳ�ʼ��		 	
 	Adc_Init();		  		//ADC��ʼ��
  IO_Init();          //NC IO��ʹ��  
  P_target_setting=730;	 
	flash=25;
	DEBUG_USARTx = USART2;
	while(1)
	{
		LED0=!LED0;
		scan_usart_2();//ɨ����λ�������Ŀ�������
		Config_io(caulat_bit(caculat_p()));//���ݼ�����Ĺ��������ʱ8bit�������
	}
 }
 
#define NUM 30		
float filter(u16 data)
{
	static int16_t buf[NUM];
	static int16_t index=0,flag=0;
	static float sum=0;
	
	sum += data - buf[index];	
	buf[index] = data;
	index++;
	
	if(index==NUM)
	{
		index = 0;
		flag = 1;
	}
	
	if(flag==0)		return sum/index;
	else			return sum/NUM;
} 
 
u16 caculat_p()
{
	  u16 adcx;
	  u16 p;
	  float temp;

 		  adcx=Get_Adc_Average(ADC_Channel_1,flash);//12bits ADC �Ĵ�������ֵ
	    temp=(float)adcx*(3.3/4096);//��ʱ����ĵ�ѹ
	    p=(float)(temp*1000/Res)*Un*sqrt(3)*In/20;
	    p=filter(p);
	    return  p;//���ش�ʱ���㹦��ֵ
}


u8 caulat_bit(u16 p)//ģ������
{
   u8 bit_8;//���巵�ص������� true
	 u8 bit_8_fault;//����������� ��ƭ��ֵ
	 u8 temp;
	  if(P_target_setting>p)//���Ŀ�깦�ʴ���ʵ�ʹ��� ʹʵ�ʹ�������
		{
		   temp=p-P_target_setting;	
			 bit_8=0x96;
			 if(temp>200)//150 fault ��150
			 {
				 bit_8_fault=0x96;
			 }
			 if((temp>180)&&(temp<=200))//95 fault ��145
			 {
				 bit_8_fault=0x91;
			 }
			 if((temp>160)&&(temp<=180))//90 fault ��140
			 {
				 bit_8_fault=0x8c;
			 }
			 if((temp>140)&&(temp<=160))//85 fault ��135
			 {
				 bit_8_fault=0x87;
			 }
			 if((temp>120)&&(temp<=140))//80 fault : 130
			 {
				 bit_8_fault=0x82;
			 }
			 if((temp>100)&&(temp<=120))//75 fault : 125
			 {
				 bit_8_fault=0x7d;
			 }
			 if((temp>80)&&(temp<=100))//70 fault ��120
			 {
				 bit_8_fault=0x78;
			 }
			 if((temp>60)&&(temp<=80))//65 fault : 115 
			 {
				 bit_8_fault=0x73;
			 }
			 if((temp>40)&&(temp<=60))//60 fault : 110
			 {
				 bit_8_fault=0x6e;
			 }
			 if((temp>20)&&(temp<=40))//55  fault :105
			 {
				 bit_8_fault=0x69;
			 }
			 if(temp<=20)//50  fault: 100
			 {
				 bit_8_fault=0x64;
			 }
		}
	  if(P_target_setting<=p)//���Ŀ�깦��С��ʵ�ʹ��� ʹʵ�ʹ��ʼ�С
		{
			 temp=P_target_setting-p;
			 bit_8=0x32;//����50
			 if(temp>200)//fault ��50
			 {
			   bit_8_fault=0x32;
			 }
			 if((temp>180)&&(temp<=200))//fault ��55
			 {
			   bit_8_fault=0x37;
			 }
			 if((temp>160)&&(temp<=180))//fault ��60
			 {
			   bit_8_fault=0x3c;
			 }
			 if((temp>140)&&(temp<=160))//fault ��65
			 {
			   bit_8_fault=0x41;
			 }
			 if((temp>120)&&(temp<=140))//fault : 70
			 {
			   bit_8_fault=0x46;
			 }
			 if((temp>100)&&(temp<=120))//fault : 75
			 {
			   bit_8_fault=0x4b;
			 }
			 if((temp>80)&&(temp<=100))//fault ��80
			 {
			   bit_8_fault=0x50;
			 }
			 if((temp>60)&&(temp<=80))//fault : 85
			 {
			   bit_8_fault=0x55;
			 }
			 if((temp>40)&&(temp<=60))//fault : 90
			 {
			   bit_8_fault=0x5a;
			 }
			 if((temp>20)&&(temp<=40))//fault :95
			 {
			   bit_8_fault=0x5f;
			 }
			 if(temp<=20)//fault: 100
			 {
			   bit_8_fault=0x64;
			 }
		}
		printf("s=%dp=%dt=%dspeed=%d,%d\r\n",bit_8_fault,p,P_target_setting,flash,bit_8);//�������� ʵʱ���� Ŀ�깦�� ˢ������ ��ʵֵ
    return bit_8;//����8bit���Ʊ���
}


void scan_usart_2()
{ 	
	 u16 len;	
	 u16 t;
   u8  order_1,order_2,order_3,order_4;
		if(USART2_RX_STA&0x8000)
		{		
			DEBUG_USARTx = USART2;
			len=USART2_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
			for(t=0;t<len;t++)
			{
				USART_SendData(USART2, USART2_RX_BUF[t]);//�򴮿�3��������
				while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
			}
      order_1 = USART2_RX_BUF[0]-0x30;	
      order_2 = USART2_RX_BUF[1]-0x30;
      order_3 = USART2_RX_BUF[2]-0x30;	
      order_4 = USART2_RX_BUF[3]-0x30;
  		P_target_setting=order_1*100+order_2*10;
  		flash=order_3*10+order_4;
			for(t=0;t<len;t++)
			{
          USART2_RX_BUF[t]=0;
			}
    }		
    USART2_RX_STA=0;
 }
