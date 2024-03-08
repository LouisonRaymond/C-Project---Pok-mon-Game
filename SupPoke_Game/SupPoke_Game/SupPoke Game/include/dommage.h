#ifndef SUPPOKE_GAME_DOMMAGE_H
#define SUPPOKE_GAME_DOMMAGE_H

int calculate_damage(struct move *move, struct supemon *launcher, struct supemon *target);
float success_rate(struct move *move, struct supemon *launcher, struct supemon *target);
int is_offensive(struct move *move);
int is_passive(struct move *move);
void execute_move(struct move *move, struct supemon *launcher, struct supemon *target);

#endif //SUPPOKE_GAME_DOMMAGE_H
