#include <stdio.h>
#include <stdlib.h>

void replacer2(char *str, int n){ //time: O(2n) space: O(1)
	if(str == NULL || n < 1) return;

	int i, s;

	//Number of chars to replace
	for(i=0, s=0; i<n; i++)
		if(str[i] == ' ') s++;

	if(s == 0) return;

	int right;

	for(i = n-1, right = n + 2*s; i >= 0; i--){
		if(str[i] == ' '){
			str[right-1] = '0';
			str[right-2] = '2';
			str[right-3] = '%';

			right -= 3;
		}
		else{
			str[right-1] = str[i];
			right -= 1;
		}

	}
}



void replacer(char *str, int n){//time: O(3n+2s) space: O(n+2s)
	if(str == NULL || n < 1) return;
	int i, s=0;

	for(i=0; i<n; i++)
		if(str[i] == ' ') s++;

	if(s == 0) return;

	char *iStart, *iEnd, *iFree;

	iFree = iStart = iEnd = malloc(sizeof(char) * (n + 2*s));

	for(i=0; i<n; i++){
		if(str[i] == ' '){
			iEnd[0] = '%';
			iEnd[1] = '2';
			iEnd[2] = '0';
			iEnd += 3;
		}
		else{
			iEnd[0] = str[i];
			iEnd++;
		}
	}

	for(;iStart < iEnd; iStart++, str++)
		*str = *iStart;

	free(iFree);

}

int main(){
	char str1[] = "Mr John Smith    ";//n = 13
	char str2[] = "               "; //n = 5 (length of 5)

	replacer2(str1, 13);

	printf("%s\n", str1);

	return 0;
}


