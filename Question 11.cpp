/*
	Name: Question 11
	Copyright: 
	Author:  Manav Arora and Tushti Adlakha
	Date: 03/04/18 10:22
	Description:  This program calculates permutation and combination recursively.
*/
#include<iostream>
using namespace std;
class PnC
{
	int result1,result2;
    public:
    PnC()
    {
    	result1=0;
    	result2=0;
	}
	int permutation(int n,int r );
	int combination(int n,int r);
};
//Function to calculate permutation
int PnC::permutation(int n,int r)
{
	if(r>n)
	return 0;
	
	if(r==0)
	return 1;
	else
	result1= n*permutation(n-1,r-1);
	
return result1;
}
//Function to calculate combination
int PnC::combination(int n,int r)
{
	if(r>n)
	return 0;
	
	if(r==0)
	return 1;
	else
	result2=combination(n-1,r)+combination(n-1,r-1);
	
return result2;
}
int main()
{
	int n,r;
	cout<<"Enter n :: ";
	cin>>n;
	cout<<"\nEnter r :: ";
	cin>>r;
	PnC obj;
	int result1=obj.permutation(n,r);
	int result2=obj.combination(n,r);
	if(result1==0|result2==0)
	{
		cout<<"\n\aInvalid, 'n' can never be smaller than 'r'\a";
	}
	else
	{
	   cout<<"\nThe number of permutations are :: "<<result1;
	   cout<<"\nThe number of combinatons are :: "<<result2;
    }
}
