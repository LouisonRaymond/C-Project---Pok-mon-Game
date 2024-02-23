#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Include library headers
#include "include/struct.h"
#include "include/shop.h"


struct player player;

int main() {
    player.money = 0;
    menu_shop();

    // Lancement du jeux
    // menu_start();
    // menu_firstsupemon();

    // while (1)
    // {
    //     menu_menu();
    // }

    //Ingame Loop
    return 0;
}
