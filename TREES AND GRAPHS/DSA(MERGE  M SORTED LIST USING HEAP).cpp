#include<iostream>
#include<cstdlib>
using namespace std ;
typedef struct list *lptr ;

struct list
{
	int data ;
	struct list *next ;
} ;

lptr create_list(lptr T , int a[] , int k ,int n)
{
	if(k>=n)  return T ;
	
	lptr temp = NULL ;
	temp = new struct list ;
	temp->data = a[k] ;
	temp->next = NULL ;
	T= temp ;
	
	T->next =  create_list(T->next , a , k+1 , n) ;
}
/*void print_list(lptr t)
{
	while(t)
	{
		cout<<t->data <<" ";
		t = t->next ;
	}
}*/
void PERCULATE_UP(int H[] , int &n , int key)
{
	H[n] = key ;
	int j = n ;
	while(H[j] < H[(j-1)/2]  && j>0)
	{
		int temp = H[(j-1)/2] ;
		H[(j-1)/2] = H[j] ;
		H[j] = temp ;
		j=(j-1)/2 ;
	}
}

int b[50] , len = 0;

int PERCULATE_DOWN( int H[] ,int  &n)
{
	int val = H[0] ;
	H[0] = H[n-1] ;
	n = n-1 ;
	int j = 0 ;
	while((H[j] > H[1+2*j]  ||  H[j] > H[2+2*j] ) && (1+2*j)<n)
	{
		if(H[j] > H[1+2*j]  &&  H[j] > H[2+2*j])
		{
			if(H[1+2*j] > H[2+2*j])
			{
				int temp = H[j] ;
				H[j] =  H[2+2*j] ;
				H[2+2*j] = temp ;
				j =  2+2*j ;
			}
			else if(H[1+2*j] < H[2+2*j])
			{
				int temp = H[j] ;
				H[j] =  H[1+2*j] ;
				H[1+2*j] = temp ;
				j = 1+2*j ;
			}
		}
		else
		{
			if(H[j] > H[2+2*j])
			{
				int temp = H[j] ;
				H[j] =  H[2+2*j] ;
				H[2+2*j] = temp ;
				j =  2+2*j ;	
			}
			else if(H[1+2*j] < H[j])
			{
				int temp = H[j] ;
				H[j] =  H[1+2*j] ;
				H[1+2*j] = temp ;
				j = 1+2*j ;
			}
		}
	}
	b[len] = val ;
	len++ ;
	return val ;
//	cout<< val<<" " ;
}
int main()
{
	lptr L[50] ;
	cout<<"ENter the number of lists "<<endl ;
	int num ;
	cin>>num;
	int z = 0;
	for(int i=0;i<num;i++)
	{
		cout<<"ENter the number of elements in list "<<i+1<<" : "<<endl;
		int n1 ,a[50] ;
		cin>>n1 ;
		cout<<"ENter the elements of lists in array"<<endl;
		for(int j=0;j<n1 ;j++)
		{
			cin>> a[j] ;
			z++ ;
		}
		lptr t = NULL ;
		L[i] = create_list(t ,a , 0 , n1) ;
    }
   /* for(int i=0;i<num;i++)
    {
    	lptr t1 = L[i] ;
    	print_list(t1 ) ;
    	cout<<endl ;
	}*/
	int H[50] ;
	for(int i=0;i<num;i++)
	{
		int key = L[i]->data ;
		PERCULATE_UP( H , i ,key) ;
	}
	int y =0 ;
	z = z-num ;
	//int b[50] , len = 0
	int n = num ;
	while(y != z)
	{
		//cout<<"L" ;
		int value = PERCULATE_DOWN( H , n) ;
		for(int i =0 ; i<num ; i++)
		{
			if(L[i] != NULL)
			{
				if(L[i]->data == value)
				{
					if( L[i]->next != NULL )
					{
						//cout<<"G";
						L[i] = L[i]->next  ;
						int key = L[i]->data  ;
						
						PERCULATE_UP( H , n ,key) ; n=n+1 ;
						y++ ;
					}
				}
			}
			
		}
	}
	for(int i=0;i<num-1;i++)
	{
		int value =  PERCULATE_DOWN( H , n) ;
	}
	for(int p=0 ;p<len;p++)
	{
		cout<<b[p] <<" ";
	}
	return 0 ;
}

