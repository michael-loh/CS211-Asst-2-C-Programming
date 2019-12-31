#include <stdio.h>
#include <stdlib.h>




int main(int argc, char**argv){

	if(argc != 3){
		return EXIT_FAILURE;
	}
	char* c = argv[1];
	int n = atoi(c);

	FILE* fp = fopen(argv[2], "r");

	//loop index
	int i;
	int j;
	int z;

//======FILLING OUT BOARD=========
	int h;
	int w; 
	fscanf(fp, "%d", &h);
	fscanf(fp, "%d", &w);

	char board[h][w];

	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			char buffer;
			fscanf(fp, " %c", &buffer);
			board[i][j] = buffer;
		}
	}

	int board2[h][w];		
//======TRANSFORMING BOARD===========================================
	for(z = 0; z < n; z++){
		for(i = 0; i < h; i++){
			
			for(j = 0; j < w; j++){
				//making board2 all '.'
				board2[i][j] = '.';
				
				int count = 0;
//==============================DECLARING DIRECTIONS=====================
				int up = i - 1;
				int down = i + 1;;
				int left = j - 1;
				int right = j + 1;
				if(up < 0){
					up = h - 1;
				}
				if(down >= h){
					down = 0;
				}
				if(left < 0){
					left = w - 1;
				}
				if(right >= w){
					right = 0;
				}


//==============================IF INDEX IS '.'========================
				if(board[i][j] == '.'){
					if(board[up][left] == '*'){
						count++;
					}
					if(board[up][j] == '*'){
						count++;
					}
					if(board[up][right] == '*'){
						count++;
					}
					if(board[i][right] == '*'){
						count++;
					}
					if(board[down][right] == '*'){
						count++;
					}
					if(board[down][j] == '*'){
						count++;
					}
					if(board[down][left] == '*'){
						count++;
					}
					if(board[i][left] == '*'){
						count++;
					}
					
					if(count == 3){
						board2[i][j] = '*';
					}
				}
//==============================IF INDEX IS '*'=========================
				else if(board[i][j] == '*'){
					if(board[up][left] == '*'){
						count++;
					}
					if(board[up][j] == '*')
						count++;
					if(board[up][right] == '*')
						count++;
					if(board[i][right] == '*')
						count++;
					if(board[down][right] == '*')
						count++;
					if(board[down][j] == '*')
						count++;
					if(board[down][left] == '*')
						count++;
					if(board[i][left] == '*')
						count++;
					
					if(count >=2 && count <=3){
						board2[i][j] = '*';
					}
				}
				count = 0;
			}
			
		}
		
//===============COPY BOARD2 TO BOARD=================================
		for(i = 0; i < h; i++){
			for(j = 0; j < w; j++){
				board[i][j] = board2[i][j];
			}
		}
	}


//======PRINT OUT BOARD===============================================
	
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			printf("%c", board[i][j]);
		}
		printf("\n");

	}
	return 0;
}
