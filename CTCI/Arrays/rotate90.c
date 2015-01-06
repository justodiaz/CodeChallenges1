#include <stdio.h>
#include <stdlib.h> //hello

#define N 3

void rotate90(int n, int img[][n]){ //time: O(2n^2) space: O(n^2)
	int *newImg = malloc(sizeof(int) * n*n);

	int i,j;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			*(newImg + n*j + (n-1-i)) = img[i][j];

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			img[i][j] = *(newImg + i*n + j);

	
}

void printImg(int n, int img[][n]){ //O(n^2)
	int i,j;

	for(i=0; i<n; i++){
		printf("| ");
		for(j=0; j<n-1; j++)
			printf("%d ", img[i][j]);
		
		printf("%d |\n", img[i][j]);
	}
}
	

int main(){
	int n =3;
	int img[][3] = { {1,2,3}, {4,5,6} ,{7,8,9} };
	
	printImg(n, img);
	printf("\n");

	rotate90(n, img);

	printImg(n, img);
	printf("\n");

	return 0;
}


	
