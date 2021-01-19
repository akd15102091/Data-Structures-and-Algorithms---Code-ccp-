#include<iostream>
using namespace std;

void PERCULATE_UP(int H[] , int n , int key)
{
	H[n] = key ;
	int j = n ;
	while(H[j] < H[(j-1)/2]  && j>0)
	{
		int temp = H[(j-1)/2] ;
		H[(j-1)/2] = H[j] ;
		H[j] = temp ;
		j=(j-1)/2 ;
	}
}

void PERCULATE_DOWN( int H[] ,int  &n)
{
	int val = H[0] ;
	H[0] = H[n-1] ;
	n = n-1 ;
	int j = 0 ;
	while((H[j] > H[1+2*j]  ||  H[j] > H[2+2*j] ) && (1+2*j)<n)
	{
		if(H[j] > H[1+2*j]  &&  H[j] > H[2+2*j])
		{
			if(H[1+2*j] > H[2+2*j])
			{
				int temp = H[j] ;
				H[j] =  H[2+2*j] ;
				H[2+2*j] = temp ;
				j =  2+2*j ;
			}
			else if(H[1+2*j] < H[2+2*j])
			{
				int temp = H[j] ;
				H[j] =  H[1+2*j] ;
				H[1+2*j] = temp ;
				j = 1+2*j ;
			}
		}
		else
		{
			if(H[j] > H[2+2*j])
			{
				int temp = H[j] ;
				H[j] =  H[2+2*j] ;
				H[2+2*j] = temp ;
				j =  2+2*j ;	
			}
			else if(H[1+2*j] < H[j])
			{
				int temp = H[j] ;
				H[j] =  H[1+2*j] ;
				H[1+2*j] = temp ;
				j = 1+2*j ;
			}
		}
	}
	
	cout<< val<<" " ;
}
int main()
{	
	int n ,key;
	int H[50] ;
	cout<<"Enter the n "<<endl;
	cin>>n;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>> key ;
		//cin>>H[i] ;
		PERCULATE_UP( H , i ,key) ;
	}
	 // 10   2 5 8 15 25 70 10 20 30 40 
/*	cout<<"ENter the value to insert"<<endl;
	cin>> key ;
	PERCULATE_UP( H , n++ ,key) ;*/
//	cout<<"New heap is "<<endl ;
   // PERCULATE_DOWN( H , n) ;
   int k = n ;
	for(int i=0 ;i<k ;i++)
	{
	 PERCULATE_DOWN( H , n) ;
	//	cout<< H[i] <<" ";
	}
	
/*	PERCULATE_DOWN( H , n) ;
	for(int i=0 ;i<n;i++)
	{
		cout<<H[i] <<" " ;
	} */
	return 0 ;
}
