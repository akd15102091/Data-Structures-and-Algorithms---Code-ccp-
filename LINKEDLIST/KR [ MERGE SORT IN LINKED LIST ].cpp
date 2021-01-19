#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
int data;
node *next;
};

void create(node **head,int key)
{
node *temp = NULL,*ref = NULL;
ref = *head;
temp = new(node);
temp->data = key;
temp->next = NULL;
if(*head == NULL)
*head = temp;
else if((*head)->next ==NULL)
{
(*head)->next = temp;
}
else{
while((*head)->next != NULL)
{
(*head) = (*head)->next;
}
(*head)->next = temp;
(*head) = ref;
}


}

node *func(node *h1,node *h2)
{
if(h1 == NULL) return h2;
else if (h2 == NULL ) return h2;
else{
node *head = NULL;
head = new(node);
node *ref = NULL;
ref = new(node);
if((h1)->data < (h2)->data)
{
head = (h1);
h1 = h1->next;
}
else if((h2)->data < (h1)->data)
{
head = (h2);
h2 = h2->next;
}
ref = head;
while(h1 != NULL || h2 != NULL)
{
if(h1 == NULL && h2 != NULL)	
{
head->next = h2;
return ref;
}
else if(h2 == NULL && h2 != NULL) 
{
head->next = h1;
return ref;
}
else if((h2)->data < (h1)->data)
{
head->next = h2;
h2 = h2->next;
head = head->next;
}
else if((h2)->data > (h1)->data)
{
head->next = h1;
h1 = h1->next;
head = head->next;
}
}
return ref;
}
}

int main()
{
node *start1 = NULL,*start2 = NULL;
int n,m;
cout << "Enter the no. of entries ";
cin >> n;
for(int i=0;i<n;i++)
{
cin >> m;
create(&start1,m);
}

cout << "Enter the no. of entries ";
cin >> n;
for(int i=0;i<n;i++)
{
cin >> m;
create(&start2,m);
}
start1 = func(start1,start2);
while(start1)
{
cout << start1->data << " ";
start1 = start1->next;
}

return 0;
}
