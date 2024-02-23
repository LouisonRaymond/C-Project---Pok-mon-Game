#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

// Include librairie perso
#include "../include/struct.h"

int menu_sup_center()
{
    int choice = 0;

    printf("Welcome to the SupÃ©mon Center!\n\n");
    printf("+------------------------------+\n");
    printf("|    1 - Heal your Supemons    |\n");
    printf("|    2 - Display your Supemons |\n");
    printf("|    3 - Save                  |\n");
    printf("|    4 - Exit                  |\n");
    printf("+------------------------------+\n\n");

    printf("Your choice (1, 2, 3, or 4): ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 4)
    {
        printf("Invalid choice\n");
        printf("Your choice (1, 2, 3, or 4): ");
        scanf("%d", &choice);
    }

    switch (choice)
    {
        case 1:
        {
            printf("All your Supemons have been healed\n");
            int sup_choice = menu_firstsupemon();
            switch(sup_choice)
            {
                case 1:
                    SupMander.hp = SupMander.max_hp;
                    printf("SupMander has been healed\n");
                    break;
                case 2:
                    SupAsaur.hp = SupAsaur.max_hp;
                    printf("SupAsaur has been healed\n");
                    break;
                case 3:
                    SupIrtle.hp = SupIrtle.max_hp;
                    printf("SupIrtle has been healed\n");
                    break;
                default:
                    printf("Invalid Supemon choice\n");
                    break;
            }
            break;
        }

        case 2:
            printf("Display Supemons\n");
            break;

        case 3:
            printf("Saving...\n");
            menu_save();
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}



