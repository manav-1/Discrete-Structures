/*
	Name: Question 19
	Copyright: 
	Author:  Manav Arora and Tushti Adlakha
	Date: 11/04/18 14:40
	Description:  This program checks for following:-
	1. Euler circuit in directed graph
	2. Euler circuit in undirected graph
	3. Euler path in undirected graph 
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
		void undirected_matrix();
		void adjacency_matrix(int ,int );
		void enter_vertex();
		void show_matrix();
		bool valid(int x,int y);
		bool check_eulercrt();
		bool check_euler_path();
		bool check_eulercrt_directed();
}obj;
//FUnction to check Euler circuit in directed graph
bool Graph::check_eulercrt_directed()
{
	if(vertex<=2)
	return false;
	
	int sum1,sum2,flag=0;
	for(int i=0;i<vertex;i++)
	{
		sum1=0;
		sum2=0;
		for(int j=0;j<vertex;j++)
		{
			sum1+=M[i][j];
			sum2+=M[j][i];
		}
		if(sum1!=sum2)
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
//Function to check Euler circuit in directed graph
bool Graph::check_eulercrt()
{
	if(vertex<=2)
	return false;
	
	int sum, flag=0;
	for(int i=0;i<vertex;i++)
	{
		sum=0;
		for(int j=0;j<vertex;j++)
		{
			sum+=M[i][j];
		}
		if(sum%2!=0)
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
//Function to check Euler path in graph
bool Graph::check_euler_path()
{
	int sum, count=0;
	for(int i=0;i<vertex;i++)
	{
		sum=0;
		for(int j=0;j<vertex;j++)
		{
			sum+=M[i][j];
		}
		if(sum%2!=0)
		{
			count++;
		}
	}
	if(count==2)
	return true;
	else
	return false;
}
//Function to input the number of vertices of graph
void Graph::enter_vertex()
{
	cin>>vertex;
	M=new int*[vertex];
	for(int i=0;i<vertex;i++)
	M[i]=new int [vertex];
	
	result=new int*[vertex];
	for(int i=0;i<vertex;i++)
	result[i]=new int [vertex];
	
	for(int i=0;i<vertex;i++)
       for(int j=0;j<vertex;j++)   //To set all elements of relation_matrix to zero.
          M[i][j]=0;
}
//Function  allocate the adjacency matrix
void Graph::adjacency_matrix(int row,int col)
{
	M[row][col]=1;
}
//Function to allacate matrix for undirected graph
void Graph::undirected_matrix()
{
	for(int i=0;i<vertex;i++)
	 for(int j=0;j<vertex;j++)
	 {
	 	if(M[i][j]==1)
	 	   M[j][i]=1;
	 }
}
//Function to display the adjacency matrix
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
//FUnction to check if entered edge pair is valid or not
bool Graph::valid(int x,int y)
{
     if(x>vertex|y>vertex)      //to check the error.
      return false;
      else
      return true;
}
 //Prototype for function for entering ordered edge pair
void enter_orderpair();
int main()
{
	int x;
    void directed_graph();
	void undirected_graph();
	void Euler_path();
	cout<<"\nEnter the number of vertices :: ";
	obj.enter_vertex();
	cout<<"\nChoose a option from menu::\n";
	cout<<"1. Euler circuit in directed graph\n";
	cout<<"2. Euler circuit in undirected graph\n";
	cout<<"3. Euler path in undirected graph\n";
	cin>>x;
	switch(x)
  {
  	case 1:{
  		directed_graph();
		break;
	  }
	case 2:{
		undirected_graph();
		break;
	}
	case 3:{
		Euler_path();
		break;
	}
	default:{
		cout<<"\a\nYOU HAVE ENTERED WRONG CHOICE\a\n";
		break;
	}
  }
	return 0;
}
//Function to evalutate whether the given graph has euler path or not
void Euler_path()
{
    enter_orderpair();
    cout<<"\nThe adjacency matrix is :: \n";
    obj.undirected_matrix();
    obj.show_matrix();
    bool result2=obj.check_euler_path();
    if(result2)
    cout<<"\nThe graph has an Euler path\n";
    else
    cout<<"\nThe graph does not has an Euler path\n";
    
}
//Function to evalutate whether the given graph has euler circuit in directed graph or not
void directed_graph()
{
	enter_orderpair();
    cout<<"\nThe adjacency matrix is :: \n";
    obj.show_matrix();
    bool result1=obj.check_eulercrt_directed();
    if(result1)
    cout<<"\nThe graph forms an Euler circuit\n";
    else
    cout<<"\nThe graph does not forms an Euler circuit\n";
    
}
//Function to evalutate whether the given graph has euler circuit in an undirected graph or not
void undirected_graph()
{
	enter_orderpair();
    cout<<"\nThe adjacency matrix is :: \n";
    obj.undirected_matrix();
    obj.show_matrix();
    bool result1=obj.check_eulercrt();
    if(result1)
    cout<<"\nThe graph forms an Euler circuit\n";
    else
    cout<<"\nThe graph does not forms an Euler circuit\n";
}
//Function to input ordered edge pairs
void enter_orderpair()
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
