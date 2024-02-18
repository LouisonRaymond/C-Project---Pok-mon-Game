#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

#include "Library.h"

// Strucuture qui contient les informations du joueur
struct player
{
    char name[20];
    int money;
    int items;
    int supemons;
    
};

// Structure qui contient les informations d'un SuPemon
struct supemon
{
    char name[20];
    int hp;
    int attack;
    int defense;
    int speed;
    int accuracy;
    int level;
    int xp;
    int xp_max;
    int xp_to_next_level;
};

struct player player;

// Fonction qui affiche le menu de depart
int menu_start()
{
    printf("Hi Young Adventurer\n");
    printf("Him the SupProfessor\n");
    printf("May you tell me your name ?\n");
    printf("Name : ");
    scanf("%s", &player.name);

    return 0;
}

int menu_firstsupemon()
{
    int choice = 0;

    printf("Hello %s\n", player.name);
    printf("Welcome to the world of SuPemon\n\n\n");
    printf("+------------------------------+\n");
    printf("|  Choose your first SuPemon   |\n");
    printf("|    1 - SupMander             |\n");
    printf("|    2 - SupAsaur              |\n");
    printf("|    3 - SupIrtler             |\n");
    printf("+------------------------------+\n\n");

    printf("Your choice (1, 2 or 3) : ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 3)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2 or 3) : ");
        scanf("%d", &choice);
    }

    return 0;
}




int main(/*int argc, char *argv[]*/)
{   
    // Lancement du jeux
    menu_start();
    //printf("Hello %s\n", player.name);
    menu_firstsupemon();


    //Ingame Loop
    

    return 0;
}
