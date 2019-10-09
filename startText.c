#include<stdio.h>
#include <string.h>
void beginText()
{
     printf("WELCOME TO OREGON TRAIL\n");
     printf("ENTER 1 TO START\n");
     printf("ENTER 2 FOR INSTRUCTIONS\n");
     printf("ENTER 3 TO EXIT\n");
}
//Print starting text
void choiceStart()
{
    printf("\nStarting\n");
}
//print instructions for the user
void choiceInstruction()
{
    printf("\nEnter A for Left, Enter W for Up, Enter D For Right, Enter S For down\nTransverse the map and try to make it to the other corner!\n");

}
//print exiting text
void choiceExit()
{
    printf("\nExiting Game!\n");
}
//print ocean space text
void oceanSpace()
{
    printf("\nCan't pass ocean tiles!\n");
}



