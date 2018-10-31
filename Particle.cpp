#include "Particle.h"



Particle::Particle(int baseX, int baseY,int maxLife)
{
	this->baseX = baseX;
	this->baseY = baseY;
	angle = random(30, 150);                           //�Ƕ��������
	life = 60;
	maxSize = 3;
	size = 3;
	//speed = 10;
	colors.push_back(BGR(0xFFEC91));
	colors.push_back(BGR(0xFCBA49));
	colors.push_back(BGR(0xE05E00));
	colors.push_back(BGR(0x9B2309));
	colors.push_back(BGR(0x4A0403));
}


Particle::~Particle()
{
}

void Particle::draw(Image* image)
{
	setfillcolor(color);
	solidcircle(x, y, size);
}


void Particle::run() 
{
	
	if (state < life) 
	{
		/*int temp = colors.size() * state / life;                //��������
		int temp2 = abs(angle - 90) * colors.size() / 30 - 1 ;  //�Ƕ�����
		color = colors[temp > temp2? temp:temp2];               //��ɫ���������ؾ���
		speed = 10;
		size = (life - state) * maxSize / life;                 //��С����������
		double straightAngle = angle * pi / 180;
		int dx = state * cos(straightAngle) * speed;            //�ɽǶȡ��������ٶ�ˮƽ����λ��
		int dy = - state * sin(straightAngle) * speed;          //�ɽǶȡ��������ٶȴ�ֱ����λ��
		double r = life / 2;
		double xr = abs(dx) - r;
		int offset = sqrt(r*r - xr * xr)* ((dx > 0)? -1: 1);    //һ��΢����
		//int offset = 0;
		y = baseY + dy;
		x = baseX + dx + offset;*/
		double straightAngle = angle * pi / 180;
		double si = sin(straightAngle);
		double co = cos(straightAngle);
		double p = (2 * state * si) / (8 * co * co + 1);
		double offsetX = p * co;
		double offsetY = p * si;
		double windAngle = wind * pi / 180;
		double �䶯 = (offsetY / p);
		double rotateAngle = �䶯 * �䶯 * �䶯 * �䶯 * �䶯 * windAngle;
		double sinRotate = sin(rotateAngle);
		double cosRotate = cos(rotateAngle);
		double offsetXRotate = cosRotate * offsetX - sinRotate * offsetY;
		double offsetYRotate = sinRotate * offsetX + cosRotate * offsetY;
		int disturbX = random(0, 5);
		int influenceOfWind = (int)(((double)state / life) * wind);
		x = (int)(baseX + offsetXRotate + disturbX);
		y = (int)(baseY - offsetYRotate);
		double colorChange = (double)state / life;
		int gray =(int)(255 - (sqrt(colorChange) * 255));
		color = RGB(gray, gray, gray);
		state++;
	}
}

bool Particle::isDead() 
{
	return state >= life;
}