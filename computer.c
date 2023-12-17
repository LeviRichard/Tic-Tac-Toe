#include <stdio.h>  // Include standard input and output library
#include <conio.h>  // Include console input and output library for getch() function
#include <stdlib.h> // Include standard library for system() function
#include <time.h>   // Include time library for srand() function

// Global array to represent the game board
char arr[10]={'0','1','2','3','4','5','6','7','8','9'};

void showboard();
int checkforwin();
int checkforblock();
int checkforcorner();
int checkforwinning();

int main()
{
    char player1[20];
    int difficulty;
    char playAgain;

    do
    {
        system("cls");
        system("Color 0A");

        printf("Enter your name:\n");
        scanf("%s", player1);

        printf("Choose difficulty level (1: Easy, 2: Medium, 3: Hard):\n");
        scanf("%d", &difficulty);

        int player = 1;
        int choice, i;
        int mark;

        srand(time(0));

        // Reset the game board
        for(int j = 1; j <= 9; j++)
        {
            arr[j] = j + '0';
        }

        do
        {
            showboard();
            player = (player %2)? 1:2;

            if(player == 1)
            {
                printf("%s: \n", player1);
                scanf("%d",&choice);
            }
            else
            {
                printf("Computer: \n");
                choice = checkforwinning();
                if(choice == 0 && difficulty > 1)
                {
                    choice = checkforblock();
                }
                if(choice == 0 && difficulty > 2)
                {
                    choice = checkforcorner();
                }
                if(choice == 0)
                {
                    do
                    {
                        choice = rand() % 9 + 1;
                    } while(arr[choice] != '1' && arr[choice] != '2' && arr[choice] != '3' && arr[choice] != '4' && arr[choice] != '5' && arr[choice] != '6' && arr[choice] != '7' && arr[choice] != '8' && arr[choice] != '9');
                }
            }

            mark = (player==1)? 'X':'O';

            if(choice==1 && arr[1]=='1')
                arr[1]=mark;
            else if(choice==2 && arr[2]=='2')
                arr[2]=mark;
            else if(choice==3 && arr[3]=='3')
                arr[3]=mark;
            else if(choice==4 && arr[4]=='4')
                arr[4]=mark;
            else if(choice==5 && arr[5]=='5')
                arr[5]=mark;
            else if(choice==6 && arr[6]=='6')
                arr[6]=mark;
            else if(choice==7 && arr[7]=='7')
                arr[7]=mark;
            else if(choice==8 && arr[8]=='8')
                arr[8]=mark;
            else if(choice==9 && arr[9]=='9')
                arr[9]=mark;
            else
            {
                printf("Invalid value \n");
                player--;
                getch();
            }
            i = checkforwin();
            player++;

        }while (i == -1);
        showboard();

        if(i == 1)
        {
            if(--player == 1)
                printf("%s won \n",player1);
            else
                printf("Computer won \n");
        }
        else
        {
            printf("Game is a draw \n");
        }

        printf("Do you want to play again? (Y/N)\n");
        scanf(" %c", &playAgain);

    } while(playAgain == 'Y' || playAgain == 'y');

    return 0;
}


// Function to display the game board
void showboard()
{
    printf("       |       |       \n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |    %c   \n",arr[1],arr[2],arr[3]);
    printf("-------|-------|-------\n");
    printf("       |       |       \n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |    %c   \n",arr[4],arr[5],arr[6]);
    printf("-------|-------|-------\n");
    printf("       |       |       \n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |    %c   \n",arr[7],arr[8],arr[9]);
}

