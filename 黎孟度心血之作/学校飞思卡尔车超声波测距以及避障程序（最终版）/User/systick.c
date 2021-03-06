/*-------------------------------------------------------------------------------
文件名称：systick.c
文件描述：系统滴答定时器的相关功能函数。   
备    注：测试平台基于华南理工大学广州学院 机械工程实验中心硬件平台_V1.0 RC
维护人员：Science
邮    箱：565369157@qq.com
---------------------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "systick.h"

u32 TimingDelay;

/*-------------------------------------------------------------------------------
函数名称：SysTick_Init
函数描述：初始化系统滴答定时器。
输入参数：无
返回参数：无
备    注：SystemFrequency / 1000 	  1ms  中断一次
					SystemFrequency / 100000  10us 中断一次
					SystemFrequency / 1000000 1us  中断一次
---------------------------------------------------------------------------------*/
void SysTick_Init(void)
{
	 if (SysTick_Config(SystemCoreClock / 100000)) 
	 {
		 while(1);
	 }
}	
/*-------------------------------------------------------------------------------
函数名称：TimingDelay_Decrement
函数描述：获取节拍程序
输入参数：无
返回参数：无
备    注：该用于在 SysTick 中断函数 SysTick_Handler()调用
---------------------------------------------------------------------------------*/
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00) 
	{
		TimingDelay--;
	}
}
