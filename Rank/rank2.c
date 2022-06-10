#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float **entries;
	int row;
	int clmn;
}Matrix;

void build_Matrix(Matrix *matrix);
void print_Matrix(Matrix *matrix);
void row_divide(Matrix *matrix, float divider, int r_num);
void row_add(Matrix *matrix, int r_adder, int r_adding, float r_scaler);
void freemat(Matrix *matrix);
int min(int a, int b);

int main(int argc, char** argv)
{
	Matrix *A = malloc(sizeof(Matrix)); 
	A->row = atoi(argv[1]);A->clmn = atoi(argv[2]);
	build_Matrix(A);
	
	for(int i=0; i<min(A->clmn, A->row); i++)
	{
		int zero_row = 1,adder;
		for(int j=0; j<(A->clmn); j++)
		{
			if(*(*(A->entries+i)+j))
			{
				zero_row &= 0; adder = j;
				row_divide(A, *(*(A->entries+i)+j), i);
				break;
			}
		}

		if(zero_row)
		{
			continue;
		}

		for(int j=0; j<(A->row); j++)
		{
			if(i-j)
			{
				row_add(A, j, adder, -*(*(A->entries+j)+adder));
			}
		}
	}
	print_Matrix(A);
	freemat(A);
}

int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}

void row_divide(Matrix *matrix, float divider, int r_num)
{
	for(int i=0; i<(matrix->clmn); i++)
	{
		*(*(matrix->entries+r_num)+i) /= divider;
	}
}

void row_add(Matrix *matrix, int r_adder, int r_adding, float r_scaler)
{
	for(int i=0; i<(matrix->clmn); i++)
	{
		*(*(matrix->entries+r_adder)+i) += *(*(matrix->entries+r_adding)+i) * r_scaler;
	}
}
void build_Matrix(Matrix *matrix)
{
	matrix->entries = malloc(matrix->row * sizeof(float*));
	for(int i=0; i<(matrix->row); i++)
	{
		*((matrix->entries)+i) = malloc(matrix->clmn * sizeof(float));
	}

	for(int i=0; i<(matrix->row); i++)
	{		
		for(int j=0; j<(matrix->clmn); j++)
		{
			scanf("%f", *((matrix->entries)+i)+j);
		}
	}	
}

void print_Matrix(Matrix *matrix)
{
	printf("\n\nRow Reduced form:\n-----------------\n");
	for(int i=0; i<matrix->row; i++)
	{		
		for(int j=0; j<matrix->clmn; j++)
		{
			printf("%.2f ", *(*((matrix->entries)+i)+j));
		}
		printf("\n");	
	}
}

void freemat(Matrix *matrix)
{
	for(int i=0; i<(matrix->row); i++)
	{
		free(*(matrix->entries+i));
	}
	free(matrix->entries);	
}