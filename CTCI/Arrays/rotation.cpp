#include <iostream>

using namespace std;
//time: worst O(n^2) best O(n) space: O(1)
bool isRotation(char *s1, char *s2){ 
	int n, n2, i, p1, p2;

	//get c string legnths if not given //O(2n)
	for(n=0; s1[n] != '\0'; n++){}
	for(n2=0; s2[n2] != '\0'; n2++){}

	if(n != n2) return false; //not same length

	bool done = false;
	for(i=0; i<n && !done; i++) //O(n^2)
		if(s2[i] == s1[0]){
			for(p1=1, p2=i+1; p2<n && s1[p1]==s2[p2]; p1++, p2++)
			{}
			if(p2 >= n) done = true; //substring complete and match
		}

	if(!done) return false; //no pivot character found

	for(p1=n-(i-1), p2=0; p1 < n; p1++, p2++)//O(n)
		if(s1[p1] != s2[p2]) return false;

	return true;
}

int main(){
	char *s1 = (char *) "waterwottle";
	char *s2 = (char *) "erwottlewat";
	
	cout << "rotations? " << (isRotation(s1, s2) ? "Yes" : "No") << endl;

	return 0;
}
	
