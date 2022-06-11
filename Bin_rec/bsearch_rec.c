#include <stdio.h>
#include <stdlib.h>

int foo;
int binary(int* bar, int baz);

int main(int argc, char* argv[])
{		
	int n=atoi(argv[1]);
	int a[n];
	for(int i=0; i<n; i++)	
	{
		scanf("%d", &a[i]);
	}
	foo = atoi(argv[2]);
	
	int result = binary(&a[0], n);
	if(result == -1)
	{
		printf("Not found\n");
	}
	else
	{
		printf("Found at %dth\n", result);
	}
}

int binary(int* bar, int baz)
{
	static int index;int mvindex;
	mvindex = (baz-1)/2;
	if(*(bar+mvindex) == foo)
	{
		index += mvindex;
		return index;
	}
	if((baz == 1)&&(foo != *(bar+mvindex)))
	{
		return -1;
	}
	if(foo > *(bar+mvindex))
	{
		bar += mvindex+1; 
		index += mvindex+1;
		return binary(bar, baz-mvindex-1);	
	}
	else if(foo < *(bar+mvindex))
	{
		return binary(bar, mvindex);
	}
	return 0;
}


/*
Classical approach

int main(void)
{
	int n=6;
	int a[] = {1,2,4,9,10,17};
	scanf("%d", &foo);

	int low=0,high=5,mid;
	
	
	while(low<=high)
	{
		mid = (low+high)/2;
		if(a[mid] > foo)
		{
			high = mid-1;
		}
		else if (a[mid] < foo)
		{
			low = mid+1;
		}
		else
		{
			printf("found\n");
			return 0;
		}	
	}
		
}
*/