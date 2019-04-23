#include "sold.h"

void test_all(void)
{
  test_soldiers_moves();
  test_is_populated_function();
}

void test_soldiers_moves(void)
{
  int board[H][W];
  if ((can_go_up(board, 2, 0)==1) &&
     (can_go_up(board, 1, 0)==1) &&
     (can_go_up(board, 0, 0)==0)) {
  assert(can_go_up(board, 2, 0)==0);
  assert(can_go_up(board, 1, 0)==0);
  assert(can_go_up(board, 0, 0)==1);
  }

  if ((can_go_up(board, 5, 0)==1) &&
     (can_go_up(board, 4, 0)==1) &&
     (can_go_up(board, 3, 0)==0)) {
  assert(can_go_up(board, 5, 0)==0);
  assert(can_go_up(board, 4, 0)==0);
  assert(can_go_up(board, 3, 0)==1);
  }

  if ((can_go_up(board, 6, 1)==1) &&
     (can_go_up(board, 5, 1)==0) &&
     (can_go_up(board, 4, 1)==1)) {
  assert(can_go_up(board, 6, 1)==1);
  assert(can_go_up(board, 5, 1)==0);
  assert(can_go_up(board, 4, 1)==1);
  }

  assert(can_go_up(board, -1, 10)==0);
  assert(can_go_left(board, -1, 10)==0);
  assert(can_go_right(board, -1, 10)==0);

  if ((can_go_right(board, 6, 1)==1) &&
     (can_go_right(board, 6, 2)==1) &&
     (can_go_right(board, 6, 3)==0)) {
  assert(can_go_right(board, 6, 1)==0);
  assert(can_go_right(board, 6, 2)==0);
  assert(can_go_right(board, 6, 3)==1);
  }

  if ((can_go_right(board, 3, 1)==1) &&
     (can_go_right(board, 3, 2)==1) &&
     (can_go_right(board, 3, 3)==0)) {
  assert(can_go_right(board, 3, 1)==0);
  assert(can_go_right(board, 3, 2)==0);
  assert(can_go_right(board, 3, 3)==1);
  }

  if ((can_go_right(board, 3, 1)==1) &&
     (can_go_right(board, 3, 2)==0) &&
     (can_go_right(board, 3, 3)==1)) {
  assert(can_go_right(board, 3, 1)==1);
  assert(can_go_right(board, 3, 2)==0);
  assert(can_go_right(board, 3, 3)==1);
  }

  if ((can_go_left(board, 3, 3)==1) &&
     (can_go_left(board, 3, 2)==1) &&
     (can_go_left(board, 3, 1)==0)) {
  assert(can_go_left(board, 3, 3)==0);
  assert(can_go_left(board, 3, 2)==0);
  assert(can_go_left(board, 3, 1)==1);
  }

  if ((can_go_left(board, 2, 3)==1) &&
     (can_go_left(board, 2, 2)==1) &&
     (can_go_left(board, 2, 1)==0)) {
  assert(can_go_left(board, 2, 3)==0);
  assert(can_go_left(board, 2, 2)==0);
  assert(can_go_left(board, 2, 1)==1);
  }

  if ((can_go_left(board, 3, 3)==1) &&
     (can_go_left(board, 3, 2)==0) &&
     (can_go_left(board, 3, 1)==1)) {
  assert(can_go_left(board, 3, 3)==1);
  assert(can_go_left(board, 3, 2)==0);
  assert(can_go_left(board, 3, 1)==1);
  }
}

void test_is_populated_function(void)
{
  Parentchild Family[10];
  assert(is_populated(Family, 1, 3)>=0);
}


/*==========================================
TEST TO SEE THAT FUNCTIONS ARE MOVING
SOLDIERS PROPERLY (HERE IT IS THE RIGHT
ONE THAT IS BEING TESTED AS I KNEW THERE
WAS A PROBLEM SPECIFICALLY IN THAT FUNCTION)
==========================================
int can_go_right(int board[H][W], int i, int j);
void move_right(int board[H][W], int i, int j);

int main (void)
{
  int i, j;
  int move;

  int board[H][W]= {
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 1, 0, 0},
                    {0, 0, 1, 1, 0, 0, 0},
                    {1, 1, 1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1, 1, 1}
                  };


   for (i=0; i<H; i++) {
     for (j=0; j<W; j++) {
       move = can_go_right(board, i, j);
          if (move==1) {
             move_right(board, i, j);
          }
      }
    }

    for (i=0; i<H; i++) {
      for (j=0; j<W; j++) {
        printf("%d", board[i][j]);
      }
      printf("\n");
    }


  return 0;
}

int can_go_right(int board[H][W], int i, int j)
{

     if ( (board[i][j]==POPULATED) &&
             (board[i][j+1]==POPULATED) &&
             (board[i][j+2]==EMPTY) &&
              ((j+1<=W) || (j+2<W)) ) {
              return 1;
     }
       return 0;
}

void move_right(int board[H][W], int i, int j)
{
  board[i][j]=EMPTY;
  board[i][j+1]=EMPTY;
  board[i][j+2]=POPULATED;
}*/
