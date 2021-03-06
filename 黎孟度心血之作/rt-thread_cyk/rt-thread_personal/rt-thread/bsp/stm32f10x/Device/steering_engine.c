#include "steering_engine.h"

/*-------------------------------------------------------------------------------
函数名称：Set_Joint_Angle
函数描述：舵机角度控制功能函数
输入参数：角度
返回参数：无
备    注：无
---------------------------------------------------------------------------------*/
void Set_Joint_Angle(float angle)
{	
	angle = angle + 90;													    // -90°~90°	
	angle = (u16)(50.0*angle/9.0 + 249);						// 0°~180° 
																									// 以上根据公式 PWM = 高电平时间 / 一个周期的时间 ；
																									// 高电平时间 = 0.5 + 旋转角度/(180度/（2.5ms - 0.5ms）)
	
	TIM_SetCompare2(TIM2,angle);									  // 设置TIMx捕获比较寄存器x的值（角度转换为比较寄存器的值(角度对应电平时间在总周期所占的份额)，用于改变PWM占空比）
}
