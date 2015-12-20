#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>

int compute2(int *v, int n){
	if (n < 1) {
		std::cout << "Error, less than 1 length" << std::endl;
		return -1;
	}

	int profit[n+1][n+1];
	
	int i,j;

	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			profit[i][j] = -1;


	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if (j == 1 && i == 1) profit[1][1] = v[0];
			else if(j < i) profit[i][j] = 0;
			else if(i == 1)
			profit[i][j] = std::max(v[j-1], profit[1][j-1]);
			else
			profit[i][j] = std::max(v[j-1] + profit[i-1][j-(i-1)], profit[i][j-1]);
		}
	/*
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++)
			std::cout << profit[i][j] << ", ";

		std::cout << std::endl;
	}*/
	int m = 0;
	for (i = 1; i <= n; i++)
		if (profit[i][n] > m) m = profit[i][n];

	return m;
}
int compute(int* v, int n){
	if (n < 1) {
		std::cout << "Error, less than 1 length" << std::endl;
		return -1;
	}
	int profit[n+1][n+1];

	int i,j;

	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			profit[i][j] = -1;

	for(i = n; i>=1; i--)
		for(j=n;j>=1; j--){
			if(j < i) 
				profit[i][j] = 0;
			else if(j == n) 
				profit[i][j] = v[n-1];
			else if(i+j > n) 
				profit[i][j] = std::max(v[j-1], profit[i][j+1]);
			else
				profit[i][j] = std::max(v[j-1] + profit[i+1][i+j], profit[i][j+1]);
				
		}

	return profit[1][1];

	/*
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++)
			std::cout << profit[i][j] << ", ";

		std::cout << std::endl;
	}
	*/

	/*
	bool done = false;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j < i) continue;

			if(j == n){
				std::cout << j <<", ";
				done = true;
				break;
			}
			else{
				if(i+j > n){
					if(v[j-1] > profit[i][j+1]){
						std::cout << j <<", ";
						done = true;
						break;
					}
				}
				else{
					if(v[j-1] + profit[i+1][i+j] > profit[i][j+1]){
						std::cout << j <<", ";
						i = i+1;
						j = i+j - 1;
					}
				}
			}


		}

		if(done) break;
	}

	std::cout << std::endl;
	*/
}

void dumpArr(int *arr, int n){
	for(int i=0;i<n;i++)
		std::cout << arr[i] << ", " ;

	std::cout << std::endl;
}
int main(){
	srand(time(NULL));	

	int arr[10];

	for(int i =0;i<10;i++) arr[i] = rand() %50 + 1;

	dumpArr(arr,sizeof(arr)/sizeof(arr[0]));

	int n = sizeof(arr) / sizeof(arr[0]);
	if (compute2(arr, n) == compute(arr, n))
		std::cout << "Match!" << std::endl;
	else
		std::cout << "No Match!" << std::endl;

}
