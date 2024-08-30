#include<iostream>
#include<string>
using namespace std;

// Tips & Understanding

// --> You have forgotten even how to intilialize an array. The size of the array should be specified when declaring it. For example, user [20]; is
// proper assignment and NOT user [];

// --> To set getters and setters for an array, you have to specify the index of the array that you want to return or get. Refer to Lab 6 for understanding


class User
{
    string name; 
    string CNIC;
    string password; 
    
    public: 

    // Constructors
    User();
    User(string x, string y, string z);
    User(User &u1);

    // Setters
    void setName(string x);
    void setCNIC(string y);
    void setPassword(string z);

    //Getters
    string getName();
    string getCNIC();
    string getPassword();

    friend istream &operator>> (istream &CIN , User &u1); // we have sucessfully declared the operator >> as friend function. Note carefully the syntex
    friend ostream &operator<< (ostream &COUT, User &u1);
    friend void Signup(User u1);
    friend bool Login();
    friend void Signup(User u1);
    friend void Delete();
    friend void Print();





};

// the the constructors for user class 

User::User()
    {
        
        name = "Default";
        password = "Default";
        CNIC = "Default";

    }

User::User(string x, string y, string z)
{
    name = x;
    CNIC = y;
    password = z;
}

User::User(User &u1)
{
    name = u1.name; // strangely, this initialization of an array worked... do ask someone if this is the right way to copy an array 
    CNIC = u1.CNIC;
    password = u1.password;
}





// All the Setters

void User::setName(string x)
{
    name = x;
}

void User::setCNIC(string y)
{
    CNIC = y;
}

void User::setPassword(string z)
{
    password = z; 
}



// All the Getters

string User::getName()
{
    return name;
}

string User::getCNIC()
{
    return CNIC; 
}

string User::getPassword()
{
    return password; 
}


// OVERLOADING OPERATORS

    ostream &operator<<(ostream &COUT , User &u1)
    {
        COUT << "User Name: " << u1.name << endl;
        COUT << "User CNIC " << u1.CNIC << endl;
        COUT << "User Password " << u1.password << endl;
        return COUT;
    }

     istream &operator >> (istream &CIN , User &u1)
    {
        cout << "Enter Name: ";
        CIN >> u1.name;
        cout << "Enter CNIC ";
        CIN >> u1.CNIC;
        cout << "Enter Password ";
        CIN >> u1.password;
        return CIN;
        
    }




class Database
{
    User username[20]; // you have forgotten even how to initialize an array. The size of the array should be declared inside. That is, user [] will return an error. 
    // also note that you can initliaze an array of objects. Add these to your notes.
    int number;

    public: 

    // Constructors
    Database();
    Database(User x[], int a);
    Database(Database &u1);

    // Setters
    void setUsername(int index, User a);
    void setNumber(int y);

    //Getters
    User getUsername(int index);

    int getNumber();

    //Overloaded operators --> Improve these. I think you are a bit shaky on these 
    void operator ++();
    void operator ++(int number);
    void operator--();
    void operator--(int number);



    //Functions 

    bool Login();
    void Signup();
    void Delete();
    void printer();
    int checkUser(User username[], User u1, int size, int index);

};



// All the Constructors for Database 

Database::Database()
    {
        cout << "Setting the Database to 20 by default" << endl;

        for (int i = 0; i < 20; i++)
        {
            username[i] = User(); 
        }
        number = 0; 
    }

Database::Database(User x[], int a)
{
    for (int i = 0; i < 20; i++)
    {
        username[i] = x[i];
    }
    number = a; 
}

Database::Database(Database &u1)
{
    username[20] = u1.username[20]; // strangely, this initialization of an array worked... do ask someone if this is the right way to copy an array 

}

// All the Setters

void Database::setUsername(int index, User a)
{
    username[index] = a;
}


void Database::setNumber(int y)
{
    number = y;
}


// All the Getters

User Database::getUsername(int index)
{
    return username[index];
}


int Database::getNumber()
{
    return number; 
}



// Overloading ++ and --


void Database::operator ++() // prefix
{
    number = ++number;
}

void Database::operator ++(int number) // postfix
{
    number = number++;
}

void Database::operator--()
{
    number = --number;
}

void Database::operator-- (int number) // prefix
{
    number = number--;
}

int Database::checkUser(User username[], User u1, int size, int index)
{
    string x = u1.getName();
    string y = u1.getPassword();
    string z = u1.getCNIC();


    if(index==size)
    {
        cout << "No Such User Exists in the Database!" << endl;
        return -1;
    }  
    else if((username[index].getName() == x) && (username[index].getPassword() == y))
        { 
            cout << "A User Name exists in the Database!" << endl;
            return index; 
        }
    else 
    {
        int result = checkUser(username,u1, size, index +1);
        return result;
    }
}

