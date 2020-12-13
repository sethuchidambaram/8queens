/*
 * main.c
 *
 *  Created on: Dec 1, 2019
 *      Author: sethu
 */

#include<stdio.h>

#define	BOARDSIZE	4

int qpos[BOARDSIZE]={ [0 ... BOARDSIZE-1]=-1};
int column[BOARDSIZE]={ [0 ... BOARDSIZE-1]=-1};
int leftdiag[2*BOARDSIZE-1]={[0 ...  2*BOARDSIZE-2]=-1};
int rightdiag[2*BOARDSIZE-1]={[0 ... 2*BOARDSIZE-2]=-1};

void setchess(int row,int column);
void print();
void backtrack(int *row,int *column);
void setq(int i,int j);
void freeq(int i,int j);
int iscfree(int j);
int isldfree(int i,int j);
int isrdfree(int i,int j);

int countprint=0;


int main()
{
	printf("Hello\n");
	setchess(BOARDSIZE, BOARDSIZE);
	printf("Hello\n");
	return 0;
}

void setchess(int row,int column)
{
	int i=0;
	int j=0;

	while(i >=0)
	{
		while(i>=0 && i < row)
		{
			while(j < column)
			{
				if(iscfree(j) && isldfree(i,j) && isrdfree(i,j))
				{
					setq(i,j);
					j=0;
					break;
				}
				else
				{
					j++;
				}

			}
			if( j == column )
			{
				backtrack(&i,&j);
				j++;
				continue;
			}
			i++;
		}
		//if(i>=0 && i<row)
		{
		// print the solution....
			countprint++;
			print();
			backtrack(&i,&j);
			j++;
		}
		//else
			//break;
	}
	printf("Total Solution: %d\n",countprint);

}

void print()
{
	int i;
	printf("Solution %d: ", countprint);
	for(i=0; i<BOARDSIZE; i++)
		printf("(%d, %d),  ", i, qpos[i]);

	printf("\n");

}

void backtrack(int *row,int *column)
{
	*row = *row-1;
	*column=qpos[*row];

	freeq(*row, *column);
}

void freeq(int i,int j)
{
	column[j]=-1;
	leftdiag[i-j+BOARDSIZE-1]=-1;
	rightdiag[i+j]=-1;

	qpos[i] = -1;
}

void setq(int i,int j)
{
	column[j]=i;
	leftdiag[i-j+BOARDSIZE-1]=1;
	rightdiag[i+j]=1;

	qpos[i]=j;
}

int iscfree(int j)
{
	return column[j] == -1;

}
int isldfree(int i,int j)
{
	return leftdiag[i-j+BOARDSIZE-1] == -1;

}
int isrdfree(int i,int j)
{
	return rightdiag[i+j] == -1;

}
