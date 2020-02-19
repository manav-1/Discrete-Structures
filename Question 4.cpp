/*
  Name: Question 4
  Copyright: 
  Author: Manav Arora and Tushti Adlakha
  Date: 23/01/18 15:09
  Description: This program take ordered pair of relations from user to check
	             following relations::
                  1.Check for equivalence relation
                  2.Check for partial-ordered relation
*/

#include<iostream>
#include<conio.h>
using namespace std;
class relation
{
	private:
		int **M;
		int*arr;
		int size;
	public:
		relation()
		{
			M=NULL;
			arr=NULL;
			size=0;
		} 
		void enter_size();
		void allocate_array();
		void show();
		bool check_reflexive();
		bool check_symmetric();
		bool check_transitive();
		bool check_antisymmetric();
		bool check_equivalence();
		bool check_partial_order();
		void relation_matrix(int row,int col);
		void allocate_matrix();
		void show_relation();
		void show_matrix();
		bool valid_relation(int x,int y);
		
}a;
void relation::show_matrix() //to display relation matrix
{
	for(int i=0;i<size;i++)
	  {
	  	for(int j=0;j<size;j++)
	  	{
	  	   cout<<" "<<M[i][j]<<" ";	
		}
		cout<<endl;
	  }
}
void relation::allocate_array() //to allocate array
{
	for(int i=0;i<size;i++)
	{
		arr[i]=i+1;
	}
}
void relation::enter_size() //to  input size form user
{
	cin>>size;
    arr=new int [size];
    allocate_array();
    allocate_matrix();
}
void relation::show() // to display set
{
	cout<<"{ ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ,";
	}
	cout<<"\b}\n";
}
void relation::allocate_matrix()
{
     //To allocate the relation matrix
    M=new int*[size];
	for(int i=0;i<size;i++)
	M[i]=new int[size];
	//To set all elements of relation_matrix to zero
	for(int i=0;i<size;i++)
       for(int j=0;j<size;j++)
          M[i][j]=0;
}
void relation::relation_matrix(int row,int col)
{   
    //To set given pairs of relation to one in relation matrix
    M[row-1][col-1]=1;
}
void relation::show_relation() //to display the ordered pair of realtions
{
     cout<<"{ ";
  for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
    {      
         if(M[i][j]==1)
             {    
                  cout<<"("<<i+1<<", "<<j+1<<"), ";
             }
    }
    }
    cout<<"\b\b }\n";
}
              
bool relation::check_reflexive()  //to check reflexivity
{
	bool check=false;
	for(int i=0;i<size;i++)
	{
			  if(M[i][i]==1)
			  {
				check=true;
			  }
			  else
			  {
				check=false;
				break;
			  }
	}
    return check;
}
bool relation::check_symmetric()  //to check symmetricity.
{ 

	bool check=false;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{  if(M[i][j]==1)
		  {
			if(M[i][j]==1&&M[j][i]==1)
			check=true;
			else
			{   
                check=false;
			    break;
            }
          }
		}
		if(!check)
		break;
	}
return check;
}
bool relation::check_antisymmetric() //to check anti-symmetricity.
{

	bool check=false;
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
	    { 
		    if(M[i][j]==1)
		    {
			     if((M[i][j]==1&&M[j][i]==1&&i==j)||(M[i][j]==1&&M[j][i]!=1))
			     check=true;
			     else
			    {
				check=false;
				break;
	            }
             }
		}
		if(!check)
		break;
	}
return check;	
}
bool relation::check_transitive()   //to check the transitivity.
{
	bool check=false;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{  
		  if(M[i][j]==1)
		   {
		  	 for(int k=0;k<size;k++)
		  	 {
			    if((M[j][k]==1&&M[i][k]==1)||M[j][k]!=1)
			     check=true;
			    else
				 {   
                 check=false;
			     break;
                 }
             }
             if(!check)
             break;
           }
		}
		if(!check)
		break;
	}
