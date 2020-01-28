#include <iostream>
#include<conio.h>
#include<math.h>
#include "set.h"
using namespace std;
int main()
{
	set A;
	A.enter_size();
	A.enter_array();
	int x;
	char c='y';
	while(c=='Y'||c=='y')
 {
        //menu for program
    cout<<"\n 1.To print the cardinality of the set\n";
	cout<<"\n 2.Check the entered element is member of the set or not\n";
	cout<<"\n 3.Display the power set of given set\n";
	cout<<"\n Choose the option from the menu\n";
	cin>>x;
	cout<<endl;
	switch(x)
	{
		case 1:{
            //to print cardinality
			     A.show_cardinality();
			     break;
		       }  
		case 2:{
                // to check the element is present in the set or not 
			         int b; 
			         cout<<"\nEnter the element to be checked\n";
			         cin>>b;
			         A.ismember(b);
				     break;
				}
		case 3:{
                        cout<<"\nThe power set of given set is ::\n";
                        A.power_set();
                        break;
               }
        default:{
            system("cls");
            cout<<"\n\tYOU HAVE ENTERED WRONG OPTION";
            
               }
             
				
     }
	cout<<" \n\nDo you want to continue?(Y/N)\n\n";
	cin>>c;
	cout<<endl;
 }

	return 0;
}
