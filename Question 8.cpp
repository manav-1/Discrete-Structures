/*
	Name: Question 8
	Copyright: 
	Author:  Manav Arora and Tushti Adlakha
	Date: 03/04/18 09:40
	Description:  This program performs Bubble sort on an array.
      
*/
#include<iostream>
using namespace std;
//Function to display array
void display(int*result,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<result[i]<<" ";
	}
}
//Function to perform Bubble sort
int* bubble_sort(int a[],int size)
{
	int temp,count=0,swap=0;
    for(int i=0;i<size;i++)
	{
		swap=0;
	    for(int j=0;j<size-(i+1);j++)
		{
			count++;
		   if(a[j]>a[j+1])
		   {
		   	   swap=1;
		       temp=a[j];
			   a[j]=a[j+1];
			   a[j+1]=temp;	
		   }	
		}
		if(swap==0)
		break;	
	}
	cout<<"\nThe total number of comparison are :: "<<count<<endl;
return a;	
}
int main()
{
	cout<<"Enter the number of elements :: ";
	int size;
	cin>>size;
	//Allocation of array
    int*a= new int [size];
    cout<<"\nEnter the elements of array :: \n";
    for(int i=0;i<size;i++)
    
    {
    	cin>>a[i];
    }
    int *result=bubble_sort(a,size);
    cout<<"\nThe sorted array is :: ";
    display(result,size);
    return 0;
}
