#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Include library headers
#include "include/struct.h"
#include "include/shop.h"
#include "include/supinit.h"
#include "include/game.h"

struct player player;

struct wild_supemon wild_supemon;

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
                100,         // xp_to_next_level
                1,          //evasion
                1,      //base_evasion
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
                100,          // xp_to_next_level
                3,        // evasion
                3   // base_evasion
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
                0,          // xp_to_next_level
                2,          //evasion
                2,      //base_evasion

        };

int main() {

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
    /*
    copy_supemon(&SupIrtle, player.current_supemon);
    printf("%d\n", player.current_supemon->evasion);

    copy_supemon(player.current_supemon, player.supemons[0]);
    printf("le supemon en position 1 a : evasion");
    printf("%d\n", player.supemons[0]->evasion);
    */


    // Lancement du jeux
    // menu_start();
    // menu_firstsupemon();

    // while (1)
    // {
    //     menu_menu();
    // }

    //Ingame Loop


    //libération de mémoire
    free(player.current_supemon);

    for (int j = 0; j < MAX_SUPEMON; j++) {
        free(player.supemons[j]);
    }

    return 0;
}
