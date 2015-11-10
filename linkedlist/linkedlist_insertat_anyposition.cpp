#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node *head;

void insert(int data,int n)
{
	node *temp1=new node();
	temp1->data=data;   // (*temp).data=data
	temp1->next=NULL;
	if(n==1)
	{
		temp1->next=head;
		head=temp1;
		return;
	}
	node *temp2=head;
	for(int i=0;i<n-2;i++)
	{
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
}

void print()
{
	node *temp=head;
	if(temp!=head)
	{
		cout<<" "<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	head=NULL;
	insert(2,1);  //2
	insert(3,2);  //2 3
	insert(4,1);  //4 2 3 
	insert(5,2);  //4 5 2 3
	print();
}
