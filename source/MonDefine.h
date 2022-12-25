#pragma once
enum MONAI_ACTION		
{
	MA_STAND,				// �Ѱ��� �ִ�.
	MA_MOVE,				// ������Ʈ�� �̵����̴�.
	MA_ATTACK,				// ���� ������ �ִ»��´�.
};

enum MONAI_WAR			
{
	MW_OBSERVATION,		// ��������̴�				
	MW_BATTLE,				// ���� �ο�� �ִ�.
	MW_ESCAPE,				// ��ġ�� �����Ȼ����̸�, ������ �����ʰ� �������Ѵ�.
};


//�����߿� �Ҽ��ִ°�
//�̵�
//����,
//��Ʈ��
//Ȧ��
//
//
//
//�����߿� �Ҽ��ִ°�
//�̵�,
//����,
//����,
//Ȧ��
//
//�����߿� �Ҽ��ִ°�
//�̵�
//����
//Ȧ��




enum MONAI_HP			
{
	MHP_LOW_HP,   			// 0      ~ 1/3����, 
	MHP_MIDDLE_HP,			// 1/3�ʰ�~ 3/2����
	MHP_HIGH_HP,			// 2/3�ʰ�~ 3/3����
};


enum MONAI_MP			
{
	MMP_LOW_MP, 			// 0  ~ 1/3����, 
	MMP_MIDDLE_MP,			// 1/3~ 3/2
	MMP_HIGH_MP,			// 2/3~ 3/3          
};




enum MONAI_TEAM_BATTLE_POWER	// ���� ����� �ɷ�ġ, ���Ѱ��ݷ�, ����HP���
{
	MTP_NOT_KNOW,
	MTP_LOW_CLASS,
	MTP_SAME_CLASS,
	MTP_HIGH_CLASS,
};


enum MONAI_BATTLE_FORMATION
{
	MB_ENVELOPING_ATTACK,			// ��������
	MB_INDIVIDUAL_COMBAT,			// ��������
};


enum MONAI_ABILITY
{
	MA_ATTACK_SPEED,
	MA_ATTACK_POWER,
	MA_MOVE_SPEED,
	MA_DEFENSIVE_POWER,
	MA_HP,
	MA_MP,
};



enum MONAI_MAGIC_ATTRIBUTE
{
	MMA_POISON,
	MMA_FIRE,
	MMA_WATER,
	MMA_LIGHTNING,
};



enum MONAI_MESSAGE
{
	MM_MOVE				= 1,	// X, Y		��������ġ�� �̵���Ų��.
	MM_STOP,					//			������Ʈ�� ����, �̵��� �����.
	MM_ATTACK_GROUND,			// X, Y		��������ġ�� ���鼭 ���� �����Ǹ� �����Ѵ�.
	MM_ATTACK_OBJECT,			// ObjectID	Ư��������Ʈ�� �����Ѵ�.
	MM_PATROL,					// X, Y		Ư����ġ�� �����Ѵ�. ������ ���⶧���� STOP, ATTACK, MOVE�������Ѵ�.
	MM_HOLD,					// BOOL		��ġ�� ������Ų��. STOP���ε� Ǯ���ִ�.

	MM_PICK_UP_ITEM,			// ITEM_NUMBER	�������ޱ�
	MM_USE_ITEM,				// ITEM_NUMBER	�����ۻ��
	MM_PHYSICAL_ATTACK,			// HP			�������ݹ���
	MM_RECOVERY_HP,				// HP			������ ����
	MM_MAGIC_ATTACK,			// MAGIC_ATTRIBUTE, HP	���������� ����
	MM_RECOVERY_MANA,			// MP			����ȸ��
	MM_RECOVERY_MAGIC,			// MAGIC_ATTRIBUTE �����̻�ȸ��
	MM_WEIGHT,					// ABILITY, INT	����ġ +-,  ATTACK_SPEED���� ���ջ�Ǵ�, �ش�ITEM�� ����ġ
};


