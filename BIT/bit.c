#include <stdio.h>

int read(int idx, int* BIT);
int create(int n, int* f, int* BIT);
int update(int index, int new, int old, int size, int* BIT);
void printarr(int* BIT, int n);

int main(void)
{
	printf("Enter Number: ");
	int n;scanf("%d", &n);
	int f[n];	
	for(int i=0; i<n; i++)
	{	
		scanf("%d", &f[i]);
	}
		
	int BIT[n+1];
	if(create(n, &f[0], &BIT[0]))
	{
		printf("----Sucessfully created\n\n");
	}

	int choice,exit=0, index;
	do
	{
		printf("\n\n----Choose an option: \n");
		printf("0: Get the sum\n");
		printf("1: Update the array\n");
		printf("2: Print the Arrays\n");
		printf("3: Exit\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 3: 
				exit =1;
				break;
			case 0:
				printf("\nIndex:");
				scanf("%d", &index);
				printf("sum = %d\n", read(index, &BIT[0]));
				break;
			case 1:
				printf("Select index to change: ");
				scanf("%d", &index);
				int new;
				printf("New value: ");	
				scanf("%d", &new);
				if(update(index, new, f[index], n,&BIT[0]))
				{
					printf("\n\n----Sucessfully updated\n\n");
				}
				f[index] = new;
				break;
			case 2:
				printf("Array:\n");
				printarr(&f[0], n);
				printf("Binary index tree:\n");
				printarr(&BIT[0], n+1);
				break;
			default: 
				printf("----Invaid choice\n");
		}
		if(exit)
		{break;}
	
	}while(1);
}


int create(int n, int* f, int* BIT)
{
	BIT[0] = 0;
	for(int i=1; i<n; i++)
	{
		int sum=0;
		for(int j=i-(i&-i)+1; j<=i; j++)
		{
			sum += f[j-1];	
		}
		BIT[i] = sum;
	}	
	return 1;
}

int update(int index, int new, int old, int size, int* BIT)
{
	int diff = new - old;
	if(!index)
	{
		index++;
	}
	for(int i=index; i<=size; i+=(i&-i))
	{
		BIT[i] += diff;
	}
	return 1;
}

int read(int idx, int* BIT)
{
	int sum;
	idx ? sum=0 : (sum=BIT[1]);
	if(!idx)
	{
		return sum;
	}
	for(int i=idx+1; i>0; i-=(i&-i))
	{
		sum+=BIT[i];
	}
	return sum;
}

void printarr(int* BIT, int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%d ", BIT[i]);
	}
	printf("\n");
}