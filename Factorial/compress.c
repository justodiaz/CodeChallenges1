#include <stdio.h>
#include <stdlib.h>
//#define one
//#define two

int countdigits(unsigned num){
	int n = 1;
	while( (num /= 10) > 0)
		n++;

	return n;
}

void compress(char *str){ //time: O(3n) space: O(n)
	if(str == NULL) return;

	int i, grps, digits, count;
	char c;

	for(i=0, grps=0, digits=0, count=0, c = str[i]; ; i++){
		if(str[i] == c){
			count++;
		}
		else{
			grps++;
			digits += countdigits(count);
			if(str[i] == '\0') break;

			count = 0;
			c = str[i];
		}

	}

	int size = i;
	int newSize = grps + digits;

	if(newSize >= size) return;

	int k;
	char *temp = malloc(sizeof(char) * newSize);

	for(i=0, k=0; ; i++){
		if(str[i] == c){
			count++;
		}
		else{
			temp[k] = c;
			k += (1 + sprintf(temp + 1 + k,"%d", count));

			if(i >= size) break;

			count = 0;
			c = str[i];
		}
	}

	for(i=0; i< newSize; i++)
		str[i] = temp[i];

	str[i] = '\0';

	free(temp);

}

int main(){
	#if defined one
	char str[] = "aabcccccaaa";
	#elif defined two
	char str[] = "abc";
	#else
	char str[] = "aabbbcc";
	#endif

	compress(str);

	printf("%s\n", str);

	return 0;
}
