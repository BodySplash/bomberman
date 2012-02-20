#include "fonction.h"

CFonction::CFonction(void)
{
	_key = NULL;
	_fonc = NULL;
}

bool CFonction::isAssociate(BYTE key)
{
	keyTree *temp;
	temp = _key;
	for(;;) {
		if (temp->key == key)
			return true;
		temp = temp->next;
		if (!temp)
			break;
	}
	return false;	
}

CFonction::~CFonction(void)
{

}
