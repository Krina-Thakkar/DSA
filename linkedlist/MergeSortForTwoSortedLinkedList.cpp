#include<iostream>
#include<assert.h>
using namespace std;

struct node
{
	int data;
	node* next;
};
//create a memory block
node* getNewNode(int data)
{
	node* temp = new node();
	temp->data=data;
	temp->next=NULL;
}

node* insertAtEnd(node* head,int data)
{
	node* temp=new node();
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	node* temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	return head;
}

void movenode(node** sourcehead,node** desthead)
{
	node* temp=*sourcehead;
	*sourcehead=temp->next;
	temp->next=*desthead;
	*desthead=temp;
}

node* mergeSortedLL(node* head1,node* head2)
{
	node dumy; // use a dumy node to hold a result
	node* tail=&dumy; // tail pointer that points to last node in dumy
	dumy.next=NULL; // the result will be in dumy.next
	while(1)
	{
		if(head1==NULL)//first part got exhausted
		{
			tail->next=head2;
			head2=head2->next;
			break;
		}
		else if(head2==NULL)//second part got exhausted
		{
			tail->next=head1;
			head1=head1->next;
			break;
		}
		else if(head1->data<=head2->data)
			movenode(&head1,&tail->next);
		else
			movenode(&head2,&tail->next);
	tail=tail->next;
	}
	return (dumy.next);
}

void print(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		cout<<"  ";
		temp=temp->next;
	}
	cout<<endl<<endl;
}

int main()
{
	node* head1=NULL;
	node* head2=NULL;
	node* res=NULL;
	
	head1=insertAtEnd(head1,5);
	head1=insertAtEnd(head1,25);
	head1=insertAtEnd(head1,30);
	head1=insertAtEnd(head1,35);
	head1=insertAtEnd(head1,40);
	
	head2=insertAtEnd(head2,2);
	head2=insertAtEnd(head2,3);
	head2=insertAtEnd(head2,20);
	
	cout<<"List a:  ";
	print(head1);
	
	cout<<"List b:  ";
	print(head2);
	
	cout<<"After Merging:  ";
	res=mergeSortedLL(head1,head2);
	print(res);
	
	return 0;
}
