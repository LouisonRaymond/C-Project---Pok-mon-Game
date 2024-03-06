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
            menu_catch();
            break;
        case 5:
            menu_run();
            break;
        default:
            break;
    }

    return choice;
}

int menu_run()
{

    float success_rate = (float)player.current_supemon->speed / (player.current_supemon->speed + wild_supemon.speed);
    float random_value = (float)rand() / RAND_MAX;

    if (random_value <= success_rate) {
        printf("You successfully escaped from the battle!\n");
    } else {
        printf("You failed to escape and must continue the battle!\n");
    }
    return 0;
}

int menu_catch()
{
    int team_position = 0;

    printf("You Throw a SupBall...\n");
    sleep(1);
    printf("TIKTOKTIKTOK...\n");
    float catch_rate = ((float)(wild_supemon.max_hp - wild_supemon.hp) / wild_supemon.max_hp) - 0.5;
    float random_value = (float)rand() / RAND_MAX;

    for (int i = 0; i < MAX_SUPEMON; i++) //boucle qui determine si la team est full ou pas et donc si catchable
    {
        if (player.supemons[i] == NULL)
        {
            team_position = i;
            break;
        }
        if (i == MAX_SUPEMON - 1)
        {
            printf("Your Supemon team is full\n");
            printf("Now You can only defeat this supemon\n");
            return 1;
        }
    }

    if (random_value <= catch_rate)  // if else qui determine si la condition de capture est valider
    {
        printf("You caught the wild %s\n", wild_supemon.name);
        copy_supemon((struct supemon *) &wild_supemon, player.supemons[team_position]);

    }
    else
    {
        printf("The wild %s escaped\n", wild_supemon.name);
    }

    return 0;
}

int menu_fight_player_turn()
{
    printf("Your Turn \n\n");
    printf("%s (enemy) \n",wild_supemon.name);
    printf("-----------------------\n");
    printf("HP: %d/%d      Lvl: %d \n",wild_supemon.hp, wild_supemon.max_hp, wild_supemon.level);
    printf("Attack: %d     Def: %d \n",wild_supemon.attack, wild_supemon.defense);
    printf("Accuracy: %d   Eva: %d \n",wild_supemon.accuracy, wild_supemon.evasion);
    printf("-----------------------\n");
    printf("%s (%19s) \n",player.current_supemon->name, player.name);
    printf("HP: %d/%d      Lvl: %d \n",player.current_supemon->hp, player.current_supemon->max_hp, player.current_supemon->level);
    printf("Attack: %d     Def: %d \n",player.current_supemon->attack, player.current_supemon->defense);
    printf("Accuracy: %d   Eva: %d \n",player.current_supemon->accuracy, player.current_supemon->evasion);
    printf("-----------------------\n");

    return 0;
}

int menu_change_supemon()
{
    int choice = 0;

    for (int i = 0; i < 6; i++)
    {
        if (player.supemons[i] == NULL)
        {
            printf("%d - Empty\n", i + 1);
            continue;
        }
        printf("%d - %s   hp: %d / %d \n", i + 1, player.supemons[i]->name, player.supemons[i]->hp, player.supemons[i]->max_hp);
    }
    printf("Choose a Supemon to Swap with : \n");
    scanf("%d", &choice);

    while (choice < 1 || choice > 6)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2, 3, 4, 5 or 6) : ");
        scanf("%d", &choice);
    }

    if (player.supemons[choice - 1] == NULL)
    {
        printf("This Supemon is empty\n");
        return 1;
    }
    else
    {
        // Stockez temporairement le Supemon actuel
        struct supemon *temp_supemon = player.current_supemon;
        // Copiez le Supemon choisi dans le Supemon actuel
        copy_supemon(player.supemons[choice - 1], player.current_supemon);
        // Mettez le Supemon temporaire dans la position choisie
        player.supemons[choice - 1] = temp_supemon;


        printf("You change your Supemon for %s\n", player.current_supemon->name);
    }


    return 0;
}

