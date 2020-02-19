/*
  Name:  Question 7
  Copyright: 
  Author: Manav Arora and Tushti Adlakha
  Date: 13/02/18 09:37
  Description: Binary search uisng recursion
*/
#include<iostream>
#include<conio.h>
using namespace std;
class Search
{
  private:
          int size,first,last;
          int * a;
  public:
  	//default constructor
Search()
{
    size=0;
    a=NULL;
}
//Function to enter size of array
void enter_size()
{
  cin>>size;
  a=new int[size];
  set();
}
//Function to set initial and final index values
void set()
{
     first=0;
     last=(size-1);
}
//fuction to display array
void show_array()
{
     for( int i=0;i<size;i++)
     cout<<a[i]<<" ";
}
//Function to sort array
void sort_array()
{
     for(int i=0;i<size;i++)
     {
             for(int j=0;j<(size-(i+1));j++)
             {
                     if(a[j]>a[j+1])
                     {
                       int temp=a[j+1];
                       a[j+1]= a[j];
                       a[j]=temp;
                     }
             }
     }                                  
}
//Function to input array
void input_array()
{
     for(int i=0;i<size;i++)
     {
       cout<<"\nEnter the "<<(i+1)<<" element :: ";
       cin>>a[i];
     }
sort_array();
}
//Function for binary search
int search_array(int n)
{
	if(last==-1|first==size)
    {
	return (-2);
	}
	int mid=(first+last)/2;
	if(a[mid]>n)
	{    
		last=mid-1;
		search_array(n);
	}
	else if(a[mid]<n)
	{
		first=mid+1;
		search_array(n);
	}
	else if(a[mid]==n) 
	{
		return mid;
	}
}
};
int main()
{
    Search obj;
    cout<<"\n Enter the size of array :: ";
    obj.enter_size();
    cout<<"\n Enter the elements of array :: \n";
    obj.input_array();
    char c='y';
    int check;
   do{
    system("cls");
    cout<<"\n\n The sorted array is :: ";
    obj.show_array();
    cout<<"\n\n Enter the element to be searched :: ";
    cin>>check;
    int result=obj.search_array(check);
    if(result==-2)
    {
       cout<<"\a\n\n The element is not found in the list\n\a\n";
    }
    else
    cout<<"\n\n\a The element is found in the list at position "<<result;
    
    cout<<"\n\n Do you want to enter more element(Y/N)";
    cin>>c;
    obj.set();
    }
    while(c=='Y'||c=='y');
    cout<<"\n\n\a!!PROGRAM TERMINATED!!\a\n";
    cout<<"Press Enter to continue...";
    getch();
    return 0;
}
