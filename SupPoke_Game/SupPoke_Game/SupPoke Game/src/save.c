
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#include "../include/struct.h"
#include "../include/save.h"

// Fonction pour sauvegarder les informations du joueur dans un fichier
void save_player(struct player *p) {
    FILE *file = fopen("save_player.txt", "w"); // Ouvrir le fichier en mode écriture
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier de sauvegarde pour le joueur.\n");
        return;
    }
    // Écrire les informations du joueur dans le fichier
    fprintf(file, "%s %d %d %d %d %d\n", p->name, p->money, p->potions, p->super_potions, p->rare_candy);
    fclose(file); // Fermer le fichier
}

// Fonction pour charger les informations du joueur depuis un fichier
void load_player(struct player *p) {
    FILE *file = fopen("save_player.txt", "r"); // Ouvrir le fichier en mode lecture
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier de sauvegarde pour le joueur.\n");
        return;
    }
    // Lire les informations du joueur depuis le fichier
    fscanf(file, "%s %d %d %d %d %d\n", p->name, &p->money, &p->potions, &p->super_potions, &p->rare_candy);
    fclose(file); // Fermer le fichier
}

// Fonction pour sauvegarder les informations d'un Supemon dans un fichier
void save_supemon(struct supemon *s) {
    FILE *file = fopen("save_supemon.txt", "w"); // Ouvrir le fichier en mode écriture
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier de sauvegarde pour le Supemon.\n");
        return;
    }
    // Écrire les informations du Supemon dans le fichier
    fprintf(file, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", s->name, s->hp, s->max_hp, s->attack, s->base_attack,
            s->defense, s->base_defense, s->speed, s->base_speed, s->accuracy, s->base_accuracy, s->level, s->xp,
            s->xp_to_next_level, s->evasion, s->base_evasion);
    fclose(file); // Fermer le fichier
}

// Fonction pour charger les informations d'un Supemon depuis un fichier
void load_supemon(struct supemon *s) {
    FILE *file = fopen("save_supemon.txt", "r"); // Ouvrir le fichier en mode lecture
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier de sauvegarde pour le Supemon.\n");
        return;
    }
    // Lire les informations du Supemon depuis le fichier
    fscanf(file, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", s->name, &s->hp, &s->max_hp, &s->attack, &s->base_attack,
           &s->defense, &s->base_defense, &s->speed, &s->base_speed, &s->accuracy, &s->base_accuracy, &s->level, &s->xp,
           &s->xp_to_next_level, &s->evasion, &s->base_evasion);
    fclose(file); // Fermer le fichier
}

bool check_save_files_exist() {
    FILE *player_file = fopen("save_player.txt", "r");
    FILE *supemon_file = fopen("save_supemon.txt", "r");

    if (player_file != NULL && supemon_file != NULL) {
        fclose(player_file);
        fclose(supemon_file);
        return true;
    }

    return false;
}

