#include <stdio.h>
#include "functions.h"

int main(int argc, char **argv)
{
    int choice = 0;
    beginText();
    //while game is not started, loop until game is launched
    while (choice != 1)
    {
        scanf(" %c",&choice);
        switch(choice)
            {
                case '1':
                    choiceStart();
                    printf("Place map in project folder, and enter name of map (example: map1.txt)\n");
                    char filename[100];
                    scanf("%s", filename);
                    startProgram(filename);
                    break;
                case '2':
                    choiceInstruction();
                    break;
                case '3':
                    choiceExit();
                    return 0;
                    break;
                default:
                    choice = getchar();
                    break;
            }
    }
    return 0;
}
