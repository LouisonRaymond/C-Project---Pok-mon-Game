
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "save.h"
#include "struct.h"



void save_game(struct player *player)
{
    FILE *file = fopen("save.txt", "w");
    if(file != NULL)
    {
        fprintf(file,"%s\n", player.name);
        fprintf(file,"%s\n", player.current_supemon);
        fprintf(file,"%s\n", player.money);
        fprintf(file,"%s\n", player.potions);
        fprintf(file,"%s\n", player.rare_candy);
        fprintf(file,"%s\n", player.supemons);
        fprintf(file,"%s\n", player.super_potions);
        fclose(file);
    }
    else
    {
        printf("impossible to open the current save file.\n");
    }
}
/*
struct player_load_game()
{
    FILE *file = fopen("save.txt", "r");
    if (file != NULL)
    {
        fscanf(file, "%s\n", player.name)
        fscanf(file,"%s\n", player.current_supemon);
        fscanf(file,"%s\n", player.money);
        fscanf(file,"%s\n", player.potions);
        fscanf(file,"%s\n", player.rare_candy);
        fscanf(file,"%s\n", player.supemons);
        fscanf(file,"%s\n", player.super_potions);
        fclose(file);
    }
    else
    {
        printf("impossible to open the current save file")
    }
    return player
}
*/