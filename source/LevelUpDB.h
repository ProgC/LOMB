// LevelUpDB.h: interface for the LevelUpDB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEVELUPDB_H__C49F5B05_F504_4BD6_B361_D8CFC8B7AE32__INCLUDED_)
#define AFX_LEVELUPDB_H__C49F5B05_F504_4BD6_B361_D8CFC8B7AE32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct LevelData {
	int MaxHP;
	int MaxMP;
	int MaxSpeed;
	int Exp;
} s_LevelData;

class LevelUpDB {
public:
	LevelUpDB();
	virtual ~LevelUpDB();

	s_LevelData Data[60];
};

#endif // !defined(AFX_LEVELUPDB_H__C49F5B05_F504_4BD6_B361_D8CFC8B7AE32__INCLUDED_)
