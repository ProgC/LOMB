// Stage.cpp: implementation of the CStage class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Stage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStage::CStage()
{

}

CStage::~CStage()
{

}

void CStage::Load(const char* filename) {
	// 스테이지 데이터에 nX, nY인덱스가 저장되어 있다. 지금은 무조건 0,0
	nXIndex = 0;
	nYIndex = 0;

	FILE *fp = NULL;
	fp = fopen( filename, "rb" );
	if ( fp == NULL ) return;
	
	fread( &nStartX, 1, sizeof(int), fp );
	fread( &nStartY, 1, sizeof(int), fp );
	fread( &nEndX, 1, sizeof(int), fp );
	fread( &nEndY, 1, sizeof(int), fp );

	nXIndex = nStartX / 160;
	nYIndex = nStartY / 160;

	for ( int y = 0; y < 5; y++ ) {
		for ( int x = 0; x < 5; x++ ) {
			// 맵 데이터 읽기
			m_Stage[y][x].LoadMap(fp);
		}
	}
	if ( fp ) fclose( fp );
}

void CStage::Update() {
	// 맵 이벤트 처리	
	const IEntity* pChar = g_Game.GetPlayer();
	if ( pChar ) {
		const int X = pChar->GetScreenX( nXIndex ) / (int)16;
		const int Y = pChar->GetScreenY( nYIndex ) / (int)16;
		
		// 갈 수 없는 곳이라면
		if ( m_Stage[nYIndex][nXIndex].m_Map[Y][X].nEventProperty != 0 ) {
			// process event
			m_Stage[nYIndex][nXIndex].Process( m_Stage[nYIndex][nXIndex].m_Map[Y][X].nEventProperty );
		}
	}
}

void CStage::Render() {
	m_Stage[nYIndex][nXIndex].Render();
}

void CStage::Collision( IEntity* pChar ) {
	
}

bool CStage::IsBlock( IEntity* pChar ) {
	int X = pChar->GetScreenX( nXIndex ) / (int)16;
	int Y = pChar->GetScreenY( nYIndex ) / (int)16;
	
	// 갈 수 없는 곳이라면
	if ( m_Stage[nYIndex][nXIndex].m_Map[Y][X].nCollision == 0 ) {
		return true;
	}
	
	return false;
}

bool CStage::IsOutOfScreen( IEntity* pChar ) {
	// 화면 바깥
	int X = pChar->GetScreenX( nXIndex );
	int Y = pChar->GetScreenY( nYIndex );

	int nR = pChar->GetRadForCollision();

	if ( X - nR < 0 ) return true;
	if ( X + nR > 160 ) return true;		
	if ( Y - nR < 0 ) return true;
	if ( Y + nR > 160 ) return true;

	return false;
}

bool CStage::IsScrollArea( IEntity* pChar ) {
	int X = pChar->GetScreenX( nXIndex );// / (int)16;
	int Y = pChar->GetScreenY( nYIndex );// / (int)16;
	
	if ( X < 5 ) {
		if ( ScrollLeft() ) {
			pChar->SetWorldX( nXIndex * 160 + 150 );
		}
		return true;
	}

	if ( Y < 5 ) {
		if ( ScrollUp() ) {
			pChar->SetWorldY( nYIndex * 160 + 150 );
		}
		return true;
	}
	if ( X >= 155 ) {
		if ( ScrollRight() ) {
			pChar->SetWorldX( nXIndex * 160 + 10 );
		}
		return true;
	}
	if ( Y >= 155 ) {
		if ( ScrollDown() ) {
			pChar->SetWorldY( nYIndex * 160 + 10 );
		}
		return true;
	}
	
	return false;
}

bool CStage::ScrollUp() {
	nYIndex--;
	if ( nYIndex < 0 ) {
		nYIndex = 0;
		return false;
	}
	return true;
}

bool CStage::ScrollLeft() {
	nXIndex--;
	if ( nXIndex < 0 ) {
		nXIndex = 0;
		return false;
	}
	return true;
}

bool CStage::ScrollRight() {
	nXIndex++;
	if ( nXIndex >= 5 ) {
		nXIndex = 4;
		return false;
	}
	return true;
}

bool CStage::ScrollDown() {
	nYIndex++;
	if ( nYIndex >= 5 ) {
		nYIndex = 4;	
		return false;
	}
	return true;
}


