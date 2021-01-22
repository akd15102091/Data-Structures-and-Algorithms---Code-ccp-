#include<iostream>
#include<vector>
#include<cstring> 
#define N 12 
using namespace std; 
  
// Return the number of nodes of subtree having 
// node as a root. 
int dfs(vector<int> tree[N], int visit[N], int *ans, int node) 
{ 
    int num = 0, temp = 0; 
  
    // Mark node as visited. 
    visit[node] = 1; 
  
    // Traverse the adjacency list to find non- 
    // visited node. 
    for (int i = 0; i < tree[node].size(); i++) 
    { 
        if (visit[tree[node][i]] == 0) 
        { 
            // Finding number of nodes of the subtree 
            // of a subtree. 
            temp = dfs(tree, visit, ans, tree[node][i]); 
  
            // If nodes are even, increment number of 
            // edges to removed. 
            // Else leave the node as child of subtree. 
            (temp%2)?(num += temp):((*ans)++); 
        } 
    } 
  
    return num+1; 
} 
  
// Return the maxium number of edge to remove 
// to make forest. 
int minEdge(vector<int> tree[N], int n) 
{ 
    int visit[n+2]; 
    int ans = 0; 
    memset(visit, 0, sizeof visit); 
  
    dfs(tree, visit, &ans, 1); 
  
    return ans; 
} 
  
// Driven Program 
int main() 
{ 
    int n = 10; 
  
    vector<int> tree[n+2]; 
    tree[1].push_back(3); 
    tree[3].push_back(1); 
  
    tree[1].push_back(6); 
    tree[6].push_back(1); 
  
    tree[1].push_back(2); 
    tree[2].push_back(1); 
  
    tree[3].push_back(4); 
    tree[4].push_back(3); 
  
    tree[6].push_back(8); 
    tree[8].push_back(6); 
  
    tree[2].push_back(7); 
    tree[7].push_back(2); 
  
    tree[2].push_back(5); 
    tree[5].push_back(2); 
  
    tree[4].push_back(9); 
    tree[9].push_back(4); 
  
    tree[4].push_back(10); 
    tree[10].push_back(4); 
  
    cout << minEdge(tree, n) << endl; 
    return 0; 
} 

