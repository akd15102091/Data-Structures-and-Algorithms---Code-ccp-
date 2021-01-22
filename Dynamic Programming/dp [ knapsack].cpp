#include<iostream>
using namespace std;
int knapsack(int val[],int weight[],int cap,int n)
{
 int dp[n+1][cap+1];
 for(int i=0;i<=cap;i++)
 {
 	dp[0][i]=0;
 }
 for(int i=1;i<=n;i++)
 {
 dp[i][0]=0;	
 }
 for(int i=1;i<=n;i++)
 {
 	for(int j=1;j<=cap;j++)
 	{
 		if(weight[i-1]>j)
 		{
 			dp[i][j]=dp[i-1][j];
		 }
		 else
		 {
		 	dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+val[i-1]);
		 }
		// cout<<dp[i][j]<<" ";
	 }
	 for(int i=0;i<=n;i++)
 	{
 	for(int j=0;j<=cap;j++)
 	{
 		
		 cout<<dp[i][j]<<" ";
	 }
	 cout<<endl;
}
	 
	 
 }
 return dp[n][cap];	
}
int main()
{
	int n;
	cout<<"enter total number of items: ";
	cin>>n;
	int capacity,val[n],weight[n];
	cout<<"enter value and weight of a item: ";
	for(int i=0;i<n;i++)
	{
		cin>>val[i]>>weight[i];
	}
	cout<<"enter capacity: ";
	cin>>capacity;
int ans=knapsack(val,weight,capacity,n);
	cout<<ans;
}
