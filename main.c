//
//  main.c
//  Khan_Z_P2
//
//  Created by Zubair Khan on 3/31/16.
//  Copyright © 2016 Zubair Khan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int rows = 0;
int col = 0;
int comp_mem = 0;
int max_rand;
int seed;
int j;
int i = 0;
int k = 0;
int **board;
int num_pairs;
int *rand_values;
int max_limit_k = 0;
int **xorno;
int turn = 0;
int gameover = 0;
int row_user1 = 0;
int row_user2 = 0;
int col_user1 = 0;
int col_user2 = 0;
int row_comp1 = 0;
int row_comp2 = 0;
int col_comp1 = 0;
int col_comp2 = 0;
int round_num = 0;
int user_score = 0;
int comp_score = 0;

typedef struct cards {
    int x;
    int y;
    int value;
    int match;
} Cards;

void printBoard (int rows, int col, int**board, int**xorno) {
    int i;
    int j;
    for (i = 0; i<rows; i++) {
        for (j = 0; j<col; j++) {
            if (xorno[i][j]==-1) {
            printf("row position: %d  col position: %d   value: X \n",i, j);
            }
            else if(xorno[i][j]==-2) {
            printf("row position: %d  col position: %d   value: %d \n",i, j, board[i][j]);
            }
            else {
            printf("row position: %d  col position: %d   value:  \n",i, j);
            }
        }
    }
}

void check_memory (Cards *comp_deck, int **board, rows, col, row_user, col_user, comp_mem) {
    int i = 0;
    
    for (i = 0; i<comp_mem; i++) {
        if (comp_deck[i].value==board[row_user][col_user]) {
            printf("value matches. a matching card in memory exists at %d %d", comp_deck[i].x, comp_deck[i].y );
        }
    }
    
    
    return;
}

void add_memory (Cards *comp_deck, int **board, rows, col, row_user, col_user, comp_mem) {
    int i = 0;
    
    for (i = 0; i<comp_mem; i++) {
        if (comp_deck[i].value==board[row_user][col_user]) {
            printf("value matches. a matching card in memory exists at %d %d", comp_deck[i].x, comp_deck[i].y );
        }
    }
    
    
    return;
}

