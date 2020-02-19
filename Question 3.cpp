/*
	Name:Question 3
	Copyright: 
	Author: Manav Arora and Tushti Adlakha
	Date: 23/01/18 13:16
	Description: This program take ordered pair of relations from user to check
	             following relations::
                  1.Check for reflexive relation
                  2.Check for symmetric relation
                  3.Check for transitive relation
                  4.Check for anti-symmetric relation
*/

#include<iostream>
#include<conio.h>
#include<iomanip>
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
		void relation_matrix(int row,int col);
		void allocate_matrix();
		void show_relation();
		void show_matrix();
		bool valid(int x,int y);
		
}a;
bool relation::valid(int x,int y)
{
     if(x>size||y>size)      //to check the error.
      return false;
      else
      return true;
}    
void relation:: show_matrix()
{
     for(int i=0;i<size;i++)
     {
             for(int j=0;j<size;j++)
             {
                     cout<<M[i][j]<<" ";
             }
        cout<<endl;
     }
}
void relation::allocate_array()  //to allocate array.
{
	for(int i=0;i<size;i++)
	{
		arr[i]=i+1;
	}
}
void relation::enter_size()   //to enter the size of the set.
{
	cin>>size;
    arr=new int [size];
    allocate_array();
    allocate_matrix();
}
void relation::show()   //to print the set.
{
	cout<<"{ ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ,";
	}
	cout<<"\b}\n";
}
void relation::allocate_matrix()  //to allocate the relation matrix.
{
     
    M=new int*[size];  //allocate the rows of relation matrix
	for(int i=0;i<size;i++)
	M[i]=new int[size];        //to allocate the columns of the relation matrix.
	
    
	for(int i=0;i<size;i++)
       for(int j=0;j<size;j++)   //To set all elements of relation_matrix to zero.
          M[i][j]=0;
}
void relation::relation_matrix(int row,int col)
{   
    //To set given pairs of relation to one in relation matrix
    M[row-1][col-1]=1;          
}
void relation::show_relation()    //to print the relation.
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
              
bool relation::check_reflexive()   //to check reflexivity
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
bool relation::check_antisymmetric()  //to check the anti-symmetricity.
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
bool relation::check_transitive()  //to check the transitivity.
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
int main()
{
	char c;
    void enter_relation();
    void menu();
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
	      cout<<"\n\n The Relation Matrix is ::\n\n";
	      a.show_matrix();
	      menu();
          cout<<"\n\nDo you want to continue(Y/N) :: ";
          cin>>c;
		  system("cls");    
	 }
	 while(c=='y'||c=='Y');
	cout<<"\n\n\t\t\aPROGRAM TERMINATED\a\n";
	getch();
	return 0;
}
void menu()
{
          int x;
          cout<<"\n 1. Check if the relation is Reflexive\n";
          cout<<"\n 2. Check if the relation is Symmetric\n";
          cout<<"\n 3. Check if the relation is Anti-Symmetric\n";
          cout<<"\n 4. Check if the relation is Transitive\n";
          cout<<"\n Choose the option from menu :: ";
          cin>>x;
          switch(x)
          {
              case 1:{
                   bool result=a.check_reflexive();
                   if(result)
                   cout<<"\n The relation is Reflexive\n";
                   else
                   cout<<"\n The relation is not Reflexive\n";
                   break;
                   }
              case 2:{
                   bool result=a.check_symmetric();
                   if(result)
                   cout<<"\n The relation is Symmetric\n";
                   else
                   cout<<"\n The relation is not Symmetric\n";
                   break;
                   }
               case 3:{
                    bool result=a.check_antisymmetric();
                    if(result)
                    cout<<"\n The relation is Anti-Symmetric\n";
                    else
                    cout<<"\n The relation is not Anti-Symmetric\n";
                    break;
                    }
               case 4:{
               	    bool result=a.check_transitive();
                    if(result)
                    cout<<"\n The relation is Transitive\n";
                    else
                    cout<<"\n The relation is not Transitive\n";
	     			break;
					}
               default:{
               	        system("cls");
                        cout<<"\n\n\t\t\aYOU HAVE ENTETRED WRONG CHOICE\a\n\n";
                        break;
                        }
               }
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
         if(a.valid(x,y))
        { a.relation_matrix(x,y);
          cout<<"\n Your entered ordered pair is ("<<x<<","<<y<<")\n";
        }
         else
         cout<<"\nSorry, the ordered pair entered is invalid !!\n";
         
         cout<<"\n Do you want to enter more ordered pair(Y/N)";
         cin>>c;
         }
    while(c=='y'||c=='Y');
    cout<<"\nPress Enter to continue....\n";
    getch();
    system("cls");
}

