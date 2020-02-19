/*
	Name: Question 13
	Copyright: 
	Author:  Manav Arora and Tushti Adlakha
	Date: 10/04/18 09:40
	Description:  This program prints truth table for following :-
	1.Conjunction
    2.Disjunction
    3.Exclusive OR
	4.Conditional
	5.Bi-conditional
	6.Exclusive NOR
	7.Negation
	8.NAND
	9.NOR
	
*/
#include<iostream>
#include<conio.h>
using namespace std;
class truth_table
{
   public:	
   void conjunction();
   void disjunction();
   void Xor();
   void Xnor();
   void negation();
   void NAND();
   void  NOR();
   void conditional();
};
//Function to print truth table for conjunction
void truth_table::conjunction()
{
	int result;
     for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++)
	  {
	  	result=i&j;
	  	if(i==1)
	  	  cout<<" True  ";
	  	else
	  	  cout<<" False ";
	  	cout<<"|";
	  	if(j==1)
	  	  cout<<" True  ";
	  	else
	  	cout<<" False ";
	  	cout<<"|";
	  	if(result==1)
	  	cout<<" True  \n";
	  	else
	  	cout<<" False \n";
	  	
	  }
	 	
}
//Function to print truth table for disjunction
void truth_table::disjunction()
{
		int result;
     for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++)
	  {
	  	result=i|j;
	  	if(i==1)
	  	  cout<<" True  ";
	  	else
	  	  cout<<" False ";
	  	cout<<"|";
	  	if(j==1)
	  	  cout<<" True  ";
	  	else
	  	cout<<" False ";
	  	cout<<"|";
	  	if(result==1)
	  	cout<<" True  \n";
	  	else
	  	cout<<" False \n";
	  	
	  }
}
//Function to print truth table for XOR
void truth_table::Xor()
{
		int result;
     for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++)
	  {
	  	result=i^j;
	  	if(i==1)
	  	  cout<<" True  ";
	  	else
	  	  cout<<" False ";
	  	cout<<"|";
	  	if(j==1)
	  	  cout<<" True  ";
	  	else
	  	cout<<" False ";
	  	cout<<"|";
	  	if(result==1)
	  	cout<<" True  \n";
	  	else
	  	cout<<" False \n";
	  	
	  }
}
//Function to print truth table for NOR
void truth_table::NOR()
{
	int result;
     for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++)
	  {
	  	result=!(i|j);
	  	if(i==1)
	  	  cout<<" True  ";
	  	else
	  	  cout<<" False ";
	  	cout<<"|";
	  	if(j==1)
	  	  cout<<" True  ";
	  	else
	  	cout<<" False ";
	  	cout<<"|";
	  	if(result==1)
	  	cout<<" True  \n";
	  	else
	  	cout<<" False \n";
	  	
	  }
}
//Function to print truth table for NAND
void truth_table::NAND()
{
	
	int result;
     for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++)
	  {
	  	result=!(i&j);
	  	if(i==1)
	  	  cout<<" True  ";
	  	else
	  	  cout<<" False ";
	  	cout<<"|";
	  	if(j==1)
	  	  cout<<" True  ";
	  	else
	  	cout<<" False ";
	  	cout<<"|";
	  	if(result==1)
	  	cout<<" True  \n";
	  	else
	  	cout<<" False \n";
	  	
	  }
}
//Function to print truth table for XNOR
void truth_table::Xnor()
{
		int result;
     for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++)
	  {
	  	result=!(i^j);
	  	if(i==1)
	  	  cout<<" True  ";
	  	else
	  	  cout<<" False ";
	  	cout<<"|";
	  	if(j==1)
	  	  cout<<" True  ";
	  	else
	  	cout<<" False ";
	  	cout<<"|";
	  	if(result==1)
	  	cout<<" True  \n";
	  	else
	  	cout<<" False \n";
	  	
	  }
}
//Function to print truth table for conditional
void truth_table::conditional()
{
	
		int result;
     for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++)
	  {
	  	result=(!i)|j;
	  	if(i==1)
	  	  cout<<" True  ";
	  	else
	  	  cout<<" False ";
	  	cout<<"|";
	  	if(j==1)
	  	  cout<<" True  ";
	  	else
	  	cout<<" False ";
	  	cout<<"|";
	  	if(result==1)
	  	cout<<" True  \n";
	  	else
	  	cout<<" False \n";	
	  }
}
//Function to print truth table for negation
void truth_table::negation()
{
	int result;
     for(int i=0;i<=1;i++)
	  {
	  	result=!i;
	  	if(i==1)
	  	  cout<<" True  ";
	  	else
	  	  cout<<" False ";
	  	cout<<"|";
	  	if(result==1)
	  	cout<<" True  \n";
	  	else
	  	cout<<" False \n";	
	  }
}
int main()
{
	void menu(int x);
	char c='Y';
	int x;
	do{
		system("cls");
		cout<<"Select a option from menu to print its Truth Table \n";
		cout<<"1.Conjunction\n";
		cout<<"2.Disjunction\n";
		cout<<"3.Exclusive OR\n";
		cout<<"4.Conditional\n";
		cout<<"5.Bi-conditional\n";
		cout<<"6.Exclusive NOR\n";
		cout<<"7.Negation\n";
		cout<<"8.NAND\n";
		cout<<"9.NOR\n";
		cout<<"Choose a option from menu :: ";
		cin>>x;
		menu(x);
	    cout<<"\nDo you want to continue(Y/N)\n";
		cin>>c;	
	  }while(c=='Y'|c=='y');
	  cout<<"\n\a!!!!!!!!Program Terminated!!!!!!!!\n\a";
	  cout<<"\n  Press Enter To Continue...";
	  getch();
	  return 0;
}
void menu(int x)
{
	truth_table obj;
	switch(x)
	{
		case 1:{
			cout<<"   p    "<<"   q    "<<" p ^ q\n\n";
			obj.conjunction();
			break;
		}
		case 2:{
		    cout<<"   p    "<<"   q    "<<" p v q\n\n";
			obj.disjunction();
			break;
		}
		case 3:{
			cout<<"   p    "<<"   q    "<<" p (+) q\n\n";
			obj.Xor();
			break;
		}
		case 4:{
			cout<<"   p    "<<"   q    "<<" p->q\n\n";
			obj.conditional();
			break;
		}
		case 5:{
			 cout<<"   p    "<<"   q    "<<" p<->q\n\n";
			 obj.Xnor();
			break;
		}
		case 6:{
			 cout<<"   p    "<<"   q    "<<" (p (+) q)'\n\n";
			 obj.Xnor();
			break;
		}
		case 7:{
			cout<<"   p    "<<" p!\n\n";
			 obj.negation();
			break;
		}
		case 8:{
			cout<<"   p    "<<"   q    "<<" (p ^ q)'\n\n";
			 obj.NAND();
			break;
		}
		case 9:{
			cout<<"   p    "<<"   q    "<<" (p v q)'\n\n";
			 obj.NOR();
			break;
		}
		default:{
			system("cls");
			cout<<"\n  You have entered a wrong choice\n";
			cout<<"Press Enter To Continue...\n";
			getch();
			break;
		}
	}
	
}
