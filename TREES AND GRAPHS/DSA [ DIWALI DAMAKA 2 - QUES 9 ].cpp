#include<iostream>
using namespace std;
void addRange(int track[],int l,int r)
{
	for(int i=l;i<r;i++)
	track[i]=1;
}
void deleteRange(int track[],int l,int r)
{
	for(int i=l;i<r;i++)
	track[i]=0;
}
bool searchRange(int track[],int l,int r)
{
	for(int i=l;i<r;i++)
	{
		if(!track[i])
		return false;
	}
	return true;
}
int main()
{
	int n,l,r;
	cout<<"Enter the upper bound (all the operations can be done in between 1 to n ) : ";
	cin>>n;
	int track[n]={0};
	char c='y';
	while(c=='y')
	{
		cout<<"Do you want to perform operations ? ";
		cin>>c;
		if(c=='y' || c=='Y')
		{
			cout<<"Enter the left limit of addition operation : ";
			cin>>l;
			cout<<"Enter the right limit of addition operation : ";
			cin>>r;
			addRange(track,l,r);
			cout<<endl<<"Enter the left limit of deletion operation : ";
			cin>>l;
			cout<<"Enter the right limit of deletion operation : ";
			cin>>r;
			deleteRange(track,l,r);
			cout<<endl<<"Enter the left limit of searching operation : ";
			cin>>l;
			cout<<"Enter the right limit of searching operation : ";
			cin>>r;
			bool t=searchRange(track,l,r);
			if(t)
			cout<<"Every number is being tracked."<<endl;
			else
			cout<<"Every number is not being tracked."<<endl;
		}
	}
	return 0;
}
