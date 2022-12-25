#include "global.h"
#include <windows.h>
#include <stdio.h>

#include "han.h"

// 조합형 한글 변환 코드 정보
static BYTE aabHanInfo[0xc8-0xb0+1][0xfe-0xa1+1][2];

#define SINGLENUM	51			/* 한글 낱자의 수 */

WORD Single[SINGLENUM] = {	/* 한글 낱자 51자의 조합형 코드 */
	0x8841,0x8c41,0x8444,0x9041,0x8446,0x8447,0x9441,0x9841,
	0x9c41,0x844a,0x844b,0x844c,0x844d,0x844e,0x844f,0x8450,
	0xa041,0xa441,0xa841,0x8454,0xac41,0xb041,0xb441,0xb841,
	0xbc41,0xc041,0xc441,0xc841,0xcc41,0xd041,0x8461,0x8481,
	0x84a1,0x84c1,0x84e1,0x8541,0x8561,0x8581,0x85a1,0x85c1,
	0x85e1,0x8641,0x8661,0x8681,0x86a1,0x86c1,0x86e1,0x8741,
	0x8761,0x8781,0x87a1
};

// 초성 , 중성 , 종성 비트맵 폰트의 각 벌에 따른 기억 장소들
BYTE HF1[8][20][32];
BYTE HF2[4][22][32];
BYTE HF3[4][28][32];
BYTE EF[128][16];


/* 모든 문자를 출력한다. */
void PrintHanList( int x , int y )
{
	BYTE HanBuf[32];
	int indexy = 0;

	for ( int i = 0; i < 8; i++ )
	{
		for ( int j = 1; j < 20; j++ )
		{
			memset( HanBuf , 0 , 32 );
			Font_Operator( HF1[i][j] , HanBuf , 32 , FONT_OR );
			Font_Put( j * 32 , indexy * 32 , HanBuf , 16 , 65535 , 0 );
		}
		indexy += 1;
	}
}

// x , y좌표
// szString은 출력될 문장
// Attr은 글자에 속성을 부여한다.
// Mode_는 현재 입력된 문자가 조합인지 완성인지 구분한다.
void PrintHan( int x , int y , char *szString , BYTE attr , int Mode_, unsigned int color )
{		
	// 초,중,종성의 벌을 계산한다.
	BYTE b1 = 0, b2 = 0, b3 = 0;
	BYTE *pb = (BYTE*)szString;
	BYTE data1 = 0, data2 = 0;
	BYTE HanBuf[32];
	BYTE EngBuf[32];
	BYTE first = 0, mid = 0, last = 0;
	WORD wHan = 0;
	
	int XScreen = 0;
	int LenOfString = 0;
	int yGrid = 0;
	int yOffset = 0;
	int RealX = 0;
	int RealY = 0;
	
	while( *pb != NULL )
	{
		memset( HanBuf , 0 , 32 );
		memset( EngBuf , 0 , 32 );

		// 한글
		if ( *pb & 0x80 )
		{
			XScreen += 16;
			
			// 조합형
			if ( KS_0 == Mode_ )
			{
				data1 = *pb++;
				data2 = *pb++;
				
				//first = (data1 & 0x7c) >> 2;
				//mid = (data1 & 3 ) * 8 + (data2 >> 5 );
				//last = ( data2 & 31 );
				
				wHan = (data1 << 8) | data2;
			}			
			else if ( KS_1 == Mode_ ) // 완성형
			{	
				b1 = (*pb++)-0xb0;
				b2 = (*pb++)-0xa1;

				if (b1 == 0xf4 && b2 < SINGLENUM && b2 >= 0)
					wHan=Single[b2];
				else
					wHan=(aabHanInfo[b1][b2][0]<<8)|(aabHanInfo[b1][b2][1]);
			
			}			
			// 글자 합침
			
			first =  Han_Table[0][(wHan & 0x7c00) >> 10];
			mid   =  Han_Table[1][(wHan & 0x03e0) >>5];
			last  =  Han_Table[2][wHan & 0x001f];
			
			b3 = midtable[0][mid];
			
			if ( !last ) {
				 b2 = fsttable[0][first];
				 b1 = midtable[1][mid];
			} else {
			 b2 = fsttable[1][first];
			 b1 = midtable[2][mid];
			}
						
			if ( first != 0 ) Font_Operator( HF1[b1][first] , HanBuf , 32 , FONT_OR );
			if ( mid != 0 )   Font_Operator( HF2[b2][mid  ] , HanBuf , 32 , FONT_OR );
			if ( last != 0 )  Font_Operator( HF3[b3][last ] , HanBuf , 32 , FONT_OR );
			
			if ( XScreen > 140 ) {
				RealX = 0;
				RealY++;
				XScreen = 0;
			}

			Font_Put( x + RealX , y + (RealY * 16) , HanBuf , 16 , color , 0 );			
			RealX += 16;
		}
		else // 영문 폰트
		{		
			XScreen += 8;
			
			memcpy ( EngBuf , EF[*pb++],16);

			if ( XScreen > 150 ) {
				RealX = 0;
				RealY++;
				XScreen = 0;
			}

			Font_Put( x + RealX , y + (RealY * 16), EngBuf , 8 , color , 0  );
			RealX += 8;
		}
	}	
}

