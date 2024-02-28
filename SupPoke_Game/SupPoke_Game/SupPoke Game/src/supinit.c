#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

#include "../include/struct.h"
#include "../include/supcenter.h"
#include "../include/supinit.h"
/*
void add_supemon_player(int supemon_s)
{
    if(player.current_supemon < MAX_SUPEMON)
    {
        player.supemon[player.current_supemon++] = supemon_s; // augmente le compteur currentsupmeon de 1
        printf("you have obtained %s !\n", supemon_s == 1 ? "SupMander" : (supemon_s == 2 ? "SupAsaur": "SupIrtle" )); //si supemon_s=1 est choisi alors on va choisir SupMander etc etc
    }
    else
    {
        printf("Your Team is full !");
    }
}*/

/*int create_new_supemon()
{
    srand(time(NULL));
    int nbrAlea = rand() % 3 + 1;  // nbr alea entre 1 et 3

    switch (nbrAlea)
    {
        case 1:
            add_supemon_player(1);
            printf("testalea1passed");
            break;

        case 2:
            add_supemon_player(2);
            printf("testalea2passed");
            break;

        case 3:
            add_supemon_player(3);
            printf("testalea3passed");
            break;

        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}*/

void copy_supemon(struct supemon *source, struct supemon *destination){
    // Copier le nom du Supémon
    strcpy(destination->name, source->name);
    // Copier les autres attributs du Supémon
    destination->hp = source->hp;
    destination->max_hp = source->max_hp;
    destination->attack = source->attack;
    destination->base_attack = source->base_attack;
    destination->defense = source->defense;
    destination->base_defense = source->base_defense;
    destination->speed = source->speed;
    destination->base_speed = source->base_speed;
    destination->accuracy = source->accuracy;
    destination->base_accuracy = source->base_accuracy;
    destination->level = source->level;
    destination->xp = source->xp;
    destination->xp_to_next_level = source->xp_to_next_level;
    destination->evasion = source->evasion;
    destination->base_evasion = source->base_evasion;
}