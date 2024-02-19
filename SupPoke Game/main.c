#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

// Include librairie perso
#include "struct.h"

// Déclaration de toutes les fonctions
int menu_start();
int menu_firstsupemon();
int menu_fight();
int menu_menu();
int menu_shop();
int menu_shop_buy();
int menu_shop_sell();


// Strucuture qui contient les informations du joueur
struct player
{
    char name[20];
    int money;
    int potions;
    int super_potions;
    int rare_candy;
    int current_supemon;
    int supemon[6];
    
};

// Structure qui contient les informations d'un SuPemon
struct supemon
{
    char name[20];
    int hp;
    int max_hp;
    int attack;
    int base_attack;
    int defense;
    int base_defense;
    int speed ;
    int base_speed;
    int accuracy;
    int base_accuracy;
    int level;
    int xp;
    int xp_to_next_level;
};


struct supemon SupMander = {
"SupMander", 10 /*hp*/, 10/*maxhp*/, 1/*atk*/, 1/*batk*/, 1/*def*/, 1/*bdef*/, 1/*spd*/, 1/*bspd*/, 2/*acu*/, 2/*bacu*/, 1/*lvl*/, 0/*xp*/, 100/*xpnex*/};
struct supemon SupAsaur = {
"SupAsaur", 10 /*hp*/, 10/*maxhp*/, 1/*atk*/, 1/*batk*/, 1/*def*/, 1/*bdef*/, 1/*spd*/, 1/*bspd*/, 2/*acu*/, 2/*bacu*/, 1/*lvl*/, 0/*xp*/, 100/*xpnex*/};
struct supemon SupIrtle = {
"SupIrtle", 10 /*hp*/, 10/*maxhp*/, 1/*atk*/, 1/*batk*/, 1/*def*/, 1/*bdef*/, 1/*spd*/, 1/*bspd*/, 2/*acu*/, 2/*bacu*/, 1/*lvl*/, 0/*xp*/, 100/*xpnex*/};



struct player player;

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

    return choice;

}

int menu_fight()
{
    int choice = 0;

    printf("+------------------------------+\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("+------------------------------+\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("+------------------------------+\n");
    printf("|    1 - Fight                 |\n");
    printf("|    2 - Bag                   |\n");
    printf("|    3 - SuPemon               |\n");
    printf("|    4 - Run                   |\n");
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

    return 0;
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






int main(/*int argc, char *argv[]*/)
{   
    player.money = 0;
    menu_shop();

    // Lancement du jeux
    menu_start();
    menu_firstsupemon();

    // while (1)
    // {
    //     menu_menu();
    // }
    


    //Ingame Loop
    

    return 0;
}