// 글자 길이 만큼만 출력한다.
void PrintHanLen( int x , int y , char *szString , BYTE attr , int Mode_, unsigned int color, unsigned int Len ) {		
	// 초,중,종성의 벌을 계산한다.
	BYTE b1 = 0, b2 = 0, b3 = 0;
	BYTE *pb = (BYTE*)szString;
	BYTE data1 = 0, data2 = 0;
	BYTE HanBuf[32];
	BYTE EngBuf[32];
	BYTE first = 0, mid = 0, last = 0;
	WORD wHan = 0;
	
	int XScreen = 0;
	int LenOfString = 0;
	int yGrid = 0;
	int yOffset = 0;
	int RealX = 0;
	int RealY = 0;
	
	int nLen = 0;
	while( *pb != NULL )
	{
		if ( nLen >= Len ) {
			return;
		}
		
		memset( HanBuf , 0 , 32 );
		memset( EngBuf , 0 , 32 );

		// 한글
		if ( *pb & 0x80 )
		{
			nLen += 2;
			XScreen += 16;
			
			// 조합형
			if ( KS_0 == Mode_ )
			{
				data1 = *pb++;
				data2 = *pb++;
				
				//first = (data1 & 0x7c) >> 2;
				//mid = (data1 & 3 ) * 8 + (data2 >> 5 );
				//last = ( data2 & 31 );
				
				wHan = (data1 << 8) | data2;
			}			
			else if ( KS_1 == Mode_ ) // 완성형
			{	
				b1 = (*pb++)-0xb0;
				b2 = (*pb++)-0xa1;

				if (b1 == 0xf4 && b2 < SINGLENUM && b2 >= 0)
					wHan=Single[b2];
				else
					wHan=(aabHanInfo[b1][b2][0]<<8)|(aabHanInfo[b1][b2][1]);
			
			}			
			// 글자 합침
			
			first =  Han_Table[0][(wHan & 0x7c00) >> 10];
			mid   =  Han_Table[1][(wHan & 0x03e0) >>5];
			last  =  Han_Table[2][wHan & 0x001f];
			
			b3 = midtable[0][mid];
			
			if ( !last ) {
				 b2 = fsttable[0][first];
				 b1 = midtable[1][mid];
			} else {
			 b2 = fsttable[1][first];
			 b1 = midtable[2][mid];
			}
						
			if ( first != 0 ) Font_Operator( HF1[b1][first] , HanBuf , 32 , FONT_OR );
			if ( mid != 0 )   Font_Operator( HF2[b2][mid  ] , HanBuf , 32 , FONT_OR );
			if ( last != 0 )  Font_Operator( HF3[b3][last ] , HanBuf , 32 , FONT_OR );
			
			if ( XScreen > 140 ) {
				RealX = 0;
				RealY++;
				XScreen = 0;
			}

			Font_Put( x + RealX , y + (RealY * 16) , HanBuf , 16 , color , 0 );			
			RealX += 16;
		}
		else // 영문 폰트
		{	
			nLen += 1;
			XScreen += 8;
			
			memcpy ( EngBuf , EF[*pb++],16);

			if ( XScreen > 150 ) {
				RealX = 0;
				RealY++;
				XScreen = 0;
			}

			Font_Put( x + RealX , y + (RealY * 16), EngBuf , 8 , color , 0  );
			RealX += 8;
		}
	}	
}

