/*
  Name: Question 2
  Copyright: 
  Author: Manav Arora and Tushti Adlakha
  Date: 16/01/18 09:43
  Description: Program performs following set operations:
               1.Check if A is a subset of B
               2.Check if B is a subset of A
               3.Union and Intersection
               4.Complement
               5.Set Difference
               6.Symmetric Difference
               7.Cartesian product
*/

#include<iostream>
#include<conio.h>
using namespace std;
class set{
	int*arr;
	int size;
	public:
		set()
		{
			arr=NULL;
			size=0;
		}
		void enter_array();
		void enter_size();	
		void show();
		bool is_subset(set obj);
		void unique();
		set Intersection(set obj);
		set Union(set obj);	
		set difference(set obj);
		set symmetric_difference(set obj);
		set complement();
		void cartesian_product(set obj);
}a,b;
void set::enter_array()  //to enter the set
{
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	unique();
}
void set::enter_size()  //to enter the size of set.
{
	cin>>size;
	arr=new int [size];
}
void set::unique()  //to remove the duplicate element of the set.
{
	for(int i=0;i<size;i++)
	{
		for(int j=(i+1);j<size;j++)
		{
			if(arr[i]==arr[j])
			{
				for(int k=j;k<size;k++)
				{
					arr[k]=arr[k+1];
				}
				j--;
				size--;
			}
		}
	}
}
void set::show()     //to show the set.
{
	cout<<"{ ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ,";
	}
	cout<<"\b}";
}
bool set::is_subset(set obj)     //to check whether the set is subset of other or not.
{	
  int flag=0;
  for(int i=0;i<size;i++)
  { flag=0;
        for(int j=0;j<obj.size;j++)
        {
            if(arr[i]==obj.arr[j])
            {
                flag=1;
                break;
            }
        }
    if(flag==0)
    { return false;
      break;
    }
  }
  if(flag==1)
   return true;
}
set set::Intersection(set obj)   //to find intersection of the sets.
{
    set temp;
    int n,count=0;
    if(size<obj.size)
        n=size;
    else
     n=obj.size;
    temp.size=n;
    temp.arr=new int [temp.size];
    for(int i=0;i<size;i++)
    {  
        for(int j=0;j<obj.size;j++)
        {
          if(arr[i]==obj.arr[j])
          { 
           temp.arr[count]=arr[i];
           count++;
          }
        }
    }
    temp.size=temp.size-(n-count);
       
    temp.unique();
	return temp;
}
set set::Union(set obj) //to find the union of sets
{
	int count=0;
	 set temp;
	 temp.size=size+obj.size;
	 temp.arr=new int [temp.size];
	for(int i=0;i<size;i++)
    {
        temp.arr[count]=arr[i];
        count++;
    }
    for(int i=0;i<obj.size;i++)
    {
        temp.arr[count]=obj.arr[i];
        count++;
    }
    temp.unique();
    return temp;
}
set set::difference(set obj) //to find the difference of sets
{   int count=0,flag=0;
    set temp;
    temp.size=size;
    temp.arr=new int [temp.size];
    for(int i=0; i<size;i++)
    {
    	flag=0;
        for(int j=0; j<obj.size;j++)
        {
            if(arr[i]==obj.arr[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
        	temp.arr[count]=arr[i];
        	count++;
		}
        
    }  
    temp.size= temp.size-(size-count);
    return temp;       
}
set set::symmetric_difference(set obj) //to find the symmetric difference of sets
{
	set obj1=Union(obj);
	set obj2=Intersection(obj);
	set result =obj1.difference(obj2);
	return result;
}
set set::complement() //to find the complement of sets
{
 set universal;
 universal.size=30;
 universal.arr= new int [universal.size];
   for(int i=0;i<universal.size;i++)
   {
   	 universal.arr[i]=(i+1);
   }
   set temp= universal.difference(*this);
   return temp;
}
void set::cartesian_product(set obj) //to find the cartesian product of sets
{
	cout<<"{ ";
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<obj.size;j++)
		{
			cout<<"("<<arr[i]<<", "<<obj.arr[j]<<"), ";
		}
	}
	cout<<"\b}";
}