return check;	
}
bool relation::check_equivalence() //to check for equivalence realtion
{
	bool ref=check_reflexive();
	bool sym=check_symmetric();
	bool trans=check_transitive();
	if(ref&&sym&&trans)
	return true;
	else
	return false;
}
bool relation::check_partial_order() //to check for partial-ordered realtion
{
	bool ref=check_reflexive();
	bool antisym=check_antisymmetric();
	bool trans=check_transitive();
	if(ref&&antisym&&trans)
	 return true;
	else
	return false;
}
bool relation::valid_relation(int x,int y)
{
	if(x>size||y>size)
	return false;
	else
	return true;
}
int main()
{
	char c;
	void menu();
    void enter_relation();
	cout<<"\n\t THIS PROGRAM CONSIDERS THAT THE SET HAS CONSECUTIVE ELEMENTS \n";
	cout<<"\nEnter the size of array :: ";
	a.enter_size();
	cout<<"\n The set is ::";
    a.show();
	enter_relation();
	do	
     {    cout<<"\n The set is ::";
          a.show();
 	      cout<<"\n\n The entered ordered pairs are ::";
	      a.show_relation();
	      cout<<"\n\nThe Relation Matrix is ::\n";
	      a.show_matrix();
	      menu();
          cout<<"\n\nDo you want to continue(Y/N) :: ";
          cin>>c;
		  system("cls");    
	 }
	 while(c=='y'||c=='Y');
	return 0;
}                  
void enter_relation()
{
     int x,y;
     char c='y';
     cout<<"\n Enter the elements of ordered pair of relation in the form (a,b) ::\n";
     do{
         cout<<"\n Enter a ::";
         cin>>x;
         cout<<"\n Enter b ::";
         cin>>y;
         if(!a.valid_relation(x,y))
         cout<<"\nSorry, this is an invalid ordered pair\n";
         else
         {
          cout<<"\n Your entered ordered pair is ("<<x<<","<<y<<")\n";
          a.relation_matrix(x,y);
         }
          cout<<"\n Do you want to enter more ordered pair(Y/N)";
          cin>>c;
       }
    while(c=='y'||c=='Y');
    cout<<"\nPress Enter to continue....\n";
    getch();
    system("cls");
}
void menu()
{
          int x;
          cout<<"\n 1. Check if the relation is Equivalence Relation\n";
          cout<<"\n 2. Check if the relation is Partial Ordered Relation\n";
          cout<<"\n Choose the option from menu :: ";
          cin>>x;
          switch(x)
          {
              case 1:{
                   bool result1=a.check_reflexive();
                   if(result1)
                   cout<<"\n The relation is Reflexive\n";
                   else
                   cout<<"\n The relation is not Reflexive\n";
                     bool result2=a.check_symmetric();
                   if(result2)
                   cout<<"\n The relation is Symmetric\n";
                   else
                   cout<<"\n The relation is not Symmetric\n";
                   bool result3=a.check_transitive();
                   if(result3)
                   cout<<"\n The relation is Transitive\n";
                   else
                   cout<<"\n The relation is not Transitive\n";
                   bool result=a.check_equivalence();
                   if(result)
                   cout<<"\n Hence, The relation is Equivalence\n";
                   else
                   cout<<"\n Hence, The relation is not Equivalence\n";
                   break;
                   }
              case 2:{
                   bool result1=a.check_reflexive();
                   if(result1)
                   cout<<"\n The relation is Reflexive\n";
                   else
                   cout<<"\n The relation is not Reflexive\n";
                    bool result2=a.check_antisymmetric();
                   if(result2)
                   cout<<"\n The relation is Anti-Symmetric\n";
                   else
                   cout<<"\n The relation is not Anti-Symmetric\n";
                   bool result3=a.check_transitive();
                   if(result3)
                   cout<<"\n The relation is Transitive\n";
                   else
                   cout<<"\n The relation is not Transitive\n";
                   bool result=a.check_partial_order();
                   if(result)
                   cout<<"\n Hence, The relation is Partial Ordered\n";
                   else
                   cout<<"\n Hence, The relation is not Partial Ordered\n";                 
                   break;
                   }
               default:{
               	        system("cls");
                        cout<<"\n\n\t\t\aYOU HAVE ENTETRED WRONG CHOICE\a\n\n";
                        break;
                        }
               }
}    
