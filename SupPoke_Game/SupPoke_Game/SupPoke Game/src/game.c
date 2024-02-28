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
    printf("I'm the SupProfessor\n");
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
    printf("|    3 - SupIrtle              |\n");
    printf("+------------------------------+\n\n");

    printf("Your choice (1, 2 or 3) : ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 3)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2 or 3) : ");
        scanf("%d", &choice);
    }

    switch (choice)
    {
        case 1:
            copy_supemon(&SupIrtle, player.current_supemon);
        default:
            break;
    }

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
    
    default:
        break;
    }


    return 0;
}

int menu_bag()
{
    int choice = 0;

    printf("+------------------------------+\n");
    printf("(1)You Have %d potions\n", player.potions);
    printf("(2)You Have %d super potions\n", player.super_potions);
    printf("(3)You Have %d rare candies\n", player.rare_candy);
    printf("This item will be used on (your current Supemon)%s\n", player.current_supemon->name);
    printf("+------------------------------+\n");
    printf("What do you want to use ? ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 3)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2 or 3) : ");
        scanf("%d", &choice);
    }

    switch (choice) {
        case 1:
            if (player.potions > 0)
            {
                player.current_supemon->hp += 5;
                if (player.current_supemon->hp > player.current_supemon->max_hp)
                {
                    player.current_supemon->hp = player.current_supemon->max_hp;
                }
                player.potions--;
            }
            else
            {
                printf("You don't have any potions\n");
            }
            break;
        case 2:
            if (player.super_potions > 0)
            {
                player.current_supemon->hp += 10;
                if (player.current_supemon->hp > player.current_supemon->max_hp)
                {
                    player.current_supemon->hp = player.current_supemon->max_hp;
                }
                player.super_potions--;
            }
            else
            {
                printf("You don't have any super potions\n");
            }
            break;
        case 3:
            if (player.rare_candy > 0)
            {
                player.current_supemon->level++;
                player.rare_candy--;
            }
            else
            {
                printf("You don't have any rare candies\n");
            }
            break;
        default:
            break;
    }

    return choice;
}

int menu_chose_supemon()
{

    return 0;
}
