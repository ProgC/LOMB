#pragma once
enum MONAI_ACTION		
{
	MA_STAND,				// 한곳에 있다.
	MA_MOVE,				// 오브젝트가 이동중이다.
	MA_ATTACK,				// 적을 때리고 있는상태다.
};

enum MONAI_WAR			
{
	MW_OBSERVATION,		// 관찰모드이다				
	MW_BATTLE,				// 적과 싸우고 있다.
	MW_ESCAPE,				// 위치가 고정된상태이면, 도망을 하지않고 전투만한다.
};


//관찰중에 할수있는거
//이동
//정지,
//패트롤
//홀드
//
//
//
//전투중에 할수있는것
//이동,
//정지,
//공격,
//홀드
//
//도망중에 할수있는것
//이동
//정지
//홀드




enum MONAI_HP			
{
	MHP_LOW_HP,   			// 0      ~ 1/3이하, 
	MHP_MIDDLE_HP,			// 1/3초과~ 3/2이하
	MHP_HIGH_HP,			// 2/3초과~ 3/3이하
};


enum MONAI_MP			
{
	MMP_LOW_MP, 			// 0  ~ 1/3이하, 
	MMP_MIDDLE_MP,			// 1/3~ 3/2
	MMP_HIGH_MP,			// 2/3~ 3/3          
};




enum MONAI_TEAM_BATTLE_POWER	// 적에 비례한 능력치, 팀총공격력, 팀총HP등등
{
	MTP_NOT_KNOW,
	MTP_LOW_CLASS,
	MTP_SAME_CLASS,
	MTP_HIGH_CLASS,
};


enum MONAI_BATTLE_FORMATION
{
	MB_ENVELOPING_ATTACK,			// 포위공격
	MB_INDIVIDUAL_COMBAT,			// 각개전투
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
	MM_MOVE				= 1,	// X, Y		지정된위치로 이동시킨다.
	MM_STOP,					//			오브젝트의 공격, 이동을 멈춘다.
	MM_ATTACK_GROUND,			// X, Y		지정된위치로 가면서 적이 관찰되면 공격한다.
	MM_ATTACK_OBJECT,			// ObjectID	특정오브젝트를 공격한다.
	MM_PATROL,					// X, Y		특정위치를 순찰한다. 순찰을 멈출때에는 STOP, ATTACK, MOVE등으로한다.
	MM_HOLD,					// BOOL		위치를 고정시킨다. STOP으로도 풀수있다.

	MM_PICK_UP_ITEM,			// ITEM_NUMBER	아이템줏기
	MM_USE_ITEM,				// ITEM_NUMBER	아이템사용
	MM_PHYSICAL_ATTACK,			// HP			물리공격받음
	MM_RECOVERY_HP,				// HP			힐링을 받음
	MM_MAGIC_ATTACK,			// MAGIC_ATTRIBUTE, HP	마법공격을 받음
	MM_RECOVERY_MANA,			// MP			마나회복
	MM_RECOVERY_MAGIC,			// MAGIC_ATTRIBUTE 마법이상회복
	MM_WEIGHT,					// ABILITY, INT	가중치 +-,  ATTACK_SPEED등의 총합산또는, 해당ITEM의 가중치
};


