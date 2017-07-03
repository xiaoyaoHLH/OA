#include <stdio.h>
#include <malloc.h>

int binarysearch(int *arr, int len, int val){
	int low = 0;
	int high = len-1;
	int mid;
	
	while(low <= high){
		mid = (low + high) / 2;
		if(arr[mid] == val){
			return mid+1;
		}else if(val < arr[mid]){
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	
	return -1;
}

int main(void){
	int * arr;
	int n, i, val;
	int x;
	
	scanf("%d%d", &n, &val);
	
	arr = (int *)malloc(sizeof(int)*n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}	
	
	x = binarysearch(arr, n, val);
	
	printf("%d", x);
	
	return 0;
}


