#include<iostream>
using namespace std;
int MIN = 0 ;
int MAX = 0 ;
struct btnode
{
	int data ;
	int dir ;
	struct btnode *lc ;
	struct btnode *rc ;
};

typedef struct btnode *btptr ;
 btptr create_node(btptr t , char a[50] ,int i)
 {
 	if(a[i] != '+')
	{
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = (a[i] ) - '0'  ;
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
void maxMinWidth(btptr T, int i ){
    if(T==NULL){
        return;
    }
    if(i<MIN){
        MIN = i;
    }
    if(i>MAX){
        MAX = i;
    }
    T->dir = i ;
    maxMinWidth(T->lc,i-1 );
    maxMinWidth(T->rc,i+1 );
    return;
}

int Vertical_Sum(btptr T , int i , int &sum)
{
	if(T)
	{
		if(T->dir == i)
		{
			sum = sum + T->data ;
		}
		Vertical_Sum(T->lc , i , sum) ;
		Vertical_Sum(T->rc, i , sum) ;
	}
	return sum ;
}


int main(){
    
    //string str = "  1 2 3 + + 4 + + 3 5 + + 6 + + ";
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
	 maxMinWidth(root, 0 ) ;
    cout<<" vertical sum "<<endl ;
    for(int i=MIN ; i <= MAX ; i++)
    {
    	int sum =0 ;
    	int x =Vertical_Sum(root , i , sum) ;
    	cout<< x <<" ";
    }
    
    return 0;
}
