// CreticalSection.h: interface for the CCreticalSection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CRETICALSECTION_H__63B15274_DEB5_4F75_A940_6D2382F587CF__INCLUDED_)
#define AFX_CRETICALSECTION_H__63B15274_DEB5_4F75_A940_6D2382F587CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <process.h>

class CCreticalSection {
public:
	CCreticalSection();
	virtual ~CCreticalSection();

	void Lock();
	void UnLock();
public:
	CRITICAL_SECTION cs;

};

#endif // !defined(AFX_CRETICALSECTION_H__63B15274_DEB5_4F75_A940_6D2382F587CF__INCLUDED_)
