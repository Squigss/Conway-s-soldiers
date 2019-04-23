#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define H 8 /*H refers to HEIGHT*/
#define W 7 /*W refers to WIDTH*/
#define EMPTY 0
#define POPULATED 1
#define N 5000000

struct Parent_Child {
  int board[H][W];
  int parent;
};
typedef struct Parent_Child Parentchild;

enum is_populated_or_not {no, yes};
typedef enum is_populated_or_not yes_no;

/*=======================================
PROTOTYPES
=========================================*/
void create_board(int board[H][W]);
int is_populated(Parentchild Family[N], int dad, int child);
int can_go_up(int board[H][W], int i, int j);
int can_go_right(int board[H][W], int i, int j);
int can_go_left(int board[H][W], int i, int j);
void copy_boards(Parentchild Family[N], int dad, int child);
void move_up(int board[H][W], int i, int j);
void move_left(int board[H][W], int i, int j);
void move_right(int board[H][W], int i, int j);
void solution_path(Parentchild Family[N], int child);
void print(int board[H][W]);
void print_error_message(void);

/*testing prototypes!*/
void test_all(void);
void test_soldiers_moves(void);
void test_is_populated_function(void);
