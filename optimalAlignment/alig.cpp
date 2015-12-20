#include <iostream>
#include <algorithm>

static int mismatch[6][6] = {	{0,1,1,2,1,0 },
			{2,0,3,3,1,0 },
			{5,1,0,4,2,0 },
			{4,4,2,0,2,0 },
			{2,2,1,1,-1,-1 },
			{0,0,0,0,-1,0}};

void dumpArr(int arr[][10], int row, int col)
{
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			std::cout << arr[i][j] << ",  ";
		
		std::cout << std::endl;
	}
}

int penalty(char x, char y){
	int i=0,j=0;
	switch(x){
		case 'A':
			i = 0; break;
		case 'C':
			i = 1; break;
		case 'T':
			i = 2; break;
		case 'G':
			i = 3; break;
		case '-':
			i = 4; break;
		case '?':
			i = 5; break;
		default:
			std::cout << "Error index: " << x << std::endl;
	}

	switch(y){
		case 'A':
			j = 0; break;
		case 'C':
			j = 1; break;
		case 'T':
			j = 2; break;
		case 'G':
			j = 3; break;
		case '-':
			j = 4; break;
		case '?':
			j = 5; break;
		default:
			std::cout << "Error index: " << y << std::endl;
	}

	if((i==4 && j==5) || (i==5 && j==4) || (i==4 && j==4))
		std::cout <<"error bad mismatch" << std::endl;

	return mismatch[i][j];
}

int main(){
	char* seq1 = "?AT?TAACA";
	char* seq2 = "?TTACC";

	int arr[7][10];

	for(int i=0;i<7;i++)
		for(int j=0;j<10;j++)
			arr[i][j] = 0;

	int i, j;

	for(i=1;i<10 && seq1[i-1] != '?';i++)
		arr[0][i] = penalty(seq1[i-1], '-') + arr[0][i-1];

	while (i < 10) {
		arr[0][i] = 100;
		i++;
	}

	for(i=1;i<7 && seq2[i-1] != '?';i++)
		arr[i][0] = penalty('-', seq2[i-1]) + arr[i-1][0];
	
	while (i < 7) {
		arr[i][0] = 100;
		i++;
	}



	for(i=1;i<7;i++)
		for(j=1;j<10;j++){
			if (seq1[j - 1] == '?' && seq2[i - 1] == '?')
				arr[i][j] = arr[i - 1][j - 1];
			else if (seq1[j - 1] == '?')
				arr[i][j] = std::min(arr[i - 1][j - 1], penalty('-', seq2[i - 1]) + arr[i - 1][j]);
			else if (seq2[i - 1] == '?')
				arr[i][j] = std::min(arr[i - 1][j - 1], penalty(seq1[j-1], '-') + arr[i][j-1]);
			else
			arr[i][j] = std::min(std::min(penalty(seq1[j-1],seq2[i-1]) + arr[i-1][j-1],
						penalty(seq1[j-1],'-') + arr[i][j-1]),
						penalty('-',seq2[i-1]) + arr[i-1][j]);
		}

	dumpArr(arr,7,10);

}
