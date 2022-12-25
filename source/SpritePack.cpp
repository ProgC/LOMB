// SpritePack.cpp: implementation of the CSpritePack class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "SpritePack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SDL_Surface *load_image( std::string filename ) {
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );
    
    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    return optimizedImage;
}

CSpritePack::CSpritePack()
{

}

CSpritePack::~CSpritePack() {
	/*int nCountOfSprite = vecImage.size();
	for ( int i = 0; i < nCountOfSprite; i++ ) {
		SDL_FreeSurface( vecImage[i] );
	}
	vecImage.clear();*/
}

bool CSpritePack::LoadImage() {
	// ¸Ê µ¥ÀÌÅÍ ÀÐ±â
	char szBuff[128];
	for ( int i = 0; i < 126; i++ ) {
		sprintf( szBuff, "map/%d.bmp" , i+1 );
		LoadImage( szBuff );
	}

	// Ä«ÀÏ °È±â ºÏ
	LoadImage( "char/zelda_walk_north_1.bmp", 8, 16 );
	LoadImage( "char/zelda_walk_north_2.bmp", 8, 16 );

	// Ä«ÀÏ °È±â ³²
	LoadImage( "char/zelda_walk_south_1.bmp", 8, 16 );
	LoadImage( "char/zelda_walk_south_2.bmp", 8, 16 );

	// Ä«ÀÏ °È±â µ¿
	LoadImage( "char/zelda_walk_east_1.bmp", 8, 16 );
	LoadImage( "char/zelda_walk_east_2.bmp", 8, 16 );
		             	
	// Ä«ÀÏ °È±â ¼­
	LoadImage( "char/zelda_walk_west_1.bmp", 8, 16 );
	LoadImage( "char/zelda_walk_west_2.bmp", 8, 16 );

	// Ä«ÀÏ °ø°Ý µ¿
	LoadImage( "char/zelda_attack_east_1.bmp", 9, 32 );
	LoadImage( "char/zelda_attack_east_2.bmp", 8, 28 );
	LoadImage( "char/zelda_attack_east_3.bmp", 8, 16 );

	// Ä«ÀÏ °ø°Ý ¼­
	LoadImage( "char/zelda_attack_west_1.bmp", 8 , 32 );
	LoadImage( "char/zelda_attack_west_2.bmp", 21, 29 );
	LoadImage( "char/zelda_attack_west_3.bmp", 23, 16 );

	// Ä«ÀÏ °ø°Ý ³²
	LoadImage( "char/zelda_attack_south_1.bmp", 23, 16 );
	LoadImage( "char/zelda_attack_south_2.bmp", 20, 14 );
	LoadImage( "char/zelda_attack_south_3.bmp", 8, 15 );

	// Ä«ÀÏ °ø°Ý ºÏ
	LoadImage( "char/zelda_attack_north_1.bmp", 6, 15);
	LoadImage( "char/zelda_attack_north_2.bmp", 6, 27);
	LoadImage( "char/zelda_attack_north_3.bmp", 8, 31);

	// Ä«ÀÏ ½ºÅ³ ½ÃÀü
	LoadImage( "char/zelda_skill_1.bmp", 8, 17 );
	LoadImage( "char/zelda_skill_2.bmp", 8, 30 );

	// ÇªÇª °È±â µ¿
	LoadImage( "evil/pupu_walk_east_1.bmp",9,15 );
	LoadImage( "evil/pupu_walk_east_2.bmp",9,15 );

	// ÇªÇª °È±â ¼­
	LoadImage( "evil/pupu_walk_west_1.bmp",9,15 );
	LoadImage( "evil/pupu_walk_west_2.bmp",9,15 );

	// ÇªÇª °È±â ³²
	LoadImage( "evil/pupu_walk_south_1.bmp",9,15 );
	LoadImage( "evil/pupu_walk_south_2.bmp",9,15 );
	
	// ÇªÇª °È±â ºÏ
	LoadImage( "evil/pupu_walk_north_1.bmp",9,15 );
	LoadImage( "evil/pupu_walk_north_2.bmp",9,15 );

	// ÇÎÅ©ÇÇ±× °È±â µ¿
	LoadImage( "evil/pinkpig_walk_east_1.bmp",9,15 );
	LoadImage( "evil/pinkpig_walk_east_2.bmp",9,15 );

	// ÇÎÅ©ÇÇ±× °È±â ¼­
	LoadImage( "evil/pinkpig_walk_west_1.bmp",9,15 );
	LoadImage( "evil/pinkpig_walk_west_2.bmp",9,15 );

	// ÇÎÅ©ÇÇ±× °È±â ³²
	LoadImage( "evil/pinkpig_walk_south_1.bmp",9,15 );
	LoadImage( "evil/pinkpig_walk_south_2.bmp",9,15 );
	
	// ÇÎÅ©ÇÇ±× °È±â ºÏ
	LoadImage( "evil/pinkpig_walk_north_1.bmp",9,15 );
	LoadImage( "evil/pinkpig_walk_north_2.bmp",9,15 );

	// ÇÎÅ©ÇÇ±× ÃÑ¾Ë
	LoadImage( "evil/pinkpig_bullet_east.bmp",9,5 );
	LoadImage( "evil/pinkpig_bullet_west.bmp",9,5 );
	LoadImage( "evil/pinkpig_bullet_south.bmp",5,10 );
	LoadImage( "evil/pinkpig_bullet_north.bmp",5,10 );
	

	// ºí·çÇÇ±× °È±â µ¿
	LoadImage( "evil/bluepig_walk_east_1.bmp",9,15 );
	LoadImage( "evil/bluepig_walk_east_2.bmp",9,15 );

	// ºí·çÇÇ±× °È±â ¼­
	LoadImage( "evil/bluepig_walk_west_1.bmp",9,15 );
	LoadImage( "evil/bluepig_walk_west_2.bmp",9,15 );

	// ºí·çÇÇ±× °È±â ³²
	LoadImage( "evil/bluepig_walk_south_1.bmp",9,15 );
	LoadImage( "evil/bluepig_walk_south_2.bmp",9,15 );
	
	// ºí·çÇÇ±× °È±â ºÏ
	LoadImage( "evil/bluepig_walk_north_1.bmp",9,15 );
	LoadImage( "evil/bluepig_walk_north_2.bmp",9,15 );

	// npc
	LoadImage( "npc/smith_walk_east_1.bmp", 6, 17 );
	LoadImage( "npc/smith_walk_east_2.bmp", 7, 17 );

	LoadImage( "npc/smith_walk_west_1.bmp", 6, 17 );
	LoadImage( "npc/smith_walk_west_2.bmp", 7, 17 );

	LoadImage( "npc/smith_walk_south_1.bmp", 9, 17 );
	LoadImage( "npc/smith_walk_south_2.bmp", 9, 17 );

	LoadImage( "npc/smith_walk_north_1.bmp", 9, 17 );
	LoadImage( "npc/smith_walk_north_2.bmp", 8, 17 );


	// Äí¿À ¾ÆÁÖ¸Ó´Ï
	LoadImage( "npc/kuo_walk_south_1.bmp", 9, 16 );
	LoadImage( "npc/kuo_walk_south_2.bmp", 9, 16 );



	// Áö´Ï¾Æ
	LoadImage( "npc/jinia_walk_east_1.bmp", 6, 17 );
	LoadImage( "npc/jinia_walk_east_2.bmp", 7, 17 );

	LoadImage( "npc/jinia_walk_west_1.bmp", 6, 17 );
	LoadImage( "npc/jinia_walk_west_2.bmp", 7, 17 );

	LoadImage( "npc/jinia_walk_south_1.bmp", 9, 17 );
	LoadImage( "npc/jinia_walk_south_2.bmp", 9, 17 );

	LoadImage( "npc/jinia_walk_north_1.bmp", 9, 17 );
	LoadImage( "npc/jinia_walk_north_2.bmp", 8, 17 );
	
	// ÀÌ¾È
	LoadImage( "npc/ean_walk_east_1.bmp", 6, 17 );
	LoadImage( "npc/ean_walk_east_2.bmp", 7, 17 );

	LoadImage( "npc/ean_walk_west_1.bmp", 6, 17 );
	LoadImage( "npc/ean_walk_west_2.bmp", 7, 17 );

	LoadImage( "npc/ean_walk_south_1.bmp", 9, 17 );
	LoadImage( "npc/ean_walk_south_2.bmp", 9, 17 );

	LoadImage( "npc/ean_walk_north_1.bmp", 9, 17 );
	LoadImage( "npc/ean_walk_north_2.bmp", 9, 17 );
	
	
	// º¸½º È£·ÕºÒ °È±â µ¿
	LoadImage( "evil/amber_walk_east_1.bmp",8,36 );
	LoadImage( "evil/amber_walk_east_2.bmp",8,36 );
	LoadImage( "evil/amber_walk_east_3.bmp",8,36 );

	// º¸½º È£·ÕºÒ °È±â ¼­
	LoadImage( "evil/amber_walk_west_1.bmp",17,36 );
	LoadImage( "evil/amber_walk_west_2.bmp",17,36 );
	LoadImage( "evil/amber_walk_west_3.bmp",17,36 );

	// º¸½º È£·ÕºÒ °È±â ³²
	LoadImage( "evil/amber_walk_south_1.bmp",17,34 );
	LoadImage( "evil/amber_walk_south_2.bmp",17,34 );
	
	// º¸½º È£·ÕºÒ °È±â ºÏ
	LoadImage( "evil/amber_walk_north_1.bmp",17,34 );
	LoadImage( "evil/amber_walk_north_2.bmp",17,34);

	// º¸½º È£·ÕºÒ ÃÑ¾Ë
	LoadImage( "evil/amber_bullet.bmp", 5,5 );
	
	// ¾Æ¸£Æ¼¾î½º
	LoadImage( "npc/artius_walk_east_1.bmp",6,17 );
	LoadImage( "npc/artius_walk_east_2.bmp",6,17 );
	
	LoadImage( "npc/artius_walk_west_1.bmp",6,17 );
	LoadImage( "npc/artius_walk_west_2.bmp",6,17 );

	LoadImage( "npc/artius_walk_south_1.bmp",9,17 );
	LoadImage( "npc/artius_walk_south_2.bmp",9,17 );

	LoadImage( "npc/artius_walk_north_1.bmp",9,17 );
	LoadImage( "npc/artius_walk_north_2.bmp",9,17 );

	// ¾ÆÀÌÅÛ
	LoadImage( "item/gold.bmp", 3,13 );
	LoadImage( "item/diamond.bmp", 3,13 );
	LoadImage( "item/diary.bmp", 7, 7 );
	LoadImage( "item/testitem.bmp", 4,4 );
	LoadImage( "item/milacho.bmp", 4,3 );
	LoadImage( "item/health_potion.bmp", 5, 5 );
	LoadImage( "item/mana_potion.bmp", 5, 5 );
	
	// °ÔÀÓ ÀÎÅÍÆäÀÌ½º
	LoadImage( "ui.bmp", 0,0 );
	LoadImage( "ui_focus.bmp", 0 , 0 );
	
	LoadImage( "hp.bmp", 0,0 );  // ¿¡³ÊÁö ¹Ù
	LoadImage( "mp.bmp", 0,0 );  // ¸¶³ª ¹Ù
	
	LoadImage( "textwindow.bmp", 0 , 0 );

	LoadImage( "Inventory.bmp", 0 , 0 );
	LoadImage( "Inventory_focus.bmp" , 0 , 0 );
		
	// ºñÆ®¸Ê ÀÌ¹ÌÁö
	LoadImage( "img/background_forest.bmp", 0 , 0 );
	LoadImage( "img/background_magicbook.bmp", 0 , 0 );
	LoadImage( "img/background_magicbookon.bmp", 0 , 0 );
	LoadImage( "img/background_ending.bmp", 0 , 0 );
	LoadImage( "img/background_noending.bmp", 0 , 0 );
	LoadImage( "img/background_credit.bmp", 0 , 0 );

	// ¸¶¹ý ÀÌ¹ÌÁö
	LoadImage( "char/magic_ball_1.bmp", 5 , 5 );
	LoadImage( "char/magic_ball_2.bmp", 5 , 5 );
	LoadImage( "char/magic_ball_3.bmp", 5 , 5 );

	

	return true;
}

bool CSpritePack::LoadImage( char* filename ,int ox, int oy) {
	CSprite *pSprite = new CSprite();

	// Áß½ÉÁ¡À» ¿©±â¼­ ¼³Á¤ÇÑ´Ù.
	pSprite->oX = ox;
	pSprite->oY = oy;
	
	pSprite->surface = load_image( filename );

	SDL_Surface* op;
	op = SDL_DisplayFormat( pSprite->surface );

	// Set the color key
    Uint32 colorkey = SDL_MapRGB( op->format, 0xFF, 0x00, 0xFF );
	SDL_SetColorKey( pSprite->surface, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
	
	pair< string , CSprite* > em;
	em.first = string(filename);
	em.second = pSprite;

	vecImageMap.insert( em );
	return true;
}


