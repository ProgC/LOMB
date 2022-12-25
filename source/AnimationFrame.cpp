// AnimationFrame.cpp: implementation of the CAnimationFrame class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "AnimationFrame.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAnimationFrame::CAnimationFrame() {
	Release();
}

CAnimationFrame::~CAnimationFrame() {

}

bool CAnimationFrame::AddFrame( string spriteName, int frame ) {
	s_FrameData sframe;
	sframe.strImage = spriteName;
	sframe.frame = frame;
		
	vecFrame.push_back( sframe );
	return true;
}
	
void CAnimationFrame::NextAni() {	
	if ( bEnd == false ) {
		nTickFrame++;
		
		if ( nTickFrame > vecFrame[nCurFrame].frame ) {
			nCurFrame++;
			nTickFrame = 0;
			
			if ( nCurFrame >= nMaxFrame ) {
				if ( bLoop ) {
					bEnd = false;
					nCurFrame = 0;
				} else {
					nCurFrame--;
					bEnd = true;				
				}
			}
		}
	}
}

void CAnimationFrame::DrawAni( int x, int y ) {
	// 현재 프레임의 스프라이트를 그린다.
	SDL_Rect offset;
    
	//Give the offsets to the rectangle
	offset.x = x - g_SpritePack.vecImageMap[vecFrame[nCurFrame].strImage]->oX;
	offset.y = y - g_SpritePack.vecImageMap[vecFrame[nCurFrame].strImage]->oY;

	//Blit the surface
	SDL_BlitSurface( g_SpritePack.vecImageMap[vecFrame[nCurFrame].strImage]->surface, NULL, screen, &offset );
}

void CAnimationFrame::DrawAni( int x, int y, int width, int height ) {
	// 현재 프레임의 스프라이트를 그린다.
	SDL_Rect offset;
	SDL_Rect ImageMid;
    
	//Give the offsets to the rectangle
	offset.x = x - g_SpritePack.vecImageMap[vecFrame[nCurFrame].strImage]->oX;
	offset.y = y - g_SpritePack.vecImageMap[vecFrame[nCurFrame].strImage]->oY;
	offset.w = width;
	offset.h = height;

	ImageMid.x = 0;
	ImageMid.y = 0;
	ImageMid.w = width;
	ImageMid.h = height;
	
	SDL_BlitSurface( g_SpritePack.vecImageMap[vecFrame[nCurFrame].strImage]->surface, &ImageMid, screen, &offset );
}

void CAnimationFrame::DrawAniWithoutOrigin( int x, int y ) {
	// 현재 프레임의 스프라이트를 그린다.
	SDL_Rect offset;
    
	//Give the offsets to the rectangle
	offset.x = x;
	offset.y = y;
	
	//Blit the surface
	SDL_BlitSurface( g_SpritePack.vecImageMap[vecFrame[nCurFrame].strImage]->surface, NULL, screen, &offset );
}

void CAnimationFrame::ResetAni() {
	bEnd = false;
	nTickFrame = 0;
	nCurFrame = 0;
}

