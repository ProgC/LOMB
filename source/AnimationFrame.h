// AnimationFrame.h: interface for the CAnimationFrame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANIMATIONFRAME_H__DD6A0E57_8449_4DC0_8F81_A2EF1D5DF9C3__INCLUDED_)
#define AFX_ANIMATIONFRAME_H__DD6A0E57_8449_4DC0_8F81_A2EF1D5DF9C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Sprite를 가진다.
#pragma warning ( disable : 4786 ) 

#include <vector>
#include <string>
using namespace std;

typedef struct tagFrameData {
	string strImage;
	int frame;
} s_FrameData;

class CAnimationFrame {
public:
	CAnimationFrame();
	virtual ~CAnimationFrame();

public:
	bool AddFrame( string spriteName, int frame );
	
	void NextAni();
	void DrawAni( int x, int y );
	void DrawAni( int x, int y, int width, int height );
	void DrawAniWithoutOrigin( int x, int y );
	void ResetAni();

	bool GetEnd() const {
		return bEnd;
	}
	void SetLoop( bool bloop_ ) {
		bLoop = bloop_;
	}
	void Release() {
		nCurFrame = 0;
		nMaxFrame = 0;
		nTickFrame = 0;
		bEnd	  = false;
		vecFrame.clear();
	}
public:
	int nMaxFrame;
	int nCurFrame;
	int nTickFrame;
	bool bLoop;

	bool bEnd;
	
	// Sprite이미지
	vector<s_FrameData> vecFrame;
};

#endif // !defined(AFX_ANIMATIONFRAME_H__DD6A0E57_8449_4DC0_8F81_A2EF1D5DF9C3__INCLUDED_)
