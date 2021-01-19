#include<iostream>
#include<cstring>
using namespace std;

struct btnode{
    char data;
    btnode *lchild;
    btnode *rchild;
};

typedef struct btnode *BTPTR;

BTPTR newnode(char k){
	if(k != '+'){
	BTPTR temp = new struct btnode;
	temp->data = k;
	temp->lchild = temp->rchild = NULL;
	return temp;}
	else return NULL;
}

BTPTR create(BTPTR &T,char a[],int n){
	static int i = 0;
	if(i>=n) return NULL;
	T = newnode(a[i++]);
	if(T==NULL) return NULL;
	T->lchild = create(T->lchild,a,n);
	T->rchild = create(T->rchild,a,n);
	return T;
}

void pre(BTPTR T){
    if(T==NULL) return;
    cout << T->data  << " ";
    pre(T->lchild);
    pre(T->rchild);
}

void printbrac(BTPTR T ,string &s){
    if(T == NULL)return;
    s += T->data;
    if(T->lchild || T->rchild){
        s += '(';
        if(T->lchild) printbrac(T->lchild,s);
        s += ')' ;}
    if(T->rchild) {
        s+= '(';
        printbrac(T->rchild,s);
        s += ')' ;}
}

int main()
{
    cout << "Enter the number of elements." << endl;
	int n;cin >> n;
	char a[n];
	cout << "Enter the elements." << endl;
	for(int i=0;i<n;i++) cin >> a[i];

	BTPTR T = NULL;

	create(T,a,n);
	string s = "";
	printbrac(T,s);
	cout << s << endl;
//	for(int i=0;i<s.size()-1;i++) cout << s[i];

    return 0;
}

