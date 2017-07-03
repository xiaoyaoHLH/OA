#include <stdio.h>

int main(void){
	long long x, y, t, i;
	long long val = 1;
	long long p = 1000000007;
	
	scanf("%lld%lld", &x, &y);
	x %= p;
	
	while(y > 0){						//a*b mod c = (a mod c * b mod c) mod c; 
		if(y % 2 == 1){					//Ææ( (a^2)^(b/2)*a ) mod c
			val = (val * x) % p;
		}
			
		y = y / 2;						//Å¼ (a^2)^(b/2) mod c 
		x = (x * x) % p;
		
	}
	
	printf("%lld", val);
	
	return 0;
}
