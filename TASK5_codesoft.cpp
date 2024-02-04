#include <iostream>
#include <string>
using namespace std;

class Book{
	public:
		string duedate;
		string booktitle;
		string author;
		string ISBN;
		int quantity;
		void initialize(string d, int q, string b, string au, string is)
		{
			duedate=d;
			booktitle=b;
			author=au;
			ISBN=is; 
			quantity=q;
		}
		Book()
		{}	
};

class library{
	public:
		Book b[10];
		library()
		{
			b[1].initialize("0",10,"Harry potter and the philospher's Stone", "J.K Rowling", "12JHU9");
			b[2].initialize("0",10,"Harry potter and the half blood prince", "J.K Rowling", "13JHU9");
			b[3].initialize("0",10,"Harry potter and the prisoner of Azkaban", "J.K Rowling", "14JHU9");
			b[4].initialize("0",10,"Harry potter and the Deathly Hollows", "J.K Rowling", "15JHU9");
			b[5].initialize("0",10,"Harry potter and the Order of Phoenix", "J.K Rowling", "16JHU9");
			b[6].initialize("0",10,"Harry potter and the Goblet of Fire", "J.K Rowling", "17JHU9");
			b[7].initialize("0",10,"Harry potter and the Cursed Child", "J.K Rowling", "18JHU9");
			b[8].initialize("0",10,"Harry potter and the Chamber of Secrets", "J.K Rowling", "19JHU9");
			b[9].initialize("0",10,"The Chronicles of Narnia", "Clive Staples Lewis", "20JHU9");
			b[0].initialize("0",10,"Turtles All the Way Down", "John Green", "21JHU9");
		}
		void displayrecords()
		{
			for(int j=0;j<10;j++)
			{
				cout<<"Book Name : "<<b[j].booktitle<<"\nBook Author : "<<b[j].author << "\nISBN : "<< b[j].ISBN << endl <<endl;
			}
		}
		void searchrecord()
		{
			string choice;
			cout<<"Enter Book Name / Author / ISBN:";
			fflush(stdin);
			getline(cin,choice);
			int flag=0;
			for(int j=0;j<10;j++)
			{
				if(choice==b[j].booktitle || choice==b[j].author || b[j].ISBN==choice)
				{ 
					flag=1;
					cout<<"Book Name : "<<b[j].booktitle<<"\nBook Author : "<<b[j].author << "\nISBN : "<< b[j].ISBN<<endl <<endl;
				}
			}
			if(flag==0)
			{
				cout<<"Not found";
			}
		}
		void checkout()
		{
			string choice;
			cout<<"Enter Book Name / ISBN : ";
			fflush(stdin);
			getline(cin,choice);
			for(int j=0;j<10;j++)
			{
				if(choice==b[j].booktitle || choice==b[j].author || b[j].ISBN==choice)
				{ 
					if(b[j].quantity>0)
					{
						string date;
						cout<<"Enter Today's Date dd/mm/yy : ";
						cin>> date;
						b[j].duedate=date;
						b[j].quantity--;
						cout<<"\nBook Quantity : "<<b[j].quantity <<"\nBook Issued"<< endl ;
					}
					else
					{
						cout<<"Book not avaliable!"<< endl ;
					}
				}
			}
			
		}
		void returnbook()
		{
			//20 days
			string choice;
			cout<<"Enter Book Name / ISBN:";
			cin>>choice;
			for(int j=0;j<10;j++)
			{
				if( (choice == b[j].booktitle || choice == b[j].author || b[j].ISBN == choice))
				{ 
					string date;
					
					cout<<"Enter Today's Date dd/mm/yy";
					cin>> date;
					
					int day=b[j].duedate[0];
					int temp1=b[j].duedate[1]*10;
					day=day+temp1;
					int month=b[j].duedate[3];
					temp1=b[j].duedate[4]*10;
					month+=temp1;
					int year=b[j].duedate[6];
					temp1=b[j].duedate[7]*10;
					year+=temp1;
					
					int day1=date[0];
					int temp2=date[1]*10;
					day1=day1+temp2;
					int month1=date[3];
					temp2=date[4]*10;
					month1+=temp2;
					int year1=date[6];
					temp2=date[7]*10;
					year1+=temp2;
					
					if (year1 > year || (year1 == year && month1 > month) || (year1 == year && month1 == month && day1 > day + 20)) 
					{
		                finecalculation(day1, day, month1, month, year1, year);
		            }
					else
					{
						b[j].quantity++;
						cout<<"-------------------------------- Book returned --------------------------------";
					}
					return;
				}
			}
			cout<<"\nBook can't be returned";
		}
		void finecalculation(int cd, int dd,int cm, int dm,int cy, int dy)
		{
			int fine=0,yr=0,mm=0,dayy=0;
			if (cd > dd+20) 
			{
		        dayy= cd-dd -20;
		    } 
			else if (cy > dy) 
			{
		        yr=cy-dy;
		        yr*=365;
		    } 
			else if (cm > dm) 
			{
		        mm =cm-dm;
		        mm *= 30;
		    }
		    fine=(dayy+yr+mm)*10;
		    cout << "Pay Fine: " << fine<<endl;
		}
};


main()
{
	int choice;
	while(1)
	{
		cout<<"\n-------------------------------------------------------------------------------";
		cout<<"\n-------------------------------- L I B R A R Y --------------------------------\n";
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"\nEnter\n1 - View books\n2 - Search a book\n3 - Borrow a book\n4 - Return a book\n5 - exit\n";
		cin>>choice;
		library l;
		switch(choice)
		{
			case 1:
			{
				l.displayrecords();
				break;
			}
			case 2:
			{
				l.searchrecord();
				break;
			}
			case 3:
			{
				l.checkout();
				break;
			}
			case 4:
			{
				l.returnbook();
				break;
			}
			case 5:
			{
				exit(1);
			}
		}
	}
}