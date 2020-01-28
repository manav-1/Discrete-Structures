#include <iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class set
{
	int *arr,size;
	public:
		set()
		{
			arr=NULL;
			size=0;
		}
		void enter_array();
		void enter_size();	
		void show();
		bool is_subset(set obj);
		void unique();
		set Intersection(set obj);
		set Union(set obj);	
		set difference(set obj);
		set symmetric_difference(set obj);
		set complement();
		void cartesian_product(set obj);
		
		void show_cardinality() // function to show the cardinality of set
		{
			cout<<"The cardinality of set is :: "<<size;
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
		
}a,b;
void set::enter_array()  //to enter the set
{
	cout<<"\nEnter the elements of array\n";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	unique();
}
void set::enter_size()  //to enter the size of set.
{
	cout<<"Enter the size of the array:";
	cin>>size;
	arr=new int [size];
}
void set::unique()  //to remove the duplicate element of the set.
{
	for(int i=0;i<size;i++)
	{
		for(int j=(i+1);j<size;j++)
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
void set::show()     //to show the set.
{
	cout<<"{ ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ,";
	}
	cout<<"\b}";
}
bool set::is_subset(set obj)     //to check whether the set is subset of other or not.
{	
  int flag=0;
  for(int i=0;i<size;i++)
  { flag=0;
        for(int j=0;j<obj.size;j++)
        {
            if(arr[i]==obj.arr[j])
            {
                flag=1;
                break;
            }
        }
    if(flag==0)
    { return false;
      break;
    }
  }
  if(flag==1)
   return true;
}
set set::Intersection(set obj)   //to find intersection of the sets.
{
    set temp;
    int n,count=0;
    if(size<obj.size)
        n=size;
    else
     n=obj.size;
    temp.size=n;
    temp.arr=new int [temp.size];
    for(int i=0;i<size;i++)
    {  
        for(int j=0;j<obj.size;j++)
        {
          if(arr[i]==obj.arr[j])
          { 
           temp.arr[count]=arr[i];
           count++;
          }
        }
    }
    temp.size=temp.size-(n-count);
       
    temp.unique();
	return temp;
}
set set::Union(set obj) //to find the union of sets
{
	int count=0;
	 set temp;
	 temp.size=size+obj.size;
	 temp.arr=new int [temp.size];
	for(int i=0;i<size;i++)
    {
        temp.arr[count]=arr[i];
        count++;
    }
    for(int i=0;i<obj.size;i++)
    {
        temp.arr[count]=obj.arr[i];
        count++;
    }
    temp.unique();
    return temp;
}
set set::difference(set obj) //to find the difference of sets
{   int count=0,flag=0;
    set temp;
    temp.size=size;
    temp.arr=new int [temp.size];
    for(int i=0; i<size;i++)
    {
    	flag=0;
        for(int j=0; j<obj.size;j++)
        {
            if(arr[i]==obj.arr[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
        	temp.arr[count]=arr[i];
        	count++;
		}
        
    }  
    temp.size= temp.size-(size-count);
    return temp;       
}
set set::symmetric_difference(set obj) //to find the symmetric difference of sets
{
	set obj1=Union(obj);
	set obj2=Intersection(obj);
	set result =obj1.difference(obj2);
	return result;
}
set set::complement() //to find the complement of sets
{
 set universal;
 universal.size=30;
 universal.arr= new int [universal.size];
   for(int i=0;i<universal.size;i++)
   {
   	 universal.arr[i]=(i+1);
   }
   set temp= universal.difference(*this);
   return temp;
}
void set::cartesian_product(set obj) //to find the cartesian product of sets
{
	cout<<"{ ";
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<obj.size;j++)
		{
			cout<<"("<<arr[i]<<", "<<obj.arr[j]<<"), ";
		}
	}
	cout<<"\b}";
}
