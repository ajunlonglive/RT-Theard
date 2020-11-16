/*代码 test_pwm.c*/
/*
测试硬件 pwm， 在 finsh 中运行
*/
#include "../libraries/ls1c_public.h"
#include "../libraries/ls1c_gpio.h"
#include "../libraries/ls1c_delay.h"
#include "../libraries/ls1c_pwm.h"
// 测试硬件 pwm 产生连续的 pwm 波形

struct pwm_info_t
{
 unsigned int gpio; // PWMn 所在的 gpio
 unsigned int mode; // 工作模式(单脉冲、连续脉冲)
 float duty; // pwm 的占空比
 unsigned long period_ns; // pwm 周期(单位 ns)
};

void pwm_control(void)
{
 pwm_info_t pwm_info;
 pwm_info.gpio = LS1C_PWM0_GPIO06; // pwm 引脚位 gpio06
 pwm_info.mode = PWM_MODE_NORMAL; // 正常模式--连续输出 pwm 波形
 pwm_info.duty =0.75; // pwm 占空比
 pwm_info.period_ns = 1*500*1000; // pwm 周期 0.5ms
 // pwm 初始化，初始化后立即产生 pwm 波形
 pwm_init(&pwm_info);
 pwm_enable(&pwm_info);

 return ;
}

#include <finsh.h>
FINSH_FUNCTION_EXPORT(pwm_control, pwm_control e.g.pwm_control());

MSH_CMD_EXPORT(pwm_control, pwm_control );

