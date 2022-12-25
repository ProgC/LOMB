#ifndef __GAME_HAN_FONT_HEADER__
#define __GAME_HAN_FONT_HEADER__


#define KS_0 0 // ������
#define KS_1 1 // �ϼ���

#define FONT_COPY 0
#define FONT_OR   1
#define FONT_AND  2
#define FONT_XOR  3
#define FONT_NOT  4

typedef unsigned char BYTE;


const BYTE Han_Table[3][32]= {
      { 0, 0, 1, 2, 3, 4, 5, 6,
	    7, 8, 9,10,11,12,13,14,
	    15,16,17,18,19, 0, 0, 0,
	    0, 0, 0, 0, 0, 0, 0, 0 },

      { 0, 0, 0, 1, 2, 3, 4, 5,
	    0, 0, 6, 7, 8, 9,10,11,
		0, 0,12,13,14,15,16,17,
		0, 0,18,19,20,21, 0, 0 },

	  { 0, 0, 1, 2, 3, 4, 5, 6,
		7, 8, 9,10,11,12,13,14,
		15,16, 0,17,18,19,20,21,
		22,23,24,25,26,27, 0, 0 }};

const BYTE fsttable[2][20]=	{ 
      { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },

	  { 0, 2, 3, 3, 3, 3, 3, 3, 3, 3,
	    3, 3, 3, 3, 3, 3, 2, 3, 3, 3 } 
      };

const BYTE midtable[3][22]= { 
      { 0, 0, 2, 0, 2, 1, 2, 1, 2, 3, 0,
	    2, 1, 3, 3, 1, 2, 1, 3, 3, 1, 1 },

	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
	    3, 3, 1, 2, 4, 4, 4, 2, 1, 3, 0  },

	  { 0, 5, 5, 5, 5, 5, 5, 5, 5, 6, 7,
	    7, 7, 6, 6, 7, 7, 7, 6, 6, 7, 5 } 
      };


// �ʼ� , �߼� , ���� ��Ʈ�� ��Ʈ�� �� ���� ���� ��� ��ҵ�
extern BYTE HF1[8][20][32];
extern BYTE HF2[4][22][32];
extern BYTE HF3[4][28][32];

// ���� ��Ʈ
extern BYTE EF[128][16];

/* ��� ���ڸ� ����Ѵ�. */
void PrintHanList( int x , int y );

// �ѱ��� ���
extern void PrintHan( int x , int y , char *szString , BYTE attr_ , int Mode_, unsigned int color );
extern void PrintHanWithShadow( int x , int y , char *szString , BYTE attr_ , int Mode_ , unsigned int color );
extern void PrintHanLen( int x , int y , char *szString , BYTE attr_ , int Mode_, unsigned int color, unsigned int len );
extern void PrintHanWithShadowLen( int x , int y , char *szString , BYTE attr_ , int Mode_ , unsigned int color, unsigned int len );
void Font_Operator( BYTE *src , BYTE *dest , int size , BYTE attr_ );
void Font_Put( int x , int y , BYTE *fnt , int size , unsigned int color , int f );

// �����͸� �д� �κ�
bool Read_Han_Font( char *szFile_ ); // �ѱ� ��Ʈ�� �о� ���δ�.
bool Read_Eng_Font( char *szFile_ ); // ���� ��Ʈ�� �о� ���δ�.
bool Load_Info( char *szName ); // �ϼ����� ���������� �ٲܼ� �ְ� �ϴ� ���̺��� �ε��Ѵ�.

// ��Ʈ�� �����Ѵ�.
//void or_img( BYTE *src, BYTE *dest, int size );
//void put_font( int x, int y, BYTE *fnt, int size, int color, int f );

extern void DrawPlot( int x, int y, unsigned int color_ );



#endif