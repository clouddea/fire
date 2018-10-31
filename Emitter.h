#pragma once
#include "Particle.h"
using namespace std;
class Emitter
{
private:
	int gap;
	int amount;            //ÿ֡���������
	int baseX;
	int baseY;
	int wind;              //ͳһ�ķ��С
	int windPeriod;        //�������
	int windProceed;       //��Ĺ���
	int windAim;           //��Ŀ��;
	vector<Particle> particles;
public:
	Emitter(int baseX = 0, int baseY = 0);
	~Emitter();
	void run();
	void setBase(int baseX, int baseY);
	void show(Image* image);
};

