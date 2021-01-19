#include <iostream>
#include<cstdlib>
using namespace std;
struct bstnode{
    struct bstnode *left;
    int data;
    struct bstnode *right;
    int hl,hr;
};

typedef struct bstnode *BSTPTR;


void add(BSTPTR &T,int x){
    if(T==NULL){
        BSTPTR P;
        P=new bstnode;
        P->data=x;
        P->left = P->right = NULL;
        T=P;
        return ;
    }
    else{
        if(T->data>x){
            add(T->left,x);
        }
        else{
            add(T->right,x);
        }
    }
}

int height(BSTPTR &T){
    if(T==NULL) return -1;
    if(T->left==NULL&&T->right==NULL) return 0;
    return 1+max(height(T->left),height(T->right));
}

void assign(BSTPTR &T){
    if(T==NULL) return ;
    T->hl=height(T->left);
    T->hr=height(T->right);
    assign(T->left);
    assign(T->right);
}

void rotateleft(BSTPTR &k1,BSTPTR &k2){
    k1->right=k2->left;
    k2->left=k1;
}

void rotateright(BSTPTR &k1,BSTPTR &k2){
    k1->left=k2->right;
    k2->right=k1;
}

void avl(BSTPTR &T){
    if(T==NULL) return ;
    avl(T->right);
    int a=T->hl - T->hr;
    if(a>1||a<-1){
            if(a>1){
            if(T->left!=NULL&&T->left->left!=NULL){
                BSTPTR k1,k2,k3;
                k1=T;
                k2=T->left;
                k3=T->left->left;
                rotateright(k1,k2);
                T=k2;
                assign(k1);
                assign(k2);
                assign(k3);
                assign(T);
            }
            else{
                BSTPTR k1,k2,k3;
                k1=T;
                k3=T->left;
                k2=T->left->right;
                k1->left=k2;
                if(k2->left){k3->right=k2->left;}
                else{k3->right=NULL;}
                k2->left=k3;
                rotateright(k1,k2);
                T=k2;
                assign(k1);
                assign(k2);
                assign(k3);
                assign(T);
                }
            }
        else{
            if(T->right!=NULL&&T->right->right!=NULL){
                BSTPTR k1,k2,k3;
                k1=T;
                k2=T->right;
                k3=T->right->right;
                rotateleft(k1,k2);
                T=k2;
                assign(k1);
                assign(k2);
                assign(k3);
                assign(T);
            }
            else{
                BSTPTR k1,k2,k3;
                k1=T;
                k3=T->right;
                k2=T->right->left;
                k1->right=k2;
                if(k2->right){k3->left=k2->right;}
                else{k3->left=NULL;}
                k2->right=k3;
                rotateleft(k1,k2);
                T=k2;
                assign(k1);
                assign(k2);
                assign(k3);
                assign(T);
            }
        }
    }
    avl(T->left);
}

void avl1(BSTPTR &T){
    if(T==NULL) return ;
    avl(T->left);
    int a=T->hl-T->hr;
    if(a>1||a<-1){
        if(a>1){
            if(T->left!=NULL&&T->left->left!=NULL){
                BSTPTR k1,k2,k3;
                k1=T;
                k2=T->left;
                k3=T->left->left;
                rotateright(k1,k2);
                T=k2;
                assign(k1);
                assign(k2);
                assign(k3);
                assign(T);
            }
            else{
                BSTPTR k1,k2,k3;
                k1=T;
                k3=T->left;
                k2=T->left->right;
                k1->left=k2;
                if(k2->left){k3->right=k2->left;}
                else{k3->right=NULL;}
                k2->left=k3;
                rotateright(k1,k2);
                T=k2;
                assign(k1);
                assign(k2);
                assign(k3);
                assign(T);
            }
        }
        else{
            if(T->right!=NULL&&T->right->right!=NULL){
                BSTPTR k1,k2,k3;
                k1=T;
                k2=T->right;
                k3=T->right->right;
                rotateleft(k1,k2);
                T=k2;
                assign(k1);
                assign(k2);
                assign(k3);
                assign(T);
            }
            else{
                BSTPTR k1,k2,k3;
                k1=T;
                k3=T->right;
                k2=T->right->left;
                k1->right=k2;
                if(k2->right){k3->left=k2->right;}
                else{k3->left=NULL;}
                k2->right=k3;
                rotateleft(k1,k2);
                T=k2;
                assign(k1);
                assign(k2);
                assign(k3);
                assign(T);
                }
        }
    }
    avl1(T->right);
}
void IN(BSTPTR t)
{
	if(t)
	{
	
		IN(t->left) ;
		cout<<t->data <<" ";
		IN(t->right) ;
	}
}
int main(){
    int A[10];
    BSTPTR root=NULL;
    int n;
    cin>>n;
    while(n!=-1){
        add(root,n);
        assign(root);
        if(n < root->data){avl1(root);}
        else avl(root);
        cin>>n;
    }
    
    cout<<endl;
    IN(root) ;
    return 0;
}
 
