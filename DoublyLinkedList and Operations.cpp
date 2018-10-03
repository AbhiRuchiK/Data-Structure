#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
class ruchi
{
public:
int prime;
ruchi *next,*prev;
};

ruchi *head = NULL,*tail = NULL,*leadnode= NULL,*obj= NULL;

void create_linked_list(int number)
{
	obj = (ruchi*)calloc(1,sizeof(ruchi));
	obj->prime = number;
	if(head == NULL)
	{
	obj->prev = NULL;
	head = obj;
	}
	else
	{
		leadnode->next = obj;
		obj->prev = leadnode;		
	}
	obj->next = NULL;
	leadnode = obj;
}

void printnumber(ruchi* leadnode)
{

if(leadnode == NULL)
	return;
cout<<leadnode->prime<<"\n";
printnumber(leadnode->next);
}

void DeletioninMiddle(ruchi* node, int position, int j)
{
	if(j == position-2)
	{
		ruchi* temp = NULL;
		temp = node->next;
		node->next = temp->next;
		temp->next->prev = node;
		free(temp);
		return;
	}
	DeletioninMiddle(node->next, position, ++j);
}

void InsertatBeginning(int number, ruchi* node)
{
	obj = (ruchi*)calloc(1,sizeof(ruchi));
	obj->prime = number;
	obj->prev = NULL;
	obj->next = node;
	node->prev = obj;
	head = obj;
}

void InsertAfterGivenNode(int number, int pos, ruchi* node)
{
	if(node->prime == pos)
	{
		obj = (ruchi*)calloc(1,sizeof(ruchi));
		obj->prime = number;
		obj->prev = node;
		obj->next = node->next;
		node->next->prev = obj;
		node->next = obj;
		return;
	}
	InsertAfterGivenNode(number, pos, node->next);

}

void InsertatEnding(int number, ruchi* node)
{
	obj = (ruchi*)calloc(1,sizeof(ruchi));
	obj->prime = number;
	node->next = obj;
	obj->prev = node;
	obj->next = NULL;
	tail = obj;

}

void InsertBeforeGivenNode(int number, int pos, ruchi* node)
{
	if(node->prime == pos)
	{
		obj = (ruchi*)calloc(1,sizeof(ruchi));
		obj->prime = number;
		obj->next = node;
		node->prev->next = obj;
		obj->prev = node->prev;
		node->prev = obj;
		return;
	}
	InsertBeforeGivenNode(number, pos, node->next);
}

void main()
{
int primenumber,j, position;

for(int i = 0; i<100; i++)
{
	primenumber = rand()%(50, 7865);

	for(j = 2; j<=primenumber; j++)
	{
		if(primenumber%j == 0)
			break;
	}
	if(j == primenumber)
	{
		create_linked_list(primenumber);
	}
}
tail = obj;

printnumber(head);

cout<<"Enter Position to delete:\n";
cin>>position;

j = 0;
DeletioninMiddle(head, position, j);

cout<<"Remaining Prime Numbers after deletion:\n";
printnumber(head);

cout<<"Insert a number at the beginning:\nEnter Number:\n";
cin>>primenumber;

InsertatBeginning(primenumber, head);

cout<<"List after Insertion:\n";
printnumber(head);

cout<<"Enter number from above list after that node you want to insert a node:\n";
cin>>position;

cout<<"Enter Number you want to insert:\n";
cin>>primenumber;

InsertAfterGivenNode(primenumber,position, head);

cout<<"List after Insertion:\n";
printnumber(head);

cout<<"Insert a number at the end:\nEnter Number:\n";
cin>>primenumber;

InsertatEnding(primenumber, tail);

cout<<"List after Insertion:\n";
printnumber(head);

cout<<"Enter number from above list before that node you want to insert a node:\n";
cin>>position;

cout<<"Enter Number you want to insert:\n";
cin>>primenumber;

InsertBeforeGivenNode(primenumber,position, head);

cout<<"List after Insertion:\n";
printnumber(head);


_getch();
}

