#include<iostream>
#include<stack>

using namespace std;
struct btnode{
    char data;
    struct btnode *lc;
    struct btnode *rc;
};
typedef struct btnode *btptr ;
 btptr create_node(btptr t , char a[50] ,int i)
 {
 	if(a[i] != '+')
	{
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = a[i] ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		return temp ;
	}
	else {	return NULL ;}
 }

btptr create_tree(btptr T , char a[50] ,int &i ,int n)
{
	if(i >= n)
	{
		return T ;
	}
	T = create_node(T , a ,i) ;
	if(T==NULL) return NULL;
	i++;
	T->lc = create_tree(T->lc , a ,i , n) ;
	i++;
	T->rc = create_tree(T->rc , a ,i ,n) ;
}
/*void ancestors(btptr t,int k)
{
    if(t == NULL)
    {
    	return ;
	}
	stack<btptr> s ;
	while(1)
	{
		while(t && t->data != k)
		{
			//cout<<"1";
			s.push(t) ;
			t = t->lc ;
		}
		if( t && t->data == k)
		{
			//cout<<"Break";
			break ;
		}
		if(s.top()->rc == NULL)
		{
		//	cout<<"2";
			t = s.top() ;
			s.pop() ;
			while(!s.empty() && s.top()->rc == t)
			{
				//cout<<"3";
				t = s.top() ;
				s.pop() ;
			}
		}
		//cout<<"4";
		t = s.empty() ? NULL : s.top()->rc ;
	}
	while(!s.empty())
	{
		//cout<<"go" ;
		cout<<s.top()->data <<" ";
		s.pop() ;
	}
}*/

void ancestors(btptr root , char x)
{
	stack<btptr> S ;
	if(root==NULL)
	return;	
	int a=1;
	while(a)
	{
		while(root && root->data!=x)
		{
			S.push(root);
			root=root->lc;
		}
			
		if(root!=NULL && root->data==x)
		break;
		
		if(S.top()->rc==NULL)
	{
			root=S.top();
			S.pop();
			
			while(!S.empty() && S.top()->rc==root)
			{
				root=S.top();
				S.pop();
			}
		}
		if(S.empty())
		root=NULL;
		else root=S.top()->rc;
	}
	while(!S.empty())
	{
		cout<<S.top()->data<<" ";
		S.pop();
	}
}
int main()
{
    btptr root = NULL ;
	int n ;
	char a[50] ;
	cout<<"Enter the n "<<endl;
	cin>>n;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	 
	 int j =0 ;
	 root = create_tree( root ,a , j , n) ;
    int k;
    cout<<"Enter k: ";
    cin>>k;
    ancestors(root,k);
    return 0;
    
    // 19  A B D + + E + + C F H + + I + + G + +
}
