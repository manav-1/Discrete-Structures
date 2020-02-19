/*
	Name: Question 17
	Copyright: 
	Author: Manav Arora and Tushti Adlakha
	Date: 10/04/18 10:15
	Description: This program prints indegree and outdegree of every vertex of a directed graph.
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
		void adjacency_matrix(int ,int );
		void enter_vertex();
		void show_matrix();
		void indegree();
		void outdegree();
		bool valid(int x,int y);
};
//Function to print indegree all vertices
void Graph::indegree()
{
	int sum=0;
	char c;
	for(int i=0;i<vertex;i++)
	{
		sum=0;
		c=(char)97+i;
		for(int j=0;j<vertex;j++)
		{
			sum+=M[j][i];
		}
		cout<<"\nThe indegree of vertex "<<c<<" is "<<sum;
	}
}
//Function to print outdegree of all vertices
void Graph::outdegree()
{
	int sum=0;
	char c;
	for(int i=0;i<vertex;i++)
	{
		sum=0;
		c=(char)97+i;
		for(int j=0;j<vertex;j++)
		{
			sum+=M[i][j];
		}
		cout<<"\nThe outdegree of vertex "<<c<<" is "<<sum;
	}
}
//Function to enter the number of vertices of a graph
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
//Fnction to allocate adjacency matrix
void Graph::adjacency_matrix(int row,int col)
{
	M[row][col]=1;
}
//Function to display adjacency matrix
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
//Function to check if endered edge pair is valid or not
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
    cout<<"\n\nThe outdegree of vertices are :: \n";
    obj.outdegree();
    cout<<"\n\nThe indegree of vertices are  :: \n";
    obj.indegree();
	return 0;
}
//Function to enter ordered edge pairs
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
