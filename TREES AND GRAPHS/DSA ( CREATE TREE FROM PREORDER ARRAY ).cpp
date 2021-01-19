#include<iostream>
#include<stack>
using namespace std;
struct treenode
{
	struct treenode *lc ;
	int data ;
	struct treenode *rc ;
};
typedef struct treenode *bstptr ;
bstptr createnode(int data)
{
	bstptr temp= NULL ;
	temp = new struct treenode;
	temp->data = data ;
	temp->lc = temp->rc = NULL ;
	return temp ;
}
bstptr create_from_preorder(bstptr t , int a[] ,int i, int n)
{
	stack<bstptr> s;
	t = createnode(a[i++]) ;
	s.push(t) ;
	while(i != n)
	{
		if(a[i] < s.top()->data)
		{
			s.top()->lc = createnode(a[i++]) ;
			s.push(s.top()->lc) ;
		}
		else
		{
			bstptr temp = NULL ;
			while(s.top()->data < a[i])
			{
				temp = s.top() ;
				s.pop() ;
				if(s.empty()) 
				{
					break ;
				}
			}
			temp->rc = createnode(a[i++]) ;
			s.push(temp->rc) ;
		}
	}
	return t ;
}
void PRE(bstptr t)
{
	if(t)
	{
		cout<<t->data <<" ";
		PRE(t->lc) ;
		PRE(t->rc);
	}
}
int main()
{	bstptr root = NULL ;
	cout<<"Enter the number of elements of pre_order_array "<<endl;
	int n , a[50];
	cin>>n;
	cout<<"enter the elements of the array "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
     root = create_from_preorder(root ,a , 0 ,n) ;
	cout<<"Pre order is "<<endl;
	PRE(root) ;
}
