#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

// Include librairie perso
#include "../include/struct.h"
#include "../include/supcenter.h"

int menu_supemon_center()
{
    int choice = 0;

    printf("Welcome to the Supemon Center!\n\n");
    printf("+------------------------------+\n");
    printf("This are your Supemons: \n");
    for (int i = 0; i < 6; i++)
    {
        if (player.supemons[i] == NULL)
        {
            printf("%d - Empty\n", i + 1);
            continue;
        }
        printf("%d - %s   hp: %d / %d \n", i + 1, player.supemons[i]->name, player.supemons[i]->hp, player.supemons[i]->max_hp);
    }
    printf("+------------------------------+\n");

    printf("What do you want to do ?\n\n");
    printf("+------------------------------+\n");
    printf("|  1 - Heal Supemons           |\n");
    printf("|  2 - Exit                    |\n");
    printf("+------------------------------+\n\n");

    printf("Your choice (1 or 2) : ");
    scanf("%d", &choice);

    while (choice < 1 || choice > 2)
    {
        printf("Invalid choice\n");
        printf("Your choice (1 or 2) : ");
        scanf("%d", &choice);
    }

    switch (choice)
    {
        case 1:
            for (int i = 0; i < 6; i++)
            {
                if (player.supemons[i] == NULL)
                {
                    continue;
                }
                player.supemons[i]->hp = player.supemons[i]->max_hp;
            }
            break;
        case 2:
            return 0;
        default:
            break;
    }


    return 1;
}



