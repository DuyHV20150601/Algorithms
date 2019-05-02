#include <stdio.h>
#include <stdlib.h>

bool mh[9][9];
bool mc[9][9];
bool mo[3][3][9];
int a[9][9];

void Init()
{
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j ++)
		{
			mh[i][j] = mc[i][j] = false;
		}
	}
	for( int i = 0 ; i < 3 ; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0 ; k < 9 ; k++)
				mo[i][j][k] = false;
}


bool check(int h, int c , int v)// kiem tra xem hang thu h cot c so v da co chua neu co roi thi return false
{
	if(mh[h][v]== true) return false;
	if(mc[c][v]== true) return false;
	if(mo[h/3][c/3][v]== true) return false;// kiem tra trong hinh vuong lon thu h/3 v/3 da co v chua? co thif return false
	return true; //chua co thi tra ve true
}

void solution()
{
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}

	exit(0);
}

void TRY(int h,int c)
{
	for(int v = 1 ; v <= 9 ; v++)
	{
		if(check(h,c,v)== true)//
		{
			a[h][c] = v;
			mh[h][v] = true;
			mc[c][v] = true;
			mo[h/3][c/3][v] = true;
			if(c == 8)
			{
				if(h == 8) solution();
				else TRY(h+1,0);
			}
			else
			{
				TRY(h,c+1);
			}
			mh[h][v] = false;
			mc[c][v] = false;
			mo[h/3][c/3][v] = false;
		}
	}
}

int main()
{
	Init();
	TRY(0,0);
	return 0;
}
