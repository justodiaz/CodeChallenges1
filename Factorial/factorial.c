#include <stdio.h>
#include <stdlib.h>

unsigned long long permute(unsigned long long n){
	if(n == 1)
		return 1;
	
	return n * permute(n-1);
}

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Usage: %s <int>\n", argv[0]);
		exit(0);
	}

	printf("%d! = %llu", atoi(argv[1]), permute(atoi(argv[1])));

	return 0;
}


