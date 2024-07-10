#include<Wire.h>
#define I2C_ADDR		0x34
#define ADC_BAT_ADDR
#define MOTOR_TYPE_ADDR
#define MOTOR_ENCODER_POLARITY_ADDR
#define MOTOR_FIXED_PWM_ADDR	31
//#define SERVOS_ADDR_CMD 40
#define MOTOR_FIXED_SPEED_ADDR	51
#define MOTOR_ENCODER_TOTAL_ADDR	60
#define MOTOR_TYPE_WITHOUT_ENOUDER	0
#define MOTOR_TYPE_JGB37_520_12V_110RPM	 3
u8 data[20];
bool
WireWriteByte(uint8_t val)
{
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(val);
	if(
		Wire.endTransmission()!=0){
			return false;
	}
	return true;
}
bool WireWriteDataArray(uint8_t reg,uint8_t *val,unsigned int len)
{
	unsigned int i;
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(reg);
	for(i=0;i<len;i++)
	{
		Wire.write(val[i]);
	}
	if(Wire.endTransmission()!=0)
	{
	return false;
	}
	return true;
}
bool WireReadDataByte(uint8_t reg,uint8_t &val)
{
	if(!WireWriteByte(reg))
{
	return false;
}
	Wire.requestFrom(I2C_ADDR,1);
	while(Wire.available())
	{
		val=Wire.read();
	}
	return true;
}
int WireReadDataArray(uint8_t reg,uint8_t *val,unsigned intlen)
{
	unsigned char i = 0;
/*
Indicate
which
register
we
want
to
read
from
*/
	if(!WireWriteByte(reg))
	{
	return -1;
}
	Wire.requestFrom(I2C_ADDR,len);
	while(Wire.available())
	{
	if(i>=len)
	{
	return -1;
	}
	val[i]=Wire.read();
	i++;
	}
	return i;
}
int serial_putc(charc,struct__file*)
{
	Serial.write(c);
	return c;
}
void printf_begin(void)
{
	fdevopen(&serial_putc,0);
}
uint8_t MotorType=MOTOR_TYPE_TT;
uint8_t MotorEncoderPolarity=1;
void setup()
{
	Wire.begin();
	Serial.begin(9600);
	printf_begin();
	delay(200);
	WireWriteDataArray(MOTOR_TYPE_ADDR,&MotorType,1);
	delay(5);
	WireWriteDataArray(MOTOR_ENCODER_POLARITY_ADDR,&MotorEncoderPolarity,1);
}
int8_t p1[4]={50,50,50,50};
int8_t p2[4]={-50,-50,-50,-50};
int8_t s1[4]={2,2,2,2};
int8_t s2[4]={-2,-2,-2,-2};
int32_t EncodeTotal[4];

void loop()
{
	u16 v;
	WireReadDataArray(ADC_BAT_ADDR,data,2);
	v = data[0]+(data[1]<<8);

	Serial.print("V=");Serial.print(v);Serial.println("mV");

	WireReadDataArray(MOTOR_ENCODER_TOTAL_ADDR,(uint8_t*)EncodeTotal,16);
	printf("Encode1 = %ld	Encode2 = %ld	Encode3 = %ld	Encode4 = %ld	\r\n",EncodeTotal[0],EncodeTotal[1],EncodeTotal[2],EncodeTotal[3]);
	WireWriteDataArray(MOTOR_FIXED_SPEED_ADDR,p1,4);

	WireWriteDataArray(MOTOR_FIXED_SPEED_ADDR,s1,4);
	delay(700);

	WireWriteDataArray(MOTOR_FIXED_SPEED_ADDR,s2,4);
	delay(700);
}



















