#include<iostream>
#include<cstring>
#include<cstdlib>
// map<<char><int>> MAP;
using namespace std;
int MAX=0,MIN=0,WIDTH=0;
#define postive(n) ((n) < 0 ? 0 - (n) : (n))

typedef struct tnode{
    struct tnode* lchild = NULL;
    char data;
    int level;
    struct tnode* rchild = NULL;
} * BTPTR;

BTPTR createTnode(char ch){
    if (ch == '.'){
        return NULL;
    }
    BTPTR tmp = new(tnode);
    tmp -> data = ch;
    return tmp;
}
BTPTR createBT(string str, int &i, BTPTR T){
    T = createTnode(str[i]);
    if(T==NULL || i == str.length()-1){
        return T;
    }
    T->lchild = createBT(str, ++i, T->lchild);
    T->rchild = createBT(str, ++i, T->rchild);
    return T;
}
void maxMinWidth(BTPTR T, int i=0){
    if(T==NULL){
        return;
    }
    if(i<MIN){
        MIN = i;
    }
    if(i>MAX){
        MAX = i;
    }
    maxMinWidth(T->lchild,i-1);
    maxMinWidth(T->rchild,i+1);
    return;
}

void topViewElements(BTPTR T, BTPTR ARR[], int level=0, int hd=0){
    if(T==NULL){
        return;
    }
    T->level = level;
    topViewElements(T->lchild, ARR, level+1, hd-1);
    if(ARR[postive(MIN)+hd] != NULL){
        if(ARR[postive(MIN) + hd]->level > level){
            ARR[postive(MIN)+hd] = T;
        }
    }
    else{
        ARR[postive(MIN)+hd] = T;
    }
    topViewElements(T->rchild, ARR, level+1, hd+1);
}

void topView(BTPTR Q[]){
    for(int i = 0; i < WIDTH; i++){
        cout<<Q[i]->data<<" ";
    }
    return;
    }
int main(){
    // string str = "ABD.EUV..W...FO..Q..CHN..P..GIK..JL.M....";
    string str = "124..5.8abcd......3679e......";
    BTPTR T = NULL;
    int i = 0;
    T = createBT(str, i, T);
    maxMinWidth(T);
    WIDTH = MAX+postive(MIN)+1;
    BTPTR ARR[WIDTH]={NULL};
    topViewElements(T, ARR);
    topView(ARR);
    return 0;
}
