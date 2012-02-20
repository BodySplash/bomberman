#pragma once


#include "ressources.h"
#include "TileSet.h"

class CGo
{
protected:
	vertexCoord _pos;
	BYTE _type;
	void tilePlotter(POINT pos);

public:
	CGo(void);
	void setPos(POINT newPos);
	void setType(BYTE type){_type = type;}
	BYTE getType(){return _type;}
	
	~CGo(void);
};
