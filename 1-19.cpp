#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node{
	int data;
	struct node * pNext;
}NODE, *PNODE;

typedef struct snode{
	char data;
	struct node * pNext;
}STRING, *PSTRING;

int priority[7][7] = {3, 3, 1, 1, 1, 3, 3,
					  3, 3, 1, 1, 1, 3, 3,
					  3, 3, 3, 3, 1, 3,	3,
				      3, 3, 3, 3, 1, 3,	3,
					  1, 1, 1, 1, 1, 2, 2,
					  3, 3, 3, 3, 0, 3, 3,
					  1, 1, 1, 1, 1, 0, 2
					}; 


PNODE init_list(void){
	PNODE top;
	top = NULL;
	
	return top;
}

int is_empty(PNODE top){
	if(top == NULL){
		return 1;
	}
	
	return 0;
}

PNODE push(PNODE top, int val){
	PNODE p;
	
	p = (PNODE)malloc(sizeof(NODE));
	
	if(p == NULL){
		printf("·ÖÅäÊ§°Ü");
		exit(-1);
	}
	
	p->data = val;
	
	p->pNext = top;
	top = p;
	
	return top;
}

PNODE pop(PNODE top, int * elem){
	PNODE t;
	
	if(is_empty(top)){
		printf("Õ»¿Õ");
		exit(-1);
	}
	
	t = top;
	*elem = top->data;
	top = top->pNext;
	free(t);
	
	return top;
}

int get_top(PNODE top){
	if(is_empty(top)){
		printf("Õ»¿Õ");
		exit(-1);
	}
	
	return top->data;
}

int sub(int c){
	switch(c){
		case '+':
			return 0;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 3;
		case '(':
			return 4;
		case ')':
			return 5;
		case '#':
			return 6;
		case '\0':
			return 6;
	}
}

int main(void){
	int x1, x2, i, j, op, t;
	char ch[100];
	int count = 0;
	PNODE string, num;
	
	string = push(string, '#');
	
	gets(ch);
	if(ch[0]=='-') {
		num = push(num, 0);
	}
	
	while(!(ch[count] == '\0' && get_top(string) == '\0')){
		if(ch[count] == '+' || ch[count] == '-' || ch[count] == '*' || ch[count] == '/' || ch[count] == '(' || ch[count] == ')' || ch[count] == '\0'){
			i = sub(get_top(string));
			j = sub(ch[count]);
			
			if(priority[i][j] == 3){
				string = pop(string, &op);
				num = pop(num, &x2);
				num = pop(num, &x1);
				
				switch(op){
					case '+':
						num = push(num, x1+x2);
						break;
					case '-':
						num = push(num, x1-x2);
						break;
					case '*':
						num = push(num, x1*x2);
						break;
					case '/':
						num = push(num, x1/x2);
						break;
				}
				
			if(ch[count] == '\0' && (get_top(string)) == '#'){
					break;
				}				
			continue;
			}
			
			if(priority[i][j] == 1){
				string = push(string, ch[count]);
			}
			
			if(priority[i][j] == 2){
				string = pop(string, &t);
			}			
		}else{
			num = push(num, ch[count]-48);
		}
		
		
		count++;
	}		
	
	printf("%d", get_top(num));
	
	return 0;	
}


