#include "Input.h"

CInput::CInput(void)
{
}

HRESULT CInput::initDInput() {
	HRESULT hr;
	if (FAILED(hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&_diObject, NULL)))
		return hr;
	// initialisation du clavier
	 _diObject->CreateDevice(GUID_SysKeyboard, &_keyboard, NULL);
	 _keyboard->SetCooperativeLevel(mainHwnd, DISCL_FOREGROUND|DISCL_NONEXCLUSIVE);
	 _keyboard->SetDataFormat(&c_dfDIKeyboard);
	 _keyboard->Acquire();
	

	// initialisation de la souris
	_diObject->CreateDevice(GUID_SysMouse, &_mouse, NULL);
	_mouse->SetCooperativeLevel(mainHwnd, DISCL_FOREGROUND|DISCL_NONEXCLUSIVE);
	_mouse->SetDataFormat(&c_dfDIMouse);
	_mouse->Acquire();
	_dinAssign = new keyToFunc[1];

}

void CInput::getInput() {
	_keyboard->GetDeviceState(sizeof(_buffer), (LPVOID)&_buffer);
	if (KEYDOWN(_buffer, DIK_ESCAPE)) {
		_dinAssign[0].func();
	}
}

void CInput::setFunc(BYTE key, fonction * func) {
	_dinAssign[0].func = func;
	_dinAssign[0].key = key;
}

void CInput::clearDInput(){
	if (_dinAssign) {
		delete[] _dinAssign;
		_dinAssign = NULL;
	}
	if (_keyboard){
	_keyboard->Unacquire();
	_keyboard->Release();
	_keyboard = NULL;
	}
	if (_mouse) {
	_mouse->Unacquire();	
	_mouse->Release();
	_mouse = NULL;
	}
	if (_diObject){
	_diObject->Release();
	_diObject = NULL;
	}
}




CInput::~CInput(void)
{
	clearDInput();
}
