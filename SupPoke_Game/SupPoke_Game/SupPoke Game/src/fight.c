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
#include "../include/dommage.h"

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

    return choice;
}

int menu_run()
{

    float success_rate = (float)player.current_supemon->speed / (player.current_supemon->speed + wild_supemon.speed);
    float random_value = (float)rand() / RAND_MAX;

    if (random_value <= success_rate) {
        printf("You successfully escaped from the battle!\n");
        return 0;
    } else {
        printf("You failed to escape and must continue the battle!\n");

    }
    return 1;
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
        return 2;

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
        } else {
            printf("%d - %s   hp: %d / %d \n", i + 1, player.supemons[i]->name, player.supemons[i]->hp, player.supemons[i]->max_hp);
        }
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

int menu_turn_by_turn_fight()
{
    int player_starts = (player.current_supemon->speed > wild_supemon.speed) ? 1 : ((player.current_supemon->speed < wild_supemon.speed) ? 0 : rand() % 2);
    int choice = 0;
    initialize_wild_supemon(&player, &wild_supemon);

    while (player.current_supemon->hp > 0 && wild_supemon.hp > 0 && player.supemons[0]->hp != 0 && player.supemons[1]->hp != 0 && player.supemons[2]->hp != 0 && player.supemons[3]->hp != 0 && player.supemons[4]->hp != 0 && player.supemons[5]->hp != 0)
    {
        if (player.current_supemon->hp <= 0)
        {
            printf("Your Supemon is dead\n");
            menu_change_supemon();
        }

        if (player_starts) {
            // Tour du joueur
            choice = menu_fight();
            menu_fight_player_turn();
        } else {
            // Tour du Supémon adverse
            // Choisissez un mouvement aléatoire pour le Supémon adverse
            int random_move_index = rand() % 2;
            execute_move((struct move *) &wild_supemon.moves[random_move_index], &wild_supemon, player.current_supemon);
            printf("The wild %s used %s\n", wild_supemon.name, wild_supemon.moves[random_move_index]->name);
        }

        switch (choice)
        {
            case 1:
                printf("+------------------------------+\n");
                printf("|  1 - %s                      |", player.current_supemon->moves[0]->name);
                printf("|  2 - %s                      | ", player.current_supemon->moves[1]->name);
                printf("+------------------------------+\n");
                printf("Your choice (1 or 2) : ");
                scanf("%d", &choice);
                //execute la competence choisie par le joueur
                if (choice == 1)
                {
                    execute_move(player.current_supemon->moves[0], player.current_supemon,&wild_supemon);
                }
                else
                {
                    execute_move(player.current_supemon->moves[1], player.current_supemon, &wild_supemon);
                }

                break;
            case 2:
                menu_bag();
                break;
            case 3:
                menu_change_supemon();
                break;
            case 4:
                if (menu_catch() == 2) // Tentative de capture
                {
                    return 0; // Quitter le combat si le Supémon est capturé avec succès
                }
                break;
            case 5:
                if (menu_run() == 0)
                {
                    return 0;
                }
            default:
                break;
        }

        if (wild_supemon.hp <= 0)
        {
            printf("You win the fight\n");
            int reward_coins = rand() % 401 + 100; // Entre 100 et 500 Supcoins
            int reward_exp = (rand() % 401 + 100) * wild_supemon.level; // Entre 100 et 500 fois le niveau du Supémon sauvage
            printf("You earned %d Supcoins and %d experience points!\n", reward_coins, reward_exp);

            // Mettre à jour les récompenses du joueur
            player.money += reward_coins;
            player.current_supemon->xp += reward_exp;

            // Mettre à jour le niveau du Supémon actuel si nécessaire
            if (player.current_supemon->xp >= player.current_supemon->xp_to_next_level) {
                player.current_supemon->level++;
                player.current_supemon->xp -= player.current_supemon->xp_to_next_level;
                player.current_supemon->xp_to_next_level = player.current_supemon->xp_to_next_level + 500;
                printf("%s is now level %d!\n", player.current_supemon->name, player.current_supemon->level);
            }

            return 0;
        }
        // mettre un if qui fait attacker le wild supemon si il est pas mort
        if (player.current_supemon->hp <= 0)
        {
            printf("You lose the fight\n");
            return 0;
        }

        // Alternez les tours
        player_starts = !player_starts;

    }
    return 1;
}
