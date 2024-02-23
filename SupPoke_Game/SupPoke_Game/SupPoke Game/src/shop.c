#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

// Include librairie perso
#include "../include/struct.h"
#include "../include/shop.h"


int menu_shop()
{
    int choice = 0;

    printf("+------------------------------+\n");
    printf("|  You have %d  SupMoney       |\n", player.money);
    printf("|    1 - Buy                   |\n");
    printf("|    2 - Sell                  |\n");
    printf("|    3 - Exit                  |\n");
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
        menu_shop_buy();
        break;
    case 2:
        menu_shop_sell();
        break;
    case 3:
        break;
    
    default:
        break;
    }

    return 0;
}

int menu_shop_buy()
{

    int choice = 0;

    printf("+------------------------------+\n");
    printf("|    1 - Potion                |\n");
    printf("|    2 - Super Potion          |\n");
    printf("|    3 - Rare Candy            |\n");
    printf("|    4 - Exit                  |\n");
    printf("+------------------------------+\n\n");

    printf("Your choice (1, 2, 3 or 4) : ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 4)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2, 3 or 4) : ");
        scanf("%d", &choice);
    }
    switch (choice)
    {
    case 1:
        if (player.money < 100)
        {
            printf("You don't have enough money\n");
            break;
        }
        player.potions++;
        player.money -= 100;
        break;
    case 2:
        if (player.money < 300)
        {
            printf("You don't have enough money\n");
            break;
        }
        player.super_potions++;
        player.money -= 300;
        break;
    case 3:
        if (player.money < 700)
        {
            printf("You don't have enough money\n");
            break;
        }
        player.rare_candy++;
        player.money -= 700;
        break;
    case 4:
        break;
    
    default:
        break;
    }

    return 0;
}

int menu_shop_sell()
{
    int choice = 0;

    printf("+------------------------------+\n");
    printf("|    1 - Potion                |\n");
    printf("|    2 - Super Potion          |\n");
    printf("|    3 - Rare Candy            |\n");
    printf("|    4 - Exit                  |\n");
    printf("+------------------------------+\n\n");

    printf("Your choice (1, 2, 3 or 4) : ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 4)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2, 3 or 4) : ");
        scanf("%d", &choice);
    }
    switch (choice)
    {
    case 1:
        if(player.potions == 0)
        {
            printf("You cant sell something you dont have\n");
            break;
        }
        player.potions--;
        player.money += 50;
        break;
    case 2:
        if(player.super_potions == 0)
        {
            printf("You cant sell something you dont have\n");
            break;
        }
        player.super_potions--;
        player.money += 150;
        break;
    case 3:
        if(player.rare_candy == 0)
        {
            printf("You cant sell something you dont have\n");
            break;
        }
        player.rare_candy--;
        player.money += 350;
        break;
    case 4:
        break;
    
    default:
        break;
    }

    return 0;
}

