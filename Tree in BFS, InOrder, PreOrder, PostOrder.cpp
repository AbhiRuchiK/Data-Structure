#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class tree
{
public:
	int number;
	tree *left,*right;
};

class node: tree
{
public:
	tree *addr;
	node *next;
};

tree* LinkingNode(tree *RN, tree *NN)
{
	if(RN == NULL)
	{
		RN = NN;
		printf_s("Address of RN: %d\n", RN);
		printf_s("Number : %d\n",RN->number);
		return RN;
	}
	else if(NN->number < RN->number)
	{
		RN->left = LinkingNode(RN->left, NN);
		printf_s("RN left : %d\n", RN->left);
		return RN;
	}
	else
	{
		RN->right = LinkingNode(RN->right, NN);
		printf_s("RN right : %d\n", RN->right);
		return RN;
	}	
}


void BFS_Order(tree *RN)
{
	printf_s("\nPrint values of tree in BFS order:\n");
	node * NewLink,*leadnode = NULL,*headnode = NULL;;

	if(RN == NULL)
		printf("Empty Tree");
	else
	{
		NewLink = (node*)calloc(1,sizeof(node));
		NewLink->addr = RN;
		NewLink->next = NULL;
		if(headnode == NULL)
		{
			headnode = NewLink;
			leadnode = NewLink;
		}
		while (headnode != NULL)
		{
			if(headnode->addr->left != NULL)
			{
				NewLink = (node*)calloc(1,sizeof(node));
				NewLink->addr = headnode->addr->left;
				NewLink->next = NULL;
				leadnode->next = NewLink;
				leadnode = NewLink;
			}
			if(headnode->addr->right != NULL)
			{
				NewLink = (node*)calloc(1,sizeof(node));
				NewLink->addr = headnode->addr->right;
				NewLink->next = NULL;
				leadnode->next = NewLink;
				leadnode = NewLink;
			}
			printf_s("Number is : %d\n", headnode->addr->number);
			node *temp = headnode;
			headnode = headnode->next;
			free(temp);
		}
	}
}

void InOrder(tree *RN)
{
	if(RN == NULL)
	    return;

	InOrder(RN->left);

	cout<<RN->number<<"\n";

	InOrder(RN->right);
}

void PreOrder(tree *RN)
{
	if(RN == NULL)
	    return;

	cout<<RN->number<<"\n";

	PreOrder(RN->left);

	PreOrder(RN->right);
}

void PostOrder(tree *RN)
{
	if(RN == NULL)
	    return;

	PostOrder(RN->left);

	PostOrder(RN->right);

	cout<<RN->number<<"\n";
}

void main()
{
int i,n;
tree *RootNode = NULL,*NewNode;
cout<<"Enter 10 numbers:\n";
for(i = 0; i<10; i++)
{
	cin>>n;
	NewNode = (tree*)calloc(1,sizeof(tree));
	NewNode->number = n;
	NewNode->left = NULL;
	NewNode->right = NULL;

	RootNode = LinkingNode(RootNode, NewNode);
	printf_s("Adderss of RootNode :%d\n", RootNode);
	printf_s("Number : %d\n", RootNode->number);

}
BFS_Order(RootNode);

cout<<"Print tree in InOrder:\n";
InOrder(RootNode);

cout<<"Print tree in PreOrder:\n";
PreOrder(RootNode);

cout<<"Print tree in PostOrder:\n";
PostOrder(RootNode);
_getch();
}
