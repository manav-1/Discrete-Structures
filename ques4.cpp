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
          cout<<"\n 1. Check if the relation is Eqivalence \n";
          cout<<"\n 2. Check if the relation is Partial Order Set\n";
          cout<<"\n Choose the option from menu :: ";
          cin>>x;
          switch(x)
          {
              case 1:{
                   bool ref=a.check_reflexive();
                   bool sym=a.check_symmetric();
                   bool tr=a.check_transitive();
                   if(ref&&sym&&tr)
                   cout<<"\n The relation is Equivalence \n";
                   else
                   cout<<"\n The relation is not Equivalence \n";
                   break;
                   }
              case 2:{
              	   bool ref=a.check_reflexive();
                   bool asym=a.check_antisymmetric();
                   bool tr=a.check_transitive();
                   if(ref&&asym&&tr)
                   cout<<"\n The relation is partial order";
                   else
                   cout<<"\n The relation is not partial order\n";
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
