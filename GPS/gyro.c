#include "all.h"

struct Gyro_State Gyro;

/*
 * ������: Gyro_Init
 * ��  ��: �����Ǳ궨ϵ��
 * ��  ��: ��
 * ��  ��: ��
 * ��  ��: �ⲿ����
 */
void Gyro_Init(void)
{
		u8 tp_last, key_value, i=0, is_key = 0;
		LCD_Clear(WHITE);
		LCD_printf(0,6+36*0,300,24,24,"Find a refrence border");
		while(i==0)
		{
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				is_key = 0;
				switch(key_value)
					{		
							case keyOK :
								i=1;//����ѭ��
								MOSI_CMD = GYRO_INIT;
								Write_Database(M_G_CMD_ID);
								break;
							case keyback:
								return;
					}
			}
		}
			i=0;
			delay_ms(10);
			LCD_Clear(WHITE);
			LCD_printf(0,6+36*0,300,24,24,"Press OK to start");
			LCD_printf(0,6+36*1,300,24,24,"Start turning me +10 circles");
		while(i==0)
		{
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				is_key = 0;
				switch(key_value)
					{		
							case keyOK :
								i=1;
							  break;
					}	
			}
		}
		i=0;
		delay_ms(10);
		LCD_Clear(WHITE);
		LCD_printf(0,6+36*0,300,24,24,"I'm turning!!!");
		LCD_printf(0,6+36*1,300,24,24,"Press OK to stop");
		//��һ������ת�ٶȵĺ���
		while(i==0)
		{
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				is_key = 0;
				switch(key_value)
					{		
							case keyOK :
								i=1;
						//��һ���ص����е���ĺ���
								break ;
					}	
			}
		}
	  i=0;
		delay_ms(10);
		LCD_Clear(WHITE);
		LCD_printf(0,6+36*0,300,24,24,"Back to the refrence -");
		LCD_printf(0,6+36*1,300,24,24,"border and press OK to end");	
		while(i==0)
		{
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				is_key = 0;
				switch(key_value)
					{		
							case keyOK :
							i=1;
					   	Write_Database(M_G_CMD_ID);
							break ;
					}	
			}
		}
		
		i=0;
		delay_ms(10);
		LCD_Clear(WHITE);
		LCD_printf(0,6+36*1,300,24,24,"Press Ok to start .");
		LCD_printf(0,6+36*2,300,24,24,"Start turning me -10 circles");
		LCD_printf(0,6+36*0,300,24,24,"Con1:%lf",Gyro.convert1);
		while(i==0)
		{
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				is_key = 0;
				switch(key_value)
					{		
							case keyOK :
							 i=1;
							break ;
					}	
			}
		}
		i=0;
		delay_ms(10);
		LCD_Clear(WHITE);
		LCD_printf(0,6+36*0,300,24,24,"I'm turning!!!");
		LCD_printf(0,6+36*1,300,24,24,"Press OK to stop");	
  //��һ����������ת�ĺ���
		while(i==0)
		{
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				is_key = 0;
				switch(key_value)
					{		
							case keyOK :
								//��һ�������е��ֹͣ�ĺ���
							  i=1 ;
							break ;
					}	
			}
		}
		i=0;
		delay_ms(10);
		LCD_Clear(WHITE);
		LCD_printf(0,6+36*0,300,24,24,"Back to the refrence -");
		LCD_printf(0,6+36*1,300,24,24,"border and press OK to end");		
		while(i==0)
		{
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				is_key = 0;
				switch(key_value)
					{		
							case keyOK :
								Write_Database(M_G_CMD_ID);
							  i=1 ;
							break;
					}	
			}
		}
		i=0;
		delay_ms(10) ;
		LCD_Clear(WHITE);
		LCD_printf(0,6+36*0,300,24,24,"Convert1:%lf",Gyro.convert1);
		LCD_printf(0,6+36*1,300,24,24,"Convert2:%lf",Gyro.convert2);	
		LCD_printf(0,6+36*2,300,24,24,"Press any key to continue...");	
		
		while(1)
		{
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{	return;}
		}
	}		
/*
 * ������: Gyro_Set
 * ��  ��: ���������ǵı궨ϵ��
 * ��  ��: ��
 * ��  ��: ��
 * ��  ��: �ⲿ����
 */
void Gyro_Set(void)
{  	u8 tp_last, key_value, i=0, is_key = 0;
	
	  MOSI_GYRO_C1.f64_data = MISO_GYRO_C1.f64_data;
    MOSI_GYRO_C2.f64_data = MISO_GYRO_C2.f64_data;
		Input_DoubleValue(&MOSI_GYRO_C1.f64_data,"Convert1");
    Write_Database(W_GYRO_C1_ID);
    
    Input_DoubleValue(&MOSI_GYRO_C2.f64_data,"Convert2");
    Write_Database(W_GYRO_C2_ID);
    
    delay_ms(10);
		
		LCD_Clear(WHITE);
		LCD_printf(0,6+36*0,300,24,24,"Convert1:%lf",Gyro.convert1);
		LCD_printf(0,6+36*1,300,24,24,"Convert2:%lf",Gyro.convert2);	
		LCD_printf(0,6+36*2,300,24,24,"Press any key to continue...");	
		while(1) 
		{
				if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				return;
			}
		}
    
}
/*
 * ������: Gyro_CheckFloat
 * ��  ��: ������У��Ư
 * ��  ��: ��
 * ��  ��: ��
 * ��  ��: �ⲿ����
 */
void Gyro_CheckFloat(void)
{
		u8 tp_last, key_value, i=0, is_key = 0;
		LCD_Clear(WHITE);
		LCD_printf(0,6+36*0,300,24,24,"==Check Float~==");
		LCD_printf(0,6+36*2,300,24,24,"Don't move the robot");
		LCD_printf(0,6+36*3,300,24,24,"   !!!!!");
	  CheckFloat();
	 while(MISO_CMD == NO_COMMAND)
	 {
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				is_key = 0;
				switch(key_value)
					{		
							case keyback :
								return ;
					}	
			}
		}
		LCD_Clear(WHITE);
		switch(MISO_CMD)
        {
				case CF_CHANGED:
				LCD_printf(0,6+36*2,300,24,24,"Zero Float Changed!!");
				break;
				case CF_ERROR:
				LCD_printf(0,6+36*2,300,24,24,"Gyro Init Error!!");
        break ;
				}
		while(1)
		{
			if (Is_USART_Key_Receive)
			{
				Is_USART_Key_Receive = 0;
				key_value = Key_RxBuffer[0];
				if (key_value != keyempty1)
					is_key = 1;
			}
			if (is_key)
			{
				is_key = 0;
				switch(key_value)
					{		
							case keyback :
						 return;
					}	
			}
		}
}