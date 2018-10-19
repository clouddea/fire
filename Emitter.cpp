#include "Emitter.h"



Emitter::Emitter(int baseX, int baseY)
{
	this->baseX = baseX;
	this->baseY = baseY;
	srand((unsigned)time(NULL));
	amount = 10;
}


Emitter::~Emitter()
{
}

void Emitter::run()
{
	//���
	for (int i = 0; i < amount; i++) 
	{
		particles.push_back(*new Particle(baseX, baseY, random(1, 30)));
	}
	//�ͷ�
	for (unsigned i = 0; i < particles.size(); i++) 
	{
		particles[i].run();
		particles[i].draw(GetWorkingImage());
	}
	//����
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
}


void Emitter::setBase(int baseX, int baseY) 
{
	this->baseX = baseX;
	this->baseY = baseY;
}

void Emitter::show(Image* image)
{

}