#ifndef _PWM_H #define _PWM_H //�� PWM �ӿ�
int pwm_export(unsigned int pwm); //�ر� PWM �ӿ�
int pwm_unexport(unsigned int pwm); //ʹ�� PWM
int pwm_enable(unsigned int pwm); //��ֹʹ�� PWM
int pwm_disable(unsigned int pwm); //����ռ�ձ�
int pwm_config(unsigned int pwm, unsigned int period, unsigned int duty_cycle); 
//���ü���
int pwm_polarity(int pwm, int polarity);
#endif // PWM H

