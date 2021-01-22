// C++ program to check if there is a subset 
// with sum divisible by m. 
#include<iostream>
#include<algorithm> 
#include<cstring>
using namespace std; 

bool modularSum(int arr[], int n, int m) 
{ 
    if(n > m)   return true; 
  
    bool DP[m]; 
    memset(DP, false, m); 
  
    for (int i=0; i<n; i++) 
    { 
      
        if (DP[0]) 
            return true; 
     
        bool temp[m]; 
        memset(temp,false,m); 
  
        for (int j=0; j<m; j++) 
        { 
            if (DP[j] == true) 
            { 
                if (DP[(j+arr[i]) % m] == false) 
                {
                    temp[(j+arr[i]) % m] = true; 
				}
            } 
        } 
  
        for (int j=0; j<m; j++)
		{
			if (temp[j]) 
			{
               DP[j] = true; 
			}
		} 
            
  
  
        DP[arr[i]%m] = true; 
    } 
  
    return DP[0]; 
} 

int main() 
{ 
    int arr[] = {3,1,7,5} ; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int m = 6; 
  
    modularSum(arr, n, m) ?  cout << "YES\n" : cout << "NO\n"; 
  
    return 0; 
} 
