#include<iostream>
using namespace std;

int binarysearch(int a[],int l,int u,int x) // array can also be passed as *a. it happens in backend as array is always pssed by refrence so ptr to array is passed.

{
	if(u>=l)
	{
	int mid=l+(u-l)/2;
	if(a[mid]==x)
	return mid;
	else if(a[mid]<x)
	return binarysearch(a,mid+1,u,x);
	else
	return binarysearch(a,l,mid-1,x);
	}
	return -1;
}

int main()
{
	int x;
	int a[]={2,3,4,10,40};
	int size = sizeof(a)/sizeof(a[0]);
	cout<<"enter value to be searched  ";
	cin>>x;
/*	int result = binarysearch(a, 0, size-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);  */
	cout<<"the element is at position "<<binarysearch(a, 0, size-1, x);
	return 0;
}
