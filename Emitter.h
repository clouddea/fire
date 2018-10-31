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
	int wind;              //统一的风大小
	int windPeriod;        //风的周期
	int windProceed;       //风的过程
	int windAim;           //风目标;
	vector<Particle> particles;
public:
	Emitter(int baseX = 0, int baseY = 0);
	~Emitter();
	void run();
	void setBase(int baseX, int baseY);
	void show(Image* image);
};

