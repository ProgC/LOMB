// CreticalSection.cpp: implementation of the CCreticalSection class.
//
//////////////////////////////////////////////////////////////////////

#include "CreticalSection.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCreticalSection::CCreticalSection() {
	InitializeCriticalSection( &cs );
}

CCreticalSection::~CCreticalSection() {
	DeleteCriticalSection( &cs );
}

void CCreticalSection::Lock() {
	EnterCriticalSection( &cs );
}

void CCreticalSection::UnLock() {
	LeaveCriticalSection( &cs );
}
