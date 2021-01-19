#include<iostream>
#include<stack>
using namespace std ;
struct adjNode
{
	int data ;
	struct adjNode *next ;
	struct adjNode *dlink ;
	//int visited =0 ; // if in edge list , edge is traverse then visit = 1,else visit=0 //
} ;
typedef struct adjNode *Gptr ;       // graph pointer , adjNode=adjacency node

Gptr create_vertex_list(Gptr t, int x)
{
	Gptr temp = NULL ;
	temp = new struct adjNode ;
	temp->data = x ;
	temp->dlink = temp->next = NULL ;
	if(t==NULL)
	{
		t=temp ;
		return t ;
	}
	
	Gptr ref= t ;
	while(ref->dlink)
	{
		ref=ref->dlink ;
	}
	ref->dlink=temp ;
	return t ;
}
Gptr create_edge_list(Gptr t ,int v1, int v2)
{
	Gptr ref=t ;
	while(ref->data != v1)
	{
		ref=ref->dlink ;
	}
	while(ref->next)
	{
		ref=ref->next ;
	}
	Gptr temp = NULL ;
	temp = new struct adjNode ;
	temp->data = v2 ;
	temp->dlink = temp->next = NULL ;
	ref->next=temp ;
	return t ;
}
void print_vertex_list(Gptr t)
{
	while(t)
	{
		cout<<t->data<<" ";
		t=t->dlink ;
	}
}

void print_graph(Gptr t)
{
	if(t)
	{
		Gptr temp=t ;
		while(temp)
		{
			cout<<temp->data<<" " ;
			temp=temp->next ;
		}
		cout<<endl ;
		print_graph(t->dlink) ;
	}
}
/*void DFS( Gptr t1 , Gptr t2 , int visited[] )
{
	if(t1==NULL) return ;
	//if(t2==NULL) return ;
	if(t2!= NULL && visited[t2->data]==0 )
	{
		cout<<t2->data <<" " ;
		t2->visited=0 ;
		
	}
	
}*/

void DFS_Iterative(Gptr t , int visited[] )
{
	if(t == NULL) return ;
	stack<int> s;
	s.push(t->data) ;
	visited[t->data]=2 ;
	while(!s.empty())
	{
		int temp = s.top() ;
		cout<<temp<<" " ;
		s.pop() ;
		visited[temp]=3 ;
		Gptr ptr = t ;/////////
		while(ptr->data!=temp)
		{
			ptr=ptr->dlink ;
		}
		while(ptr->next)
		{
			if(visited[ptr->next->data]==1)
			{
				s.push(ptr->next->data) ;
				visited[ptr->next->data]=2 ;
			}
			ptr=ptr->next ;
		}
	
	}
	return ;
}

int main()
{
	Gptr root = NULL ;
	int v,e ;
	cout<<"Enter no. of vertecies and edges : "<<endl ;
	cin>>v>>e ;
	cout<<"Enter the vertaxs first : "<<endl ;
	for(int i=1 ;i<=v; i++)
	{
		int x ;
		cin>>x ;
		root = create_vertex_list(root,x) ;
	}
	cout<<"Vertex list : ";
	print_vertex_list(root) ;
	cout<<"Enter vertex1 and vertax2 combinations : "<<endl ;
	for(int i=1 ;i<=e ;i++)
	{
		cout<<"Enter v1 , v2 : "<<endl ;
		int v1,v2 ;// vertex1 and vertex2
		cin>>v1>>v2 ;
		root = create_edge_list(root,v1,v2) ;
	}
	cout<<"Graph is : "<<endl ;
	print_graph(root) ; // pre_oreder
	int visited[50] ;
	for(int i=1 ;i<=v ;i++)
	{
		visited[i]=1 ;
	}
	cout<<endl ;
	cout<<"Depth first search is : "<<endl ;
	//DFS(root , root->next,visited) ;
	DFS_Iterative(root , visited) ;
	return 0 ;
}

/*
5 7
1
2
3
4
5
1 2
1 3
1 4
2 3
3 4
4 5
5 3

*/
