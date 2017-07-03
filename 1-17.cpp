#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct pos{
	int x;
	int y;
}POS, *PPOS;

int flag = 1;
int j = 0;

int ** init_maze(int row, int col){
	int ** p;
	int i;
	
	p = (int **)malloc(sizeof(int *) * row); 
	
	if (NULL == p) 
	{ 
   		exit(0);
	} 

	for (i = 0; i < row; i++) { 
   		*(p + i) = (int *)malloc(sizeof(int) * col); 
   		
		if (NULL == *(p + i)) { 
   			exit(0);
   		} 
	} 
	
	return p;
}

int set_maze(int ** maze, int row, int col){
	int i, j;
	
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			if(i == 0 || i == row-1 || j == 0 || j == col-1){
				maze[i][j] = -1;
			}
		}
	}
	
	for(i = 1; i < row-1; i++){
		for(j = 1; j < col-1; j++){
			scanf("%d", &maze[i][j]);
		}
	}
} 

int get_star_end(int ** maze, PPOS star, PPOS end, int row, int col){
	int i, j;
	
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++)
			if(maze[i][j] == 0){
				star->x = i;
				star->y = j;
			}else if(maze[i][j] == 2){
				end->x = i;
				end->y = j;
			}
	}
} 

int gogogo(int ** maze, PPOS star, PPOS end, PPOS t){
	PPOS next;
	next = (PPOS)malloc(sizeof(POS));
	POS dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int i;
	int val_x, val_y;
	
	for(i = 0; i <= 3; i++){
		if(flag){
			next->x = star->x + dir[i].x;
			next->y = star->y + dir[i].y;
		
			if(maze[next->x][next->y] == 1){
					val_x = next->x;
					val_y = next->y;
					t[j].x = val_x;
					t[j].y = val_y;
					j++;
					if(next->x != end->x || next->y != end->y){
						maze[next->x][next->y] = -1; 
						gogogo(maze, next, end, t);
					}else{
						printf("YES!");
						}	
					}else if(maze[next->x][next->y] == 2){
						flag = 0;
						break;
				}	
			}			
		}
	
	
	if(!flag){
		return j;
	}
	
	return 0;
	
}

int main(void){
	int m, n, sign, i;
	int ** maze;
	PPOS star, end;
	PPOS teml;

	
	scanf("%d%d", &n, &m);
	n += 2;
	m += 2;
	
	maze = init_maze(n, m);
	star = (PPOS)malloc(sizeof(POS));
	end = (PPOS)malloc(sizeof(POS));
	teml = (PPOS)malloc(sizeof(POS)*m*n);
	
	set_maze(maze, n, m);
	get_star_end(maze, star, end, n, m);
	sign = gogogo(maze, star, end, teml);
	
	if(!flag){
		printf("YES\n");
		printf("(%d,%d)->", star->x-1, star->y-1);
		for(i = 0; i < sign; i++){
			printf("(%d,%d)->", teml[i].x-1, teml[i].y-1);	
		}
		printf("(%d,%d)", end->x-1, end->y-1);
		
	}else{
		printf("NO");
	}

	free(maze);
	free(star);
	free(end);
	free(teml);
	
	return 0;
}
