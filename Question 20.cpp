/*
	Name: Question 20
	Copyright: 
	Author: Manav Arora and Tushti Adlakha
	Date: 11/04/18 16:15
	Description: This program evaluates the number of leaves of Tree
*/
#include<iostream>
#include<conio.h>
using namespace std;
class Tree
{
	private:
	int m,i;
	public:
	Tree()
	{
		m=0;
		i=0;
	}
    Tree(int M,int I)
    {
    	m=M;
    	i=I;
	}
	int cal_leaves();
};
//Function to evalute the number of leaves
int Tree::cal_leaves()
{
	return((m-1)*i)+1;
}
int  main()
{
      	int m,i;
    	//Input of m for m-ary Tree
		cout<<"\n\nEnter the m :: ";
		cin>>m;
		cout<<"\n\nEnter the number of internal vertices(i) :: ";
		cin>>i;
		Tree obj(m,i);
		int result=obj.cal_leaves();
		cout<<"\n\nThe number of leaves are :: "<<result;
		getch();
		return 0;
}

