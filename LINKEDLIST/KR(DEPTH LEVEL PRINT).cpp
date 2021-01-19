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
void depthlevelprint( mlptr ml)
{    if(ml->dlink != NULL)
     {
			depthlevelprint(ml->dlink) ;
     }

	cout<< ml->data <<" ";
	if(ml->next != NULL)
	{
		depthlevelprint(ml->next) ;
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
	depthlevelprint(ml);
	//printlist(ml);
}
