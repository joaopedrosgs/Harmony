#include <stdio.h>
#include <stdlib.h>


// STRUCTS
struct personagem {
char nome[20];
int level;
int hp;
int vitalidade;
int forca;
int resistencia;
int gold;


};
struct enemy {
char nome[20];
int level;
int hp;
int vitalidade;
int forca;
int resistencia;
};





int main () {



int request;
int location; // 0 - cidade ; 1 - lutando; 2 - resting;
int monlevel;

switch(request) {

case 0: // start a new game

{
struct personagem player;
}

break;
case 1: // change location

break;

case 2: // on monster death

break;

case 3: // recover hp
player.hp = player.vitalidade;
break;

case 4: //increment status

break;


}


return 0;
}