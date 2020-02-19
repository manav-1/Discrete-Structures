/*
	Name: Question 14
	Copyright: 
	Author:  Manav Arora and Tushti Adlakha
	Date: 13/04/18 13:40
	Description:  This program generates result recursively to different fuctions.
*/
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class Recursion
{
	public:
		//Function to generate result to first function
	int R1(int n)
	{
		if(n==0)
		return 1;
		else
		return R1(n-1)+n; 
	}
	//Function to generate result to second function
	int R2(int n)
	{
		if(n==0)
		return 1;
		else
		return R2(n-1)+pow(n,2);
	}
	//Function to generate result to third function
	int R3(int n)
	{
		if (n==1)
		return 1;
		else 
		return 2*R3(n/2)+n;
	}
};
int main()
{
	Recursion obj;
	int n,x;
	cout<<"\nChoose option from menu\n";
	cout<<"\n1. T(n)+n \n";
	cout<<"\n2. T(n-1)+n^2 \n";
	cout<<"\n3.T(n/2)+n\n";
	cin>>x;
	switch(x)
	{
		case 1:
			{
			  cout<<"\nEnter n ::";
			  cin>>n;
			  int result=obj.R1(n);
			  cout<<"The result is "<<result;
			  break;
			}
		case 2:{
			cout<<"\nEnter n ::";
			cin>>n;
			int result=obj.R2(n);
			cout<<"The result is "<<result;
			break;
		}
		case 3:{
			cout<<"\nEnter n ::";
			cin>>n;
			int result=obj.R3(n);
			cout<<"The result is "<<result;
			break;
		}
	}
}
