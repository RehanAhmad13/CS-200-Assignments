#include<iostream>
#include<string>
#include <limits>
using namespace std;



int inp_validation(int inp, int low, int high)
{
    while(1)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize>::max(),'\n');
            cout << "Please enter an integer value: " << endl;
            cin >> inp;
        }
        else if(!cin.fail())
		{
            if (inp > high || inp < low)
            {
                cout << "Please enter a value between " << low << " and " << high << " : "; 
                cin >> inp;
                inp = inp_validation(inp,low, high);
            }
            break;
        }
     
    }
    return inp;
    
}


class time
{
    int hour;
    int minute;
    
    // constructors
    public: 
    time(int a, int b);
    time();

    //setters
    void sethour(int a);
    void setminute(int b);

    // getter
    int gethour();
    int getminute();

    // overloading
    friend ostream& operator<<(ostream &COUT, time t1);

};

time::time(int a, int b)
{
    hour = a; 
    minute = b;
}

time:: time()
{
    hour = 0;
    minute = 0;
}


void time:: sethour(int a)
{
    hour = a;
}

void time:: setminute(int b)
{
    minute = b;
}

int time:: gethour()
{
    return hour;
}

int time:: getminute()
{
    return minute;
}

ostream& operator << (ostream &COUT, time* t1)
{
    if (t1 -> gethour() < 10 && t1 -> getminute() < 10 )
    {
        COUT << "0" << t1 -> gethour() << ":" << "0" << t1->getminute() << endl;
    }
    else if(t1 -> gethour() < 10)
    {
        COUT << "0" << t1 -> gethour() << ":" << t1 -> getminute() << endl;
    }
    else if(t1 -> getminute() < 10)
    {
        COUT << t1 -> gethour() << ":" << "0" << t1 -> getminute() << endl;
    }
    else
    {
        COUT <<  t1->gethour() << ":" << t1->getminute() << endl;
    }
    return COUT;
}




struct Node
{
    string task;
    time t1;
    int completion; 
    Node *next;
};

Node *getNewNode(string a, time b, int c)
{
    Node *temp = new Node;
    if(temp == NULL)
    {                   
        cerr << "List is full. No more memory available." << endl;
        exit(-1);     
    }
    else
    {
        temp-> task = a;
        temp -> t1 = b;
        temp -> completion = c;
        temp-> next = NULL;
    }
    return temp;
}




class ToDoList 
{
    Node *head;
    public:

    ToDoList();
    ~ToDoList();

    bool isToDoListEmpty();
    bool isToDoListFull();

    Node* gethead();
    void sethead(Node * p);
    void InsertAtEnd(Node* temp, Node* add);
    void insertAfter(Node* prev_node, Node* add);
    void DeleteTask(Node* temp);
    void PrintList(Node* head);
    Node* leasttime(Node* head, Node* least);
    int lengthList (Node* head);
    bool search_by_task(Node* head, string x);
    bool search_by_time(Node* head, time y);
    bool search_by_completion(Node* head, int c);
    void delete_list(Node* temp);
    Node* Nodegetter(string a);

};


//getters and setters 
Node* ToDoList :: gethead() // is this the correct getter? check again
{
     if (head == NULL)
    {
        return NULL;
    }
    return head;
}


void ToDoList :: sethead(Node* h)
{
    head = h; 
}
   
    
    
    

//constuctors and destructors 


ToDoList::ToDoList()
{
    head = NULL;
}

ToDoList::~ToDoList()
{
    Node* temp = head; // startng from head remove/delete every element till the last one


    while(temp != NULL)
    {
        temp = head->next;        // move p to the next element -- p = p->next;
        delete temp;        // delete element at the head of the list
        head = temp;           // move head to the next element
    }
}

// for error handling

bool ToDoList::isToDoListEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ToDoList::isToDoListFull()
{
    Node *temp = new Node;
    if(temp == NULL)
    {
        return true;
    }
    else
    {
        delete temp;
        return false;
    }
}







// the base case is that when head points to NULL
void ToDoList:: InsertAtEnd(Node* temp, Node* add)
{
     if (head == NULL) 
    {
        head = add;
        return;
    }

    if(temp -> next == NULL)
    {
        temp -> next = add;
        return;
    }
    else
    {
        InsertAtEnd(temp -> next, add);
    }
    
}




