#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//Boards that are global.
//Playerboard is the board where player guesses.
//cpuboard is the board where cpu guesses
// Legend for each Symbol
// o -- cpu tile that is not yet guessed by the player. Exist on playerboard
// = -- player tile that is not yet guessed by the cpu. Exist on cpuboard
// x -- tiles the player has guessed. Exist on playerboard
// | -- tiles the cpu has guessed. Exist on cpuboard.
static char playerboard[5][5];
static char cpuboard[5][5];
int ai(int a1,int b1);
//Main game loop
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
    printf("\t \t \t GL HF \n");
    printf("------------------------------------------------------------------\n");

    //all game variables initialization
    int count=25,x1=5,y1=5,c=5,d=5,ansx,ansy;
    char name[20];
    int exitcheck=1,gamecheck=1;

    //Input players name
    printf("enter your name ");
    fgets(name,20,stdin);
    //start gameloop
    while(exitcheck)
    {
      //initialize playerboard
      for(int g=0;g<5;g++)
      {
          for(int h=0;h<5;h++)
          {
              playerboard[g][h]='o';
          }
      }
      printf("\n   0  1  2  3  4 \n");
      for(int g=0;g<5;g++)
      {
          printf("%d ",g);
          for(int h=0;h<5;h++)
          {
              printf(" %c ",playerboard[g][h]);
            }
            printf("\n");
      }
      //Player chooses which tile to safeguard
      while(1)
      {
        printf("\n choose your tile to safeguard (y,x) \n");
        fflush(stdin);
        scanf("%d %d",&x1,&y1);
        if(x1<0||x1>4||y1<0||y1>4)
        {
            printf("\n invalid input \n");
        }
        else
        {
          gamecheck=1;
          srand(time(NULL));
          c = rand() % 5;
          d=rand() % 5;
          break;
        }
      }
      //Individual game loop
      while(gamecheck)
      {
          //print playerboard
          printf("   0  1  2  3  4 \n");
          for(int g=0;g<5;g++)
          {
            printf("%d ",g);
            for(int h=0;h<5;h++)
            {
              printf(" %c ",playerboard[g][h]);
            }
            printf("\n");
          }
          printf("\n Your move \n");
          //Player Guess
          while(1)
          {
            printf("Guess the location (y,x)");
            ansx=5,ansy=5;
            fflush(stdin);
            scanf("%d %d",&ansx,&ansy);
            if(ansx<0||ansx>4||ansy<0||ansy>4)
            {
              printf("\n invalid input \n");
            }
            else
              break;
          }
          if(ansx==c&&ansy==d)
          {
            //If player wins
            printf("\n Your score= %d \n",count);
            printf("\n YOU WIN !!!!!\n");
            gamecheck=0;
          }
          else
          {
            //Normal turn
            playerboard[ansx][ansy]='x';
            //AI turn
            int chk=ai(x1,y1);
            if (chk==1)
            {
              //If player loses
              printf("\n YOU LOSE !!!!! \n");
              printf("\nGET REKT M8\n");
              gamecheck=0;
            }
            count--;
          }
    }
    printf("=================================================");  
}
}


int ai(int a1,int b1)
{
    //code for AI turn
    printf("\n thinking... \n");
    int ai_c,ai_d;
    //initialize cpuboard
    for(int g=0;g<5;g++)
    {
        for(int h=0;h<5;h++)
        {
            if(cpuboard[g][h]=='|')
            {
                //to avoid reintializing guessed tiles
                continue;
            }
            cpuboard[g][h]='=';
        }
    }
    // AI loop
    while(1)
    {
      //cpu Guess
      srand(time(NULL));
      ai_c=rand()%5;ai_d=rand()%5;
      if(cpuboard[ai_c][ai_d]=='|')
      {
          continue;
      }
      else if(ai_c==a1&&ai_d==b1)
      {
          //If cpu guesses right
          printf("AI tile was %d %d",ai_c,ai_d);
          return 1;
      }
      else
      {
          cpuboard[ai_c][ai_d]='|';
      }
      printf("\n The A.I. move \n");
      printf("   0  1  2  3  4 \n");
      for(int g=0;g<5;g++)
      {
          printf("%d ",g);
          for(int h=0;h<5;h++)
          {
            printf(" %c ",cpuboard[g][h]);
          }
          printf("\n");
      }
      printf("\n");
      return 0;
    }
}
