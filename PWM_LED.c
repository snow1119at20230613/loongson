#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include "PWM.h"
int main()
{int pwm = 0;
//PWM0
int period = 10000;
//���� ns
int duty_cycle = 0;
//��ռ�ձ�ʱ�� ns
int calc = 500;
//�� PWM �ӿ�
pwm_export(pwm);
printf("pwm_export:%d\n", pwm);
//ʹ�� PWM pwm_enable(pwm);
printf("pwm_enable:%d\n", pwm);
while (1)
{ //����ռ�ձ�
pwm_config(pwm, period, duty_cycle);
duty_cycle += calc;
if (duty_cycle == period)
{ calc = calc * -1;
}
else if (duty_cycle == 0)
{ calc = calc * -1;
}
usleep(50000);
}
}
