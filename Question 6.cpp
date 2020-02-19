/*
	Name: Question 6
	Copyright: 
	Author:  Manav Arora and Tushti Adlakha
	Date: 13/04/18 14:40
	Description:  This program calculates the minimum number of moves
	              required to solve Tower Of Hanoi
        
*/
#include<iostream>
#include<conio.h>
using namespace std;
class TOH
{
	public:
		//Function to return minimum number of moves
		int toh(int n)
		{
			if(n==1)
			return 1;
			else
			return (2*toh(n-1))+1;
		}
};
int main()
{
	TOH obj;
	int n;
	//Input for number of disks
	cout<<"\nEnter the number of disks :: ";
	cin>>n;
	int result=obj.toh(n);
	cout<<"\nThe minimum number of moves is "<<result;
	getch();
	return 0;
}

