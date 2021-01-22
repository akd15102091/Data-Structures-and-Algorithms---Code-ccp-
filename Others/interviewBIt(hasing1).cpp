#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std ;

vector<vector<int> > anagrams(const vector<string> &A) 
{
    map<int,vector<int> >mp ;
    int n = A.size() ;
    cout<<"Enter"<<endl;
    for(int i=0;i<n;i++)
    {
        vector<int> vec ;
        for(int k=0;k<26;k++)
        {
            vec.push_back(0) ;
        }
        for(int j=0;j<(A[i]).length();j++)
        {
            vec[A[i][j]-97]++ ;
        }
        mp[i] = vec ;
    }
    cout<<"Enter1"<<endl;
    
    vector<vector<int> > rs ;
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++ )
        {
            int cnt=0 ;
            vector<int> v1 = mp[i] ;
            vector<int> v2 = mp[j] ;
            for(int k=0;k<26;k++)
            {
                if(v1[k] != v2[k] )
                {
                    cnt=1 ;
                }
            }
            if(cnt==0)
            {
                vector<int> v ;
                v.push_back(i+1) ;
                v.push_back(j+1) ;
                rs.push_back(v) ;
            }
            
        }
    }
   cout<<"Enter2"<<endl;
   cout<<endl<<"answer is : "<<endl;
   for(int i=0;i<rs.size();i++)
   {
   		cout<<rs[i][0]<<" "<<rs[i][1] <<endl;
   }
    cout<<"Exit1" ;
}


int main()
{
	int n ;
	cin>>n ;
	vector<string> ques ;
	for(int i=0;i<n;i++)
	{
		string str ;
		cin>>str ;
		ques.push_back(str) ;
	}
	anagrams(ques);
	cout<<endl<<"Exit2";
}

/*

4
cat 
dog
god
tca

*/
