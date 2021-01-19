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
void IN(bstptr t)
{ if(t)
	{   IN(t->lc);
	    cout<<t->data <<" ";
		 IN(t->rc);
	}  
}
/*void PRE(bstptr t)
{
	if(t){ cout<<t->data<<" " ;IN(t->lc);  IN(t->rc);} 
}
void POST(bstptr t)
{
	if(t)	{   IN(t->lc); IN(t->rc);  cout<<t->data <<" "  ;}
}*/

void sumofelements(bstptr t ,int &sum) 
{
	if(t)
	{
		sumofelements(t->lc,sum);
		sum=sum + t->data ;
		sumofelements(t->rc ,sum) ;
	}
}/*
void convert(bstptr &t ,int &sum)
{
	if(t)
	{
		convert(t->lc  , sum) ;
		int a =t->data ;
		t->data= sum ;
		sum = sum-a  ;
		if(sum == 0)		t->data=0;
		convert(t->rc , sum) ;
	}
}*/
void convert(bstptr &t,int &sum)
{
	if(t)
	{
		convert(t->rc,sum);
		int ts = t->data;
		t->data = sum+ts ;
		if(sum == 0) t->data = 0;
		sum += ts;
		
		convert(t->lc,sum) ;
		//return sum;
	}
	
}

int main()
{   bstptr root =NULL;
    int n ;
	cout<<"ENter how many number of nodes : "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x ;
		root = insert(root ,x) ;
	}
	cout<<"Pre order is : "<<endl;
	IN(root)  ;
	int sum=0 ;
	sumofelements(root ,sum) ;
    cout<<"SUM IS "<<sum <<endl;
    sum =0 ;
    convert(root,sum) ;
	cout<<"Converted IN order "<<endl;
    IN(root) ;
    cout<<"SUM IS "<<sum <<endl;

    return 0;  
}
		

