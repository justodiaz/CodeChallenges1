#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 100
#define BOOST
//#define USEMALLOC
#define USESTATIC
//#define DEBUG


void _mergesort(int *arr, int *temp, int n){
	if(n<= 1) return;
	#ifdef BOOST
	if(n == 2){
		if(arr[0] < arr[1]) return;
		int temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
	#endif

	int mid = n/2;

	_mergesort(arr, temp, mid);
	_mergesort(arr+mid, temp, n%2 ? mid+1 : mid);

	int i,j,k;

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

}

void mergesort(int *arr, int n){
	int *temp = malloc(sizeof(int) * n);

	_mergesort(arr, temp, n);

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
	#if defined USEMALLOC
	int *arr = malloc(sizeof(int) * ARRSIZE);
	#elif defined USESTATIC
	static int arr[ARRSIZE];
	#else
	int arr[ARRSIZE]; //stack overflow with large arr sizes
	#endif

	#ifdef DEBUG
	printf("arr: %x\n", arr);
	printf("&arr: %x\n", &arr);
	printf("&arr[0]: %x\n", &arr[0]);
	printf("&arr[1]: %x\n", &arr[1]);
	#endif
	
	fillArr(arr, ARRSIZE, 100);

	printArr(arr, ARRSIZE);

	mergesort(arr, ARRSIZE);

	printArr(arr, ARRSIZE);

	return 0;
}
