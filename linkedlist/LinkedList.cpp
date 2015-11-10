#include<iostream>
#include<assert.h>
using namespace std;

// insertion deletion getcount search swap getNthnode deleteGivenNode printMiddle printNthFromLast occurence reverse reverseInGroupOfSize
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

//insert at begining
node* insertAtFront(node* head,int data)
{
	node* temp=getNewNode(data);
	temp->data=data;
	temp->next=head;
	head=temp;
	return head;
}

node* insertAtAnyPosition(node* head,int data,int n)
{
	node* temp=new node();
	temp->data=data;
	temp->next=NULL;
	if(n==1)
	{
		temp->next=head;
		head=temp;
		return head;
	}
	node* temp1=head;
	for(int i=0;i<n-2;i++)
	{
	temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
	return head;
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

node* deleteNode(node* head,int n)
{
	node* temp1=head;
	if(n==1)
	{
		head=temp1->next;
		delete temp1;
		return head;
	}
	for(int i=0;i<n-2;i++)
	{
		temp1=temp1->next; 
	}
	// temp1 points to (n-1)th node
	node* temp2=temp1->next;// temp2 points to nth node
	temp1->next=temp2->next;
	delete temp2;
	return head;
}

int getcount(node* head)
{
	int count=0;
	node* temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
		return count;
}

node* Search(node* head,int data)
{
	node* current=head;
	while(current!=NULL)
	{
		if(current->data==data)
		{
			cout<<"found";
			return head;
		}
		current=current->next;
	}
	cout<<"not found";
	return head;
}

node* swap(node* head,int x,int y)
{
	//conditions to be checked
	//1) x and y may not be present in ll
	//2) x and y may not be adjacent
	//3) x or y may be head node or last node
	if(x==y)
	return head;
	// Searching for x
	node* prevX=NULL;
	node* currX=head;
	while(currX!=NULL && currX->data!=x)
	{
		prevX=currX;
		currX=currX->next;
	}
	// Searching for y
	node* prevY=NULL;
	node* currY=head;
	while(currY!=NULL && currY->data!=y)
	{
		prevY=currY;
		currY=currY->next;
	}
	// if any of x or y not present
	if(currX==NULL || currY==NULL)
	{
		return head;
	}
	//if x is not head of ll
	if(prevX!=NULL)
	prevX->next=currY;
	else // if x is head node then make y as head node
	head=currY;
	
	//if y is not head of ll
	if(prevY!=NULL)
	prevY->next=currX;
	else // if y is head node then make x as head node
	head=currX;
	
	//swap next pointers
	node* temp=currY->next;
	currY->next=currX->next;
	currX->next=temp;
	return head;
}
/* Takes head pointer of the linked list and index  as arguments and return data at index*/
int getNthnode(node* head,int pos)
{
	node* temp=head;
	int count=0; //the current node at index 0 we r pointing to presently
	while(temp!=NULL)
	{
		if(count==pos)
		return (temp->data);
		temp=temp->next;
		count++;
	}
	/* if we get to this line, the caller was asking for a non-existent element so we assert fail */
    assert(0);     
}

//given only a pointer to the node to be deleted how do u delete it?
void deleteGivenNode(node* nodeptr)
{
	node* temp=nodeptr->next;
	nodeptr->data=temp->data;
	nodeptr->next=temp->next;
	delete(temp);
}

void printMiddle(node* head)
{
	node* slow_ptr=head;
	node* fast_ptr=head;
	if(head!=NULL)
	{
	while(fast_ptr!=NULL && fast_ptr->next!=NULL)
	{
		fast_ptr=fast_ptr->next->next;
		slow_ptr=slow_ptr->next;
	}
	cout<<"middle element is:  "<<slow_ptr->data;
	}
}

void printNthFromLast(node* head,int n)
{
	int len=getcount(head);
	node* temp=head;
	if(len<n)
	return;
	for(int i=1;i<(len-n+1);i++)
	{
		temp=temp->next;
	}
	cout<<"\n\nnth element from last is:  "<<temp->data;
}

void printNthFromLast2(node* head,int n)
{
	node* ref_ptr=head;
	node* main_ptr=head;
	int count=0;
	if(head!=NULL)
	{
		while(count<n)
		{
			if(ref_ptr==NULL)
			{
				cout<<"n is greater than elements in the linked list"<<endl;
				return;
			}
			ref_ptr=ref_ptr->next;
			count++;
		}//now ref_ptr points at nth node
		while(ref_ptr!=NULL)
		{
			main_ptr=main_ptr->next;
			ref_ptr=ref_ptr->next;
		}
		cout<<"\n\nnth node from last by method2 is:  "<<main_ptr->data;
	}
}

//function that counts the no. of occurences of a node
int occurence(node* head,int x)
{
	struct node* current = head;
    int count = 0;
    while (current!= NULL) 
    {
        if (current->data == x)
           count++;
        current = current->next;
    }
    return count;
}

node* reverse(node* head)
{
	node* prev=NULL;
	node* current=head;
	node* next;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return head;
}

node* reverseRecurssion(node* head)
{
	if(head==NULL)
	return head;
	
	reverseRecurssion(head->next);

	cout<<head->data<<"  ";
	return head;
}

node* reverseInGroupsOfGivenSize(node* head,int k)
{
	node* prev=NULL;
	node* next;
	node* current=head;
	int count=0;
	while(current!=NULL && count<k)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	//now next points to (k+1)th node
	if(next!=NULL)
	{
		head->next=reverseInGroupsOfGivenSize(current,k);
	}
	return prev;
}

node* reverseAlternateKNodes(node* head,int k)
{
	node* prev=NULL;
	node* next;
	node* current=head;
	int count=0;
	while(current!=NULL && count<k)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	// now head points to kth node so change next of head to (k+1)th node
	//(suppose 3 elements are reversed i.e 2->4->6->8 here head is at 2 after reversing 3 nodes it will be 6->4->2->8 
	//so now head points at third place as 2 is at third place and prev also points at third place so return head)
	if(head!=NULL)
	{
		head->next=current;
	}
	count=0;
	//skip k nodes
	while(count<k-1 && current!=NULL)
	{
		current=current->next;
		count++;
	}
	if(current!=NULL)
	{
		current->next=reverseAlternateKNodes(current->next,k);//attach rest of the list after kth nodes
	}
	return prev;
}

//delete nodes having higher value on right side
// algo: reverse the list and assign max to head if next node < max delete the node and if next node > max do max = next node
node* delNodesWithGreaterValueOnRight(node* head)
{
	node* current=head;
	node* temp;
	node* maxnode=head;
	while(current!=NULL && current->next!=NULL)
	{
		if(current->next->data <= maxnode->data)
		{
			temp=current->next;
			current->next=temp->next;
			delete temp;
		}
		else
		{
			current=current->next;
			maxnode=current;
	 	}
	}
   return head;
}
node* _delNodesWithGreaterValueOnRight(node* head)
{
	head=reverse(head);
	head=delNodesWithGreaterValueOnRight(head);
	head=reverse(head);
	return head;
}

bool compareList(node* head1,node* head2)
{
	node* temp1=head1;
	node* temp2=head2;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data==temp2->data)
		{
			temp1=temp1->next;
			temp2=temp2->next;
			return true;	
		}
		else
		return false;
	}	
	if(temp1==NULL && temp2==NULL)
	return true;
	else
	return false;
}

