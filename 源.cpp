#include <graphics.h>
#include "Particle.h"
#include "Emitter.h"
const int width = 640;
const int height = 480;
const int flushGap = 50;
const Color backcolor = 0x000000;
const int emitterGap = 20;
const int emitterAmount = 33;
const int yPostion = 500;
int main() 
{
	initgraph(width, height, 0);
	Emitter emitters[emitterAmount];
	for (int i = 0; i < emitterAmount; i++)
	{
		emitters[i].setBase(i * emitterGap, yPostion);
	}
	while (true) 
	{
		BeginBatchDraw();
		/***********************/
		setfillcolor(backcolor);
		fillrectangle(0, 0, width, height);

		for (int i = 0; i < emitterAmount; i++)
		{
			emitters[i].run();
		}

		/***********************/
		EndBatchDraw();
		Sleep(flushGap);
	}
}