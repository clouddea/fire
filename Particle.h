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
//��
class Particle
{
private:
	int baseX;
	int baseY;
	int x;
	int y;
	int angle;
	int size;                     //�뾶��С
	int maxSize;
	int state;                    //��ǰ״̬
	int life;                     //��������
	int speed;                    //�˶��ٶ�
	Color color;                  //��ǰ��ɫ
	vector<Color> colors;         //������ɫ
public:
	Particle(int baseX, int baseY, int maxLife = 30);
	~Particle();
	void run();                     //ÿ֡������
	void draw(Image*);
	bool isDead();                  //�Ƿ��Ѿ���������
};

