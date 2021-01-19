#include<iostream>
using namespace std ;
struct avl_node
{
	int height ;
	int data ;
	struct avl_node *lc,*rc ;
} ;
typedef struct avl_node *aptr ;

aptr create_node(int x)
{
	aptr temp = new struct avl_node() ;
	temp->data = x ;
	temp->lc = temp->rc = NULL ;
	temp->height = 1 ;// new node is initially 
                      // added at leaf  
    return temp ;
}

int height(aptr N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height ;  
}  

int getBalance(aptr N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->lc) - height(N->rc);  
}  

aptr leftRotate(aptr pt)  
{  
    aptr y = pt->rc;  
    aptr T2 = y->lc;  
  
    // Perform rotation  
    y->lc = pt;  
    pt->rc = T2;  
  
    // Update heights  
    pt->height = max(height(pt->lc),     
                    height(pt->rc)) + 1;  
    y->height = max(height(y->lc),  
                    height(y->rc)) + 1;  
  
    // Return new root  
    return y;  
}  

aptr rightRotate(aptr pt)  
{  
    aptr x = pt->lc;  
    aptr T2 = x->rc;  
  
    // Perform rotation  
    x->rc = pt;  
    pt->lc = T2;  
  
    // Update heights  
    pt->height = max(height(pt->lc), height(pt->rc)) + 1;  
    x->height = max(height(x->lc), height(x->rc)) + 1;  
  
    // Return new root  
    return x;  
}  

aptr Create_avl_tree(aptr t , int x)
{
	if(t==NULL)
	{
		return create_node(x) ;
	}
	if(x<t->data)
	{
		t->lc = Create_avl_tree(t->lc,x) ;
	}
	else if(x>t->data)
	{
		t->rc = Create_avl_tree(t->rc,x) ;
	}
	else  // equal keys not allowed
	{
		return t ;
	}
	// update height of ancester node
	t->height = 1 + max(height(t->lc) , height(t->rc));
	int balance = getBalance(t);  // balance is the balance_factor
	
	// If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && x < t->lc->data) 
	{
		return rightRotate(t); 
	}  
	// Right Right Case  
    if (balance < -1 && x > t->rc->data)  
        return leftRotate(t);  
  
    // Left Right Case  
    if (balance > 1 && x > t->lc->data)  
    {  
        t->lc = leftRotate(t->lc);  
        return rightRotate(t);  
    }  
  
    // Right Left Case  
    if (balance < -1 && x < t->rc->data)  
    {  
        t->rc = rightRotate(t->rc);  
        return leftRotate(t);  
    }  
  
    /* return the (unchanged) node pointer */
    return t;  
  
}

void IN_ORDER(aptr t)
{
	if(t)
	{
			cout<<t->data<<" ";
		IN_ORDER(t->lc) ;
	//	cout<<t->data<<" ";
		IN_ORDER(t->rc) ;
	}
}

int main()
{
	aptr root = NULL ;
	int n ;
	cout<<"Enter the number of elements : "<<endl ;
	cin>>n ;
	cout<<"Enter the elements : "<<endl ;
	for(int i=0;i<n;i++)
	{
		int x ;
		cin>> x;
		root =	Create_avl_tree(root,x) ;
	}
	cout<<endl ;
	cout<<"IN order of constructed AVL tree : "<<endl ;
	
	IN_ORDER(root) ;
	cout<<(root->height) ;
}
/*
14
130
100
150
50
110
160
40
60
35
45
55
70
65
75
*/
