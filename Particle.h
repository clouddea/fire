#pragma once
#include <iostream>
#include <graphics.h>
#include <vector>
#include <cmath>
#include <ctime>
#define random(a,b) (rand()%(b-a+1)+a)
#define pi 3.1415926
using namespace std;
typedef COLORREF Color;
typedef IMAGE Image;
//类
class Particle
{
private:
	int baseX;
	int baseY;
	int x;
	int y;
	int angle;
	int size;                     //半径大小
	int maxSize;
	int state;                    //当前状态
	int life;                     //生命长度
	int speed;                    //运动速度
	Color color;                  //当前颜色
	vector<Color> colors;         //所有颜色
public:
	Particle(int baseX, int baseY, int maxLife = 30);
	~Particle();
	void run();                     //每帧做的事
	void draw(Image*);
	bool isDead();                  //是否已经结束生命
};

