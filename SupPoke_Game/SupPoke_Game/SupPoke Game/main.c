#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Include library headers
#include "include/struct.h"
#include "include/shop.h"

struct player player;

struct supemon SupMander =
        {
                "SupMander", // Nom du Supemon
                9,           // hp
                9,           // max_hp
                1,           // attack
                1,           // base_attack
                1,           // defense
                1,           // base_defense
                1,           // evasion
                1,           // speed
                1,           // base_speed
                2,           // accuracy
                2,           // base_accuracy
                1,           // level
                0,           // xp
                100,         // xp_to_next_level
        };

struct supemon SupAsaur =
        {
                "SupAsaur", // Nom du Supemon
                10,         // hp
                10,         // max_hp
                1,          // attack
                1,          // base_attack
                1,          // defense
                1,          // base_defense
                3,          // evasion
                1,          // speed
                1,          // base_speed
                2,          // accuracy
                2,          // base_accuracy
                1,          // level
                0,          // xp
                100,        // xp_to_next_level
        };

struct supemon SupIrtle =
        {
                "SupIrtle", // Nom du Supemon
                11,         // hp
                11,         // max_hp
                1,          // attack
                2,          // base_attack
                2,          // defense
                1,          // base_defense
                2,          // evasion
                2,          // speed
                2,          // base_speed
                1,          // accuracy
                1,          // base_accuracy
                1,          // level
                0,          // xp
                100,        // xp_to_next_level
        };

int main() {
    player.money = 0;
    menu_shop();

    // Lancement du jeux
    // menu_start();
    // menu_firstsupemon();

    // while (1)
    // {
    //     menu_menu();
    // }

    //Ingame Loop
    return 0;
}
