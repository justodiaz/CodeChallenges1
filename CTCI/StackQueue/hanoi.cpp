#include <iostream>

using namespace std;

void hanoi(int n, int s, int t, int d){
	if(n<=0){
		cout << "N disks must be a positive integer." << endl;
		return;
	}

	if(n==1){
		cout << s << " to " << d << endl;
		return;
	}

	hanoi(n-1, s, d, t);
	hanoi(1, s, t, d);
	hanoi(n-1, t, s, d);
}

int main(){

	hanoi(3, 1, 2, 3);

	return 0;
}
