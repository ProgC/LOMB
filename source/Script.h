// Script.h: interface for the CScript class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCRIPT_H__56B361DD_511E_48C9_879D_9E68A7C5D1C8__INCLUDED_)
#define AFX_SCRIPT_H__56B361DD_511E_48C9_879D_9E68A7C5D1C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum SCRIPT_STATE {
	SCRIPT_END,
	CONTINUE,
	WAIT_KEYBOARD,
	WAIT_MOUSE,
	WAIT_END,
};

enum SCRIPT_COMMAND {
	SC_EMPTY,
	SC_PRINT,
	SC_NARRATION,
	SC_SHOW,
};

#include <map>
#include <string>
using namespace std;

class CScript {
public:

public:
	CScript();
	virtual ~CScript();
	void Release();
	
	SCRIPT_COMMAND GetCurCommand() const {
		return CurrentCommand;
	}
	void NextWord() {
		nCurNarrationLen++;
		if ( nCurNarrationLen > nMaxNarrationLen ) 
			nCurNarrationLen = nMaxNarrationLen;
	}
	bool IsEndNarration() {
		//if ( nCurNarrationLen == nMaxNarrationLen ) return true;
		//return false;
		return true;		
	}
	void ReadFunc();
public:
	SCRIPT_STATE CurrentState;
	SCRIPT_COMMAND CurrentCommand;

	FILE *fp;
	char Buffer[1024];
	char TextBuffer[1024];
	int	 nCurNarrationLen;
	int  nMaxNarrationLen;
	void Init();
	bool LoadVariable( char* filename );
	bool LoadScript( char* filename );
	SCRIPT_STATE Step();
	void NextElse();
	void GotoLabel( char* label );
	
	map<string,int> mapVariable;

	bool bBitmapImage;
	CAnimationFrame BitmapImage;
};

#endif // !defined(AFX_SCRIPT_H__56B361DD_511E_48C9_879D_9E68A7C5D1C8__INCLUDED_)
