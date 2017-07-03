#include <stdio.h>
#include <malloc.h>

int Max(int max, int * a, int k, int len){
	if(k == len){
		return max;
	}else{
			
		if(max < a[k]){
			max = a[k];
		}
		
		k++;
		Max(max, a, k, len);
		
	}

}

int Sum(int sum, int * a, int k, int len){
	if(k == len){
		return sum;
	}else{
		sum += a[k];
		k++;
		Sum(sum, a, k, len);		
	}
}

int Avg(int sum, int * a, int k, int len){
	if(k == len){
		return sum/len;
	}else{
		sum += a[k];
		k++;
		Avg(sum, a, k, len);		
	}
}


int main(void){
	int len, i;
	int * p;
	scanf("%d", &len);
	p = (int*)malloc(sizeof(int)*len);
	
	for(i = 0; i < len; i++){
		scanf("%d", &p[i]);
	}
	
	printf("%d\n%d\n%d\n", Max(p[0], p, 0, len), Sum(0, p, 0, len), Avg(0, p, 0, len));
	
	free(p);
	
	return 0;
} 
