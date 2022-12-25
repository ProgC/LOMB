// SceneEffect.cpp: implementation of the CSceneEffect class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "SceneEffect.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSceneEffect::CSceneEffect() {
	bStart = false;
	fValue = 1;
}

CSceneEffect::~CSceneEffect() {

}

void CSceneEffect::SetFadeIn() {
	fValue = 0;
	Type = FADEIN;
	bStart = true;
}

void CSceneEffect::SetFadeOut() {
	fValue = 1;
	Type = FADEOUT;
	bStart = true;
}

void CSceneEffect::SetFadeOutGray() {
	fValue = 1;
	Type = FADEOUT_GRAY;
	bStart = true;
}

void CSceneEffect::SetFadeInWhite() {
	fValue = 0;
	Type = FADEIN_WHITE;
	bStart = true;
}

void CSceneEffect::SetFadeOutWhite() {
	fValue = 1;
	Type = FADEOUT_WHITE;
	bStart = true;
}

void CSceneEffect::Update() {
	if ( bStart ) {
		if ( Type == FADEIN ) {
			fValue += 0.01f;
			if ( fValue > 1 ) {
				fValue = 1;
				bStart = false;
			}
		} else if ( Type == FADEOUT ) {
			fValue -= 0.01f;
			if ( fValue < 0 ) {
				fValue = 0;
				bStart = false;
			}
		} else if ( Type == FADEOUT_GRAY ) {
			fValue -= 0.01f;
			if ( fValue < 0 ) {
				fValue = 0;
				bStart = false;
			}
		} else if ( Type == FADEIN_WHITE ) {
			fValue += 0.01f;
			if ( fValue > 1 ) {
				fValue = 1;
				bStart = false;
			}
		} else if ( Type == FADEOUT_WHITE ) {
			fValue -= 0.01f;
			if ( fValue < 0 ) {
				fValue = 0;
				bStart = false;
			}
		}
	}
}

void CSceneEffect::Render() {
	int i, j;
	unsigned int sr;
	unsigned int sg;
	unsigned int sb;
	
	unsigned int dr;
	unsigned int dg;
	unsigned int db;
	
	int pitch = screen->pitch / 3;
	
	for (i = 0; i < SCREEN_HEIGHT; i++) {
		for (j = 0; j < SCREEN_WIDTH; j++) {
			sb = ((unsigned char*)screen->pixels)[(i*pitch+j)*3];
			sg = ((unsigned char*)screen->pixels)[(i*pitch+j)*3+1];
			sr = ((unsigned char*)screen->pixels)[(i*pitch+j)*3+2];
			
			db = 0;
			dg = 0;
			dr = 0;
			
			if ( Type == FADEIN || Type == FADEOUT ) {
			//置曽事 := (( 事1 * alpha) + ( 事2 * (255-alpha))) div 255;				
				((unsigned char*)screen->pixels)[(i*pitch+j)*3] = sb * fValue + db * (1-fValue);
				((unsigned char*)screen->pixels)[(i*pitch+j)*3+1] = sg * fValue + dg * (1-fValue);
				((unsigned char*)screen->pixels)[(i*pitch+j)*3+2] = sr * fValue + dr * (1-fValue);
			} else if ( Type == FADEOUT_GRAY ) {
				((unsigned char*)screen->pixels)[(i*pitch+j)*3] = sb * fValue + ((sb+sg+sr)/3) * (1-fValue);
				((unsigned char*)screen->pixels)[(i*pitch+j)*3+1] = sg * fValue + ((sb+sg+sr)/3) * (1-fValue);
				((unsigned char*)screen->pixels)[(i*pitch+j)*3+2] = sr * fValue + ((sb+sg+sr)/3) * (1-fValue);				
			} else if ( Type == FADEIN_WHITE || Type == FADEOUT_WHITE ) {
				((unsigned char*)screen->pixels)[(i*pitch+j)*3] = sb * fValue + 255 * (1-fValue);
				((unsigned char*)screen->pixels)[(i*pitch+j)*3+1] = sg * fValue + 255 * (1-fValue);
				((unsigned char*)screen->pixels)[(i*pitch+j)*3+2] = sr * fValue + 255 * (1-fValue);
			}
		}		
	}
}

