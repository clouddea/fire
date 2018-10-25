#include "Particle.h"



Particle::Particle(int baseX, int baseY,int maxLife)
{
	this->baseX = baseX;
	this->baseY = baseY;
	angle = random(60, 120);                           //角度随机生成
	life = (30 -abs((90 - angle))) * maxLife / 30;     //偏离90度越远，生命越短
	maxSize = 3;
	speed = 10;
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
		int temp = colors.size() * state / life;                //生命因素
		int temp2 = abs(angle - 90) * colors.size() / 30 - 1 ;  //角度因素
		color = colors[temp > temp2? temp:temp2];               //颜色由两个因素决定
		speed = 10;
		size = (life - state) * maxSize / life;                 //大小由生命决定
		double straightAngle = angle * pi / 180;
		int dx = state * cos(straightAngle) * speed;            //由角度、生命、速度水平决定位移
		int dy = - state * sin(straightAngle) * speed;          //由角度、生命、速度垂直决定位移
		double r = life / 2;
		double xr = abs(dx) - r;
		int offset = sqrt(r*r - xr * xr)* ((dx > 0)? -1: 1);    //一个微调量
		//int offset = 0;
		y = baseY + dy;
		x = baseX + dx + offset;
		state++;
	}
}

bool Particle::isDead() 
{
	return state >= life;
}