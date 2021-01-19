#include<stack>
#include <iostream>
using namespace std;

struct dlink {
int data;
//dlink* left;
dlink* right;
};

typedef dlink* dptr;

void create(dptr& head, int key)
{
dptr temp = NULL;
temp = new(dlink);
temp->data = key;
temp->right = NULL;
if ((head) == NULL)
{
head = temp;
}
else if ((head)->right == NULL)
{
(head)->right = temp;
}
else {
dptr khem = NULL;
khem = head;
while (khem->right != NULL)
{
khem = khem->right;
}
khem->right = temp;
}
}

void print(dptr head)
{
if (head == NULL) return;
else
{
cout << head->data << " ";
print(head->right);
}
}

/*void relate(dptr head)
{
if (head->right == NULL) return;
dptr last = head;
dptr temp = head->right;
if (last->right->right == NULL) return;
while (last->right->right != NULL)
{
last = last->right;
}
//cout << last->data << " ";
head->right = last->right;
head->right->right = temp;
last->right = NULL;
relate(temp);
}*/

/*dptr reverseLL(dptr* head, dptr* prev)
{
if (*head == NULL)	return *prev;
dptr next = (*head)->right;
(*head)->right = *prev;
return  reverseLL(&next, &(*head));
}*/

void addone(dptr h1, int carry)
{
if (h1->right == NULL)
{
if ((h1->data+carry) > 9)
{
cout << h1->data << "+" << carry << endl;
h1->data = ((h1->data + carry) % 10);
dptr ans = NULL;
ans = new(dlink);
ans->right = NULL;
ans->data = 1;
h1->right = ans;
}
}
else {
if ((h1->data + carry) > 9)
{
cout << h1->data << "+" << carry << endl;

h1->data = (h1->data + carry) % 10;
carry = 1;
}
else {
h1->data = (h1->data + carry);
carry = 0;
}
addone(h1->right, carry);
}
}

dptr add(dptr l1, dptr l2,int carry)
{
dptr ans = NULL;
ans = new(dlink); 
ans->right = NULL;
if (l1->right == NULL && l2->right == NULL)
{
cout << l1->data << "+" << l2->data << "+" << carry << endl;
ans->data = l1->data + l2->data + carry;
if (ans->data > 9) {
ans->data = (ans->data) % 10;
dptr car = NULL;
car = new(dlink);
car->data = 1;
car->right = NULL;
ans->right = car;
}
return ans;
}
else if (l1->right != NULL && l2->right != NULL)
{
cout << l1->data << "+" << l2->data << "+" << carry << endl;
ans->data = l1->data + l2->data + carry;
if (ans->data > 9)
{
ans->data = (ans->data) % 10;
carry = 1;
}
else carry = 0;
ans->right = add(l1->right, l2->right, carry);
return ans;
}
else if (l1->right != NULL && l2->right == NULL)
{
cout << l1->data << "+" << l2->data << "+" << carry << endl;
ans->data = l1->data + l2->data + carry;
if (ans->data > 9)
{
ans->data = (ans->data) % 10;
addone(l1->right, 1);
}
ans->right = l1->right;
return ans;
}
else if (l1->right == NULL && l2->right != NULL)
{
cout << l1->data << "+" << l2->data << "+" << carry << endl;
ans->data = l1->data + l2->data + carry;
if (ans->data > 9)
{
ans->data = (ans->data) % 10;
addone(l2->right, 1);
}
ans->right = l2->right;
return ans;
}
}

int main()
{
dptr head = NULL,tail = NULL;
cout << "Enter the number of entries\n";
int n, m;
cin >> n;
for (int i = 0; i < n; i++)
{
cin >> m;
create(head, m);
}
dptr ref = head;
cout << endl;
//sortLL(head, ref);
//head = reverseLL(&head,&prev);
//relate(head);
cout << "Enter the number of entries\n";
cin >> n;
for (int i = 0; i < n; i++)
{
cin >> m;
create(tail, m);
}
head = add(head,tail, 0);
//addone(tail, 1);
cout << "Answer is ";
print(head);

return 0;
}

