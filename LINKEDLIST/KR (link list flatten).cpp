#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next ;
	struct node *dlink ;
};
typedef struct node *mlptr ;
void printlist( mlptr L )
{   static int c = 0;
	if(L != NULL)
	{   c++;
		cout<< L->data <<" ";
		printlist(L->next) ;
	}
	else if(c == 0)
	{
		cout<<"List is empty "<<endl;
	}
	
}
mlptr createnode(int data)
{
		mlptr T = NULL ;
		T = new struct node ;
		T->data = data ;
		T->next = NULL ;
		T->dlink = NULL ;
		return T ;
}
mlptr flatten( mlptr ml)
{
	if(ml ->next == NULL) return ml ;
	if(ml->dlink != NULL)
	{
      ml->dlink->next = ml -> next ;
      ml->next = ml->dlink ;
      ml->dlink = NULL ;
      
    }
	flatten(  ml -> next) ;
	return ml ;
}
int main()
{
	mlptr ml = NULL ;
	ml =createnode(8);
	ml ->next = createnode(10);
	ml->next->next =createnode(18);
	ml->next->dlink = createnode(2);
	ml->next->dlink->dlink = createnode(6);
	ml->next->dlink->dlink->dlink = createnode(3);
	ml->next->next->dlink=createnode(9);
	ml->next->next->next=createnode(12);
	ml->next->next->dlink->dlink =createnode(10);
	ml = flatten(ml);
	printlist(ml);
}
