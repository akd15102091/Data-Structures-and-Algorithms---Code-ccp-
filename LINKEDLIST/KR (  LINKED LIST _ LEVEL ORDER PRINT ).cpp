#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next ;
	struct node *dlink ;
};
typedef struct node *mlptr ;

mlptr createnode(int data)
{
		mlptr T = NULL ;
		T = new struct node ;
		T->data = data ;
		T->next = NULL ;
		T->dlink = NULL ;
		return T ;
}
void printlist(int dist , mlptr head , int j=0)
{
	if(head == NULL) return ;
	else
	{
		if(j==dist) cout<< head->data <<" " ;
		printlist(dist , head->dlink ,j+1) ;
		printlist(dist , head->next , j) ;
	}
}

int main()
{
	mlptr ml = NULL ;
	ml =createnode(8);
	ml->dlink = createnode(5) ;
	ml ->next = createnode(10);
	ml->next->next =createnode(18);
	ml->next->dlink = createnode(2);
	ml->next->dlink->dlink = createnode(6);
	ml->next->dlink->dlink->dlink = createnode(3);
	ml->next->next->dlink=createnode(9);
	ml->next->next->next=createnode(12);
	ml->next->next->dlink->dlink =createnode(10);
	ml->next->dlink->dlink->next=createnode(11) ;
	ml->next->next->dlink->dlink->next=createnode(7);
	ml->next->next->next->dlink=createnode(8);
	cout<<"enter maxdistance "<<endl;
	int max_dist ;
	cin>>max_dist ;
	for(int i=0;i<max_dist ;i++)
	{
		printlist(i,ml , 0) ;
		cout<<endl;
	}
	//printlist(ml);
}