void ToDoList::insertAfter(Node* prev_node, Node* add) // takes the node after which the new node has to be added as parameter
{
     if (prev_node == NULL)
     {
         cout << "There is no NODE before this" << endl;
         return; 
    }
    Node* temp = add;
    temp -> next = prev_node -> next; // makes the next pointer of temp point towards what prev_node was pointing towards
    prev_node -> next = temp; // the next of prev-pointer now points towards temp node

}

void ToDoList:: DeleteTask(Node* temp)
{
     if (head == NULL) 
    {
        cout << "The list is empty" << endl;
        return;
    }
    else if (head->next==NULL)
    {
        delete head;
        head=NULL;
    }
    else if (temp->next -> next == NULL)
    {
        delete temp->next;
        temp->next=NULL;
        cout << "The Last Account has been removed" << endl;
        
    }
    else
    {
        DeleteTask(temp -> next);
    }
    
    
}


// this is printing the list recursively. Try fixing it up
void ToDoList :: PrintList(Node* temp)
{
    if (head == NULL)
    {
        return;
        cout << "There is no content inside the List" << endl;
    }

    if (temp == NULL)
    {
        return;
    }
    cout << endl;
    cout << "The name of the task is " << temp -> task << endl; 
    cout << "The time taken to complete the task in minutes is " << temp -> completion << endl;
    cout << "The time in 24 hour format is " << temp -> t1 << endl;
    
    PrintList(temp -> next);

}



Node* ToDoList ::leasttime(Node* temp, Node* least)
{
    if(head==NULL)
    {
        cout << "The list is empty" << endl;
        return NULL;
    }

    if(temp==NULL)
    {
        return least;
    }

    if (temp -> t1.gethour() < least -> t1.gethour())
    {
        return leasttime(temp -> next, temp); // least node has now been changed to temp
    }
    else
    {
        return leasttime(temp -> next, least); // least node remains the same
    }

    if (temp -> t1.getminute() < least -> t1.getminute() )
    {
        return leasttime(temp -> next, temp);
    }
    else
    {
        return leasttime(temp -> next, least);
    }
}


int ToDoList:: lengthList (Node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + lengthList(head -> next));
    }
}

bool ToDoList:: search_by_task(Node* head, string x)
{
    if (head == NULL)
    {
        return false;
    }

    if (head ->task == x)
    {
        return true;
    }

    return search_by_task(head -> next, x);

}


bool ToDoList:: search_by_time(Node* head, time y)
{
    if (head == NULL)
    {
        return false;
    }

    if (head ->t1.gethour() == y.gethour() && head -> t1.getminute() == y.getminute())
    {
        return true;
    }

    return search_by_time (head -> next, y);
}






bool ToDoList :: search_by_completion(Node* head, int c)
{
    if (head == NULL)
    {
        return false;
    }

    if (head ->completion == c)
    {
        return true;
    }

    return search_by_completion (head -> next, c);
}

void ToDoList::delete_list(Node* temp)//we will be passing the head of the list in it and traverse the head
{
    if(head==NULL)//break case is when head becomes null
    {
        return;
    }
    head=head->next;//we traverse and set head as object next to head
    delete temp;//we delete the checking which would be the previous head
    delete_list(head);// we recursively call the function and pass head which has changed to the next object in line and the previous one has been deleted

}

Node* ToDoList :: Nodegetter(string a)
{
    Node* temp = head;
    if (isToDoListEmpty())
    {
        return NULL;
    }
    else
    {
        while (temp!= NULL && temp -> task !=a)
        {
            temp = temp -> next;
        }
        if(temp != NULL)
        {
            return temp;
        }
        else
        {
            return NULL;
        }

    }
}


void menu()
{
    cout << "Welcome to the To Do List" << endl;
    cout <<"1)Insert a task at the end" << endl;
    cout << "2) Insert a Task after a specific task" << endl;
    cout << "3) Delete a Task from the end" << endl;
    cout << "4) Display To Do list" << endl;
    cout << "5) Find the task which requires lowest time" << endl;
    cout<< "6) Determine the length of the To Do list" << endl;
    cout << "7) Search for the Task by Description" << endl;
    cout << "8) Search for the Task by Time" << endl;
    cout << "9) Search for the Task by Completion" << endl;
    cout << "10) Delete the To-Do-List" << endl;
    cout << "11) Exit the Program" << endl;

}

