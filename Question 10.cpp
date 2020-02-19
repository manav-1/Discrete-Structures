 /*
	Name: Question 10
	Copyright: 
	Author:  Manav Arora and Tushti Adlakha
	Date: 16/04/18 12:15
	Description:  This program print all possible permutation of 
	            a given set of numbers without repetition and with repetition
      
*/
#include<iostream>
#include<conio.h>
#include<algorithm>
using namespace std;
class Combos
{
  public:
  	//Function to print all permutation without repetition
  void perm_without_repetition(int A[],int n,int b)
  {
     if(b==n-1)
	 {
	    for(int i=0;i<n;i++)
		cout<<A[i]<<" ";

		cout<<endl;  	
	 }
	 else
	 {
	 	for(int i=b;i<n;i++)
	 	{
	 	    swap(A[b],A[i]);
			perm_without_repetition(A,n,b+1);
			swap(A[b],A[i]);	
		}
	 }	
  }
   	//Function to print all permutation with repetition
  void perm_with_repetition(int A[],int B[],int n,int b)
  {
      	if(b==n)
	 {
	    for(int i=0;i<n;i++)
		cout<<B[i]<<" ";

		cout<<endl;  	
	 }
	 else
	 {
	 	for(int i=0;i<n;i++)
	 	{
	 	    B[b]=A[i];
			perm_with_repetition(A,B,n,b+1);	
		}
	 }
  }	
};
int main()
{
	Combos obj;
	 int n,b=0,x;
	 int*A,*B;
	cout<<"Enter the size of array :: ";
	cin>>n;
	A=new int [n];
	B=new int [n];
	cout<<"\nEnter the elements of array \n";
	for(int i=0;i<n;i++)
	cin>>A[i];
	cout<<"\nChoose a option from te menu\n";
	cout<<"\n1.Permutation without repetition";
	cout<<"\n2.Permutation with repetition\n";
	cin>>x;
	switch(x)
	{
		case 1:
		{
			obj.perm_without_repetition(A,n,b);
			break;
		}
		case 2:
		{
			obj.perm_with_repetition(A,B,n,b);
			break;
		}
	}
	
return 0;
}
