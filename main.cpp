#include<iostream>
#include<string>
using namespace std;

class Book//Book class definition.
{
	private:
		// data members.
		string title;
		string author;
		string genre;
		//availability status either 0 or 1. 
		int availability_status;
	public:
		//Parametrized constructor assinging values to data memebers.
	    Book(string title, string author ,string genre, int availability_status):title(title), author(author), genre(genre), availability_status(availability_status){}
		
		//getter title function will return title of current book;
		string Get_title() const
		{
			return title;
		}
		//setter will assign values pass in arguments to data members.
		void set_title(string title)
		{
			this->title = title;
		}
		
		//getter title function will return name of author of book.;
		string Get_author()
		{
			return author;
		}
		
		void set_author(string title)
		{
			this->title = title;
		}
		
		//getter title function will return genre of current book.;
		string Get_genre()
		{
			return genre;
		}
		void set_genre(string title)
		{
			this->genre = genre;
		}
		
		// will return status of book available or not.
		int Get_avaiability_status()
		{
			return availability_status;
		}
		void set_avaiability_status(int status) 
		{
             if (status == 0 || status == 1) // condition check for status pass in arguments is either 1 or 0 to insure the correct input.
			 {
             availability_status = status;// if condition is true the assign value.
        } 
		else //if condition fails then tell user to enter correct input.
		{
             cout << "Invalid availability status. Please enter 0 (unavailable) or 1 (available)." << endl;
        }
     }

};

class Library//Library class definition.
{
	private:
	    Book *B1[100];//dynamically array of object of book class and also assign max books to 100 .
	    int count;//variable to keep track of the current number of books in the library.
	public:
	    Library():count(0){}//assign count default value to 0.
	    
	   ~Library()//destructor will distroy the object of book class.
	   {
        for (int i = 0; i < count; ++i) 
		{
            delete B1[i];
        }
      }	
      //Add book function will add new book to LBS(library maangment system), will take as argument the title,author name, genre and availability status.
	    void Add_Book(string title, string author , string genre, int availabilty) 
	    {
           if (count < 100) //will insure that count value is less that the total limit.
		   {
		   	    //dynamically allocating the array of bank object and calling bank class parametrized constructor for index.
                B1[count++] = new Book(title , author, genre , availabilty);
                cout << "Book Added successfully!" << endl;
            } 
		  else //if count value reached the maximum limit then no more books will be added.
	  	   {
              cout << "Cannot Add more accounts. Limit reached." << endl;
           }
        }
    
        void Display_Available_Books(string genre) //display books by genre.
		{
          int found = 0;//will keep track either book found with specific genre.
          for (int i = 0; i < count; i++) 
		   {
              if (B1[i]->Get_genre() == genre && B1[i]->Get_avaiability_status() == 1)//will called getter function of book class to match the genre with user provided genre. 
			  {
                cout << "Book found:" << endl;
                cout << "Title: " << B1[i]->Get_title() << endl;
                cout << "Author: " << B1[i]->Get_author() << endl;
                cout << "Genre: " << B1[i]->Get_genre() << endl << endl;
                found++;//when book is found then increment value of found.
              }
           }
           
            if (found ==0)//if found is still 0 means book is not found with the genre. 
			{
                cout << "Book not found in this genre." << endl;
            }
        }
    
        void Display_all_Books() const//Display function will display the etails of all books.
	    {
          if (count == 0) //means no book present
	      {
             cout << "No books found." << endl;
          } 
	     else //book are present
	      {
	      	//then display all books.
           for (int i = 0; i<count; i++) 
		  {
            cout << "Book " << i + 1 << " details:" << endl;
            cout << "Title: " << B1[i]->Get_title() << endl;
            cout << "Author: " << B1[i]->Get_author() << endl;
            cout << "Genre: " << B1[i]->Get_genre() << endl << endl;
          }
         }
      }
      
};

int main()
 {
	Library L1; //object made of library.
	
	string title;
	string author;
	string genre;
	int avaiability_status;
	
	int choice;
	string option;
	
	do //menu driven program.
	{
		cout<<"***Library Managment System***"<<endl;
		cout << "\tPress[1]. Add Book" << endl;
        cout << "\tPress[2]. Find Book" << endl;
        cout << "\tPress[3]. Display All Books" << endl;
        cout << "\tPress[0]. Exit" << endl;
        cout<<"\n";
        
        cout << "Enter your choice: ";//prompt user to enter choice from (0-3).
        cin >> choice;
        
        switch(choice)
        {
        	case 1: //for add books
        		
                    cout << "Enter Book title: ";//prompt user to enter book title.
                    cin.ignore(); //empty buffer
                    getline(cin, title);
                    
                    //prompt user to enter book author name.
                    cout << "Enter Author Name: ";
                    getline(cin, author);
                    
                    //prompt user to enter genre
                    cout << "Enter Book Genre: ";
                    getline(cin, genre);
                    
                    //prompt user to enter availability status (0 for not, 1 for yes.)
                    cout << "Enter Availability Status(1 for yes, 0 for no): ";
                    cin >> avaiability_status;
                    cin.ignore(); //empty buffer
                    
                    //call add book function.
                    L1.Add_Book(title, author, genre, avaiability_status);
                    break;

                
            case 2: //for find book. 
            	 
            	    //Prompt user to enter genre to find book.
			        cout<<"Entre genre of book you want to search: ";
			        cin.ignore();
				    getline(cin,genre);
				 
				    L1.Display_Available_Books(genre);
				    break;
				 
			case 3:
				    //Display all book stored details.
			        L1.Display_all_Books();
			        break;
			
			case 0:
				   //0 to exit the program
			        cout<<"Thank you for using BMS."<<endl;
				    break;
				 
			default:
			        cout<<"Invalid input!"<<endl;	 	 	     
		  }
		
		    if (choice != 0)//if choice is not 0 then ask user to perform another information.
			{
				// 'y' for yes means user wants to do more operations, and 'n' for No.
                 cout << "\nDo you want to perform another operation? (y/n): ";
                 cin >> option;
                 
           if (option != "y" && option != "Y") //if option is not y and n
		   {
                 cout << "\nThank you for using Library Management System." << endl;
                 break;
           }
         }
		 		
        }   while(option == "y" ||option == "Y");//loop will iterate until option is y for yes.
   
   
     return 0;	
}
