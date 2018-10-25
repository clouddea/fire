#include <graphics.h>
#include "Particle.h"
#include "Emitter.h"
const int width = 640;
const int height = 480;
const int flushGap = 50;
const Color backcolor = 0x000000;
const Color forecolor = 0xffffff;
const int emitterGap = 20;
const int emitterAmount = 33;
const int yPostion = 500;
int main() 
{
	initgraph(width, height, 0);
	Emitter emit;
	emit.setBase(320, 350);
	while (true) 
	{
		BeginBatchDraw();
		/***********************/
		setfillcolor(backcolor);
		fillrectangle(0, 0, width, height);

		setfillcolor(forecolor);
		fillrectangle(290, 350, 350, 480);
		emit.run();
		/***********************/
		EndBatchDraw();
		Sleep(flushGap);
	}
}