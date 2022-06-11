#include <stdio.h>
#define N 4

int check(int x, int y, int *pattern, int p);

int puzzle[N][N];

int main(void)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%d", &puzzle[i][j]);
		}
	}
	printf("no of elements to search:\n");
	int p; scanf("%d", &p);
	printf("Pattern to look for:\n");
	int pattern[p];
	for(int i=0; i<p; i++)
	{	
		scanf("%d", &pattern[i]);
	}

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			int a = check(i, j, &pattern[0], p); 
			if(a)
			{
				printf("at (%d, %d) going ", j+1, i+1);
				switch (a)
				{
					case 1 : printf("up\n"); break;
					case 2 : printf("right\n"); break;
					case 3 : printf("down\n"); break;
					case 4 : printf("left\n"); break;
				}	
				return 0;
			}
		}
	}
	printf("no matches\n");	
}



int check(int y, int x, int *pattern, int p)
{
	if(*pattern == puzzle[y][x])
	{
		int c = p-1;
		for(int i=1 ;(i < p) && (x-i >= 0) && (puzzle[y][x-i] == *(pattern+i)); i++){c--;}
		if(!c){return 4;}
		c = p-1;
		for(int i=1 ;(i < p) && (x+i < N) && (puzzle[y][x+i] == *(pattern+i)); i++){c--;}
		if(!c){return 2;}
		c = p-1;
		for(int i=1 ;(i < p) && (y-i >= 0) && (puzzle[y-i][x] == *(pattern+i)); i++){c--;}
		if(!c){return 1;}
		c = p-1;
		for(int i=1 ;(i < p) && (y+i < N) && (puzzle[y+i][x] == *(pattern+i)); i++){c--;}
		if(!c){return 3;}
		return 0;
	}
	return 0;
}