bool Database::Login()
{
    User u1;
    bool exiter = false;
    cout << "YOU HAVE CHOSEN TO LOGIN" << endl;
    cin >> u1; 

    int check = checkUser(username, u1, 19, 0);
    
    if (check != -1)
    {
        cout << "You have sucessfully logged in!" << endl;
        cout << "The Details of the User are the following" << endl;
        cout << u1 << endl;
        exiter = true;
        return exiter;

    }
    else 
    {
        cout << "Returning to Main Interface" << endl;
        cout << endl;
        exiter = false;
        return exiter;
    }
}


void Database::Delete()
{
    cout << "You have Chosen to Delete your account" << endl;
    cout << "Please Add User Details" << endl;
    User u1;
    cin >> u1;

    int check = checkUser(username,u1, 19, 0);
    cout << check << endl;
    if (check == -1)
    {
        cout << "Exiting to the Main interface" << endl;    
    }
    else
    {
        cout << "Now Deleting the User" << endl;
        username[check].setCNIC("Default"); 
        username[check].setName("Default");
        username[check].setPassword("Default");
        cout << "The User has been sucessfully deleted" << endl;
        --number;
        cout << number << endl;
        if (check == 19)
        {
            cout << "The Database has been sorted" << endl;
        }
        else if (check != 19)
        {
            if ((username[check + 1].getName() == "Default") && (username[check +1].getPassword() == "Default"))
            {
                cout << "The Array has been sorted!" << endl;  
            }
        else
        {
    
            for (int i = check; i < 19;i++)
            {        
                username[i] = username[i+1];
            }
   

    

        cout << "The Array was sorted" << endl;
        }

    }

    }
    
    


    
    
}

void Database::printer()
{
    cout << "Now Showcasing the entire Database" << endl;
            for(int i=0; i<20; i++)
            {
                cout << username[i].getName()<<endl;
                cout << username[i].getPassword()<<endl;
            }


}


    void Database::Signup() /// THESE WILL TAKE USER AS ARGUMENTS! 
{
    User u1;
    cout << "YOU HAVE CHOSEN TO Sign In" << endl;
    cin >> u1;
    bool repeat = false;
  

    for (int i = 0; i < 20; i++)
    {
        if (username[i].getPassword() == u1.getPassword() && username[i].getName() == u1.getName()) 
        {
            cout << "You Already have an account" << endl;
            cout << "Exiting to Main Interface" << endl;
            cout << endl;
            repeat = true;
            break;
        }
    }

    if (repeat == false)
    {
        cout << "You have sucessfully signed up" << endl;
        cout << endl;
        username[number] = u1;
        ++number;


    }



  

   

}

void menu()
{
    cout << "WELCOME TO THE INTERFACE" << endl;
    cout << "1) Login" << endl;
    cout << "2) Sign Up" << endl;
    cout << "3) Delete" << endl;
    cout << "4) Exit" << endl; 
}


int main()
{
    bool exiter = false;
    int choice1;
    int choice2;
    Database d1;
    int login_checker;


    while (exiter == false)
    {
        menu();
        cin >> choice1;
        if (choice1 == 1)
        {
            bool login_checker = d1.Login();

            if (login_checker == true)
            {
                cout << "You now have the following options" << endl;
                cout << "1) Logout" << endl;
                cout << "2) Exit Program" << endl;
                cin >> choice2;
                if (choice2 ==1)
                {
                   cout << "You have chosen to Logout" << endl;
                }
                else if(choice2==2)
                {
                  cout << "Now Exiting the Program" << endl;
                  exiter = true;
                }
            }
            
        
        }
        else if (choice1 == 2)
        {
            d1.Signup();

        }
        else if(choice1 == 3)
        {
            d1.Delete();

        }
        else if (choice1 == 4)
        {
           
            cout << "For Test Purposes, I am Printing my entire database" << endl;
            d1.printer();
            cout << "The total number of Users are " << d1.getNumber() << endl;
            exiter = true;
        }


    }




}












    














// CURRENT TASKS:
// --> Note that Functions SignUp , Login, and Delete would take User Objects as inputs!
// --> Note that the Members of Database may contain arrays of Users and Password and CNIC Seperately
// --> HOW TO ADD THE INSTANCE OF THE USER to the array of Users in the class Database? This is a little tricky. 

 








// int main()
// {

    
// }

