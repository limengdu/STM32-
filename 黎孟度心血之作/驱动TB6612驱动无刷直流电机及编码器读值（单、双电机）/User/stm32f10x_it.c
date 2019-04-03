/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"

int Encoder_Left;                     
int Encoder_RIGHT;                    //左右编码器的脉冲计数

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/


/*******************************************************************************
* 函 数 名         : TIM2_IRQHandler
* 函数功能		   : TIM2中断服务函数
* 输    入         : 无
* 输    出         : 无
*                             黎孟度心血之作                                   *
*******************************************************************************/
void TIM2_IRQHandler(void)
{ 		    		  			    
	if(TIM2->SR&0X0001)//溢出中断
	{    				   				     	    	
	}				   
	TIM2->SR&=~(1<<0);//清除中断标志位 	    
}


/*******************************************************************************
* 函 数 名         : TIM3_IRQHandler
* 函数功能		   : TIM3中断服务函数
* 输    入         : 无
* 输    出         : 无
*                             黎孟度心血之作                                   *
*******************************************************************************/
void TIM3_IRQHandler(void)   //TIM3中断
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) 
	//检查指定的TIM3中断发生与否
		{
			Encoder_Left=(short)TIM2->CNT;           //将编码器的值赋给变量
//			Encoder_RIGHT=(short)TIM4->CNT;          //将编码器的值赋给变量
		}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //清除TIM3的中断待处理位
}


/*******************************************************************************
* 函 数 名         : TIM4_IRQHandler
* 函数功能		   : TIM4中断服务函数
* 输    入         : 无
* 输    出         : 无
*                             黎孟度心血之作                                   *
*******************************************************************************/
void TIM4_IRQHandler(void)
{ 		    		  			    
	if(TIM4->SR&0X0001)//溢出中断
	{    				   				     	    	
	}				   
	TIM4->SR&=~(1<<0);//清除中断标志位 	    
}


/********************** (C) COPYRIGHT 2019 GCUwildwolfteam *********************
**********************************END OF FILE**********************************/
