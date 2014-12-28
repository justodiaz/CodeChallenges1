#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 15

void mergesort(int *arr, int n){
	if(n<= 1) return;
	if(n == 2){
		if(arr[0] < arr[1]) return;
		int temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}

	int mid = n/2;

	mergesort(arr, mid);
	mergesort(arr+mid, n%2 ? mid+1 : mid);

	int i,j,k;
	int *temp = malloc(sizeof(int) * n);

	for(i=0, j=mid, k=0; k<n ; k++){
		if(i < mid && (j >= n || arr[i] < arr[j]) ){
			temp[k] = arr[i];
			i++;
		}
		else{
			temp[k] = arr[j];
			j++;
		}
	}

	for(i=0; i<n; i++)
		arr[i] = temp[i];

	free(temp);

}

void printArr(int *arr, int n){
	int i;

	printf("{");
	for(i=0; i<n-1; i++)
		printf("%d, ", arr[i]);
	printf("%d}\n", arr[i]);

}

void fillArr(int *arr, int n, int max){
	srand(time(NULL));

	int i;
	for(i=0;i<n;i++)
		arr[i] = rand() % (max+1);
}
	

int main(int argc, char *argv[]){
	int arr[ARRSIZE];
	
	fillArr(arr, ARRSIZE, 100);

	printArr(arr, ARRSIZE);

	mergesort(arr, ARRSIZE);

	printArr(arr, ARRSIZE);

	return 0;
}
