#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

// Include library headers
#include "include/struct.h"
#include "include/shop.h"
#include "include/supinit.h"
#include "include/game.h"
#include "include/supcenter.h"
#include "include/fight.h"
#include "include/save.h"
#include "include/dommage.h"


struct player player;

struct wild_supemon wild_supemon;

struct move foliage = {"Foliage", 0, 0, 1, 0}; // Foliage gives 1 Evasion
struct move scratch = {"Scratch", 3, 0, 0, 0}; // Scratch deals 3 damage
struct move grawl = {"Grawl", 0, 0, 0, 1}; // Grawl gives 1 Attack
struct move pound = {"Pound", 2, 0}; // Pound deals 2 damage
struct move shell = {"Shell", 0, 1}; // Shell gives 1 Defense

struct supemon SupMander =
        {
                "SupMander", // Nom du Supemon
                10,           // hp
                10,           // max_hp
                1,           // attack
                1,           // base_attack
                1,           // defense
                1,           // base_defense
                1,           // speed
                1,           // base_speed
                2,           // accuracy
                2,           // base_accuracy
                1,           // level
                0,           // xp
                500,         // xp_to_next_level
                1,          //evasion
                1,      //base_evasion
                {&scratch, &grawl} // moves
        };

struct supemon SupAsaur =
        {
                "SupAsaur", // Nom du Supemon
                9,         // hp
                9,         // max_hp
                1,          // attack
                1,          // base_attack
                1,          // defense
                1,          // base_defense
                2,          //speed
                2,          // base_speed
                2,          // accuracy
                2,          // base_accuracy
                1,          // level
                0,          // xp
                500,          // xp_to_next_level
                3,        // evasion
                3,   // base_evasion
                {&foliage, &pound} // moves

        };

struct supemon SupIrtle =
        {
                "SupIrtle", // Nom du Supemon
                11,         // hp
                11,         // max_hp
                1,          // attack
                1,          // base_attack
                2,          // defense
                2,     // base_defense
                2,          // speed
                2,          // base_speed
                1,          // accuracy
                1,          // base_accuracy
                1,          // level
                0,          // xp
                500,          // xp_to_next_level
                2,          //evasion
                2,      //base_evasion
                {&pound, &shell} // moves
        };




int main() {

    // Initialisation de la graine pour la génération de nombres aléatoires
    srand(time(NULL));

    //alloue la mémoire pour stocker un supémon dans current supemon
    player.current_supemon = (struct supemon*)malloc(sizeof(struct supemon));
    if (player.current_supemon == NULL) {
        // Handle allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    // alloue la mémoire pour stocker un supemon dans la liste de supemon
    for (int i = 0; i < MAX_SUPEMON; i++) {
        player.supemons[i] = (struct supemon*)malloc(sizeof(struct supemon));
        if (player.supemons[i] == NULL) {
            // Gérer l'échec d'allocation
            fprintf(stderr, "Memory allocation failed for Supemon %d\n", i);
            // Libérer la mémoire allouée précédemment pour éviter les fuites
            for (int j = 0; j < i; j++) {
                free(player.supemons[j]);
            }
            // Libérer la mémoire allouée pour player.current_supemon
            free(player.current_supemon);
            return 1;
        }
    }
    /*  TEST DE FONCTIONNALITE
    copy_supemon(&SupIrtle, player.current_supemon);
    printf("%d\n", player.current_supemon->evasion);

    copy_supemon(player.current_supemon, player.supemons[0]);
    printf("le supemon en position 1 a : evasion");
    printf("%d\n", player.supemons[0]->evasion);
    */

    /*
    player.current_supemon = &SupIrtle;
    player.supemons[0] = &SupIrtle;
    player.supemons[1] = &SupMander;
    player.supemons[2] = &SupAsaur;
    initialize_wild_supemon(&player, &wild_supemon);

    printf("%d base hp\n", wild_supemon.hp);
    execute_move(&scratch, player.current_supemon, &wild_supemon);
    printf("%d hp after move\n", wild_supemon.hp);
*/

    //printf("%s\n", player.current_supemon->moves[0]->name);
/*
    printf("le supemon en position 0 est : %s\n", player.supemons[0]->name);
    menu_change_supemon();
    printf("le supemon en position 0 est : %s\n", player.supemons[0]->name);
         TEST DE FONCTIONNALITE      */

    // Lancement du jeu

    // Fonction qui vérifie si les fichiers de sauvegarde existent
    bool save_exists = check_save_files_exist();


    if (save_exists) {
        load_player(&player);
        for (int i = 0; i < MAX_SUPEMON; i++) {
            load_supemon(player.supemons[i]);
        }
    } else {
        menu_start();
        menu_firstsupemon();
    }

    //Ingame Loop
    while (1)
    {
        if (menu_menu() == 0)
        {
            break;
        }
    }

    printf("partie Sauvegarder\n");
    // Sauvegarde des informations dans les fichiers avant de quitter
    save_player(&player);
    for (int j = 0; j < MAX_SUPEMON; j++) {
        save_supemon(player.supemons[j]);
    }

    //libération de mémoire
    free(player.current_supemon);

    for (int j = 0; j < MAX_SUPEMON; j++) {
        free(player.supemons[j]);
    }
    printf("partie Sauvegarder\n");
    printf("Memoire liberer\n");

    return 0;
}
