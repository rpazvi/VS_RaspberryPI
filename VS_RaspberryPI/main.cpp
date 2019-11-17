#include <wiringPi.h>

// PIN de LED: el PIN 0 de wiringPi es BCM_GPIO 17.
// hemos tenido que usar la numeración de BCM al inicializar con wiringPiSetupSys
// cuando elige un número PIN diferente, use la numeración de BCM, también
// en Páginas de propiedades, seleccione Eventos de compilación > Evento remoto posterior a la compilación y actualice el comando. 
// que utiliza la exportación de gpio para la configuración de wiringPiSetupSys
//#define	LED	17

#define MOTOR_A0	4
#define MOTOR_A1	17
#define MOTOR_B0	22
#define MOTOR_B1	27

#define ANGLE2STEP(x)		(((x) * 4096) / 360)

void poweroff_motor()
{
	digitalWrite(MOTOR_A0, LOW);	  // Desactivado
	digitalWrite(MOTOR_A1, LOW);
	digitalWrite(MOTOR_B0, LOW);
	digitalWrite(MOTOR_B1, LOW);
}

void step_motor(bool clockwise) 
{
	static int i = 0;

	if (clockwise)
	{
		if (i == 7)
			i = 0;
		else
			i++;
	}
	else
	{
		if (i == 0)
			i = 7;
		else
			i--;
	}
	
	switch (i) {
		case 0: 
			digitalWrite(MOTOR_A0, LOW);  
			digitalWrite(MOTOR_A1, LOW);
			digitalWrite(MOTOR_B0, LOW);
			digitalWrite(MOTOR_B1, HIGH);
			break;

		case 1: 
			digitalWrite(MOTOR_A0, LOW);
			digitalWrite(MOTOR_A1, LOW);
			digitalWrite(MOTOR_B0, HIGH);
			digitalWrite(MOTOR_B1, HIGH);
			break;

		case 2: 
			digitalWrite(MOTOR_A0, LOW);
			digitalWrite(MOTOR_A1, LOW);
			digitalWrite(MOTOR_B0, HIGH);
			digitalWrite(MOTOR_B1, LOW);
			break;
		case 3: 
			digitalWrite(MOTOR_A0, LOW);
			digitalWrite(MOTOR_A1, HIGH);
			digitalWrite(MOTOR_B0, HIGH);
			digitalWrite(MOTOR_B1, LOW);
			break;
		case 4: 
			digitalWrite(MOTOR_A0, LOW);
			digitalWrite(MOTOR_A1, HIGH);
			digitalWrite(MOTOR_B0, LOW);
			digitalWrite(MOTOR_B1, LOW);
			break;
		case 5: 
			digitalWrite(MOTOR_A0, HIGH);
			digitalWrite(MOTOR_A1, HIGH);
			digitalWrite(MOTOR_B0, LOW);
			digitalWrite(MOTOR_B1, LOW);
			break;
		case 6: 
			digitalWrite(MOTOR_A0, HIGH);
			digitalWrite(MOTOR_A1, LOW);
			digitalWrite(MOTOR_B0, LOW);
			digitalWrite(MOTOR_B1, LOW);
			break;
		case 7: 
			digitalWrite(MOTOR_A0, HIGH);
			digitalWrite(MOTOR_A1, LOW);
			digitalWrite(MOTOR_B0, LOW);
			digitalWrite(MOTOR_B1, HIGH);
			break;		
		}
}

int main(void)
{
	wiringPiSetupSys();

	//pinMode(LED, OUTPUT);
	pinMode(MOTOR_A0, OUTPUT);
	pinMode(MOTOR_A1, OUTPUT);
	pinMode(MOTOR_B0, OUTPUT);
	pinMode(MOTOR_B1, OUTPUT);

	while (true)
	{
		static int clockwise = 0;
		int i;
		for (i = 0; i < ANGLE2STEP(90); i++)
		{
			step_motor(clockwise);
			delay(1);
		}
		poweroff_motor();
		clockwise = !clockwise;
		delay(1000);
	}
	
	return 0;
}