int main(int argc, const char * argv[]) {
    
    do {

    printf("Please enter the size of the game board (e.g. 3x6): \n");
    scanf("%dx%d", &rows, &col);
    printf("Please select the level of the game (0-9): \n");
    scanf("%d", &comp_mem);
    printf("Please enter the largest card value (1-99): \n");
    scanf("%d", &max_rand);
    printf("Please enter the seed of the random number generator (0-9999): \n");
    scanf("%d", &seed);
        
    } while (((rows+col)>2) && (comp_mem> -1) && (comp_mem < 10) && (max_rand>0) && (max_rand<100) && (seed>-1) && (seed<10000));
    
    
    num_pairs = (rows*col)/2;
    printf("Num of pairs: %d \n", num_pairs);
    
    Cards *comp_deck = calloc(sizeof(Cards), comp_mem);
    
            comp_deck[i].y = k;
            comp_deck[i].x = j;
            comp_deck[i].value = rand()%max_rand;
    //make this into a function
    //everytime computer has memory available after human
    //flips or after computer flips
    //then enter values into comp_deck of
    //coordinates x and coordinates y and value

    
    if ((rand_values = (int*)malloc(num_pairs*sizeof(int)+1)) == NULL) {
        printf("No memory");
        exit(0);
    }
    
    srand(seed);
    if ((board = (int**)malloc(rows*sizeof(int*))) == NULL) {   //allocate memory for rows of board and safety check
        printf("No memory");
        exit(0);
    }
    
    for(i = 0; i<col; i++) {
    
        if ((board[i] = (int *)malloc(col * sizeof(int))) == NULL) {  //allocate memory for col of board and safety check
            printf("No memory");
            exit(0);
        }
        
    }

    if ((xorno = (int**)malloc(rows*sizeof(int*))) == NULL) {   //allocate memory for rows of board and safety check
        printf("No memory");
        exit(0);
    }
    
    for(i = 0; i<col; i++) {
        
        if ((xorno[i] = (int *)malloc(col * sizeof(int))) == NULL) {  //allocate memory for col of board and safety check
            printf("No memory");
            exit(0);
        }
        
    }
    
    //set every element position as -1 orginally and start the initial board placement
    //for half the board, then place the random values stored in rand_values into position
    //containing -1 as -1 is a value that cannot be generated in the game
    //generate num_pair amount of random values into the first num_pair amount of cards
    //then do nested for loop and check every rand%i+1 and every rand%j+1 if there is a value
    //greater than zero. if so then do NOT overwrite value. if value is less than zero then
    //overwrite value with rand_value[k]
    
    for (i = 0; i<rows; i++) {
        for (j = 0; j<col; j++) {
            board[i][j] = -1;
            xorno[i][j] = -1;
        }
    }
    
    printf("\n");
    
    k = 0;
    while (k<num_pairs) {
    for (i = 0; i<rows; i++) {
        for (j = 0; j<col; j++) {
            board[i][j] = rand()%max_rand+1;
            rand_values[k] = board[i][j];
            k++;
            if (k>num_pairs) {
                break;
            }
        }
        if (k>num_pairs) {
            break;
        }
    }
    }
    
    for (i = 0; i<rows; i++) {
        for (j = 0; j<col; j++) {
            printf("row position: %d  col position: %d   value: %d \n",i, j, board[i][j]);
        }
    }
    
    printf("k = %d \n \n", k);
    
    max_limit_k = 2 * num_pairs;
    k = 0;
    int counter;
    while (k <= num_pairs ) {
        i = rand()%rows;
        j = rand()%col;
        counter++;
        printf("i = %d j = %d \n", i, j);
        printf("board[i][j] =  %d \n", board[i][j]);
        if (board[i][j]==-1) {
            board[i][j] = rand_values[k];
            k++;
        }
        if (counter > 100000) { //prevents it going into an infinite loop
            break;
        }
     //printf("k = %d \n \n", k);
        
    }
  
   /* for (i = 0; i<rows; i++) {
        for (j = 0; j<col; j++) {
            printf("row position: %d  col position: %d   value: %d \n",i, j, board[i][j]);
        }
    } */
    
    
    
    //Board is now filled!
    
    //big while (gameover != 1)
    //print board with Xs (if xorno[i][j] is -1 then print 'X'
    //if (turn%2) = 0 then print board and ask human for input row_user1, col_user1
    //flip over card and print board (change xorno[row_user1][col_user1] to -2)
    //ask for human input again input row_user2, col_user2
    //flip over card and print board (change xorno[row_user2][col_user2] to -2)
    //if board[row_user1][col_user1] == board[row_user2][col_user2] then
    //change xorno[row_user1][col_user1] and xorno[row_user2][col_user2] to 0
    //else != then store board[row_user1][col_user1] and board[row_user2][col_user2]
    //to comp_deck if space is available
    //turn++
    //if (turn%2) then computer checks comp_deck and plays that card

    
    printBoard(rows, col, board, xorno);
    
    while (gameover != 1) {
        
        if (turn%2==0){
            round_num++;
            printf("Please enter the two coordinates of the card you want to \n");
            scanf("%dx%d", &row_user1, &col_user1);
            xorno[row_user1][col_user1] = -2;
            printBoard(rows, col, board, xorno);
            //add this card to comp_mem if possible
            
            printf("Round[%d] Please enter the two coordinates of the card you want \n", round_num);
            scanf("%dx%d", &row_user2, &col_user2);
            xorno[row_user2][col_user2] = -2;
            printBoard(rows, col, board, xorno);
            
            //add this card to comp_mem if possible
            if (board[row_user1][col_user1] == board[row_user2][col_user2]) {
                user_score++;
                xorno[row_user1][col_user1] = 0;
                xorno[row_user2][col_user2] = 0;
                turn++;
                //delete these cards from comp_mem
            }
            else {
                turn++;
                xorno[row_user1][col_user1] = -1;
                xorno[row_user2][col_user2] = -1;
            }
            
        }
        else if (turn%2!=0) {
            printf("It's now the computer's turn...\n \n");
            //start using a value from comp_deck if one exists
            //otherwise select a random location
            row_comp1 = rand()%rows;
            col_comp1 = rand()%col;
            
            xorno[row_comp1][col_comp1] = -2;
            printBoard(rows, col, board, xorno);
            printf("\n");
            
            //check comp_deck if board[row_comp1][col_comp1] == anything form comp_deck
            //if not then use random location
            
            row_comp2 = rand()%rows;
            col_comp2 = rand()%col;
            
            xorno[row_comp2][col_comp2] = -2;
            printBoard(rows, col, board, xorno);
            printf("\n");
            
                if (board[row_comp1][col_comp1] == board[row_comp2][col_comp2]) {
                    comp_score++;
                    xorno[row_comp1][col_comp1] = 0;
                    xorno[row_comp2][col_comp2] = 0;
                    turn++;
                    //delete these cards from comp_mem
                }
                else {
                    turn++;
                    xorno[row_comp1][col_comp1] = -1;
                    xorno[row_comp2][col_comp2] = -1;
                }

        }
        //check if all pairs have been matched

        
    }
    
    
    
    
    

    
    /* for ( i = 0; i<(rows*col); i++) {
        for (j = 0; j < rows; j++) {
        deck[i].x = j;
            for (k = 0; k < col; k++) {
                    deck[i].y = k;
            }
        deck[i].value = rand()%max_rand;
        }
    }*/
    
  /*  for (i = 0; i < (rows*col); i++) {
        printf("Card[%d] x position: %d  y position: %d   value: %d \n",i, deck[i].x,deck[i].y, deck[i].value);
    } */
    
 //   Cards *memory = calloc(sizeof(Cards), comp_mem);
    
  /*  cards = (int**)malloc(rows*sizeof(int*));
   
    for (i = 0; i < rows; i++) {
        cards[i] = (int*)malloc(col*sizeof(int));
    }

    for(i = 0; i < rows; i++) {
        for(j = 0; j < col; j++) {
         cards[rows][col] = 0;
        }
    }
    
    for (i=rows-1; i>=0; i--)
    { for (j=col-1; j>=0; j--) {
        printf("%2d", cards[i][j]);
        printf("\n");
    }
    }  */

    //struct card *cards = calloc(sizeof(cards), (rows*col));
    
    
    /* gnerate row*col / 2 amount of random values*/
   /* struct cards card1;
    card1.value = rand()%max_rand; */
    
    
    
    return 0;
}
