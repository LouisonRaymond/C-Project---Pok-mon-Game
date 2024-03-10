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
    destination->hp = source->hp;  //source p supemon i
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

    for (int i = 0; i < 2; i++) {
        destination->moves[i] = source->moves[i];
    }
}

void initialize_wild_supemon(struct player *player, struct wild_supemon *wild_supemon) {
    struct supemon *current_supemon = player->current_supemon;

    const char *wild_names[] = {"SupIrtle", "SupMander", "SupAsaur"};
    int random_index = rand() % 3; // Générer un nombre aléatoire entre 0 et 2
    strcpy(wild_supemon->name, wild_names[random_index]);

    // Assigner les mouvements en fonction du nom du Supémon sauvage
    if (strcmp(wild_supemon->name, "SupIrtle") == 0) {
        wild_supemon->moves[0] = &foliage; // Premier mouvement
        wild_supemon->moves[1] = &pound;   // Deuxième mouvement
    } else if (strcmp(wild_supemon->name, "SupMander") == 0) {
        wild_supemon->moves[0] = &scratch; // Premier mouvement
        wild_supemon->moves[1] = &grawl;   // Deuxième mouvement
    } else if (strcmp(wild_supemon->name, "SupAsaur") == 0) {
        wild_supemon->moves[0] = &scratch; // Premier mouvement
        wild_supemon->moves[1] = &pound;   // Deuxième mouvement
    }

    // Calculer les nouvelles statistiques en réduisant légèrement celles du Pokémon actuel
    wild_supemon->hp = (int)(current_supemon->hp * 0.9); // Réduire la santé de 10%
    wild_supemon->hp = (wild_supemon->hp < 1) ? 1 : wild_supemon->hp; // Vérifier si la santé est inférieure à 1

    wild_supemon->max_hp = (int)(current_supemon->max_hp * 0.9);
    wild_supemon->max_hp = (wild_supemon->max_hp < 1) ? 1 : wild_supemon->max_hp;

    wild_supemon->attack = (int)(current_supemon->attack * 0.9);
    wild_supemon->attack = (wild_supemon->attack < 1) ? 1 : wild_supemon->attack;

    wild_supemon->base_attack = (int)(current_supemon->base_attack * 0.9);
    wild_supemon->base_attack = (wild_supemon->base_attack < 1) ? 1 : wild_supemon->base_attack;

    wild_supemon->defense = (int)(current_supemon->defense * 0.9);
    wild_supemon->defense = (wild_supemon->defense < 1) ? 1 : wild_supemon->defense;

    wild_supemon->base_defense = (int)(current_supemon->base_defense * 0.9);
    wild_supemon->base_defense = (wild_supemon->base_defense < 1) ? 1 : wild_supemon->base_defense;

    wild_supemon->speed = (int)(current_supemon->speed * 0.9);
    wild_supemon->speed = (wild_supemon->speed < 1) ? 1 : wild_supemon->speed;

    wild_supemon->base_speed = (int)(current_supemon->base_speed * 0.9);
    wild_supemon->base_speed = (wild_supemon->base_speed < 1) ? 1 : wild_supemon->base_speed;

    wild_supemon->accuracy = (int)(current_supemon->accuracy);
    wild_supemon->accuracy = (wild_supemon->accuracy < 1) ? 1 : wild_supemon->accuracy;

    wild_supemon->base_accuracy = (int)(current_supemon->base_accuracy);
    wild_supemon->base_accuracy = (wild_supemon->base_accuracy < 1) ? 1 : wild_supemon->base_accuracy;

    wild_supemon->level = current_supemon->level;

    wild_supemon->xp = (int)(current_supemon->xp);

    wild_supemon->xp_to_next_level = (int)(current_supemon->xp_to_next_level);

    wild_supemon->evasion = (int)(current_supemon->evasion * 0.9); // Réduire l'esquive de 10%
    wild_supemon->evasion = (wild_supemon->evasion < 1) ? 1 : wild_supemon->evasion; // Vérifier si l'esquive est inférieure à 1

    wild_supemon->base_evasion = (int)(current_supemon->base_evasion * 0.9);
    wild_supemon->base_evasion = (wild_supemon->base_evasion < 1) ? 1 : wild_supemon->base_evasion;
