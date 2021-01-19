#include<iostream>
#include<cstdlib>
//#include<vector>
using namespace std;
struct btnode{
    int data;
    struct btnode *lc;
    struct btnode *rc;
};
void addmax(int H[],int n,int k)
{
    H[n]=k;
    while(H[n]>H[(n-1)/2]&&(n-1)/2>=0)
    {
        int t=H[n];
        H[n]=H[(n-1)/2];
        H[(n-1)/2]=t;
        n=(n-1)/2;
    }
}
int  del(int H[],int n)
{
    int x=H[0];
    H[0]=H[n];
    int i=0;
    while((H[i]>H[2*i+1]||H[i]>H[2*i+2])&&(2*i+2)<=n-1)
    {
        if(H[2*i+1]>H[2*i+2])
        {
            int t=H[i];
            H[i]=H[2*i+2];
            H[2*i+2]=t;
            i=2*i+2;
        }
        else
        {
            int t=H[i];
            H[i]=H[2*i+1];
            H[2*i+1]=t;
            i=2*i+1;
        }
    }
    if(2*i+1==n-1)
    {
        if(H[i]>H[2*i+1])
        {
            int t=H[i];
            H[i]=H[2*i+1];
            H[2*i+1]=t;
            i=2*i+1;
        }
    }
    return x;
}
int  del1(int H[],int n)
{
    int x=H[0];
    H[0]=H[n];
    int i=0;
    while((H[i]<H[2*i+1]||H[i]<H[2*i+2])&&(2*i+2)<=n-1)
    {
        if(H[2*i+1]<H[2*i+2])
        {
            int t=H[i];
            H[i]=H[2*i+2];
            H[2*i+2]=t;
            i=2*i+2;
        }
        else
        {
            int t=H[i];
            H[i]=H[2*i+1];
            H[2*i+1]=t;
            i=2*i+1;
        }
    }
    if(2*i+1==n-1)
    {
        if(H[i]<H[2*i+1])
        {
            int t=H[i];
            H[i]=H[2*i+1];
            H[2*i+1]=t;
            i=2*i+1;
        }
    }
    return x;
}
void addmin(int H1[],int n,int k)
{
    H1[n]=k;
    while(H1[n]<H1[(n-1)/2]&&(n-1)/2>=0)
    {
        int t=H1[n];
        H1[n]=H1[(n-1)/2];
        H1[(n-1)/2]=t;
        n=(n-1)/2;
    }
}
int main()
{
    int H[50],H1[50];
    int flag=1,n1=0,n2=0;
    float median=0;
    while(flag==1)
    {
        int x;
        cin>>x;
        if(x!=-1)
        {
            if(x<median)
            {
                addmax(H,n1,x);
                n1++;
            }
            else
            {
                addmin(H1,n2,x);
                n2++;
            }
            if(abs(n1-n2)>1)
            {
                if(n1>n2)
                {
                    int y=del1(H,--n1);
                    addmin(H1,n2,y);
                    n2++;
                }
                else
                {
                    int y=del(H1,--n2);
                    addmax(H,n1,y);
                    n1++;
                }
            }
            if(n1==n2)
            {
                median=(H[0]+H1[0])/2.0;
            }
            else
            {
                if(n1>n2)
                    median=H[0];
                else
                    median=H1[0];
            }
            cout<<"meadian: "<<median<<endl;
        }
        else
        flag=0;
    }
    return 0;
}
