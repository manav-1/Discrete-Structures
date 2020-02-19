/*
	Name: Question 9
	Copyright: 
	Author:  Manav Arora and Tushti Adlakha
	Date: 03/04/18 10:04
	Description:  This program performs Insertion sort on an array.
*/
#include<iostream>
#include<conio.h>
using namespace std;
class Insertion
{
  int size;
  int*a;
  public:
  	//Default Constructor
  Insertion()
  {
      size=0;
	  a=NULL;	
  }	
  void enter_size();
  void enter_array();
  void insertion_sort();
  void display();
  
};
//Function to enter size of array
void Insertion::enter_size()
{   
	cin>>size;
	a=new int[size];
}
//Function to input array
void Insertion::enter_array()
{
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
}
//Function to display array
void Insertion::display()
{
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" "; 
	}
}
//Function to perform Insertion sort
void Insertion::insertion_sort()
{
	int j,k,count=0;
    for(int i=1;i<size;i++)
	{
	   int temp=a[i];
	   j=i-1;
	   while(j>=0&&a[j]>temp)
	   {
	   	  count++;
	   	  a[j+1]=a[j];
	   	  j--;
	   }	
	   a[j+1]=temp;
	}
cout<<"\nThe total number of comparison are :: "<<count<<endl;	
}
int main()
{
	Insertion obj;
	cout<<"Enter the size of array:: ";
	obj.enter_size();
	cout<<"\nEnter the elements of the array:\n";
	obj.enter_array();
	obj.insertion_sort();
	cout<<"\nThe sorted array is:: ";
	obj.display();
	return 0;
}
