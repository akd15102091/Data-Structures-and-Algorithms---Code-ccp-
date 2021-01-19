#include<iostream>
#include<cstdlib>
using namespace std;
struct mlnode
{
	int data ;
//	int Number;
	struct mlnode *next[5]  ;
};
typedef struct mlnode *mlptr ;
mlptr create( mlptr ml )
{   
    int num , n ;
	cout<<"enter element "<<endl;
	cin>>num ;
	cout<<"Enter how many directions ( nexts ) in this node "<<endl;
	cin>>n ;
	mlptr T =new struct mlnode ;
	T->data = num ;
	for(int i=0;i<n;i++)
	{
		T->next[i] = NULL ;
	}
	if(n== 0) {cout << "go";return ml ;}
	for(int j=0;j<n ; j++)
	{
		ml->next[j] = create(ml->next[j]);
	}
}
int main()
{
	mlptr ml =NULL ;
	ml=new struct mlnode ;
	ml = create(ml) ;
	/*while(ml->next[0] != NULL)
	{  cout<<ml->data <<" " ;
		ml = ml->next[0]  ;
	}*/
	
}
