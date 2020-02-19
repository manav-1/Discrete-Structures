/*
	Name: Question 5
	Copyright: 
	Author: Manav Arora and Tushti Adlakha
	Date: 13/02/18 9:15
	Description: This program prints Fibonacci series using recursion 
*/

#include<iostream>
#include<conio.h>
using namespace std;
class Fibonacci
{
	public:
	// To calculate the fibonacci series using recursion
	int fibo(int n)
	{
		if(n==0||n==1)
		{
		   return n;
	    }
		else
		{
		   return (fibo(n-1)+fibo(n-2));
	    }
	}
};
int main()
{
	Fibonacci obj;
	int n,sum=0;
	cout<<"\n Enter the number of terms :: ";
	cin>>n;
	cout<<"\n The Fibonacci series is :: ";
	// To print Fibonacci series
	for(int i=0;i<n;i++)
	{
	   cout<<" "<<obj.fibo(i);
	   sum+=obj.fibo(i);
    }
	cout<<endl;
	cout<<"\n The sum of Fibonaaci series is ::  "<<sum;
	cout<<"\n\n Press Enter to continue...";
	getch();
	return 0;
}
