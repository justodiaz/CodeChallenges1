#include <stdio.h>

typedef enum{NONE, ROW, COL} Skip;

void mark(int row, int col, int m, int n, int matrix[][n], Skip skip){
	matrix[row][col] = -1;

	int x,y;

	if(skip != ROW)
		for(x=0; x < n; x++){
			if(matrix[row][x] == 0)
				mark(row,x,m,n,matrix,ROW);
			else
				matrix[row][x] = -1;
		}

	if(skip != COL)
		for(y=row-1; y >= 0; y--){
			if(matrix[y][col] == 0){
				mark(y,col,m,n,matrix, BOTTOM);
				break; //stop marking
			}
			else
				matrix[y][col] = -1;
		}

	if(skip != RIGHT)
		for(x=col+1; x < n; x++){
			if(matrix[row][x] == 0){
				mark(row,x,m,n,matrix, LEFT);
				break; //stop marking
			}
			else
				matrix[row][x] = -1;
		}

	if(skip != BOTTOM)
		for(y=row+1; y < m; y++){
			if(matrix[y][col] == 0){
				mark(y,col,m,n,matrix, TOP);
				break; //stop marking
			}
			else
				matrix[y][col] = -1;
		}