int main()
{
    ToDoList* L1 = new ToDoList(); 
    bool c1 = true; 
    while (c1 == true)
    {
        menu();
        int c2; 
        cin >> c2;


        if (c2 == 1)
        {
            cout << "Enter the Name of Task" << endl;
            string task;
            getline(cin, task);
            cin.ignore();
            cout << "Enter Minutes" << endl;
            int minute;
            cin >> minute;
            minute = inp_validation(minute,1, 59);
            cin.ignore();
            cout << "Enter hours" << endl;
            int hour;
            cin >> hour;
            hour = inp_validation(hour, 1, 24);
            cin.ignore();
            cout << "Enter Time to Complete the Task (in minutes)" << endl;
            int completion;
            completion = inp_validation(completion, 1, 1440);
            cin >> completion;
            cin.ignore();
            time t1;
            t1.setminute(minute);
            t1.sethour(hour);

            Node* a1 = getNewNode(task,t1,completion);
            L1 -> InsertAtEnd(L1-> gethead(), a1);
    

        }
        else if(c2 == 2)
        {
            cout<<"Please Enter the name of Task you want to enter (no space)" << endl;
            string task;
            getline(cin, task);
            cin.ignore();
            cout<<"Enter Minutes " << endl;
            int m;
            cin>> m;
            m = inp_validation(m,1, 60);
            cin.ignore();
            cout << "Enter Hours" << endl;
            int h;
            cin >> h;
            h = inp_validation(h, 1, 24);
            cin.ignore();
            cout << "Enter Time to Complete (in minutes)" << endl;
            int completion;
            cin >> completion;
            completion = inp_validation(completion,1, 1440);
            cin.ignore();
            time t1;
            t1.sethour(h);
            t1.setminute(m);
            Node* a1 = getNewNode(task, t1, completion);

            cout << "Enter the name of the Task you want to insert after" << endl;
            string b;
            getline(cin, b);
            cin.ignore();
            Node* prev_node = L1 -> Nodegetter(b);
            L1 -> insertAfter(prev_node, a1);

        }
        else if(c2 == 3)
        {
            L1 -> DeleteTask(L1->gethead()); // where the dot operator is replaced by -> because L1 is a node

        }
        else if(c2 == 4)
        {
            L1 -> PrintList(L1->gethead());

        }
        else if(c2 == 5)
        {
            time t1;
            t1.setminute(INT_MAX);
            t1.sethour(INT_MAX);
            Node *b = getNewNode("task1", t1, 1);
            Node* least = L1 -> leasttime(L1->gethead(),b);
            if (least!= NULL)
            {
                cout << "Task with least time is: " << least -> task << " and the time required is: " << least -> t1 << endl;
            }

        }
        else if(c2 == 6)
        {
            cout << "The Length is " << L1 -> lengthList(L1->gethead()) << endl;

        }
        else if(c2 == 7)
        {
            cout << "You have chosen to search by task" << endl;
            cout << "Type the task" << endl;
            string task;
            getline(cin, task);
            bool a = L1 -> search_by_task(L1-> gethead(), task);
             if (a == true)
            {
                cout << "Match found!" << endl;
            }
            else if (a == false)
            {
                cout << "No Match found!" << endl; 
            }
            
        }
        else if(c2 == 8)
        {
            cout << "You have chosen to search by time" << endl;
            cout << "Type the time in minutes" << endl;
            int minute;
            cin >> minute;
            minute = inp_validation(minute, 1, 60);
            cin.ignore();
            cout << "Type the time in hours" << endl;
            int hour;
            cin >> hour;
            hour = inp_validation(hour, 1, 24);
            cin.ignore();
            time t1;
            t1.sethour(hour);
            t1.setminute(minute);
            bool a = L1 -> search_by_time(L1-> gethead(), t1);
             if (a == true)
            {
                cout << "Match found!" << endl;
            }
            else if (a == false)
            {
                cout << "No Match found!" << endl; 
            }

        }
        else if(c2 == 9)
        {
            cout << "You have chosen to search by completion" << endl;
            cout << "Type the completion time" << endl;
            int completion;
            cin >> completion; 
            completion = inp_validation(completion,1, 1440);
            bool a = L1 -> search_by_completion(L1-> gethead(), completion);
            if (a == true)
            {
                cout << "Match found!" << endl;
            }
            else if (a == false)
            {
                cout << "No Match found!" << endl; 
            }


        }
        else if(c2 == 10)
        {
            L1 -> delete_list(L1->gethead());

        }
        else if(c2 == 11)
        {
            c1 = false; 

        }

    }

}

    
