#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



// STRUCTS
struct personagem
{
	int id;
	int level;
	int hp;
	int vitalidade;
	int forca;
	int resistencia;
	int gold;


};

struct monster {
	int sprite;
	int hp;
	int def;
	int dropg;
	int attack;
	int level;
	int exp;
	int shine;
};

typedef enum _locais {
	CIDADE,
	ARENA,
	REST
} locais;


typedef enum _requests {
	DEFAULT,
	NEWGAME,
	CHANGELOCATION,
	MONSTERDEATH,
	RECOVERHP,
	INCRESTATS,
	DEATH
} requests;

typedef enum _status {
	FORCA,
	VITALIDADE,
	RESISTENCIA
} status;


// --------------------MONSTERS--------------------------



void monsterJson(struct monster *monstro) {

	printf("{\"sprite\": %i,\"hp\":%i,\"def\":%i,\"dropg\":%i,\"attack\":%i,\"level\":%i,\"exp\":%i, \"shine\":%i}",
	       monstro->sprite,
	       monstro->hp,
	       monstro->def,
	       monstro->dropg,
	       monstro->attack,
	       monstro->level,
	       monstro->exp,
	       monstro->shine);


}


struct monster getmonster (int plevel) {

	struct monster monstro;

	float multiplier = 1;
	int shine = (rand() % plevel) % 100;
	monstro.level = plevel;
	monstro.shine = 0;

	if (shine > 90) {
		multiplier = 1.8;
		monstro.shine = 1;
	}


	monstro.sprite =  (rand() % 39) + 1;
	monstro.hp = (int)((pow(monstro.level, 2.01) + 50 * monstro.level + ( rand() % (monstro.level + 1) * 3)) * multiplier);
	monstro.attack = (int)(monstro.hp * 0.2 + ( rand() % (monstro.level + 1) / 10));
	monstro.dropg = (int)((pow(monstro.level, 1.8) + ( rand() % (monstro.level + 1) * 2)) * multiplier);
	monstro.exp = (int)((pow(monstro.level, 1.7) + ( rand() % (monstro.level + 1) * 2)) * multiplier);
	monstro.def = (int)(monstro.attack / 3 + ( rand() % (monstro.level + 1) / 7));


	return monstro;

}





// -----------------------HTML-------------------------------

void cType () {
	printf("%s%c%c\n", "Content-Type:text/html;charset=UTF-8", 13, 10);

}
void createElement( char* classe,char* id, char* content)
{

	printf("<div class='%s' id='%s'>%s\n", classe, id, content );

}
void closeElement() {
	printf("</div>\n");

}

void header (char* title, char* cssfile)
{

	printf("<!DOCTYPE html>\n");

	printf("<html lang=\"pt\">\n");

	printf("<head>");

	printf("<meta charset=\"utf-8\">\n");
	printf("<title>%s</title>\n", title);
	printf("<link rel=\"stylesheet\" href=\"%s\">\n", cssfile);
		printf("<script src='../jquery-3.0.0.min.js'></script>");

	printf("</head>\n");

	printf("<body>\n");
}

void ending()
{
	printf("</body>\n");

	printf("<script src='../main.js'></script>\n");

	printf("</html>\n");
}

void printgame(struct personagem *player) {



printf("<div class='statusbar'>");
printf("<div class='char'></div>\n");

      printf(" <div class='hp' id='playerhp' >");
        printf(" <div  id='playerhpfill' class='hpfill'>");
        printf(" </div>");
      printf(" </div>");
      printf(" <div class='gold'></div>");
      
    printf(" </div>");
    printf(" <div class='content'>");
      printf(" <div class='wrapmonster'>");
        printf(" <div><div class='monstro' id='monstro'>");
          printf(" <div class='effect attack'></div>");
        printf(" </div></div>");
        printf(" <div class='shadowwrap'><div class='shadow'></div>");
      printf(" </div>");
      printf(" <div class='hp' id='enemyhp'>");
        printf(" <div id='enemyhpfill' class='hpfill'>");
        printf(" </div>");
      printf(" </div>");
    printf(" </div>");
  printf(" </div>");
}


//----------------------PLAYER----------------------------------

void incrementlevel (struct personagem *player)
{

	player->level +=  1;
}

void incrementstatus (struct personagem *player, enum _status status, int qnt)
{
// 0 = força; 1 = vitalidade; 2 = resistencia;
	switch (status) {
	case FORCA:
	{
		player->forca += qnt;
		break;
	}


	case VITALIDADE:
	{
		player->vitalidade  += qnt;
		break;
	}


	case RESISTENCIA:
	{
		player->resistencia  += qnt;
		break;
	}


	}
}
