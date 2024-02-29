#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

// Include librairie perso
#include "../include/struct.h"
#include "../include/fight.h"
#include "../include/supinit.h"
#include "../include/game.h"

int menu_fight()
{
    int choice = 0;


    printf("+------------------------------+\n");
    printf("|    1 - Fight                 |\n");
    printf("|    2 - Bag                   |\n");
    printf("|    3 - SuPemon               |\n");
    printf("|    4 - Catch                 |\n");
    printf("|    5 - Run                   |\n");
    printf("+------------------------------+\n\n");
    printf("What do you want to do ?\n\n");

    printf("Your choice (1, 2, 3 or 4) : ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 4)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2, 3 or 4) : ");
        scanf("%d", &choice);
    }

    switch (choice) {
        case 1:
            printf("You choose to fight\n");
            break;
        case 2:
            menu_bag();
            break;
        case 3:
            menu_chose_supemon();
            break;
        case 4:
            printf("You Throw a SupBall\n");
            sleep(2);


            break;
    }

    return choice;
}

int menu_fight_player_turn()
{
    printf("Your Turn \n\n");
    printf("%s\n",wild_supemon.name);



}