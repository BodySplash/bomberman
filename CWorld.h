#pragma once
#include "Crenderer.h"
#include "ressources.h"
#include "input/Input.h"




class CWorld :
	public CRenderer
{
private:
	CInput input;
public:
	CWorld( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nShowCmd);
	~CWorld(void);
	void gameLoop();
};
