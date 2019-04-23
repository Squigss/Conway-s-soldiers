#include "sold.h"

int main(int argc, char *argv[])
{
   static Parentchild Family[N];
   int num_children = 1;
   int dad=0;
   int child=0;
   int j, x, y;

   test_all();

   x = atoi(argv[1]);
   y = atoi(argv[2]);

   if (argc!=3 || (x<0 || x>=H) || (y<0 || y>=W)) {
      print_error_message();
   }

   else {
      create_board(Family[0].board);
      Family[0].parent=0;

         while(Family[child].board[x][y]!=POPULATED) {
            for(j=0; j<num_children; j++) {
               num_children = is_populated(Family, dad, child);
               child = child + num_children;
               dad++;
                  /*Check to ensure we do not go off the bounds of
                  the array FAMILY*/
                  if (child >= N) {
                     printf("Looks like we have run out of space.\n");
                     print_error_message();
                     return 1;
                  }
            }
         }
         solution_path(Family, child);
  }
   return EXIT_SUCCESS;
}


/*==========================================
CREATES THE VERY FIRST BOARD
===========================================*/
void create_board(int board[H][W])
{
   int i, j;

   for (i=0; i<H; i++) {
      for (j=0; j<W; j++) {
         if (i<H/2) {
            board[i][j]= EMPTY;
         }
         else {
            board[i][j]= POPULATED;
         }
      }
   }
}

/*======================================================
TAKES THE FATHER BOARD, CHECKS FOR EACH POPULATED CELL
WHETHER IT CAN MOVE OR NOT AND PRODUCES A CHILD FOR EACH
MOVE THAT SPECIFIC CELL CAN MAKE AND SAVING THAT CHILD
IN THE NEXT AVAILABLE CELL OF THE ARRAY FAMILY.
=======================================================*/
int is_populated(Parentchild Family[N], int dad, int child)
{
   int i, j;
   int children=0;

   for (i=0; i<H; i++) {
      for (j=0; j<W; j++) {
         if (Family[dad].board[i][j]==POPULATED) {

               if (can_go_up(Family[dad].board, i, j)==1) {
                  children++;
                  child++;
                  copy_boards(Family, dad, child);
                  move_up(Family[child].board, i, j);
                  Family[child].parent = dad;
               }

               if (can_go_right(Family[dad].board, i, j)==1) {
                  children++;
                  child++;
                  copy_boards(Family, dad, child);
                  move_right(Family[child].board, i, j);
                  Family[child].parent = dad;
               }

               if (can_go_left(Family[dad].board, i, j)==1) {
                  children++;
                  child++;
                  copy_boards(Family, dad, child);
                  move_left(Family[child].board, i, j);
                  Family[child].parent = dad;
               }
         }
      }
   }
   return children;
}

/*===============================================
3 FUNCTIONS TO CHECK WHETHER A CELL CAN MOVE OR NOT
=================================================*/
int can_go_up(int board[H][W], int i, int j)
{
   if ( ((i-1>0) && (i-2>=0)) &&
        (board[i][j]==POPULATED) &&
        (board[i-1][j]==POPULATED) &&
        (board[i-2][j]==EMPTY)) {
      return yes;
   }
   return no;
}

int can_go_right(int board[H][W], int i, int j)
{
   if ( ((j+1>W) && (j+2>=W)) &&
         (board[i][j]==POPULATED) &&
         (board[i][j+1]==POPULATED) &&
         (board[i][j+2]==EMPTY)) {
      return yes;
   }
   return no;
}

int can_go_left(int board[H][W], int i, int j)
{
   if ( ((j-1>0) && (j-2>=0)) &&
        (board[i][j]==POPULATED) &&
        (board[i][j-1]==POPULATED) &&
        (board[i][j-2]==EMPTY)) {
      return yes;
   }
   return no;
 }

 /*==========================================
 IF A CELL CAN MOVE THIS FUNCTION COPIES THE
BOARD INTO THE NEXT AVAILABLE CELL OF THE
ARRAY FAMILY SO THAT THE CELL CAN BE MOVED
WITHOUT ALTERING THE FATHER BOARD.
 ===========================================*/
 void copy_boards(Parentchild Family[N], int dad, int child)
 {
   int i, j;

   for (i=0; i<H; i++) {
     for (j=0; j<W; j++) {
       Family[child].board[i][j] = Family[dad].board[i][j];
     }
   }
 }

/*===============================================
MOVING FUNCTIONS
=================================================*/
void move_up(int board[H][W], int i, int j)
{
   board[i][j]=EMPTY;
   board[i-1][j]=EMPTY;
   board[i-2][j]=POPULATED;
}

void move_left(int board[H][W], int i, int j)
{
   board[i][j]=EMPTY;
   board[i][j-1]=EMPTY;
   board[i][j-2]=POPULATED;
}

void move_right(int board[H][W], int i, int j)
{
   board[i][j]=EMPTY;
   board[i][j+1]=EMPTY;
   board[i][j+2]=POPULATED;
}

/*=========================================
FINDS AND PRINTS OUT THE SOLUTION PATH
==========================================*/
void solution_path(Parentchild Family[N], int child)
{
   int papa=0;
   papa = Family[child].parent;

   printf("Solution found:\n");

   while(papa!=0) {
      printf("This board was generated from:\n"
             "board with parent index: %d\n\n"
              , Family[papa].parent);
      print(Family[papa].board);
      papa = Family[papa].parent;
   }
}

/*===============================================
PRINTING FUNCTION
=================================================*/
void print(int board[H][W])
{
   int i, j;

   for (i=0; i<H; i++) {
      for (j=0; j<W; j++) {
        if (board[i][j]==EMPTY) {
           printf(".");
        }
        else {
           printf("X");
        }
      }
      printf("\n");
   }
   printf("\n\n");
}

/*==================================================
MESSAGING TO PROVIDE FURTHER INFORMATION ON WHAT IS A
VALID COORINATE TO USERS.
======================================================*/
void print_error_message(void)
{
   printf("Please enter 2 integers to start the game.\n\n"
          "You need to select integers between 0 and 7\n"
          "for the height and 0 and 6 for the width.\n\n");
}
