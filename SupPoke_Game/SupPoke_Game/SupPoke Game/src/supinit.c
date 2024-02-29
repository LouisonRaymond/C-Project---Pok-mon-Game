#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

#include "../include/struct.h"
#include "../include/supcenter.h"
#include "../include/supinit.h"



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

void initialize_wild_supemon(struct player *player, struct wild_supemon *wild_supemon) {
    struct supemon *current_supemon = player->current_supemon;

    const char *wild_names[] = {"SupIrtle", "SupMander", "SupAsaur"};
    int random_index = rand() % 3; // Générer un nombre aléatoire entre 0 et 2
    strcpy(wild_supemon->name, wild_names[random_index]);

    // Calculer les nouvelles statistiques en réduisant légèrement celles du Pokémon actuel
    wild_supemon->hp = (int)(current_supemon->hp * 0.9); // Réduire la santé de 10%
    wild_supemon->max_hp = (int)(current_supemon->max_hp * 0.9);
    wild_supemon->attack = (int)(current_supemon->attack * 0.9);
    wild_supemon->base_attack = (int)(current_supemon->base_attack * 0.9);
    wild_supemon->defense = (int)(current_supemon->defense * 0.9);
    wild_supemon->base_defense = (int)(current_supemon->base_defense * 0.9);
    wild_supemon->speed = (int)(current_supemon->speed * 0.9);
    wild_supemon->base_speed = (int)(current_supemon->base_speed * 0.9);
    wild_supemon->accuracy = (int)(current_supemon->accuracy * 0.9);
    wild_supemon->base_accuracy = (int)(current_supemon->base_accuracy * 0.9);
    wild_supemon->level = current_supemon->level;
    wild_supemon->xp = (int)(current_supemon->xp);
    wild_supemon->xp_to_next_level = (int)(current_supemon->xp_to_next_level);
    wild_supemon->evasion = (int)(current_supemon->evasion * 0.9); // Réduire l'esquive de 10%
    wild_supemon->base_evasion = (int)(current_supemon->base_evasion * 0.9);
    // Ajustez les statistiques comme nécessaire
}