void PrintHanWithShadow( int x , int y , char *szString , BYTE attr_ , int Mode_, unsigned int color ) {
	PrintHan( x+2,y+1,szString,attr_, Mode_, 0x00000000 );
	PrintHan( x,y,szString,attr_, Mode_, color );
}

// 글자 길이 만큼만 출력한다.
void PrintHanWithShadowLen( int x , int y , char *szString , BYTE attr_ , int Mode_, unsigned int color, unsigned int Len ) {
	PrintHanLen( x+2,y+1,szString,attr_, Mode_, 0x00000000, Len );
	PrintHanLen( x,y,szString,attr_, Mode_, color, Len );
}

// 폰트를 연산한다.
void Font_Operator( BYTE *src , BYTE *dest , int size , BYTE attr_ )
{
	int i = 0;

	for ( i = 0; i < size; i++ )
	{	
		if ( FONT_COPY == attr_ )
		{
			dest[i] = src[i];
		}
		else if ( FONT_OR == attr_ )
		{
			dest[i] |= src[i];
		}
		else if ( FONT_AND == attr_ )
		{
			//dest[i] &= src[i];
		}
		else if ( FONT_XOR == attr_ )
		{
			//dest[i] ^= src[i];
		}
		else if ( FONT_NOT == attr_ )
		{
			//dest[i] = ~src[i];	
		}
	}	
}

// 폰트를 그린다
void Font_Put( int x , int y , BYTE *fnt , int size , unsigned int color , int f ) {
    int i, k, m = 0, n = 0;
    unsigned char dat = 0x80;
		
    for ( i = y; i < y + 16; i++ ) 
	{
		for ( k = x; k < x + size; k++ ) 
		{
			if (( fnt[m]&( dat >> n ))== ( dat >> n )) DrawPlot( k , i , color );
				if (  ( ++n ) == 8 ) 
				{ 
					n = 0; m += 1; 
				}		
 	    }		
    }
}

// 한글 폰트를 읽어 들인다.
bool Read_Han_Font( char *szFile_ )
{
	FILE *fp = NULL;
	fp = fopen( szFile_ , "rb" );	
	if ( NULL == fp ) return false;
	fread( HF1 , 5120 , 1 , fp );
	fread( HF2 , 2816 , 1 , fp );
	fread( HF3 , 3584 , 1 , fp );
	fclose( fp );
	return true;
}

// 영문 폰트를 읽어 들인다.
bool Read_Eng_Font( char *szFile_ )
{
	FILE *fp = NULL;
	fp = fopen( szFile_ , "rb" );
	if ( NULL == fp ) return false;
	fread( EF , 2048 , 1 , fp );
	fclose( fp );
	return true;
}

// 완성형을 조합형에 변환하기 위해서 필요한 테이블을 로드한다.
bool Load_Info( char *szName )
{
	FILE *fp = NULL;
	fp = fopen( szName , "rb" );
	if ( NULL == fp )
	{
		fclose( fp );
		return false;
	}
	else
	{
		fread( aabHanInfo , 4700 , 1 , fp );
	}
	fclose( fp );
	return true;
}

void DrawPlot( int x, int y, unsigned int color_ ) {
	int yofs;
	yofs = (y * (screen->pitch / 3) + x) * 3;	

		/*sb = ((unsigned char*)screen->pixels)[(i*pitch+j)*3];
			sg = ((unsigned char*)screen->pixels)[(i*pitch+j)*3+1];
			sr = ((unsigned char*)screen->pixels)[(i*pitch+j)*3+2];*/
	
	unsigned char r = (color_ & 0x00ff0000) >> 16;
	unsigned char g = (color_ & 0x0000ff00) >> 8;
	unsigned char b = (color_ & 0x000000ff);

	((unsigned char*)screen->pixels)[yofs]	 = r; //color_;
	((unsigned char*)screen->pixels)[yofs+1] = g;
	((unsigned char*)screen->pixels)[yofs+2] = b;
}