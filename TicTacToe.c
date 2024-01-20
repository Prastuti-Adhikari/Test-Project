#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

char board[3][3];
const char Player='X';
const char Computer='O';

void NewBoard();
void PrintBoard();
int CheckFreeSpace();
void PlayerMove();
void ComputerMove();
char CheckWinner();
void PrintWinner(char);

int main()
{
    char winner = ' ';
    char response = ' ';
 do
   {
      winner = ' ';
      response = ' ';
      NewBoard();

      while(winner == ' ' && CheckFreeSpace() != 0)
      {
         PrintBoard();

         PlayerMove();
         winner = CheckWinner();
         if(winner != ' ' || CheckFreeSpace() == 0)
         {
            break;
         }

         ComputerMove();
         winner= CheckWinner();
         if(winner != ' ' || CheckFreeSpace() == 0)
         {
            break;
         }
      }

      PrintBoard();
      PrintWinner(winner);

      printf("\nWould you like to play again? (Y/N): ");
      scanf(" %c", &response);
      response = toupper(response);
   } while (response == 'Y');
printf("Thanks for playing Tic Tac Toe, hehe!");

return 0;
}

void NewBoard(){
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        board[i][j]=' ';
    }
}
}

void PrintBoard()
{
    printf("\n\n");
    printf("=== TIC-TAC-TOE===\n\n");
    printf("   P   P   \n");
    printf(" %c R %c R %c \n", board[0][0], board[0][1], board[0][2]);
    printf("___A___A___\n");
    printf("   S   S   \n");
    printf(" %c T %c T %c \n", board[1][0], board[1][1], board[1][2]);
    printf("___U___U___\n");
    printf("   T   T   \n");
    printf(" %c I %c I %c \n", board[2][0], board[2][1], board[2][2]);
    printf("   A   A   \n");
    printf("\n\n");
}

int CheckFreeSpace()
{
    int freespaces=9;
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i][j]!=' '){
                freespaces--;
            }
        }
    }
    return freespaces;
}
void PlayerMove()
{
int x,y;
do{
    printf("enter row number 1-3:");
scanf("%d",&x);
x--;
printf("enter column number 1-3:");
scanf("%d",&y);
y--;

if(board[x][y]!=' '){
    printf("Invalid Move");  
}
else{
    board[x][y]=Player;
    break;
}
} while(board[x][y]!=' ');
}

void ComputerMove()
{
//for generating random number i am creating a seed based on current time
srand(time(0));
int x,y;
if(CheckFreeSpace()>0)
{
    do{
        x=rand()%3;
        y=rand()%3;
    } while(board[x][y]!=' ');
    board[x][y]=Computer;
}
}

char CheckWinner()
{
    //checking rows
for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&& board[i][0]==board[i][2]){
            return board[i][0];
        }
    }
    //checking columns
for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i]&& board[0][i]==board[2][i]){
            return board[0][i];
        }
}
//checking diagonals
    if(board[0][0]==board[1][1]&& board[0][0]==board[2][2]){
    return board[0][0];
        }
if(board[0][2]==board[1][1]&& board[0][2]==board[2][0]){
    return board[0][2]; 
}
return ' ';
}
/// this is for printing the winner, whoever wins the game
void PrintWinner(char winner)
{
    if(winner==Player){
        printf("YOU WON!");
    }
    else if(winner==Computer){
        printf("YOU LOSE!");
    }
    else{
        printf("IT'S A TIE");
    }
}


 



