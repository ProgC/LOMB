// MobData.h: interface for the CMobData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOBDATA_H__5C42A59B_2BEB_4BEC_B427_E106F79F6482__INCLUDED_)
#define AFX_MOBDATA_H__5C42A59B_2BEB_4BEC_B427_E106F79F6482__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using namespace std;

typedef struct tagMobData {
	int nID;
	char Name[128];
	char Desc[128];
	int Energy;
	int DropItem[3];
} s_MobData;

// 몹 데이터 베이스
class CMobData {
public:
	CMobData();
	virtual ~CMobData();

	bool LoadDB( const char* filename );

	const s_MobData* GetMobData( int index ) {
		return vecMobData[index];
	}
private:
	vector<s_MobData*> vecMobData;
};

#endif // !defined(AFX_MOBDATA_H__5C42A59B_2BEB_4BEC_B427_E106F79F6482__INCLUDED_)
