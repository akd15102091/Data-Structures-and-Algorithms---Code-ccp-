#include<iostream>
using namespace std;
struct bstnode
{   int data;
	struct bstnode *lc,*rc;
};
typedef struct bstnode *bstptr ;
 bstptr getnewnode(int data)
{   bstptr newnode=new bstnode();
	newnode->data=data;
	newnode->lc=newnode->rc=NULL;
	return newnode;
}
bstptr insert(bstptr root,int data)
{   if(root == NULL)  {  	root=getnewnode(data); }
  	else if(data<= root->data)  {  root->lc=insert(root->lc,data);  }
	else { 	root->rc=insert(root->rc,data);  }
	return root;
}


bstptr search(bstptr root,int data)
{ // if(root==NULL) return false;
	if(root->data== data) return root;
	else if(data<=root->data ) return search(root->lc,data) ;
	else return search(root->rc,data);  
}
int bstnode_min_max(bstptr root , int &max1)
{
	bstptr t2 = root ;
	bstptr t1 = root ;
	while(t2 -> rc)
	{
		t2 = t2->rc ;
	} 
	max1 = t2->data;
	
    
    while(t1 -> lc)
	{
		t1 = t1->lc ;
	}
	return (t1->data) ;
	
}
int bstnode_range(bstptr root , int &max)
{
	bstptr t2 = root->lc ;
	if(t2 == NULL) {max = root->data ;}
	bstptr t1 = root->rc ;
	if(t2)
	{
		while(t2 -> rc)
	{
		t2 = t2->rc ;
	} 
	max = t2->data;
	}
    if(t1)
    {
    		while(t1 -> lc)
	{
		t1 = t1->lc ;
	}
	return (t1->data) ;
	}
	if(t1==NULL) return root->data ;

}
int main()
{   bstptr root =NULL;
    root=insert(root,50); root=insert(root,15); root=insert(root,62);root=insert(root,5);
	root=insert(root,20); root=insert(root,58); root=insert(root,90); root=insert(root,3);
	
	int max1 = root->data ;
	int x= bstnode_min_max(root , max1) ;
	cout<<"Minimum value is "<<x <<endl;
	cout<<"Maximum value is "<<max1<<endl; 
	
	int number;
	cout<<"Enter the number : "; 
    cin>>number;
    bstptr temp = NULL ;
    temp = search(root , number) ;
    int max = temp->data ;
    int x2= bstnode_range(temp , max) ;
    /*cout<<"Minimum value is "<<x <<endl;
	cout<<"Maximum value is "<<max<<endl;*/
	cout<<"range is "<<max<<" - "<<x2 <<endl;
     return 0;   }
		

