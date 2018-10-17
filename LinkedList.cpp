#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

class abhi
{
public:
	int prime;
	abhi *ptr;
};

abhi* lead= NULL;

void InsertPrimeNumber(int number)
{   
	abhi* NewPrime = (abhi*) calloc(1,sizeof(abhi));
	NewPrime->prime = number;
	if(lead == NULL)
	{
		NewPrime->ptr=NULL;
	}
	else
	{
		NewPrime->ptr=lead;
	}
	lead=NewPrime;
}

void PrintLinkedList(abhi* Node)
{
	if(Node==NULL)
		return;
	std::cout << Node->prime << "\t";
	PrintLinkedList(Node->ptr);
}

void DeletioninMiddle(abhi *Node,int position,int  position_reached)
{
	if(position_reached == position-2)
	{
		abhi *temp=NULL;
		temp = Node->ptr;
		Node->ptr = temp->ptr;
		free(temp);
		return;
	}
	DeletioninMiddle(Node->ptr,position,++position_reached);
}

void InsertioninMiddle(abhi *Node, int position, int position_reached, int number)
{
	if(position_reached == position-2)
	{
		abhi *NewNumber = NULL;
		NewNumber = (abhi*) calloc(1,sizeof(abhi));
		NewNumber->prime=number;
		NewNumber->ptr= NULL;
		NewNumber->ptr=Node->ptr;
		Node->ptr= NewNumber;
		return;
	}
	InsertioninMiddle(Node->ptr, position, ++position_reached, number);
}

void DeletionLIFO()
{
	abhi *temp=NULL;
	temp=lead->ptr;
	free(lead);
	lead=temp;
}

void DeletionFIFO(abhi *Node)
{
	if(Node->ptr->ptr == NULL)
	{
		free(Node->ptr->ptr);
		Node->ptr=NULL;
		return;
	}
	DeletionFIFO(Node->ptr);
}
void main()
{
	int arr[1000] ,i ,j ,position=0 ,position_reached=0;
	for(i=0; i<1000; i++)
	{
		arr[i]=rand();
		for(j=2; j<arr[i]; j++)
		{
			if(arr[i]%j == 0)
				break;
		}
		if(j==arr[i])
			InsertPrimeNumber(arr[i]);
	}
	PrintLinkedList(lead);
	std::cout<<"\n\nEnter Position of number\n\n";
	std::cin>>position;
	DeletioninMiddle(lead, position, position_reached);
	PrintLinkedList(lead);
	std::cout<<"\n\nDeletion at first using LIFO stack:\n";
	DeletionLIFO();
	std::cout<<"\nList after deletion LIFO:\n";
	PrintLinkedList(lead);
	std::cout<<"\nList after deletion FIFO:\n";
	DeletionFIFO(lead);
	PrintLinkedList(lead);
	std::cout<<"\n\nEnter Position of number for Insert:\n";
	std::cin>>position;
	std::cout <<"\nEnter value do u want to insert:\n";
	std::cin>>j;
	InsertioninMiddle(lead, position, position_reached,j);
	std::cout<<"\nList After insertion:\n";
	PrintLinkedList(lead);
	_getch();
}
