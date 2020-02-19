/*
	Name: Question 15
	Copyright: Manav Arora and Tushti Adlakha
	Author: 
	Date: 10/04/18 09:42
	Description: THis program calculates the value of a Polynomial for value of n.
*/

#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
class Polynomial
{
	private:
		int order;
		int *a;
	public:
		Polynomial()
		{
			order=0;
			a=NULL;
		}
		void input_order();
		void input_coeff();
		void show_poly();
		int evaluate(int n);
};
//Function to input order of polynomial
void Polynomial::input_order()
{
	cin>>order;
	order++;
	a=new int[order];
}
//Function to input the coefficients of polynomial
void Polynomial::input_coeff()
{
	for(int i=0;i<order;i++)
	{
		cout<<"\nEnter coefficient of x^"<<i<<" ::";
		cin>>a[i];
	}
}
//Function to evaluate value of polynomial for value of n
int Polynomial::evaluate(int n)
{
	int sum=0;
	for(int i=0;i<order;i++)
	{
		sum+=a[i]*pow(n,i);
	}
return sum;
}
//Function to show polynomial
void Polynomial::show_poly()
{
	for(int i=order-1;i>=0;i--)
	{
	  cout<<a[i]<<"n^"<<i<<"+";	
	}
	cout<<"\b ";
}
int main ()
{
	int n,result;
	Polynomial obj;
	cout<<"\nEnter the order of the polynomial ::";
	obj.input_order();
	obj.input_coeff();
	cout<<"\n\nThe Polynomial is :: ";
	obj.show_poly();
	cout<<"\n\nEnter the value of n ::";
	cin>>n;
	result=obj.evaluate(n);
	cout<<"\nf("<<n<<") = "<<result;
	getch();
	return 0;
	
}
