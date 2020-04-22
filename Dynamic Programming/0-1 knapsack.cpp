//https://www.includehelp.com/icp/0-1-knapsack-algorithm.aspx

#include<stdio.h> 

int max(int a, int b) { 
	return (a > b)? a : b; 
} 

int knapsack(int W, int w[], int V[], int n) 
{ 
	int i, j; 
	int T[n+1][W+1]; 

	for (i = 0; i <= n; i++) 
	{ 
		for (j = 0; j <= W; j++) 
		{ 
			if (i==0 || j==0) 
				T[i][j] = 0; 
			else if (w[i-1] <= j) 
				T[i][j] = max(V[i-1] + T[i-1][j-w[i-1]],  T[i-1][j]); 
			else
				T[i][j] = T[i-1][j]; 
		} 
	}

	printf("DP table T[i,j] : \n");
	for(i=0;i<=n;i++)
	{ 
		printf("i=%d\t",i);
		for(j=0;j<=W;j++)
		{
			printf("%d\t",T[i][j]);
		}
		printf("\n");
	} 
	printf("\n");
	
	printf("The weights that contribute to the result: ");
	int temp=W;
	for(i=n;i>0 && temp>0;--i)
	{
		if(T[i][temp]==T[i-1][temp])continue;
		else 
		{
			printf("%d ",w[i-1]);
			temp-=w[i-1];
		}
	}
	printf("\n\n");
	return T[n][W]; 
} 

int main() 
{
	int wt[] = {1, 3, 4, 5};  
	int val[] = {1, 4, 5, 7};    
	int W = 7; 
	int n = 4;
	int Max;

	printf("details of all items : \n");
	printf("Value\\Profit\tWeight\t\n");
	for (int i = 0; i < n; i++) 
	{ 
		printf("%d\t\t%d\n",val[i],wt[i]);
	}

	printf("\n");
	Max = knapsack(W, wt, val, n); 
	printf("Maximum profit we can obtain = %d\n\n", Max); 
	return 0; 
} 
