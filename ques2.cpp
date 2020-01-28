#include<iostream>
#include<conio.h>
#include "set.h"
using namespace std;
int main()
{
 char c;
 void menu();
 a.enter_size();
 a.enter_array();
 b.enter_size();
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
