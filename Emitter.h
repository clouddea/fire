#pragma once
#include "Particle.h"
using namespace std;
class Emitter
{
private:
	int gap;
	int amount;            //每帧发射的数量
	int baseX;
	int baseY;
	vector<Particle> particles;
public:
	Emitter(int baseX = 0, int baseY = 0);
	~Emitter();
	void run();
	void setBase(int baseX, int baseY);
	void show(Image* image);
};

