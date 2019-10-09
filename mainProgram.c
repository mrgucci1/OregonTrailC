#include <stdio.h>
#include "functions.h";
#define MAXCHAR 100
char map[MAXCHAR][MAXCHAR];
long health;
//above
int topLeftRow = 7;
int topLeftCol = 7;
int aboveRow = 7;
int aboveCol = 8;
int topRightRow = 7;
int topRightCol = 9;
//current
int leftRow = 8;
int leftCol = 7;
int currentRow = 8;
int currentCol = 8;
int rightRow = 8;
int rightCol = 9;
//below
int lowLeftRow = 9;
int lowLeftCol = 7;
int lowRow = 9;
int lowCol = 8;
int lowRightRow = 9;
int lowRightCol = 9;

char viewPort[MAXCHAR][MAXCHAR];

void updatePos(int rowChange, int colChange)
    {
            int prevRow = currentRow;
            int prevCol = currentCol;
            //update all positions
            topLeftRow = topLeftRow + rowChange;
            topLeftCol = topLeftCol + colChange;
            aboveRow = aboveRow + rowChange;
            aboveCol = aboveCol + colChange;
            topRightRow = topRightRow + rowChange;
            topRightCol = topRightCol + colChange;
            //current
            leftRow = leftRow + rowChange;
            leftCol = leftCol + colChange;
            currentRow = currentRow + rowChange;
            currentCol = currentCol + colChange;
            rightRow = rightRow + rowChange;
            rightCol = rightCol + colChange;
            //below
            lowLeftRow = lowLeftRow + rowChange;
            lowLeftCol = lowLeftCol + colChange;
            lowRow = lowRow + rowChange;
            lowCol = lowCol + colChange;
            lowRightRow = lowRightRow + rowChange;
            lowRightCol = lowRightCol + colChange;
            if(viewPort[prevRow][prevCol] == 'X')
                viewPort[prevRow][prevCol] = 'U';
            viewPort[currentRow][currentCol] = 'X';
    }
//look ahead at the users requested space, figure out what it is, and based on what it is, do the appropriate action
//shares positioning variables, takes in the row and column change based off witch direction the user wanted to go
int evaluateSpace(int rowChange, int colChange)
    {
        int tempRow, tempCol;
        tempRow = currentRow + rowChange;
        tempCol = currentCol + colChange;
        if(tempRow == 0 || tempCol == 0 || tempCol == 9 || tempRow == 9)
        {
                oceanSpace();
                return 2;
        }
        char space = map[tempRow - 1][tempCol - 1];
        switch (space)
        {
        case 'G':
            printf("You encounter a bear!\nDo you want to hunt? (y/n)\n");
            char choice;
            choice = getchar();
            choice = getchar();
            if(choice == 'y')
            {
                printf("\nThe Bear attacked and you lost 10 health!\n");
                health = health - 10;
                return 1;
            }
            else
            {
                printf("\nYou slipped away un-noticed\n");
                viewPort[currentRow + rowChange][currentCol + colChange] = 'G';
                return 2;
            }
            break;
        case 'B':
            printf("You encounter a Wild Boar!\nDo you want to hunt? (y/n)\n");
            choice = getchar();
            choice = getchar();
            if(choice == 'y')
            {
                printf("\nThe Boar overpowered you and you lost 5 health!\n");
                health = health - 5;
                return 1;
            }
            else
            {
                printf("\nYou backed up slowly\n");
                viewPort[currentRow + rowChange][currentCol + colChange] = 'B';
                return 2;
            }
            break;
        case 'H':
            printf("You encounter a Hare!\nDo you want to hunt? (y/n)\n");
            choice = getchar();
            choice = getchar();
            if(choice == 'y')
            {
                printf("\nYou killed and cooked the Hare! Plus 5 Health!\n");
                health = health + 5;
                return 1;
            }
            else
            {
                printf("\nThe Hare ran away quickly\n");
                viewPort[currentRow + rowChange][currentCol + colChange] = 'H';
                return 2;
            }
            break;
        case 'E':
            printf("You encountered an Elk!\nDo you want to hunt? (y/n)\n");
            choice = getchar();
            choice = getchar();
            if(choice == 'y')
            {
                printf("\nYou killed and cooked the Elk! Plus 10 Health!\n");
                health = health + 10;
                return 1;
            }
            else
            {
                printf("\nThe Elk sent it!\n");
                viewPort[currentRow + rowChange][currentCol + colChange] = 'E';
                return 2;
            }
            break;
        case 'D':
            printf("You caught Dysentery!\n");
            printf("\nMinus 15 Health!\n");
            health = health - 15;
            return 1;
            break;
        case 'F':
            printf("You caught the Flu!\n");
            printf("\nMinus 15 Health!\n");
            health = health - 10;
            return 1;
            break;
        case 'C':
            printf("You caught a Cold!\n");
            printf("\nMinus 5 Health!\n");
            health = health - 5;
            return 1;
            break;
        case 'R':
            printf("You are in a wild raging river!\n");
            printf("\nMinus 20 Health\n");
            health = health - 20;
            return 1;
            break;
        case 'N':
            printf("You are on solid ground\n");
            return 1;
            break;
        case 'Z':
            printf("\nYou WIN!\n");
            exit(0);
        default:
            printf("you are on magic space, how?\n");
            printf("%c\n",space);
            break;
        }
        return 2;
    }
