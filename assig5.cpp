#include<iostream>
#include<string.h>
using namespace std;
class array
{
	int *a;
	int size;
	public:
	array()
	{
		size=0;
	}
	array(int s)
	{
		a=new int[s];	
		size=s;
		for(int i=0;i<size;i++)
		{
			*(a+i)=0;
		}	
	}
	array(const array &ar)
	{
		size=ar.size;
		a=new int[size];
		int *x=ar.a; 
		for(int i=0;i<size;i++)
		{
			*(a+i)=*(x+i); 
		}
	}
	array(int x[],int s)
	{
		size=s;
	 	a=new int[size];
		for(int i=0;i<size;i++)
		{
			a[i]=x[i]; 
		}
		
	}
	void take_data()
	{
		
		cout<<"enter elements: "<<endl;
		for(int i=0;i<size;i++)
		{
			printf("a[%d]= ",i);
			cin>>a[i];
		}
	}
	void show_data()
	{
		cout<<"elements of object is/are:  "<<endl;
		for(int i=0;i<size;i++)
		{
			cout<<*(a+i)<<" ";
		}	
		cout<<endl;
	}
	int operator +(const array ar1)
	{
		if(size == ar1.size)
		{
			for(int i=0;i<size;i++)
			{
				a[i]=a[i]+ar1.a[i];
			}
			cout<<"addition successfull"<<endl;
			return 1;
		}
		else 
		{
			cout<<"addition is not possible"<<endl;
			return 0;
		}
		
	}
	int operator =(const array ar1)
	{
		array ar(size);
		if(size == ar1.size)
		{
			for(int i=0;i<size;i++)
			{
				a[i]=ar1.a[i];
			}
			return 1;
		}
		else 
		{
			cout<<"= operation is not possible"<<endl;
			return 0;
		}
	}
	array friend operator * (array &ar,int s)
	{
		for(int i=0;i<ar.size;i++)
		{
			ar.a[i]*=s;
		}
		cout<<"multiplication successfull"<<endl;
		return(ar);
	}
    array friend operator * (int s,array &ar)
	{
		for(int i=0;i<ar.size;i++)
		{
			ar.a[i]*=s;
		}
		cout<<"multiplication successfull"<<endl;
		return ar;
	}
	int operator [](int s)
	{
		if(s<=size-1)
		return a[s];
		else
		{
			cout<<"index overflow"<<endl;
		}
	}
	
};
class inst_list
{
	public:
		void menu()
		{
			cout<<"1 to initilize a object: "<<endl;
			cout<<"2 to initilize a object with another object:"<<endl;
			cout<<"3 to initilize a object with another array:"<<endl;
			cout<<"4 to addition:"<<endl;
			cout<<"5 to perform = operation"<<endl;
			cout<<"6 to multiplication(i*ar format)"<<endl;
			cout<<"7 to multiplication(ar*i format)"<<endl;
			cout<<"8 return element of given index: "<<endl;
		}
		void list()
		{
			int s;
			while(1)
			{
			cout<<"enter your choice(-1 to exit,0 to menu): ";
			int i;
			cin>>i;
			if(i==-1) break;
			else if(i==0)
			{
				menu();
			}
			else if(i==1)
			{   
				
				cout<<"enter the size object: ";
				cin>>s;
				array ar(s);
				ar.show_data();	
			}
			
			else if(i==2)
			{
				cout<<"enter the size 1st object: ";
				cin>>s;
				array ar(s);
				ar.take_data();
				array arr(ar);
				cout<<"initilization with ist object is successfull : ";
				arr.show_data();
			}
			else if(i==3)
			{
				cout<<"enter the size of the array ";
				cin>>s;
				int a[s];
				cout<<"enter elements: "<<endl;
				for(int i=0;i<s;i++)
				{
					//scanf("a[%d]= ",i);
                                         cin>>i;
					cin>>a[i];
				}
				array ar(a,s);
				ar.show_data();
			}
			else if(i==4)
			{
				cout<<"enter size of 1st array obj: ";
				cin>>s;
				array ar(s);
				ar.take_data();
				cout<<"enter size of 2nd array obj: ";
				cin>>s;
				array arr(s);
				arr.take_data();
				if((ar+arr))
				ar.show_data();
			}
			else if(i==5)
			{
				cout<<"enter size of 1st array obj: ";
				cin>>s;
				array ar(s);
				ar.take_data();
				array arr(s);
				if((arr=ar))
				arr.show_data();
			}
			else if(i==6)
			{
				cout<<"enter size of 1st array obj: ";
				cin>>s;
				array ar(s);
				ar.take_data();
				cout<<"enter multiplicant: ";
				cin>>s;
				ar=ar*s;
				ar.show_data();
			}
			else if(i==7)
			{
				cout<<"enter size of 1st array obj: ";
				cin>>s;
				array ar(s);
				ar.take_data();
				cout<<"enter multiplicant: ";
				cin>>s;
				ar=s*ar;
				ar.show_data();
			}
			else if(i==8)
			{
				cout<<"enter size of 1st array obj: ";
				cin>>s;
				array ar(s);
				ar.take_data();
				cout<<"enter index position: ";
				cin>>s;
				printf("a[%d]= ",s);
				cout<<ar[s]<<endl;
			}
			else
			cout<<"you enter invalid key";
			}
		}
		
};
int main()
{
inst_list l;
l.list();
}
