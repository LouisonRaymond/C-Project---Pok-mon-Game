#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

// Include librairie perso
#include "../include/struct.h"
#include "../include/game.h"
#include "../include/shop.h"
#include "../include/fight.h"
#include "../include/supinit.h"

int menu_start()
{
    printf("Hi Young Adventurer\n");
    printf("Him the SupProfessor\n");
    printf("May you tell me your name ?\n");
    printf("Name : ");
    scanf("%19s", player.name);

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

    add_supemon_player(choice);

    return choice;

}

int menu_menu()
{
    int choice = 0;

    printf("What do you want to do ?\n\n");
    printf("+------------------------------+\n");
    printf("|    1 - Go into the wild      |\n");
    printf("|    2 - shop                  |\n");
    printf("|    3 - Supemon Center        |\n");
    printf("|    4 - Save                  |\n");
    printf("|    5 - Exit                  |\n");
    printf("+------------------------------+\n\n");

    printf("Your choice (1, 2, 3 or 4) : ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 5)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2, 3, 4 or 5) : ");
        scanf("%d", &choice);
    }
    switch (choice)
    {
    case 1:
        menu_fight();
        break;
    case 2:
        menu_shop();
        break;
    case 3:
        //menu_supemon_center(); // a faire
        break;
    case 4:
        //save(); // a faire
        break;
    case 5:
        exit(0);
        break;
    
    default:
        break;
    }


    return 0;
} 