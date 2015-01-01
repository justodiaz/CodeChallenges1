//flawed can't use FLAG for integer matrix;
#include <stdio.h>

#define FLAG -1

typedef enum{NONE, ROW, COL} Skip;

void mark(int row, int col, int m, int n, int matrix[][n], Skip skip){
	matrix[row][col] = FLAG;

	int i;

	if(skip != ROW)
		for(i=0; i < n; i++){
			if(matrix[row][i] == 0)
				mark(row,i,m,n,matrix,ROW);
			else
				matrix[row][i] = FLAG;
		}

	if(skip != COL)
		for(i=0; i < m; i++){
			if(matrix[i][col] == 0)
				mark(i,col,m,n,matrix,COL);
			else
				matrix[i][col] = FLAG;
		}
}

void transform(int m, int n, int matrix[][n]){ //O(3mn)
	int i,j;
	for(i=0; i < m; i++)
		for(j=0; j < n; j++)
			if(matrix[i][j] == 0){
				mark(i,j,m,n,matrix,NONE);
				break; //skip search for 0's on this row
			}

	for(i=0; i < m; i++)
		for(j=0; j < n; j++)
			if(matrix[i][j] == FLAG){
				matrix[i][j] = 0;
			}
}

void printImg(int m, int n, int img[][n]){ //O(mn)
	int i,j;

	for(i=0; i<m; i++){
		printf("| ");
		for(j=0; j<n-1; j++)
			printf("%d ", img[i][j]);
		
		printf("%d |\n", img[i][j]);
	}
}

int main(){
	int m=6,n=6;
	int matrix[6][6] = { {1,0,1,1,0,1}, 
			     {1,1,1,1,1,1},
			     {0,1,1,1,1,1},
			     {1,1,1,1,0,1},
			     {1,1,1,1,1,1},
			     {1,1,1,1,1,0} };

	printImg(m, n, matrix);
	printf("\n");

	transform(m,n, matrix);

	printImg(m, n, matrix);
	printf("\n");

	return 0;
}



