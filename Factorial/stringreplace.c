#include <stdio.h>
#include <stdlib.h>

void replacer(char *str, int n){
	if(str == NULL || n < 1) return;
	int i, s=0;

	for(i=0; i<n; i++)
		if(str[i] == ' ') s++;

	if(s == 0) return;

	char *iStart, *iEnd;

	iStart = iEnd = malloc(sizeof(char) * (n + 2*s));

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

}

int main(){
	char str[] = "Mr John Smith    ";

	replacer(str, 13);

	printf("%s\n", str);

	return 0;
}


