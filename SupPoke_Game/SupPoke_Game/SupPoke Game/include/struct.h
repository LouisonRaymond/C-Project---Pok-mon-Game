#ifndef STRUCT_H
#define STRUCT_H

#define MAX_SUPEMON 6

// Structure qui contient les informations du joueur
extern struct player
{
    char name[20];
    int money;
    int potions;
    int super_potions;
    int rare_candy;
    struct supemon *current_supemon; // Change this to a pointer to supemon
    struct supemon *supemons[MAX_SUPEMON]; // Change this to a pointer to supemon

} player;

// Structure qui contient les informations d'un SuPemon
extern struct supemon
{
    char name[20];
    int hp;
    int max_hp;
    int attack;
    int base_attack;
    int defense;
    int base_defense;
    int speed ;
    int base_speed;
    int accuracy;
    int base_accuracy;
    int level;
    int xp;
    int xp_to_next_level;
    int evasion;
    int base_evasion;
} SupMander, SupAsaur, SupIrtle;

extern struct wild_supemon
{
    char name[20];
    int hp;
    int max_hp;
    int attack;
    int base_attack;
    int defense;
    int base_defense;
    int speed;
    int base_speed;
    int accuracy;
    int base_accuracy;
    int level;
    int xp;
    int xp_to_next_level;
    int evasion;
    int base_evasion;
} wild_supemon;


#endif // STRUCT_H
