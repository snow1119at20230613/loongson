#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
//�� PWM �ӿ�
int pwm_export(unsigned int pwm)
{int fd;
if (pwm == 0)
{ fd = open("/sys/class/pwm/pwmchip0/export", O_WRONLY);
}
else if (pwm == 1)
{ fd = open("/sys/class/pwm/pwmchip1/export", O_WRONLY);
}
else if (pwm == 2)
{ fd = open("/sys/class/pwm/pwmchip2/export", O_WRONLY);
}
else if (pwm == 3)
{ fd = open("/sys/class/pwm/pwmchip3/export", O_WRONLY);
}
if (fd < 0)
{ printf("\nFailed expport PWM%c\n", pwm);
return -1;
}
write(fd, "0", 2);
close(fd);
return 0;
}
//�ر� PWM �ӿ�
int pwm_unexport(unsigned int pwm)
{int fd;
if (pwm == 0)
{ fd = open("/sys/class/pwm/pwmchip0/unexport", O_WRONLY);
}
else if (pwm == 1)
{ fd = open("/sys/class/pwm/pwmchip1/unexport", O_WRONLY);
}
else if (pwm == 2)
{ fd = open("/sys/class/pwm/pwmchip2/unexport", O_WRONLY);
}
else if (pwm == 3)
{ fd = open("/sys/class/pwm/pwmchip3/unexport", O_WRONLY);
}
if (fd < 0)
{ printf("\nFailed unexpport PWM%d\n", pwm);
return -1;
}
write(fd, "0", 2);
close(fd);
return 0;
}
//ʹ�� PWM
int pwm_enable(unsigned int pwm)
{int fd;
if (pwm == 0)
{ fd = open("/sys/class/pwm/pwmchip0/pwm0/enable", O_WRONLY);
}
else if (pwm == 1)
{ fd = open("/sys/class/pwm/pwmchip1/pwm0/enable", O_WRONLY);
}
else if (pwm == 2)
{ fd = open("/sys/class/pwm/pwmchip2/pwm0/enable", O_WRONLY);
}
else if (pwm == 3)
{ fd = open("/sys/class/pwm/pwmchip3/pwm0/enable", O_WRONLY);
}
if (fd < 0)
{ printf("\nFailed enable PWM%d\n", pwm);
return -1;
}
write(fd, "1", 2);
close(fd);
return 0;
}
//��ֹʹ�� PWM
int pwm_disable(unsigned int pwm)
{int fd;
if (pwm == 0)
{ fd = open("/sys/class/pwm/pwmchip0/pwm0/enable", O_WRONLY);
}
else if (pwm == 1)
{ fd = open("/sys/class/pwm/pwmchip1/pwm0/enable", O_WRONLY);
}
else if (pwm == 2)
{ fd = open("/sys/class/pwm/pwmchip2/pwm0/enable", O_WRONLY);
}
else if (pwm == 3)
{ fd = open("/sys/class/pwm/pwmchip3/pwm0/enable", O_WRONLY);
}
if (fd < 0)
{ printf("\nFailed disable PWM%d\n", pwm);
return -1;
}
write(fd, "0", 2);
close(fd);
return 0;
}
//����ռ�ձ�
int pwm_config(unsigned int pwm, unsigned int period, unsigned int duty_cyc
le)
{int fd, len_p, len_d;
char buf_p[10];
char buf_d[10];
len_p = snprintf(buf_p, sizeof(buf_p), "%d", period);
len_d = snprintf(buf_d, sizeof(buf_d), "%d", duty_cycle);
if (pwm == 0)
{ fd = open("/sys/class/pwm/pwmchip0/pwm0/period", O_WRONLY);
}
else if (pwm == 1)
{ fd = open("/sys/class/pwm/pwmchip1/pwm0/period", O_WRONLY);
}
else if (pwm == 2)
{ fd = open("/sys/class/pwm/pwmchip2/pwm0/period", O_WRONLY);
}
else if (pwm == 3)
{ fd = open("/sys/class/pwm/pwmchip3/pwm0/period", O_WRONLY);
}
if (fd < 0)
{ printf("\nFailed set PWM period%d\n", pwm);
return -1;
}
write(fd, buf_p, len_p);
close(fd);
if (pwm == 0)
{ fd = open("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", O_WRONLY);
}
else if (pwm == 1)
{ fd = open("/sys/class/pwm/pwmchip1/pwm0/duty_cycle", O_WRONLY);
}
else if (pwm == 2)
{ fd = open("/sys/class/pwm/pwmchip2/pwm0/duty_cycle", O_WRONLY);
}
else if (pwm == 3)
{ fd = open("/sys/class/pwm/pwmchip3/pwm0/duty_cycle", O_WRONLY);
}
if (fd < 0)
{ printf("\nFailed set PWM duty_cycle%d\n", pwm);
 return -1;
}
write(fd, buf_d, len_d);
close(fd);
return 0;
}
//���ü���
int pwm_polarity(int pwm, int polarity)
{int fd;
if (pwm == 0)
{ fd = open("/sys/class/pwm/pwmchip0/pwm0/polarity", O_WRONLY);
}
else if (pwm == 1)
{ fd = open("/sys/class/pwm/pwmchip1/pwm0/polarity", O_WRONLY);
}
else if (pwm == 2)
{ fd = open("/sys/class/pwm/pwmchip2/pwm0/polarity", O_WRONLY);
}
else if (pwm == 3)
{ fd = open("/sys/class/pwm/pwmchip3/pwm0/polarity", O_WRONLY);
}
if (fd < 0)
{ printf("\nFailed set PWM polarity%d\n", pwm);
 return -1;
}
if (polarity == 1)
{ write(fd, "normal", 6);
}
else if (polarity == 0)
{ write(fd, "inversed", 8);
}
close(fd);
return 0;
}
