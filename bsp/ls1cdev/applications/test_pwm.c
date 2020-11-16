/*���� test_pwm.c*/
/*
����Ӳ�� pwm�� �� finsh ������
*/
#include "../libraries/ls1c_public.h"
#include "../libraries/ls1c_gpio.h"
#include "../libraries/ls1c_delay.h"
#include "../libraries/ls1c_pwm.h"
// ����Ӳ�� pwm ���������� pwm ����

struct pwm_info_t
{
 unsigned int gpio; // PWMn ���ڵ� gpio
 unsigned int mode; // ����ģʽ(�����塢��������)
 float duty; // pwm ��ռ�ձ�
 unsigned long period_ns; // pwm ����(��λ ns)
};

void pwm_control(void)
{
 pwm_info_t pwm_info;
 pwm_info.gpio = LS1C_PWM0_GPIO06; // pwm ����λ gpio06
 pwm_info.mode = PWM_MODE_NORMAL; // ����ģʽ--������� pwm ����
 pwm_info.duty =0.75; // pwm ռ�ձ�
 pwm_info.period_ns = 1*500*1000; // pwm ���� 0.5ms
 // pwm ��ʼ������ʼ������������ pwm ����
 pwm_init(&pwm_info);
 pwm_enable(&pwm_info);

 return ;
}

#include <finsh.h>
FINSH_FUNCTION_EXPORT(pwm_control, pwm_control e.g.pwm_control());

MSH_CMD_EXPORT(pwm_control, pwm_control );

