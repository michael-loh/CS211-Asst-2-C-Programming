#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
	
	if(argc != 2){
		return EXIT_FAILURE;
	}

	FILE* ptr = fopen(argv[1], "r");

	int k;
	fscanf(ptr, "%d", &k);

//======BUILD MATRIX=================================
	int matrix[k][k];
	int copy[k][k];
	int i;
	int j;
	for(i = 0; i < k; i++){
		
		for(j = 0; j < k; j++){
			fscanf(ptr, "%d", &matrix[i][j]);
			copy[i][j] = matrix[i][j];
		}
		
	}

	int n;
	fscanf(ptr, "%d", &n);
	
	int product[k][k];
	int count;

	for(count = 1; count < n; count++){
		
//==============MATRIX MULTIPLICATION======================
		for(i = 0; i < k; i++){
			
			for(j = 0; j < k; j++){
				int z;
				product[i][j] = 0;
				for(z = 0; z < k; z++){
					product[i][j] += matrix[i][z]*copy[z][j]; 
				}  
			}

		}

//==============RESETTING MATRICES FOR REPEATED MULTIPLICATIONS===============
		for(i = 0;i < k; i++){
			for(j = 0; j < k; j++){
				matrix[i][j] = product[i][j];
			}
		}

	}

//======IF N = 0, PRINT IDENTITY MATRIX====================================
	if(n == 0){
		for(i = 0; i < k; i++){
			for(j = 0; j < k; j++){
				if(i == j){
					matrix[i][j] = 1;	
				}
				else{
					matrix[i][j] = 0;
				}
			}
		
		}
	}



//======PRINT OUT MATRIX==========================================
	for(i = 0; i < k; i++){

		for(j = 0; j < k; j++){
			printf("%d",matrix[i][j]);
			if(!(k-1 == j)){
				printf(" ");
			} 
		}
		printf("\n");
	}

	
	return 0;
}



















