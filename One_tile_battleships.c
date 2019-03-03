#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
//Boards that are global.
//Playerboard is the board where player guesses.
//cpuboard is the board where cpu guesses
// Legend for each Symbol
// o -- cpu tile that is not yet guessed by the player. Exist on playerboard
// = -- player tile that is not yet guessed by the cpu. Exist on cpuboard
// x -- tiles the player has guessed. Exist on playerboard
// | -- tiles the cpu has guessed. Exist on cpuboard.

//Dimensions of the board

const int X_LEN = 5;
const int Y_LEN = 5;

//Utility function to print a board
void printboard(int x, int y, char board[][Y_LEN]){
  printf("\n  ");
  for(int i=0;i<x;i++){
    printf("%d\t",i);
  }
  printf("\n");
  for(int i=0;i<x;i++){
    printf("%d ",i);
    for(int j=0;j<x;j++){
      printf("%c\t",board[i][j]);
    }
    printf("\n");
  }
}


bool ai(int a1,int b1,char cpuboard[][Y_LEN])
{
    //code for AI turn
    printf("\n thinking... \n");
    int ai_c,ai_d;
    // AI loop
    while(1)
    {
      //cpu Guess
      ai_c=rand()%X_LEN;
      ai_d=rand()%Y_LEN;
      if(cpuboard[ai_c][ai_d]=='|')
      {
          continue;
      }
      else if(ai_c==a1&&ai_d==b1)
      {
          //If cpu guesses right
          return true;
      }
      else
      {
          cpuboard[ai_c][ai_d]='|';
      }
      printf("\n The A.I. move \n");
      printboard(X_LEN,Y_LEN,cpuboard);
      printf("\n");
      return false;
    }
}


void main()
{
    //Menu printing code
    printf("\t \t \t ONE TILE BATTLESHIPS \n");
    printf("                             |    |    |                   \n ");
    printf("                            )_)  )_)  )_)               \n");
    printf("                            )___))___))___)\\           \n");
    printf("                           )____)____)_____)\\         \n");
    printf("                        _____|____|____|____\\\\__      \n");
    printf("                ---------\\                   //---------\n");
    printf("                  ^^^^^ ^^^^^^^^^^^^^^^^^^^^^          \n");
    printf("                    ^^^^      ^^^^     ^^^    ^^       \n");
    printf("                         ^^^^      ^^^                 \n");
    printf("Rules:1) Both you and the A.I get one tile to safeguard \n");
    printf("      2) Your goal is to find the enemy tile while protecting your own \n");
    printf("      3) The lesser turns you take the higher is your score \n");
    printf("\nLEGEND : \n Player Tiles \t \t \t \t Enemy Tiles \n = -- your tiles \t \t \t o -- opponent's tiles \n x--tiles you have guessed \t \t |--tiles the opponent has guessed \n");
    printf("\t \t \t Good Luck Have Fun \n");
    printf("------------------------------------------------------------------\n");
    //all game variables initialization
    int count=X_LEN * Y_LEN;  //Maximum number of turns / Current score
    int player_square_x;
    int player_square_y;
    int ai_square_x;
    int ai_square_y;
    int ansx,ansy;
    char name[20]; //String to hold player name
    bool exitcheck=true,gamecheck=true; // Flags to check game status
    char playerboard[X_LEN][Y_LEN];
    char cpuboard[X_LEN][Y_LEN];

    //Input players name
    printf("enter your name ");
    fgets(name,20,stdin);
    for(int g=0;g<X_LEN;g++)
    {
        for(int h=0;h<Y_LEN;h++)
        {
            playerboard[g][h]='o';
            cpuboard[g][h] = '-';
        }
    }
    //start gameloop
    //initialize playerboard
    printboard(X_LEN,Y_LEN,cpuboard);
    srand(time(NULL));
    //Player chooses which tile to safeguard
    while(1)
    {
      printf("\n choose your tile to safeguard (x,y) \n");
      fflush(stdin);
      scanf("%d %d",&player_square_x,&player_square_y);
      if(player_square_x<0||player_square_x>=X_LEN||player_square_y<0||player_square_y>=Y_LEN)
      {
          printf("\n invalid input \n");
      }
      else
      {
        cpuboard[player_square_x][player_square_y] = '*';
        gamecheck=true;
        ai_square_x = rand() % X_LEN;  //AI choses it's tile to safeguard
        ai_square_y = rand() % Y_LEN;
        break;
      }
    }
    //Individual game loop
    while(gamecheck)
    {
        //print playerboard
        printboard(X_LEN,Y_LEN,playerboard);
        printf("\n Your move \n");
        //Player Guess
        while(1)
        {
          printf("Guess the location (x,y)\n");
          ansx=-1,ansy=-1;
          fflush(stdin);
          scanf("%d %d",&ansx,&ansy);
          if(ansx<0||ansx>=X_LEN||ansy<0||ansy>=Y_LEN)
          {
            printf("\n invalid input \n");
          }
          else
            break;
        }
        if(ansx==ai_square_x&&ansy==ai_square_y)
        {
          //If player wins
          printf("\n Your score= %d \n",count);
          printf("\n YOU WIN !!!!!\n");
          gamecheck=false;
        }
        else
        {
          //Normal turn
          playerboard[ansx][ansy]='x';
          //AI turn
          if (ai(player_square_x,player_square_y,cpuboard))
          {
            //If player loses
            printf("\nthe AI guessed %d %d",player_square_x,player_square_y);
            printf("\n YOU LOSE !!!!! \n");
            printf("\nGET REKT M8\n");
            gamecheck=false;
          }
          count--;
        }
    }
    printf("\n=================================================\n");
}
