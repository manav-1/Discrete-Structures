/*
	Name: Question 12
	Copyright: 
	Author: Manav Arora and Tushti Adlakha
	Date: 13/04/18 14:15
	Description: This program prints all the possible combinations for n variables to get sum S.
*/
#include<iostream>
using namespace std;
class Combos
{
	public:
		//Function to diaplay combination
		void display (int b[],int n)
		{
			for (int i=0;i<n;i++)
			cout<<b[i]<<" ";
		}
		//Function to calculte possible combination
		int combos(int b[],int k,int n,int s)
		{
			if (k==0)
			{
				b[k]=s;
				display(b,n);
				cout<<"\n";
				return 0;
			}
			    for(int i=0;i<=s;i++)
				{
					b[k]=i;
					combos(b,k-1,n,s-i);
				}
			
		}
		
};
int main()
{
	Combos obj;
	int s,n;
	cout<<"Enter the no. of groups ::";
	cin>>n;
	cout<<"Enter the sum ::";
	cin>>s;
	int b[n];
	obj.combos(b,n-1,n,s);
	return 0;
}