bool isPalindrome(node* head)
{
	node* second_ptr;
	node* slow_ptr=head;
	node* prev_slow_ptr=head;
	node* fast_ptr=head;
	node* midnode=NULL; //for odd length
	bool result=true;
	if(head!=NULL && head->next!=NULL)
	{
		//let slow ptr points at the middle node and reverse the second half and compare both first half and second half if both are same palindrome
		//reverse again the second half and join to the first half
		while(fast_ptr!=NULL && fast_ptr->next!=NULL)
		{
			fast_ptr=fast_ptr->next->next;
			prev_slow_ptr=slow_ptr;
			slow_ptr=slow_ptr->next;
		}
		// for ll with even length fast_ptr will be null and with odd length it wont be null
		if(fast_ptr!=NULL)
		{
			midnode=slow_ptr;
			slow_ptr=slow_ptr->next;
		}
		// now reverse the second half
		second_ptr=slow_ptr;
		prev_slow_ptr->next=NULL;
		second_ptr=reverse(second_ptr);
		result=compareList(head,second_ptr);
		//construct the original list back
		second_ptr=reverse(second_ptr);
		if(midnode!=NULL)
		{
			prev_slow_ptr->next=midnode;
			midnode->next=second_ptr;
		}
		else
			prev_slow_ptr->next=second_ptr;
	}
	return result;
}

