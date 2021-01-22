#include<iostream>
using namespace std ;

int MATRIX_MULTIPLICATION_ORDER(int P[],int n)
{
	int m[n+1][n+1]  ; ///m[1][1] to m[n][n]
	//int l=n ;
	for(int i=1;i<=n;i++)
	{
		m[i][i] = 0;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=(n-l+1);i++)
		{
			int j = i+l-1 ;
			m[i][j] = INT_MAX;
			for(int k=i;k<j;k++)
			{
				int t = m[i][k]+m[k+1][j] +( (P[i-1])*(P[k])*(P[j]) ) ;
				if(m[i][j] > t)
				{
					m[i][j]=t ;
				}
			}
		}
	}
	return m[1][n] ;
}

int main()
{
	//A1.A2.A3........An    matrix chain multiplication
	//   A1 - (P0*P1), A2 -(P1*P2) ,..........order of matrix
	int n;
	cout<<"Enter the number of matrix : "<<endl;
	cin>>n;
	int P[n+1] ;
	cout<<"Enter order like    P0,P1,P2,P3,........,Pn  : "<<endl;
	for(int i=0;i<=n;i++)
	{
		cin>>P[i] ;
	}
	int x = MATRIX_MULTIPLICATION_ORDER(P,n) ;
	cout<<"Minimum required scaler multiplication : "<<x<<endl;
}