// Function to check the game status
int checkforwin()
{
    // Check for a winning line (horizontal, vertical, or diagonal)
    if(arr[1]==arr[2] && arr[2]==arr[3])
        return 1;
    else if(arr[4]==arr[5] && arr[5]==arr[6])
        return 1;
    else if(arr[7]==arr[8] && arr[8]==arr[9])
        return 1;
    else if(arr[1]==arr[4] && arr[4]==arr[7])
        return 1;
    else if(arr[2]==arr[5] && arr[5]==arr[8])
        return 1;
    else if(arr[3]==arr[6] && arr[6]==arr[9])
        return 1;
    else if(arr[1]==arr[5] && arr[5]==arr[9])
        return 1;
    else if(arr[3]==arr[5] && arr[5]==arr[7])
        return 1;

    // Check for a draw (no empty cells left)
    else if (arr[1] != '1'&& arr[2] != '2'&& arr[3] != '3'&& arr[4] != '4'&& arr[5] != '5'&& arr[6] != '6'&& arr[7] != '7'&& arr[8] != '8'&& arr[9] != '9')
        return 0;
    else
        return -1; // The game is still ongoing
}

// Function to check if the player is about to win
int checkforblock()
{
    //for horizontal
    if(arr[1]=='X' && arr[2]=='X' && arr[3]=='3')
        return 3;
    if(arr[4]=='X' && arr[5]=='X' && arr[6]=='6')
        return 6;
    if(arr[7]=='X' && arr[8]=='X' && arr[9]=='9')
        return 9;
    //for vertical
    if(arr[1]=='X' && arr[4]=='X' && arr[7]=='7')
        return 7;
    if(arr[2]=='X' && arr[5]=='X' && arr[8]=='8')
        return 8;
    if(arr[3]=='X' && arr[6]=='X' && arr[9]=='9')
        return 9;    
    //for Diagonal
    if(arr[1]=='X' && arr[5]=='X' && arr[9]=='9')
        return 9;
    if(arr[3]=='X' && arr[5]=='X' && arr[7]=='7')
        return 7;
    
    else
        return 0; // Return 0 if there's no line to block
}

// Function to check if a corner is available
int checkforcorner()
{
    if(arr[1]=='1')
        return 1;
    else if(arr[3]=='3')
        return 3;
    else if(arr[7]=='7')
        return 7;
    else if(arr[9]=='9')
        return 9;
    else
        return 0; // Return 0 if there's no corner available
}

// Function to check if the computer is about to win
int checkforwinning()
{
    //for horizontal
    if(arr[1]=='O' && arr[2]=='O' && arr[3]=='3')
        return 3;
    if(arr[1]=='O' && arr[2]=='2' && arr[3]=='O')
        return 2;
    if(arr[1]=='1' && arr[2]=='O' && arr[3]=='O')
        return 1;
    if(arr[7]=='O' && arr[8]=='O' && arr[9]=='9')
        return 9;
    if(arr[7]=='O' && arr[8]=='8' && arr[9]=='O')
        return 8;
    if(arr[7]=='7' && arr[8]=='O' && arr[9]=='O')
        return 7;
    //for vertical
    if(arr[1]=='O' && arr[4]=='O' && arr[7]=='7')
        return 7;
    if(arr[1]=='O' && arr[4]=='4' && arr[7]=='O')
        return 4;
    if(arr[1]=='1' && arr[4]=='O' && arr[7]=='O')
        return 1;
    if(arr[3]=='O' && arr[6]=='O' && arr[9]=='9')
        return 9;
    if(arr[3]=='O' && arr[6]=='6' && arr[9]=='O')
        return 6;
    if(arr[3]=='3' && arr[6]=='O' && arr[9]=='0')
        return 3;      
    //for Diagonal
    if(arr[1]=='O' && arr[5]=='O' && arr[9]=='9')
        return 9;
    if(arr[1]=='1' && arr[5]=='O' && arr[9]=='O')
        return 1;
    if(arr[3]=='O' && arr[5]=='O' && arr[7]=='7')
        return 7;
    if(arr[3]=='3' && arr[5]=='O' && arr[7]=='O')
        return 3;
    
    else
        return 0; // Return 0 if there's no line to block
}