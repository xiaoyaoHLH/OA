#include <stdio.h>
#define MaxSize 5

typedef int MazeType[MaxSize][MaxSize];

struct PosType{
	int x;
	int y;
};

struct PosType end;
MazeType m;
int col, row;

void Print(int row, int col){
	int i, j;
	
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++)
			printf("%3d", m[i][j]);
		printf("\n");
	}
		
	printf("\n");
}

void Try(struct PosType cur, int curstep){
	struct PosType next;
	int i;
	
	struct PosType direc[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	
	for(i = 0; i <= 3; i++){
		next.x = cur.x + direc[i].x;
		next.y = cur.y + direc[i].y;
		
		if(m[next.x][next.y] == 0){
			m[next.x][next.y] = ++curstep;
			
			if(next.x != end.x || next.y != end.y){
				Try(next, curstep);
			}else
				Print(row, col);
			
		m[next.x][next.y] = 0;
		curstep--;
			
		}		
	}
}


int main(void){
	struct PosType cur;
	
	
	
	return 0;
}
