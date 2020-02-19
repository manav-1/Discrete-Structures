/*
	Name: Question 16
	Copyright: 
	Author: Manav Arora and Tushti Adlakha
	Date: 10/04/18 9:55
	Description: This program checks whether a graph is complete or not. 
*/

#include<iostream>
#include<conio.h>
using namespace std;
class Graph
{
	private:
	int vertex;
	int **M;	
	public:
		Graph()
		{
			vertex=0;
			M=NULL;
		}
		bool check_sum();
		bool check_diagonal();
		void adjacency_matrix(int ,int );
		void enter_vertex();
		void show_matrix();
		bool check_complete_graph();
		bool valid(int x,int y);
};
//Function to enter number of vertices of graph
void Graph::enter_vertex()
{
	cin>>vertex;
	M=new int*[vertex];
	for(int i=0;i<vertex;i++)
	M[i]=new int [vertex];
	
	for(int i=0;i<vertex;i++)
       for(int j=0;j<vertex;j++)   //To set all elements of relation_matrix to zero.
          M[i][j]=0;
}
//Function to allocate adjacency matrix
void Graph::adjacency_matrix(int row,int col)
{
	M[row][col]=1;
}
//Function to check if all diagonal elements are zero or not
bool Graph::check_diagonal()
{
	int flag=0;
	for(int i=0;i<vertex;i++)
	{
		if(M[i][i]!=0)
		{
			flag=1;
			break;
		}
		
	}
     if(flag==0)
     return true;
     else
     return false;
}
//Function to check if sum all degrees is eual to n-1 or not
bool Graph::check_sum()
{
	int flag=0,sum=0;
	for(int i=0;i<vertex;i++)
	{
		sum=0;
		for(int j=0;j<vertex;j++)
		{
		    sum+=M[i][j];
		}
		if(sum!=vertex-1)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	return true;
	else
	return false;
}
//Function to check whether the graph is complete or not
bool Graph::check_complete_graph()
{
	bool check1,check2;
	check1=check_diagonal();
	check2=check_sum();
	if(check1&check2)
	return true;
	else
	return false;
}
//Function to show adjacency matrix
void Graph::show_matrix()
{
	cout<<endl;
     for(int i=0;i<vertex;i++)
     {
             for(int j=0;j<vertex;j++)
             {
                     cout<<M[i][j]<<" ";
             }
        cout<<endl;
     }
}
//Function to check whether entered ordered pair is valid or not
bool Graph::valid(int x,int y)
{
     if(x>vertex|y>vertex)      //to check the error.
      return false;
      else
      return true;
} 
int main()
{
	void enter_orderpair(Graph &obj);
	Graph obj;
	cout<<"\nEnter the number of vertices :: ";
	obj.enter_vertex();
    enter_orderpair(obj);
    cout<<"\nThe adjacency matrix is :: \n";
    obj.show_matrix();
    bool result= obj.check_complete_graph();
    if(result)
    cout<<"\nThe Graph is complete\n";
	else
	cout<<"\nThe Graph is not complete\n";
	return 0;
}
//Function to enter order edge pairs
void enter_orderpair(Graph &obj)
{
     char x,y;
     int r,c;
     char chk='y';
     cout<<"\n Enter the elements of ordered pair of graph in the form (a,b,c,.....) ::\n";
     do{
         cout<<"\n Enter 1st vertex ::";
         cin>>x;
         cout<<"\n Enter 2nd vertex ::";
         cin>>y;
         r=(int)x-97;
         c=(int)y-97;
         if(obj.valid(r,c))
        { 
		  obj.adjacency_matrix(r,c);
          cout<<"\n Your entered ordered pair is ("<<x<<","<<y<<")\n";
        }
         else
         cout<<"\nSorry, the ordered pair entered is invalid !!\n";
         
         cout<<"\n Do you want to enter more ordered pair(Y/N)";
         cin>>chk;
         }
    while(chk=='y'||chk=='Y');
    cout<<"\nPress Enter to continue....\n";
    getch();
    system("cls");
}
