#include<iostream>
#include<cstdlib>
using namespace std;
struct mlnode
{
	int data;
	struct mlnode *next ; 
	struct mlnode *dlink ;
};
typedef struct mlnode *mlptr;
mlptr create(int x)
{
	mlptr T = NULL ;
	T->data = x ;
	T->next = NULL ;
	T->dlink = NULL ;
	return T ;
}
int traverse(mlptr ml ,int a[] ,int n )
{
	if(ml->dlink == NULL && ml->next == NULL)
	{
		
		for(int i=0;i<n;i++)
		{
			cout<<a[i] <<" ";
		}
		return n;
	}
	
	a[n]= ml->data ;
	
	if(ml->dlink) 
	{
		traverse(ml->dlink , a ,n+1 ) ;
	}
	if(ml->next)
	{
		traverse(ml->next ,a ,n+1 ) ;
	}
	
}
int main()
{
	mlptr ml = NULL ;
	ml =new struct mlnode;
	ml = create(3) ;
	ml->next = create(7) ;
	ml->next->next = create(10) ;
	ml->next->next->next = create(36) ;
	ml->dlink =create(8);
	ml->dlink->dlink = create(15) ; 
	ml->next->dlink=create(12) ;
	ml->next->dlink->dlink =create(45) ;
	ml->next->next->dlink=create(18) ;
	ml->next->next->dlink->dlink=create(72) ;
	int a[50]  ;
	
   int x=  traverse(ml , a ,0 ) ;	
    for(int i=0;i<x;i++)
    {
    	cout<<a[i]<<" ";
	}
	return 0;
}