//removing duplicates from unsorted ll
void removeDuplicates(node* head)
{
	node* ptr1=head;
	node* ptr2;
	node* dup;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1;
		while(ptr2->next!=NULL)
		{
			if(ptr1->data==ptr2->next->data)
			{
				dup=ptr2->next->next;
				delete ptr2->next;
				ptr2->next=dup;
			}
			else
			{
				ptr2=ptr2->next;
			}
		}
		ptr1=ptr1->next;
	}
}

//pairwise swap elements
void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

node* swapPairwise(node* head)
{
	node* current = head;
	while(current!=NULL && current->next!=NULL)
	{
			swap(&current->data,&current->next->data);
			current=current->next->next;
	}
	return head;
}

//move last node to front
node* moveToFront(node* head)
{
	node* current=head;//points to last node
	node* prev=head;//points to second last node
	if(current==NULL || current->next==NULL)
	return head;
	
	while(current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	prev->next=NULL;
	current->next=head;
	head=current;
	return head;
}

void deleteAlternateNode(node* head)
{
	node* prev=head;
	node* current=head->next;
	if(head==NULL)
	return;
	while(prev!=NULL)
	{
		prev->next=current->next;
		delete current;
		prev=prev->next;
		if(prev!=NULL)
		{
			current=prev->next;
		}
	}
}

//Alternating Split
void moveNode(node** sourcehead,node** desthead)
{
	/* Take the node from the front of the source, and move it to the front of the dest.
   It is an error to call this with the source list empty. 
    
   Before calling MoveNode():
   source == {1, 2, 3}   
   dest == {1, 2, 3}
       
   Affter calling MoveNode():
   source == {2, 3}      
   dest == {1, 1, 2, 3}  */    

	node* temp=*sourcehead;
	// expression in assert if returns true then it will do nothing and 
	//if it returns false it will stop execution and display error in stderr(standard error message display)
	assert(temp!=NULL);
	
	//advance the source head point
	*sourcehead=temp->next;
	//build link in dest ll
	temp->next=*desthead;
	*desthead=temp;
}
// puts each element in front(order is changed)
void AlternatingSplit(node** sourcehead,node** headA,node** headB)
{
	node* a=NULL;
	node* b=NULL;
	node* current=*sourcehead;
	while(current!=NULL)
	{
		moveNode(&current,&a);
		if(current!=NULL)
		moveNode(&current,&b);
	}
	*headA=a;
	*headB=b;
}
//without changing the order
void AlternatingSplitWithoutChangingOrder(node**sourcehead,node** headA,node** headB)
{
	node dumyA;
	node* tailA=&dumyA; //points at last node in list a
	node dumyB;
	node* tailB=&dumyB; //points at last node in list b
	node* current=*sourcehead;
	dumyA.next=NULL;
	dumyB.next=NULL;
	while(current!=NULL)
	{
		moveNode(&current,&tailA->next);
		tailA=tailA->next;
		if(current!=NULL)
		{
			moveNode(&current,&tailB->next);
			tailB=tailB->next;
		}
	}
	*headA=dumyA.next;
	*headB=dumyB.next;
}

//segregate even and odd nodes together such that all even nos. appear before all odd nos.
//algo: move all odd no. at the end of the list.
node* segregate(node* head)
{
	node* current=head;
	node* prev=NULL;
	node* end=head;
	while(end->next!=NULL)
	{
		end=end->next;//get pointer to the last node.
	}
	node* new_end=end;
	//consider all odd nodes before first even node and move them at the end of the list
	while(current->data%2!=0 && current!=end)
	{
		new_end->next=current;
		current=current->next;
		new_end->next->next=NULL;
		new_end=new_end->next;
	}
	//if there is any even node
	if(current->data%2==0)
	{
		//make head ptr point to first even node.
		head=current;
		while(current!=end)
		{
			if(current->data%2==0)
			{
				prev=current;
				current=current->next;
			}
			else
			{
				//mving odd node at the end
				prev->next=current->next;
				current->next=NULL;
				new_end->next=current;
				new_end=current;
				current=prev->next;
			}
		}
	}
	else
	prev=current;
	/* If there are more than 1 odd nodes and end of original list is
      odd then move this node to end to maintain same order of odd
      numbers in modified list */
    if (new_end!=end && (end->data)%2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
	return head;
}

/*First List: 5->6->3  // represents number 365
  Second List: 8->4->2 //  represents number 248
Output:
  Resultant list: 3->1->6  // represents number 613*/
node* AddTwoLL(node* headA,node* headB)
{
  	node* res=NULL;
  	node* prev=NULL;
  	node* temp;
  	int carry=0,sum=0;
  	while(headA!=NULL && headB!=NULL)
  	{
  		sum=carry+(headA?headA->data:0)+(headB?headB->data:0);
  		carry=(sum>10)?1:0;
  		sum=(sum>10)?(sum%10):sum;
  		temp=getNewNode(sum);
  		if(res==NULL)
  		{
  			res=temp;	
		}
		else//if it is not first node
		prev->next=temp;
		prev=temp;
		if(headA)
			headA=headA->next;
		if(headB)
			headB=headB->next;
	}
	if(carry>0)
	{
	temp=getNewNode(carry);
	prev->next=temp;
	}
	return res;
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
	cout<<endl;
}

int main()
{
	node* head=NULL;
	head=insertAtEnd(head,9);//9
	head=insertAtEnd(head,4);//948	 
	head=insertAtEnd(head,8);//9-4-8
	head=insertAtFront(head,3);//3-9-4-8
	head=insertAtFront(head,2);//2-3-9-4-8     
	head=insertAtFront(head,1);//123948 
	head=insertAtAnyPosition(head,4,3);//1243948
	head=insertAtFront(head,6);//61243948
	head=insertAtAnyPosition(head,5,4);//612543948
	head=insertAtFront(head,2);//2612543948
	head=insertAtFront(head,7);//72612543948	
	print(head);
	head=deleteNode(head,2);
	cout<<"\nAfter deleting node at given position:  ";		//deleting at position 3 not the number 3
	print(head);
	int count=getcount(head);
	cout<<"\nLength of Linked List is: "<<count<<endl<<endl;
//	Search(head,6)?cout<<"found":cout<<"not found";
	head=Search(head,2);
	cout<<endl<<endl;
	head=swap(head,6,9);// swaping
	cout<<"After swapping:  ";
	print(head);
	cout<<"\nnode at position 4 is "<<getNthnode(head,4)<<endl<<endl;
	deleteGivenNode(head);
	cout<<"Delete give node:  ";
	print(head);
	cout<<endl;
	printMiddle(head);
	printNthFromLast(head,5);
	printNthFromLast2(head,5);
	cout<<"\n\noccurence of 2 is:  "<<occurence(head,2)<<endl;
	head=reverse(head);
	cout<<"\nAfter reversing using iterative method:  ";
	print(head);
	head= reverseInGroupsOfGivenSize(head,3);
	cout<<"\nAfter reversing in groups:  ";
	print(head);
	head=reverseAlternateKNodes(head,2);
	cout<<"\nAfter reversing Alternate K Nodes:  ";
	print(head);
	//check by removing comments.
/*	head=_delNodesWithGreaterValueOnRight(head);
	cout<<"\nDeleting Nodes With Greater Value On Right Side:  ";
	print(head);*/
	cout<<"\nAfter reversing using recurssion:  ";
	head=reverseRecurssion(head);
	cout<<"\n\nAfter removing Duplicates:  ";
	removeDuplicates(head);
	print(head);
	cout<<"\nSwaping Pairwise:  ";
	head=swapPairwise(head);
	print(head);
	cout<<"\nMoving Last Node To Front:  ";
	head=moveToFront(head);
	print(head);
	cout<<"\nSegregate even and odd together:  ";
	head=segregate(head);
	print(head);
	cout<<"\nDelte Alternate Node:  ";
	deleteAlternateNode(head);
	print(head);
	isPalindrome(head)?cout<<"\nisPalindrome":cout<<"\nis not palindrome";
	node* a=NULL;
	node* b=NULL;
	//choose any method
/*	AlternatingSplit(&head,&a,&b);
	cout<<"\n\nResulting Linked List of a:  ";
	print(a);
	cout<<"\nResulting Linked List of b:  ";
	print(b);*/
	AlternatingSplitWithoutChangingOrder(&head,&a,&b);
	cout<<"\n\nResulting Linked List of a:  ";
	print(a);
	cout<<"\nResulting Linked List of b:  ";
	print(b);
	cout<<"\nAdding two Linked List:  ";
	head=AddTwoLL(a,b);
	print(head);
	return 0;
}
