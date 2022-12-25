// BulletFactory.cpp: implementation of the CBulletFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "Bullet.h"
#include "BulletFactory.h"
#include "Bullet_Amber.h"
#include "Bullet_Pink_Pig.h"
#include "Bullet_MagicBall.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBulletFactory::CBulletFactory() {

}

CBulletFactory::~CBulletFactory() {

}

CBullet* CBulletFactory::MakeBullet( int BulletType ) {
	switch ( BulletType ) {
		case CBullet::AMBER_BULLET:
			return new CBullet_Amber();
		break;

		case CBullet::PINK_PIG_BULLET:
			return new CBullet_Pink_Pig();
		break;

		case CBullet::KAIL_MAGIC_BALL:
			return new CBullet_MagicBall();
		break;
	}
	return NULL;
}