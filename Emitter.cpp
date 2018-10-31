#include "Emitter.h"



Emitter::Emitter(int baseX, int baseY)
{
	this->baseX = baseX;
	this->baseY = baseY;
	srand((unsigned)time(NULL));
	amount = 50;
	wind = 45;
	windPeriod = 20;
	windProceed = 0;
	windAim = 0;
}


Emitter::~Emitter()
{
}

void Emitter::run()
{
	//添加
	for (int i = 0; i < amount; i++) 
	{
		particles.push_back(*new Particle(baseX, baseY, random(1, 30)));
	}
	//释放
	int newWind =(int)(wind + (double)windProceed / windPeriod * (windAim - wind));
	for (unsigned i = 0; i < particles.size(); i++) 
	{
		particles[i].run();
		particles[i].wind =  newWind;
		particles[i].draw(GetWorkingImage());
		
	}

	//回收
	for (auto i = particles.begin(); i != particles.end(); )
	{
		if ((*i).isDead()) 
		{
			i = particles.erase(i);
		}
		else
		{
			i++;
		}
	}
	//风
	windProceed++;
	if (windProceed >= windPeriod)
	{
		wind = windAim;
		windAim = random(1, 90) - 45;
		windPeriod = random(5, 15);
		windProceed = 0;
	}
}


void Emitter::setBase(int baseX, int baseY) 
{
	this->baseX = baseX;
	this->baseY = baseY;
}

void Emitter::show(Image* image)
{

}