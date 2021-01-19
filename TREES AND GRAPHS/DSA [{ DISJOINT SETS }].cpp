#include<iostream>
using namespace std;
int S[10];
void Union(int i,int j)
{
	if(S[i]==j)
	cout<<"This input is not possible.";
	else
	{
		if(S[i]<=0 && S[j]==0)
		--S[i];
		if(S[j]==0)
		{
			S[j]=i;
			return;
		}
		else if(S[j]<0)
		{
			if(S[i]>0)
			Union(S[i],j);
			else
			{
				int d=S[j];
				S[j]=i;
				S[i]+=d;
			}
		}
		else
		Union(i,S[j]);
	}
}
int Find(int i)
{
	if(S[i]==0)
	return i;
	else
	return Find(S[i]);
}

int main()
{
	int n,x,y;
	cout<<"Enter no. of queries : ";
	cin>>n;
	for(int i=1;i<=9;i++)
	S[i]=0;
	cout<<"Enter queries : "<<endl;
	for(int i=0;i<n;i++)
	{
	cout<<"Enter query1 and query2 : ";
	cin>>x>>y;
	Union(x,y);
	}
	while(x!=0 && y!=0)
	{
		cout<<"Enter 2 numbers : ";
		cin>>x>>y;
		if(x!=0 && y!=0)
		{
		x=Find(x);
		y=Find(y);
		if(x==y)
		cout<<"Both elements belong to same set."<<endl;
		else
		cout<<"Both elements belong to different set."<<endl;
		}
	}
	for(int i=1;i<=9;i++)
	{
		cout<<S[i]<<" ";
	}
	cout<<"For joining purpose , enter 2 elements : ";
	cin>>x>>y;
	Union(x,y);
	cout<<"Enter :";
	cin>>x>>y;
	x=Find(x);
	y=Find(y);
	if(x==y)
	cout<<"Both elements belong to same set."<<endl;
	else
	cout<<"Both elements belong to different set."<<endl;
	return 0;
}

