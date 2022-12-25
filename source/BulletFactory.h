// BulletFactory.h: interface for the CBulletFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BULLETFACTORY_H__329D7016_8EE5_4314_BE5E_AFF40A939BB7__INCLUDED_)
#define AFX_BULLETFACTORY_H__329D7016_8EE5_4314_BE5E_AFF40A939BB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBullet;

class CBulletFactory {
public:

public:
	CBulletFactory();
	virtual ~CBulletFactory();

	CBullet* MakeBullet( int BulletType );
	

};

#endif // !defined(AFX_BULLETFACTORY_H__329D7016_8EE5_4314_BE5E_AFF40A939BB7__INCLUDED_)
