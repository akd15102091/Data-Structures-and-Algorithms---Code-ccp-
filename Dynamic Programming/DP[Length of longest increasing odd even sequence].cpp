#include<iostream> 
using namespace std; 

int longOddEvenIncSeq(int arr[], int n) 
{ 
    // lioes[i] stores longest increasing odd  even subsequence ending at arr[i] 
    int lioes[n]; 
  
    // to store the length of longest increasing odd even subsequence 
    int maxLen = 0; 
  
    // Initialize LIOES values for all indexes 
    for (int i = 0; i < n; i++) 
        lioes[i] = 1; 
  
    // Compute optimized LIOES values 
    // in bottom up manner 
    for (int i = 1; i < n; i++) 
    {
    	for (int j = 0; j < i; j++) 
    	{
    	 	if (arr[i] > arr[j] &&  (arr[i] + arr[j]) % 2 != 0 && lioes[i] < lioes[j] + 1) 
            {
			    lioes[i] = lioes[j] + 1;
			}
		}
   	}
       
  
    // Pick maximum of all LIOES values 
    for (int i = 0; i < n; i++) 
        if (maxLen < lioes[i]) 
            maxLen = lioes[i]; 
  
    // required maximum length 
    return maxLen; 
} 
  
// Driver program to test above 
int main() 
{ 
    int arr[] = { 1, 12, 2, 22, 5, 30,  31, 14, 17, 11 }; 
    int n = sizeof(arr) / sizeof(n); 
    cout << "Longest Increasing Odd Even Subsequence: "<< longOddEvenIncSeq(arr, n); 
    return 0; 
} 