//checks the users health to make sure they are above zero, if not, says they died and kills program
    void evaulateHealth()
{
    if(health <= 0)
    {
        printf("\nYou Died\n");
        exit(0);
    }
}
//print current viewport to user
//uses all global positioning variables
void printView()
    {

            printf("Health: %d\n", health);
            printf("=========\n");
            printf("||%c|%c|%c||\n",viewPort[topLeftRow][topLeftCol],viewPort[aboveRow][aboveCol],viewPort[topRightRow][topRightCol]);
            printf("||%c|%c|%c||\n",viewPort[leftRow][leftCol],viewPort[currentRow][currentCol],viewPort[rightRow][rightCol]);
            printf("||%c|%c|%c||\n",viewPort[lowLeftRow][lowLeftCol],viewPort[lowRow][lowCol],viewPort[lowRightRow][lowRightCol]);
            printf("=========\n");
    }
//update all variables based on the row size (row size is also column size)
//uses global positioning variables and rowCounter, which is passed in
void updateVariables(int rowCounter)
{
topLeftRow = rowCounter - 1;
topLeftCol = rowCounter - 1;
aboveRow = rowCounter - 1;
aboveCol = rowCounter;
topRightRow = rowCounter - 1;
topRightCol = rowCounter + 1;
//current
leftRow = rowCounter;
leftCol = rowCounter - 1;
currentRow = rowCounter;
currentCol = rowCounter;
rightRow = rowCounter;
rightCol = rowCounter + 1;
//below
lowLeftRow = rowCounter + 1;
lowLeftCol = rowCounter - 1;
lowRow = rowCounter + 1;
lowCol = rowCounter;
lowRightRow = rowCounter + 1;
 lowRightCol = rowCounter + 1;
}
//called by main to read in file, get health value, and set map array to map in text file
void startProgram(char *filename)
{
    FILE *fp;
    FILE *fp2;
    //array to store read in characters from file
    //buff is for counting rows, buff2 is for reading file
    char buff[100];
    char buff2[100];
    //get first line
    fp = fopen(filename, "r+");
    fp2 = fopen(filename, "r+");
    fgets(buff, 100, (FILE*)fp);
    fgets(buff2, 100, (FILE*)fp2);
    //seperate number from first line of file
    char *str = buff, *p = str;
    while (*p) { // While there are more characters to process...
    if ( isdigit(*p) || ( (*p=='-'||*p=='+') && isdigit(*(p+1)) )) {
        // Found a number
        long val = strtol(p, &p, 10); // Read number
        health = val;
    } else {
        // Otherwise, move on to the next character.
        p++;
    }
}
    //for loop indexing variables
    int index;
    int rowCounter = 0;
    int rows;
    int cols;
    //set rowCounter to number of rows in text document
    while (fgets(buff, MAXCHAR, fp) != NULL)
    {
        if(buff != "")
            rowCounter++;
    }
    //set map to read in text document
    for(rows=0;rows<rowCounter;rows++)
    {
        fgets(buff2, 100, (FILE*)fp2);
        for(cols=0;cols<rowCounter;cols++)
        {
            map[rows][cols] = buff2[cols];
        }
    }
    //close files
    fclose(fp);
    fclose(fp2);
    //setup viewPort, this places ocean spaces and U's everywhere else
    for(rows = 0;rows < rowCounter+2;rows++)
    {
        for(cols=0;cols<rowCounter+2;cols++)
        {
            if(rows == 0 || rows == (rowCounter+1))
            {
                viewPort[rows][cols] = 'O';
            }
            else if(cols == 0 || cols == (rowCounter+1))
            {
               viewPort[rows][cols] = 'O';
            }
            else
            {
                viewPort[rows][cols] = 'U';
            }
        }
    }
    //print full read in map to user, this is mainly debugging
    printf("Health: %d\n",health);
    //printf("===================\n");
    for(index = 0;index <= (rowCounter - 1) + 3 + rowCounter;index++)
        printf("=");
    printf("\n");
    for(rows = 0;rows < rowCounter;rows++)
    {
        printf("|");
        for(cols = 0;cols < rowCounter;cols++)
        {
            printf("|%c", map[rows][cols]);
        }
        printf("||\n");
    }
    for(index = 0;index <= (rowCounter - 1) + 3 + rowCounter;index++)
        printf("=");
    printf("\n");
    //update posiitioning variables with rowCounter
    updateVariables(rowCounter);
    //set current pos to X
    viewPort[currentRow][currentCol] = 'X';
    printView();
    printf("Enter a for Left, Enter w for Up, Enter d For Right, Enter s For down\n");
    //forever while loop to keep taking instructions until game is won or lost
    while(1)
    {
        char choice = getchar();
        switch(choice)
        {
        case 'a':
            if(evaluateSpace(0, -1) == 1)
                updatePos(0, -1);
            evaulateHealth();
            printView();
            break;
        case 'w':
            if(evaluateSpace(-1, 0) == 1)
                updatePos(-1, 0);
            evaulateHealth();
            printView();
            break;
        case 'd':
            if(evaluateSpace(0, 1) == 1)
                updatePos(0, 1);
            evaulateHealth();
            printView();
            break;
        case 's':
            if(evaluateSpace(1, 0) == 1)
                updatePos(1, 0);
            evaulateHealth();
            printView();
            break;
        default:
            break;
        }
    }
}



