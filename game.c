#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Global array to represent the game board
char arr[10]={'0','1','2','3','4','5','6','7','8','9'};

// Function prototypes
void showboard(); // Function to display the game board
int checkforwin(); // Function to check the game status
int checkforblock(); // Function to check if the player is about to win
int checkforcorner(); // Function to check if a corner is available
int checkforwinning(); // Function to check if the computer is about to win
void brokenlines();
int main()
{
    system("cls");
    system("color 0A");
    char player1[20], player2[20]; // Variables to store player names
    int difficulty; // Variable to store game difficulty level
    char playAgain; // Variable to store the user's choice to play again
    int gameMode; // Variable to store the game mode (1: User vs User, 2: User vs Computer)

   

    do
    {
        system("cls");
        printf("                                      TIC-TAC-TOE");
        brokenlines();
        printf("Choose game mode: \n1: Player vs Player \n2: Player vs Computer\n");
        brokenlines();
        printf("Enter Choice: ");
        scanf("%d", &gameMode);
        system("cls");

        printf("Enter your name:\n");
        scanf("%s", player1);

        if(gameMode == 1)
        {
            printf("Enter name for Player 2:\n");
            scanf("%s", player2);
        }
        else
        {
            system("cls");
            printf("                                    DIFFICULTY LEVEL");
            brokenlines();
            printf("Choose difficulty level \n1: Easy \n2: Medium \n3: Hard\n");
            brokenlines();
            printf("Difficuty: ");
            scanf("%d", &difficulty);
        }
        int player = 1; // Variable to store the current player number
        int choice, i; // Variables to store the player's choice and the game status
        int mark; // Variable to store the player's mark (X or O)

        srand(time(0)); // Seed the random number generator

        // Reset the game board
        for(int j = 1; j <= 9; j++)
        {
            arr[j] = j + '0';
        }

        do
        {
            showboard(); // Display the game board
            player = (player %2)? 1:2; // Switch player

            if(player == 1)
            {
                printf("%s: \n", player1);
                scanf("%d",&choice); // Get the player's choice
            }
            else
            {
                if(gameMode == 1)
                {
                    printf("%s: \n", player2);
                    scanf("%d",&choice); // Get the player's choice
                }
                else
                {
                    printf("Computer: \n");
                    choice = checkforwinning(); // Get the computer's choice
                    if(choice == 0 && difficulty > 1)
                    {
                        choice = checkforblock(); // Get the computer's choice
                    }
                    if(choice == 0 && difficulty > 2)
                    {
                        choice = checkforcorner(); // Get the computer's choice
                    }
                    if(choice == 0)
                    {
                        do
                        {
                            choice = rand() % 9 + 1; // Get a random choice
                        } while(arr[choice] != '1' && arr[choice] != '2' && arr[choice] != '3' && arr[choice] != '4' && arr[choice] != '5' && arr[choice] != '6' && arr[choice] != '7' && arr[choice] != '8' && arr[choice] != '9');
                    }
                }
            }

            mark = (player==1)? 'X':'O'; // Determine the player's mark

            // Update the game board with the player's mark
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
                player--; // It's still the current player's turn
                getch();
            }
            i = checkforwin(); // Check the game status
            player++; // Switch to the next player

        }while (i == -1); // Continue the game until there's a winner or a draw
        showboard(); // Display the final game board

        // Announce the game result
        if(i == 1)
        {
            if(--player == 1)
                printf("%s won \n",player1);
            else
            {
                if(gameMode == 1)
                    printf("%s won \n",player2);
                else
                    printf("Computer won \n");
            }
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
    system("cls");
    printf("                                     BOARD");
    brokenlines();
    
    
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
    printf("   %c   |   %c   |    %c   ",arr[7],arr[8],arr[9]);
    brokenlines();
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
    // Check for a winning line (horizontal, vertical, or diagonal)
    //all instances for rows
    if(arr[1]=='X' && arr[2]=='X' && arr[3]=='3')
        return 3;
    if(arr[1]=='1' && arr[2]=='X' && arr[3]=='X')
        return 1;
     if(arr[1]=='X' && arr[2]=='2' && arr[3]=='X')
        return 2;
    if(arr[4]=='X' && arr[5]=='X' && arr[6]=='6')
        return 6;
    if(arr[4]=='X' && arr[5]=='5' && arr[6]=='X')
        return 5;
     if(arr[4]=='4' && arr[5]=='X' && arr[6]=='X')
        return 4;        
    if(arr[7]=='X' && arr[8]=='X' && arr[9]=='9')
        return 9;
    if(arr[7]=='X' && arr[8]=='8' && arr[9]=='X')
        return 8;
    if(arr[7]=='7' && arr[8]=='X' && arr[9]=='X')
        return 7;
    // ALL INSTANCES FOR COLUMNS
    if(arr[1]=='X' && arr[4]=='X' && arr[7]=='7')
        return 7;
    if(arr[1]=='X' && arr[4]=='4' && arr[7]=='X')
        return 4;
    if(arr[1]=='1' && arr[4]=='X' && arr[7]=='X')
        return 1;
    if(arr[2]=='X' && arr[5]=='X' && arr[8]=='8')
        return 8;
    if(arr[2]=='X' && arr[5]=='5' && arr[8]=='X')
        return 5;
     if(arr[2]=='2' && arr[5]=='X' && arr[8]=='X')
        return 2;
    if(arr[3]=='X' && arr[6]=='X' && arr[9]=='9')
        return 9;
    if(arr[3]=='X' && arr[6]=='6' && arr[9]=='X')
        return 6;
    if(arr[3]=='3' && arr[6]=='X' && arr[9]=='X')
        return 3;
    //all instances for diagonal    
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
    // Check for an available corner and center
    if(arr[5]=='5')
        return 5;
    else if(arr[7]='X')
        return 4;
    else if(arr[1]=='1')
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
    // Check for a winning line (horizontal, vertical, or diagonal)
    //ALL INSTANCES FOR ROWS
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
    //ALL INSTANCES FOR COLLUMNS
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
    if(arr[3]=='3' && arr[6]=='O' && arr[9]=='O')
        return 3;      
    //all instances for Diagonal
    if(arr[1]=='O' && arr[5]=='O' && arr[9]=='9')
        return 9;
    if(arr[1]=='1' && arr[5]=='O' && arr[9]=='O')
        return 1;
    if(arr[3]=='O' && arr[5]=='O' && arr[7]=='7')
        return 7;
    if(arr[3]=='3' && arr[5]=='O' && arr[7]=='O')
        return 3;
    
    else
        return 0; // Return 0 if there's no line to win
}
void brokenlines()
{
    int i;
    printf("\n");
    for(i=0;i<50;i++)
    {
        printf("..");
    }
    printf("\n");
}