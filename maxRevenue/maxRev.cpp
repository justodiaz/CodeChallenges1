#include <iostream>
#include <algorithm>

int maxRev(int *x, int *s, int n){
	int i,case1,case2;

	int v[n];
	int c = 1;

	v[0] = std::min(x[0],s[0]);
	for(i=1;i<n;i++){
		case1 = std::min(x[i],s[c]) + v[i-1];

		if(i==1) case2  = std::min(x[i],s[0]);
		else
		case2 = std::min(x[i],s[0]) + v[i-2];

		v[i] = std::max(case1,case2);

		if(case2 > case1) {
			std::cout << "We rebooted on day" << i << std::endl;
			c = 0;
		}

		c++;
	}

	return v[n-1];
}

int main(){
	int x[] = {15,15,15,15,15};
	int s[] = {10,4,3,2,1};
	
	int n = sizeof(x)/sizeof(x[0]);

	std::cout << "Optimal: " << maxRev(x,s,n) << std::endl;
}
