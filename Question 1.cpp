/*
	Name: Question 1
	Copyright: 
	Author:  Manav Arora and Tushti Adlakha
	Date: 05/01/18 13:40
	Description:  This program provides following menu to operate on user entered array:
        1. Show the cardinality of Set
        2. Check the user entered element is member of set or not
        3. Generate power set
*/

#include <iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class set
{
	int *arr,size;
	public:
		set()       // default constructor                                      
		{
			arr=NULL;
			size=0;
		}
		
		void setsize()     //function to enter the size of the array
		{
			cout<<"Enter the size of the array:";
			cin>>size;
			arr=new int [size];
		}
	
	    void enter()        //function to enter the elements of the array
	    {
	    	cout<<"\nEnter the elements of array\n";
	    	for(int i=0;i<size;i++)
	    	{
	    		cin>>arr[i];
			}
	        unique();
	        cout<<"\nThe set is:";
	        show();
		}
		
		void unique()       //function to remove diuplicates from array
		{ 
		   for(int i=0;i<size;i++)
		   {
		   	for(int j=i+1;j<size;j++)
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
		void show_cardinality() // function to show the cardinality of set
		{
			cout<<"The cardinality of set is :: "<<size;
		}
		void show() ///function to display set
		{
			cout<<"{";
			for(int i=0;i<size;i++)
			{
				cout<<arr[i]<<" ,";
			}
			cout<<"\b}";
		}
		void ismember(int a) //function to check if the given element is member of set or not
		{
			int flag=0;
			for( int i=0;i<size;i++)
			{
				if(a==arr[i])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				cout<<"\n The element belongs to the set.\n";
			}
			else
			{
				cout<<"\n The element does not belongs to the set.\n";
			}
		}
		void power_set() // function to display the power set of given set
		{
            int print_element;
            cout<<"{ ";
            for(int i=0;i<pow(2,size); i++)
            {
                if(i==0) //to print null set
                {
                    cout<<"{ },";
                    continue;
                }
                cout<<"{ ";
                 print_element= i; 
                for(int j=0;j<size;j++)  //for checking the bits of each element
                {
                    
                    if(print_element&1)
                    {
                        cout<<arr[j]<<" ,";
                    }
                    print_element=print_element>>1; // right shift
                }
                 cout<<"\b} ,";
            }
                cout<<"\b}";
		}
		
};
int main()
{
	set A;
	A.setsize();
	A.enter();
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
