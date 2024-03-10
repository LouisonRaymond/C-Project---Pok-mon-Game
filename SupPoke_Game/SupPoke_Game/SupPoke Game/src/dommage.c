#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

#include "../include/struct.h"
#include "../include/fight.h"
#include "../include/supinit.h"
#include "../include/game.h"
#include "../include/supcenter.h"
#include "../include/save.h"
#include "../include/dommage.h"

int is_offensive(struct move *move) {
    return move->damage > 0;
}

int is_passive(struct move *move) {
    return move->damage == 0;
}

int calculate_damage(struct move *move, struct supemon *launcher, struct supemon *target) {
    int damage = launcher->attack * move->damage / target->defense;
    if (rand() % 2 == 0) {
        // 50% chance d'arrondir vers le haut
        damage++;
    }
    return damage;
}

// Fonction pour calculer le taux de succès du mouvement
int success_rate(struct move *move, struct supemon *launcher, struct supemon *target) {
    return (int)launcher->accuracy / ((int)launcher->accuracy + target->evasion);
}

// Fonction pour exécuter un mouvement
void execute_move(struct move *move, struct supemon *launcher, struct supemon *target) {
    if (is_offensive(move)) {
        // Mouvement offensif
        int damage = calculate_damage(move, launcher, target);
        int rate = success_rate(move, launcher, target);
        if ((int)rand() / RAND_MAX < rate) {
            // Le mouvement a réussi
            printf("l'attaque a réussi !\n");
            //printf("Le mouvement %s est un mouvement offensif.\n", move->name);
            if (strcmp(launcher->name, wild_supemon.name) == 0)
            {
                printf("Degats recus : %d\n", damage);
            } else {
                printf("Degats infliges : %d\n", damage);
            }

            // Appliquer les dégâts à la cible
            target->hp -= damage;
            if (target->hp < 0) {
                target->hp = 0;
            }
        } else {
            // Le mouvement a échoué
            printf("l'attaque a échoué !\n");

        }
    } else {
        // Mouvement non-offensif
        // Gérer l'effet du mouvement ici (par exemple, augmentation/diminution des statistiques)
        // Mouvement non-offensif
        //printf("Le mouvement %s n'est pas un mouvement offensif.\n", move->name);
        if (move->defense_boost != 0) {
            // Augmentation ou diminution de la défense
            launcher->defense += move->defense_boost;
            printf("La défense de %s a été modifiée de %d.\n", launcher->name, move->defense_boost);
        }
        if (move->evasion_boost != 0) {
            // Augmentation ou diminution de l'evasion
            launcher->evasion += move->evasion_boost;
            printf("L'évasion de %s a été modifiée de %d.\n", launcher->name, move->evasion_boost);
        }
        if (move->attack_boost != 0) {
            // Augmentation ou diminution de l'attaque
            launcher->attack += move->attack_boost;
            printf("L'attaque de %s a été modifiée de %d.\n", launcher->name, move->attack_boost);
        }
        //printf("Le mouvement %s n'est pas un mouvement offensif.\n", move->name);
    }
}

