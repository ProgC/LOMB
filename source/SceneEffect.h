// SceneEffect.h: interface for the CSceneEffect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENEEFFECT_H__FDEA5748_7A80_4ACE_A7D9_81C0D152C0B1__INCLUDED_)
#define AFX_SCENEEFFECT_H__FDEA5748_7A80_4ACE_A7D9_81C0D152C0B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSceneEffect {
public:
	static enum EFFECT_TYPE { FADEIN, FADEOUT, FADEOUT_GRAY, FADEOUT_WHITE, FADEIN_WHITE };

public:
	CSceneEffect();
	virtual ~CSceneEffect();
	
	void SetFadeIn();
	void SetFadeOut();
	void SetFadeOutGray();

	void SetFadeInWhite();
	void SetFadeOutWhite();
	void Update();
	void Render();
	bool GetEnd() const {
		if ( bStart == false ) return true;
		return false;
	}
public:
	bool bStart;
	EFFECT_TYPE Type;
	float	fValue;
};

#endif // !defined(AFX_SCENEEFFECT_H__FDEA5748_7A80_4ACE_A7D9_81C0D152C0B1__INCLUDED_)
