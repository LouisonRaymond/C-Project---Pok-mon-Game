#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

// Include librairie perso
#include "../include/struct.h"
#include "../include/fight.h"

int menu_fight()
{
    int choice = 0;

    printf("+------------------------------+\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("+------------------------------+\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("|                              |\n");
    printf("+------------------------------+\n");
    printf("|    1 - Fight                 |\n");
    printf("|    2 - Bag                   |\n");
    printf("|    3 - SuPemon               |\n");
    printf("|    4 - Run                   |\n");
    printf("+------------------------------+\n\n");
    printf("What do you want to do ?\n\n");

    printf("Your choice (1, 2, 3 or 4) : ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 4)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2, 3 or 4) : ");
        scanf("%d", &choice);
    }

    return 0;
}