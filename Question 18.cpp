/*
	Name: Question 18
	Copyright: 
	Author: Manav Arora and Tushti Adlakha
	Date: 11/04/18 15:20
	Description: This program finds the number of paths in a graph for 
	             given length of path.
*/
#include<iostream>
#include<conio.h>
using namespace std;
class Graph
{
	private:
	int vertex;
	int **M;	
	int **result;
	public:
		Graph()
		{
			vertex=0;
			M=NULL;
			result=NULL;
		}
		void adjacency_matrix(int ,int );
		void enter_vertex();
		void show_matrix();
		bool valid(int x,int y);
		void cal_paths(int);
		int get_path(int v1,int v2);
		void copy_matrix(int**mat);
};
//Function to copy 2 matrices
void Graph::copy_matrix(int**Mat)
{
	for(int i=0;i<vertex;i++)
		for(int j=0;j<vertex;j++)
		  result[i][j]=Mat[i][j];
}
//Function to return the number of paths between given vertices
int Graph::get_path(int v1,int v2)
{
	return result[v1][v2];
}
//Function to calculate the number of paths for given path length
void Graph::cal_paths(int r)
{
	copy_matrix(M);
	while(r!=1)
		{		
		    int**pro=new int*[vertex];
		    for(int i=0;i<vertex;i++)
		    pro[i]=new int [vertex];
			int count=1;
			int temp=0;
			int sum=0;
			int c=0;
			for( int i=1;i<=vertex*vertex;i++)
			{
				sum=0;	
				if(count==(vertex+1))
				{
					temp++;
					c=0;
					count=1;
				}	
				for(int j=0;j<vertex;j++)
				{
					sum= sum + (result[temp][j]*M[j][c]);
				}
				pro[temp][c]=sum;
				count++;
				c++;
			}
			copy_matrix(pro);
			r--;
       } 
}
//Funtion to enter the number of vertices of graph
void Graph::enter_vertex()
{
	cin>>vertex;
	M=new int*[vertex];
	for(int i=0;i<vertex;i++)
	M[i]=new int [vertex];
	//allocation of result matrix
	result=new int*[vertex];
	for(int i=0;i<vertex;i++)
	result[i]=new int [vertex];

	for(int i=0;i<vertex;i++)
       for(int j=0;j<vertex;j++)   //To set all elements of relation_matrix to zero.
          M[i][j]=0;
}
//To allocate adjacency matrix
void Graph::adjacency_matrix(int row,int col)
{
	M[row][col]=1;
}
//To show matrix
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
//Function to check for valid edge pair
bool Graph::valid(int x,int y)
{
     if(x>vertex|y>vertex)      //to check the error.
      return false;
      else
      return true;
} 
int main()
{
	int r;
	char v1,v2;
	void enter_orderpair(Graph &obj);
	Graph obj;
	cout<<"\nEnter the number of vertices :: ";
	obj.enter_vertex();
    enter_orderpair(obj);
    cout<<"\nThe adjacency matrix is :: \n";
    obj.show_matrix();
    cout<<"\n\nEnter the lengh of paths you required :: ";
    cin>>r;
    obj.cal_paths(r);
    char character='y';
    do{
    cout<<"\nEnter the source vertex(a,b,c...) :: ";
    cin>>v1;
    cout<<"\nEnter the destination vertex(a,b,c...) ::" ;
    cin>>v2;
    int result=obj.get_path(v1-97,v2-97);
    cout<<"\nThe number of paths is from "<<v1<<" to "<<v2<<" is "<<result;
    cout<<"\n\n Do you want to check for more?(Y/N)";
    cin>>character;
     }
    while(character=='y'|character=='Y');
	return 0;
}
//Function to input ordered edge pairs
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
