#ifndef SUPPOKE_GAME_SAVE_H
#define SUPPOKE_GAME_SAVE_H

#include <stdbool.h>

void save_player(struct player *p);
void save_supemon(struct supemon *s);
void load_player(struct player *p);
void load_supemon(struct supemon *s);
bool check_save_files_exist();

#endif //SUPPOKE_GAME_SAVE_H
