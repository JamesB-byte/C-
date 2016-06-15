#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <limits>
#include <memory>


/*

This was a class assignment. Its a simple file cabinet system.
You can add, remove  and view people 

*/

using namespace std;

// list of global variables and arrays

string fName;
string lName;
string wholeName;



int pos;

const int maxSize = 10;

int upCount = 0; // basic counter

string* fileCabinet = new string[100]; //create an array
string* tempArray = new string[100];






// class of persons
class Persons
{
    public:

    string firstName;
    string lastName;

} ;


 Persons student;  // declare student objects

// Function to exit the program
void exitProgram()
{
    exit(0);
}




 // add people to file cabinet
 void userInformation()
 {
     // define variables for this function



     char userInput;


     system("CLS"); // this clears the screen

     cout << "\n";
     cout << "Please enter your first name: ";
     cin >> fName;

     cout << "Please enter your last name:";
     cin >> lName;

     // convert first letter of each name to capital letter

     fName[0] = toupper(fName[0]);
     lName[0] = toupper(lName[0]);

     system("CLS");
     cout << "\n";
     cout << lName <<","<< fName <<":" << " Is the name you want to add. Is this correct? Y/N:";
     cin >> userInput;

     userInput = toupper(userInput);

     if(userInput == 'Y')

     {

     // create a student object and give them first and last name
     student.firstName = fName;
     student.lastName = lName;



     // please student object into cabinet
     wholeName = student.lastName.append(",") + student.firstName;

     }
     else
		{
			userInformation();


		}

 }


 // checks if person being added is in the file cabinet, if so, request a new name, if not, add to file cabinet
 addPerson()
 {


  for(int i = 0; i <= upCount; i++)
{

		if(wholeName.compare(fileCabinet[i]) == 0)
			{
                system("CLS");
                cout << "\n";

				cout << fileCabinet[i] << " is already in the File Cabinet."<< endl << "Please add another name." << endl ;
				cout << "Press any button to continue.";
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
         		cin.get();

         		userInformation();


			}


 }


fileCabinet[upCount] = wholeName;

cout << "\n";
cout << "Name added to File Cabinet." << endl;

upCount = upCount + 1;  // increases counter by 1

 }

 // view people to file cabinet

   void viewPerson()
 {
     int elementCount = 0;

     system("CLS");

     // sort the people in order

     sort(fileCabinet, fileCabinet + upCount);

     for(int i = 0; i < upCount; ++i)
     {
       elementCount = elementCount + 1;
     }


    // if there are no people print out message, if there are people print the people in the file cabinet
      if( elementCount == 0)
     {
         cout << endl;
         cout << "Im sorry Dave. Im afraid I cant do that" << endl;
     }
     else
     {

    for(int i = 0; i <= upCount; i++)
     {
         cout << "\n" << fileCabinet[i] << endl;

     }

     }


 }


 // Remove person from file cabinet
 deletePerson()
 {

 char userInput;

int elementCount = 0;

     system("CLS");

     // sort the people in order

     sort(fileCabinet, fileCabinet + upCount);

     for(int i = 0; i < upCount; ++i)
     {
       elementCount = elementCount + 1;
     }


    // if there are no people print out message, if there are people print the people in the file cabinet
      if( elementCount == 0)
     {
         cout << endl;
         cout << "404! People not found" << endl;
     }

else
    {


system("CLS");
cout << "\n";
cout << "Who would you like to delete from existence?"<< endl ;
cout << "\n";

for (int i = 0 ; i < upCount ; i++)

{
    cout << i + 1 <<"." << fileCabinet[i] << endl; // prints the names in the file cabinet
}

cin >> pos;


system("CLS");
cout << fileCabinet[pos - 1] << ": Are you sure you want to remove them from the File Cabinet? Y/N:";  // asked the user if the selection is correct
cin >> userInput;

userInput = toupper(userInput);


// if the selection is correct, then the name is removed from the file cabinet

     if(userInput == 'Y')
     {
         for (int i = 0 ; i < upCount ; i++)
            {
            if (fileCabinet[i] != fileCabinet[pos-1])  // grabs all names that are NOT the one being deleted
                    {

                    tempArray[i] = fileCabinet[i]; // places them in a temporary array

                    }
            }


system("CLS");
cout << fileCabinet[pos -1] << " has been removed." << endl;

upCount = upCount - 1;



for (int i = 0; i <= upCount  ; i++)
{
    fileCabinet[i] = tempArray[i]; //overwrites the old array with the remaining names not being deleted

}


sort(fileCabinet, fileCabinet + upCount);  // sorts and prints the names


cout << "Remaining users" << endl;
for(int i = 0 ;i < upCount; i++)
  {
  cout << fileCabinet[i] << endl;
  }

}
 else
 {
    system("CLS");

    cout << "Please select another name.";
 }



}



 }






// main Function
int main()
{
int input;

while(input != 4){


  system("CLS");

  cout <<" \n";
  cout<<"1. View List of People in File Cabinet." << endl;
  cout<<"2. Add a person to the File Cabinet." << endl;
  cout<<"3. Remove a person from the File Cabinet" << endl;
  cout<<"4. Exit\n"<< endl;
  cout<<"Selection: ";
  cin>> input;


  switch ( input ) {
  case 1:
    viewPerson();
    break;
  case 2:
    userInformation();
    addPerson();
    break;
  case 3:
    deletePerson();
    break;
  case 4:

    system("CLS");
    cout<<"Exiting program";
    exitProgram();

    break;
  default:
    system("CLS");
    cout << "\n";
    cout<<"Something bad happend."<< endl << "Im sending you back to the main menu."<<endl;
    cin.clear();


    break;
  }
  cout << "\n";
  cout << "Press any button to continue." << endl;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cin.get();

}
   return 0;

}



