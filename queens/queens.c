#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSafe(char board[8][8], int i, int j){
	
	int row;
	int col;
//======CHECK UP AND LEFT==================
	row = i-1;
	col = j-1;
	while(row >= 0 && col >= 0){
		if(board[row][col] == 'Q'){
			return 0;
		}
		row--;
		col--;	
	}
//======CHECK UP===========================
	row = i-1;
	col = j;
	while(row >= 0){
		if(board[row][col] == 'Q'){
			return 0;
		}
		row--;	
	}
//======CHECK UP AND RIGHT=================
	row = i-1;
	col = j+1;
	while(row >= 0 && col < 8){
		if(board[row][col] == 'Q'){
			return 0;
		}
		row--;
		col++;
	}
//======CHECK RIGHT========================
	row = i;
	col = j+1;
	while(col < 8){
		if(board[row][col] == 'Q'){
			return 0;
		}
		col++;
	}
//======CHECK DOWN AND RIGHT================
	row = i+1;
	col = j+1;
	while(row < 8 && col < 8){
		if(board[row][col] == 'Q'){
			return 0;
		}
		row++;
		col++;
	}
//======CHECK DOWN==========================
	row = i+1;
	col = j;
	while(row < 8){
		if(board[row][col] == 'Q'){
			return 0;
		}
		row++;
	}
//======CHECK DOWN AND LEFT=================
	row = i + 1;
	col = j - 1;
	while(row < 8 && col >= 0){
		if(board[row][col] == 'Q'){
			return 0;
		}
		row++;
		col--;
	}
//======CHECK LEFT=========================
	row = i;
	col = j-1;
	while(col >= 0){
		if(board[row][col] == 'Q'){
			return 0;
		}
		col--;	
	}


	return 1;

}



int main(int argc, char**argv){

	if(!(argc > 1 && argc < 4)){
		return EXIT_FAILURE;
	}

	
	
	//checking if +2 is an arg
	int plusTwo;
	plusTwo = 0;
	if(argc == 3 || argc == 4){
		if(strcmp(argv[1], "+2") == 0){
			plusTwo = 1;
		}
		if(strcmp(argv[2], "+2") == 0){
			plusTwo = 1;
		}
	}

	FILE* fp = fopen(argv[argc-1], "r");

	//index variables
	int i;
	int j;


//======FILL OUT BOARD===================
	char board[8][8];
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			char buffer;
			fscanf(fp, " %c", &buffer);
			board[i][j] = buffer;
		}
	}
	
//======CHECK IF BOARD IS VALID=============

	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			if(board[i][j] == 'Q'){
				int valid = isSafe(board, i, j);
				if(valid == 0){
					printf("Invalid\n");
					return 0;
				}
			}
		}
	}
	
//======FIND WHERE QUEEN CAN BE PLACED=====
	char board2[8][8];
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			if(board[i][j] != 'Q'){
				int valid2 = isSafe(board, i, j);
				if(valid2 == 0){
					board2[i][j] = '.';
				}
				if(valid2 == 1){
					board2[i][j] = 'q';
				}				
				
			}
			else{
				board2[i][j] = 'Q';
			}
		}
	}

//======PRINT BOARD==========================

	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			printf("%c", board2[i][j]);
		}
		printf("\n");
	}
	
	if(plusTwo == 1){
//======PLUS TWO SECTION======================
		int qCount = 0;
		int a;
		int b;
		for(i = 0; i < 8; i++){
			for(j = 0; j < 8; j++){
				if(board2[i][j] == 'q'){
					qCount++;

//==============================CHECKING FOR A SECOND VALID QUEEN================
					board2[i][j] = 'Q';
					for(a = 0; a < 8; a++){
						for(b = 0; b < 8; b++){
							if(board2[i][j] != 'Q'){
								int valid2 = isSafe(board2, a, b);
								if(valid2 == 1){
									printf("Two or more\n");
									return 0;
								}
							} 
						}	
					}
					board2[i][j] = 'q';
				}
			}
		}
		if(qCount > 0){
			printf("One\n");
			return 0;
		}
	
		printf("Zero\n");
	}
	return 0;

}
















