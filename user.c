#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Global array to represent the game board
char arr[10]={'0','1','2','3','4','5','6','7','8','9'};

// Function prototypes
void showboard();
int checkforwin();

int main()
{
    system("cls");
    system("Color 0A");

    // Variables to store player names
    char player1[20];
    char player2[20];

    // Prompt players to enter their names
    printf("Enter name for Player 1:\n");
    scanf("%s", player1);
    printf("Enter name for Player 2:\n");
    scanf("%s", player2);

    // Variables for game logic
    int player = 1; // Current player number
    int choice; // Player's choice for cell to mark
    int i; // Game status
    int mark; // Player's mark (X or O)

    do
    {
        showboard(); // Display the game board
        player = (player %2)? 1:2; // Switch player

        // Prompt the current player to make a move
        if(player == 1)
            printf("%s: \n", player1);
        else
            printf("%s: \n", player2);

        scanf("%d",&choice); // Get the player's choice
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
        if(player == 1)
            printf("%s won \n", player2);
        else
            printf("%s won \n", player1);
    }
    else
    {
        printf("Game is a draw \n");
    }
    getch();

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
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
        return 0;
    else
        return -1; // The game is still ongoing
}











