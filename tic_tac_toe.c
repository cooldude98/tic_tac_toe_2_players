#include <stdio.h>
#include <conio.h>
#include <string.h>

// CHAR SQUARE-  TO DISPLAY THE CHOICES ON BOARD AND STORE USER INPUT
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


int checkwin();
void board();

// FUNCTION TO START THE GAME
void game() {
    int player = 1;
    int i, choice;
    char name1[100];
    char name2[100];

    printf("Enter Player 1 name\n");
    scanf("%s",name1);
    printf("\n");
    printf("Enter Player 2 name\n");
    scanf("%s",name2);

    char mark; // FILLS THE "X" AND "O" IN PLACE OF NUMBERS IN THE SQUARE ARRAY.
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        if(player==1){
        printf("Player %d %s, select box:  ", player,name1);
        scanf("%d", &choice);
        }
        else{
        printf("Player %d %s, select box:  ", player,name2);
        scanf("%d", &choice);
        }
        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid move");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);

    board();

    if (i == 1){
        if(--player==1)
            printf("Player %d %s win !! ",player,name1 );
        else
            printf("Player %d %s win !! ",player,name2 );
    }
    else
        printf("Game draw");
    char c;

    printf("\n");
    scanf("%c",&c);
    if(c=='y')
        game();

}

int main(){
    char c[1];
    do{
        game();
        printf("Play again? (Y/N): ");
        getch();
        scanf("%c", &c[0]);
        system("cls");
    }while (c[0] == 'y');

    return 0;
}
/*
FUCTION TO CHECK GAME STATUS
FINISHED = 1, IN PROGRESS = -1, DRAW = 0
*/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]!= '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return  - 1;
}

// BOARD FOR TIC TAC TOE
void board()
{

    system("cls");
    printf("\tTic Tac Toe\n\n");
    printf("Player 1 is cross (X)  -  Player 2 is circle (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     |     \n\n");
}
