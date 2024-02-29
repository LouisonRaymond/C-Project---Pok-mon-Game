#ifndef SUPINIT_H
#define SUPINIT_H

void add_supemon_player(int supemon_s);
int create_new_supemon();
void copy_supemon(struct supemon *source, struct supemon *destination);
void initialize_wild_supemon(struct player *player, struct wild_supemon *wild_supemon);

#endif //SUPINIT_H
