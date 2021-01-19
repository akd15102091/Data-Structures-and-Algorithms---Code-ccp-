#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int G[10][10];
stack <int> S;
void DFS(int s,int v,int visit[],int &h)
{
	visit[s]=1;
	S.push(s);
	if(S.size()==v)
	{
		vector <int> V;
		while(!S.empty())
		{
			V.push_back(S.top());
			S.pop();
		}
		if(!h)
		cout<<endl<<"All Hamiltonian paths in the above graph are : "<<endl;
		++h;
		cout<<h<<" :\t";
		for(int f=V.size()-1;f>=0;f--)
		{
			if(!f)
			cout<<V[f]<<endl;
			else
			cout<<V[f]<<" -> ";
		}
		for(int f=V.size()-1;f>=0;f--)
		{
			S.push(V[f]);
			V.clear();
		}

	}
	for(int j=0;j<v;j++)
	{
		if(G[s][j] && !visit[j])
		{
		DFS(j,v,visit,h);
		S.pop();
		visit[j]=0;
		}
	}
    return;
}

int main()
{
	int i,j,k,v,e,s;
	cout<<"Enter the no. of vertices : ";
	cin>>v;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		G[i][j]=0;
	}
	cout<<"Enter the no. of edges : ";
	cin>>e;
	for(i=1;i<=e;i++)
	{
		cout<<"Enter vertex 1 and vertex 2 : ";
		cin>>j>>k;
		G[j][k]=1;
		G[k][j]=1;
	}
	int visit[v]={0};
	k=0;
	for(i=0;i<v;i++)
	{
		DFS(i,v,visit,k);
		while(!S.empty())
		S.pop();
		for(j=0;j<v;j++)
		visit[j]=0;
	}
	if(!k)
	cout<<endl<<"Oops , there are no Hamiltonian paths in the given graph.";
}
/*
4
4
0 1
1 2
1 3
2 3
*/
