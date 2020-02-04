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
     if(x>size||y>size) //to check the error.
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
void relation::allocate_array() //to allocate array.
{
  for(int i=0;i<size;i++)
  {
    arr[i]=i+1;
  }
}
void relation::enter_size() //to enter the size of the set.
{
  cin>>size;
    arr=new int [size];
    allocate_array();
    allocate_matrix();
}
void relation::show() //to print the set.
{
  cout<<"{ ";
  for(int i=0;i<size;i++)
  {
    cout<<arr[i]<<" ,";
  }
  cout<<"\b}\n";
}
void relation::allocate_matrix() //to allocate the relation matrix.
{
     
    M=new int*[size]; //allocate the rows of relation matrix
  for(int i=0;i<size;i++)
  M[i]=new int[size]; //to allocate the columns of the relation matrix.
  
    
  for(int i=0;i<size;i++)
       for(int j=0;j<size;j++) //To set all elements of relation_matrix to zero.
          M[i][j]=0;
}
void relation::relation_matrix(int row,int col)
{   
    //To set given pairs of relation to one in relation matrix
    M[row-1][col-1]=1;          
}
void relation::show_relation() //to print the relation.
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
              
bool relation::check_reflexive() //to check reflexivity
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
bool relation::check_symmetric() //to check symmetricity.
{ 

  bool check=false;
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
    { if(M[i][j]==1)
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
bool relation::check_antisymmetric() //to check the anti-symmetricity.
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
bool relation::check_transitive() //to check the transitivity.
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
