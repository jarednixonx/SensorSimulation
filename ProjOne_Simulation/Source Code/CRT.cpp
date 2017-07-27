#include "CRT.h"

CRT::CRT(Display* tempDisplay)
{
	setDisplayType(tempDisplay->getDisplayType());
	setDisplayCountID(tempDisplay->getDisplayCountID());
	setDisplayID(tempDisplay->getDisplayID());
}

CRT::~CRT()
{

}
