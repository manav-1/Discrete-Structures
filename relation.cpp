/*
	Name: Relation class checking whether it is reflexive sym trans and antisym
	Copyright: 
	Author: Tushti And Manav
	Date: 29-01-20 10:06
	Description: 
*/
#include "relation.h"
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
     { cout<<"\n The set is ::";
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

