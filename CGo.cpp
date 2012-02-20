#include "cgo.h"

CGo::CGo(void)
{
	_pos.x = 0;
	_pos.y = 0;
}

void CGo::setPos(POINT newPos){
	tilePlotter(newPos);
}

CGo::~CGo(void)
{
}

void CGo::tilePlotter(POINT pos) {
	_pos.x = TILEWIDTH * pos.x;
	_pos.y = TILEHEIGHT * pos.y;
}