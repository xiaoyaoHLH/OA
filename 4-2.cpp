#include <stdio.h>

int num = 0;
int convert(char *s, int i){
	if(s[i] == '\0'){
		return num;
	}else{
		num = num*10+(s[i] - '0');
		i++;
		convert(s, i);
	}
}

int main(void){
	char ch[100];
	
	gets(ch);
	
	printf("%d", convert(ch, 0));
	
	return 0;
}
