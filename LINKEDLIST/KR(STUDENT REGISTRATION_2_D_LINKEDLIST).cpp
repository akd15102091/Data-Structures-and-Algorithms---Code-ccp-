#include<iostream>
using namespace std;

typedef struct rnode* rptr;

union regnode {
int roll;	//f1 
char subname;	//f2
};

struct rnode {
int f1;
union regnode u;
rptr rnext;
rptr rlink;
};

void addSub(rptr head)
{
	rptr temp = NULL;
	temp = new(rnode);
	temp->f1 = 2;
	cin>>temp->u.subname;
	temp->rlink = NULL;
	temp->rnext = NULL;
	if (head->rnext == NULL)
    	head->rnext = temp;
	else
	 {
		rptr crawl = head->rnext;
		while (crawl->rnext != NULL)
		crawl = crawl->rnext;
		crawl->rnext = temp;
	}
}

void addStd(rptr head)
{
	rptr temp = NULL;
	temp = new(rnode);
	temp->f1 = 1;
	int n;
	cin >> n;
	temp->u.roll = n;
	temp->rlink = NULL;
	temp->rnext = NULL;
	if (head->rlink == NULL)
	head->rlink = temp;
	else 
	{
		rptr crawl = head->rlink;
		while (crawl->rlink)
		crawl = crawl->rlink;
		crawl->rlink = temp;
	}
}

rptr tempGen()
{
	rptr temp = NULL;
	temp = new(rnode);
	temp->f1 = 5;
	temp->rlink = NULL;
	temp->rnext = NULL;
	return temp;
}

void regStd(rptr sub, rptr stud)
{
	int roll = (stud->u.roll);
	while (sub)
	{
		rptr sub1 = sub;
		cout << " " << sub->u.subname << " \t y/n \t";
		char yorn;
		cin >> yorn;
	if (yorn == 'y')
	{
		rptr temp = tempGen();
		while (sub1->rlink)
		sub1 = sub1->rlink;
		sub1->rlink = temp;
		stud->rnext = temp;
		stud = stud->rnext;
		
	}
	sub = sub->rnext;
	}
	cout << "\nRegistration for " << roll << " was successful \n";
}

void regAll(rptr stud, rptr sub)
{

	while (stud)
	{
		cout << "\nRegistration for " << (stud->u.roll) << " is started \n";
		regStd(sub, stud);
		stud = stud->rlink;
	}

}

void linkSub(rptr head)
{
	rptr ref = head;
	while (head->rnext)
	{
	    head = head->rnext;
	}
	head->rnext = ref;
}

void linkStd(rptr head)
{
	rptr ref = head;
	while (head->rlink)
	{
	   head = head->rlink;
	}
	head->rlink = ref;
}

void linkAllStd(rptr sub)
{
	while (sub)
	{
    	linkStd(sub);
    	sub = sub->rnext;
	}
}

void linkAllSub(rptr std)
{
	while (std)
	{
	linkSub(std);
	std = std->rlink;
	}
}

void showAllStd(rptr std)
	{
	while (std)
	{
	cout << std->u.roll << " ";
	std = std->rlink;
	}
}

void showAllSub(rptr sub)
{
	while (sub)
	{
	cout << sub->u.subname << " ";
	sub = sub->rnext;
	}
}

void PrintStd(rptr head)
{
	rptr ref = head;
	while (head->f1 > 3)
	{
	head = head->rnext;
	}
	cout << head->u.roll << " ";
}

void PrintSub(rptr head)
{
	rptr ref = head;
	while (head->f1 > 3)
	{
	head = head->rlink;
	}
	cout << head->u.subname << " ";
}
void PrintAllStd(rptr head)
{
	head = head->rlink;
	while (head->f1 != 2 && head->f1 != 1)
	{
	PrintStd(head);
	head = head->rlink;
	}
}

void PrintAllSub(rptr head)
{
	head = head->rnext;
	while (head->f1 != 2 && head->f1 != 1)
	{
	PrintSub(head);
	head = head->rnext;
	}
}


int main()
{
	rptr mnode = NULL;
	mnode = new(rnode);
	mnode->rlink = NULL;
	mnode->rnext = NULL;
	cout << "Enter the subject names \n";
	for (int i = 0; i < 3; i++)
	addSub(mnode);
	cout << "\nEnter the roll no. \n";
	for (int i = 0; i < 3; i++)
	addStd(mnode);
	cout << "\nAvailable subjects ";
	showAllSub(mnode->rnext);
	cout << endl;
	regAll(mnode->rlink, mnode->rnext);
	
	linkAllSub(mnode->rlink);
	linkAllStd(mnode->rnext);
	cout << "\n\n";
	cout << "\nStudent registered  ";
	showAllStd(mnode->rlink);
	cout << "\n*****************************************************/n";
	cout << "Want to search for \n1.Students registered for a sub";
	cout << "\n2Subject registered by a student\nPlease respond correctly\t";
	int resp;
	cin >> resp;
	cout << endl;
	if (resp == 1)
	{
		cout << "Enter the subject code : ";
		cout << "\nAvailable subjects ";
		showAllSub(mnode->rnext);
		//cin.ignore();
		char sbj;
		cin >> sbj;
		while (mnode->u.subname != sbj)
		mnode = mnode->rnext;
		PrintAllStd(mnode);
	}
	else if (resp == 2)
	{
		cout << "Enter the roll no : ";
		cout << "\nStudent registered  ";
		showAllStd(mnode->rlink);
		cout << endl;
		int rno;
		cin >> rno;
		while (mnode->u.roll != rno)
		mnode = mnode->rlink;
		PrintAllSub(mnode);
	}
	return 0;
}
