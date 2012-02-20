/////////////////////////////////////////////////////////////////////////////////////////////////
//				class CInput qui se charge d'initialiser l'input						       //
//				et de g�rer ses messages...										               //
//					2003	Jibe DUSSEAUT													   //
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
/////////////////////////////////////////////////////////////////
// INCLUDE
/////////////////////////////////////////////////////////////////


#include "../ressources.h"

/////////////////////////////////////////////////////////////////
// MACRO DE TEST 
/////////////////////////////////////////////////////////////////

#define KEYDOWN(name, key)(name[key]&0x80)

typedef void fonction(void);


struct keyToFunc {
	BYTE key;
	fonction* func;
};



/////////////////////////////////////////////////////////////////
// DECLARAtION DE LA CLASSE
/////////////////////////////////////////////////////////////////

class CInput
{
private:
	keyToFunc* _dinAssign;
	char _buffer[256];
	LPDIRECTINPUT8 _diObject;
	LPDIRECTINPUTDEVICE8 _keyboard;
	LPDIRECTINPUTDEVICE8 _mouse;


public:
	CInput(void);
	HRESULT initDInput();
	void setFunc(BYTE key,  fonction * func);
	void getInput();
	void clearDInput();

	~CInput(void);
};