int main()
{
 char c;
 void menu();
 cout<<"\n Enter the size of first array :: ";
 a.enter_size();
 cout<<"\n Enter the elements of first array\n";
 a.enter_array();
 cout<<"\n Enter the size of second array :: ";
 b.enter_size();
 cout<<"\n Enter the elements of second array\n";
 b.enter_array();
 do
 {
    menu(); //calls the menu function.
    cout<<"\nDo you want to continue(Y/N)";
    cin>>c;
    system("cls");
 }
 while(c=='Y'||c=='y');	
 return 0;
}
void menu()
{
	int x;
	cout<<"\nSet A is :: ";
 	a.show();
 	cout<<"\nSet B is :: ";
 	b.show();
 	cout<<"\n\n1. Check whether A is subset of B or not\n";
 	cout<<"\n2. Check whether B is a subset of A or not\n";
 	cout<<"\n3. Union and Intersection\n";
 	cout<<"\n4. Difference of sets\n";
 	cout<<"\n5. Symmetric difference\n";
 	cout<<"\n6. Complement\n";
 	cout<<"\n7. Cartesian Product\n";
 	cout<<"\n Choose a option from menu ::";
 	cin>>x;
	switch(x)
	{
	 case 1:{
	 	bool result=a.is_subset(b);
	 	if(result)
	 	{
	 		cout<<"\nA is the subset of B\n";
		}
		else
		{
			cout<<"\nA is not a subset of B\n";
		}
		break;
	 }
	 case 2:{
	 	bool result=b.is_subset(a);
	 	if(result)
	 	{
	 		cout<<"\nB is the subset of A\n";
		}
		else
		{
			cout<<"\nB is not a subset of A\n";
		}
		break;
	 }
	 case 3:{
	 	set ob,ob1;
	 	ob=a.Union(b);
	 	cout<<"\n The Union of set is :: ";
	 	ob.show();
	 	ob1=a.Intersection(b);
	 	cout<<"\n\n The Intersection of set is ::";
	 	ob1.show();
		break;
	 }
	 case 4:{
              int choice;
              cout<<"\n1. A-B\n";
              cout<<"\n2. B-A\n";
              cout<<"\n Choose a option from the submenu  :: ";
              cin>>choice;
              switch(choice)
              {
                    case 1:{
                        set ob=a.difference(b);
                        cout<<"\nA-B is ::"; 
                        ob.show();
                        break;
                    }
                    case 2:{
                        set ob=b.difference(a);
                        cout<<"\nB-A is ::";
                        ob.show();
                        break;
                    }
                    default:{
                             system("cls");
                             cout<<"INVALID INPUT";
                             break;
                            }
                }
		break;
	 }
	 case 5:{
	 	set ob=a.symmetric_difference(b);
	 	cout<<"\nThe symmetric difference of set is ::";
	 	ob.show();
		break;
	 }	
	 case 6:{
	 	
              int choice;
              cout<<"\n1. A'\n";
              cout<<"\n2. B'\n";
              cout<<"\n Choose a option from the submenu  :: ";
              cin>>choice;
              cout<<"\nConsidering Universal set to be set of first 30 natural number\n";
              switch(choice)
              {
                    case 1:{
                        set ob=a.complement();
                        cout<<"\nThe complement of A is ::"; 
                        ob.show();
                        break;
                    }
                    case 2:{
                        set ob=b.complement();
                        cout<<"\nThe complement of B is ::";
                        ob.show();
                        break;
                    }
                    default:{
                        system("cls");
                    	cout<<"INVALID INPUT";
						break;
					}
                }
	 	
		break;
	 }
	 case 7:{
	 	
              int choice;
              cout<<"\n1. A X B\n";
              cout<<"\n2. B X A\n";
              cout<<"\n Choose a option from the submenu  :: ";
              cin>>choice;
              cout<<"\nConsidering Universal set to be set of first 10 natural numbers\n";
              switch(choice)
              {
                    case 1:{
                        cout<<"\nA X B is ::"; 
                        a.cartesian_product(b);
                        break;
                    }
                    case 2:{
                        cout<<"\nB X A is ::";
                        b.cartesian_product(a);
                        break;
                    }
                    default:{
                             system("cls");
                             cout<<"INVALID INPUT";
                             break;
                            }
                }
		break;
	 }
	 default:{
	 	system("cls");
	 	cout<<"\n\n\n\n\n\t\t\t\aYOU HAVE ENTERED WRONG CHOICE\a\n\n";
		break;
	 }
	}
}
