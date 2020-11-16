/*代码 test_gpio.c*/
#include <rtthread.h>
#include <stdlib.h>
#include "../libraries/ls1c_public.h"
#include "../libraries/ls1c_gpio.h"
#include "../libraries/ls1c_delay.h"
#define led_gpio 52
#define key_gpio 85

void turn_on(void)
{
 int i;
 // 初始化
 rt_kprintf("Init gpio! \n");
 gpio_init(led_gpio, gpio_mode_output);

 gpio_set(led_gpio, gpio_level_low); //指示灯开启

 return ;
}

void turn_off(void)
{
 int i;
 // 初始化
 rt_kprintf("Init gpio! \n");
 gpio_init(led_gpio, gpio_mode_output);

 gpio_set(led_gpio, gpio_level_high); //指示灯熄灭

 return ;
}


#include <finsh.h>
FINSH_FUNCTION_EXPORT(turn_on, turn_on e.g.turn_on());
FINSH_FUNCTION_EXPORT(turn_off, turn_off e.g.turn_off());

/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(turn_on, gpio output sample);
MSH_CMD_EXPORT(turn_off, gpio output sample);

