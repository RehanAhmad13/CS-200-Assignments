#include<iostream>
#include<iostream>
using namespace std;



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
    friend ostream& operator<<(ostream &COUT, time* t1);

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
    COUT <<  t1->gethour() << ":" << t1->getminute() << endl;
    return COUT;
}


class node
{
    public:
    string task;
    time* t1;
    int completion;
    node* prev;
    node* next;
    node();
    node(string a, time* b, int c);
};



node::node()
{
    next=NULL;
    prev = NULL;
    task = "";
    t1 = NULL;
    completion = 0;
}

node::node(string a,time* b,int c)
{
    task = a;
    t1=b;
    completion = c;
    next=NULL;
    prev = NULL;
}

class DoublyLinked
{
    node *head;
    node *tail;
    public:

    DoublyLinked();

    node* gethead();
    node* gettail();
    void sethead(node * p);
    void insertattail(node* temp, node* add);
    void insertathead(node* add);

    void deleteatend();
    void deletefromstart(node* head);
    void printlist(node* temp);
    void insertionsort();
};



DoublyLinked::DoublyLinked()
{
    head = NULL;
}


//getters and setters
node* DoublyLinked :: gethead()
{
     if (head == NULL)
    {
        return NULL;
    }
    return head;
}

void DoublyLinked :: sethead(node* h)
{
    head = h;
}

node* DoublyLinked:: gettail()
{
    if (head == NULL)
    {
        return NULL;
    }
    return tail;
}

// node *getNewNode(string a, time b, int c)
// {
//     node *temp = new node;
//     if(temp == NULL)
//     {                  
//         cerr << "List is full. No more memory available." << endl;
//         exit(-1);    
//     }
//     else
//     {
//         temp-> task = a;
//         temp -> t1 = b;
//         temp -> completion = c;
//         temp-> next = NULL;
//         cout << "this is working" << endl;
//     }
//     return temp;
// } buggy af

void DoublyLinked:: insertathead(node* add)
{
    if (head == NULL)
    {
        head = add;
        tail = add;
        return;
    }
       
    add -> next = head;
    head = add;

    // cout << add->task << endl;
    // cout << &head << endl; for testing. this function is working well.
}

void DoublyLinked::insertattail(node* temp, node* add)
{
    if(head == NULL)
    {
        head = add;
        tail = add;
        return;
    }
    else
    {
        tail -> next = add;
        tail = tail -> next;
        tail -> next = NULL;
    }

}


void DoublyLinked:: deletefromstart(node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    if(head->next==NULL)
    {
        head=NULL;
        tail=NULL;
        return;
    }
    else
    {
        node* todelete = head;
        head = head -> next;
        head -> prev = NULL;
        delete todelete;
    }
}

void DoublyLinked:: deleteatend()
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    if(head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        node * temp = tail ->prev;
        tail=temp;
        tail->next=NULL;
    }

}



void DoublyLinked:: insertionsort()
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    if(head -> next == NULL)
    {
        cout << "There is only one element in the list" << endl;
        return;
    }

    node* i = head;
    while (i != NULL)
    {
        node* j = i;
        while(j != NULL)
        {
            if( j !=i)
            {
                if (j -> completion < i -> completion)
                {
                    int swap = j -> completion;
                    j -> completion = i -> completion;
                    i -> completion = swap;
                }
            }
           j = j -> next;
        }
        i = i -> next;
    }
   

}



void DoublyLinked :: printlist(node* temp)
{
    if (head == NULL)
    {
        cout << "There is no content inside the List" << endl;
        return;
    }

    if (temp == NULL)
    {
        return;
    }

    cout << endl;
    cout << "The name of the task is " << temp -> task << endl;
    cout << "The time taken to complete the task in minutes is " << temp -> completion << endl;
    cout << "The time in 24 hour format is " << (temp->t1)<< endl;

    printlist(temp->next);
}

void menu()
{
    cout << "Welcome to the To Do List" << endl;
    cout <<"1) Insert a task at the end" << endl;
    cout << "2) Insert at the start of the list" << endl;
    cout << "3) Delete from the end of the list" << endl;
    cout << "4) Delete from the start of the list" << endl;
    cout<< "5) Display List" << endl;
    cout << "6) Carry out Insertion Sort" << endl;
    cout << "7) Exit Menu" << endl;
   
}

int main()
{
    DoublyLinked* L1 = new DoublyLinked();
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
            cin >> task;
            cin.ignore();
            cout << "Enter Minutes" << endl;
            int minute;
            cin >> minute;
            cin.ignore();
            cout << "Enter hours" << endl;
            int hour;
            cin >> hour;
            cin.ignore();
            cout << "Enter Time to Complete the Task (in minutes)" << endl;
            int completion;
            cin >> completion;
            cin.ignore();
            time* t1 = new time(hour,minute);
            node* a1 = new node(task, t1, completion);
            // t1.setminute(minute);
            // t1.sethour(hour);

            // node* a1 = getNewNode(task,t1,completion); // get node has become buggy idk. I will pass pointers.
            L1 -> insertattail(L1-> gethead(), a1);
        }
         else if(c2 == 2)
        {
            cout<<"Please Enter the name of Task you want to enter (no space)" << endl;
            string task;
            cin >> task;
            cin.ignore();
            cout<<"Enter Minutes " << endl;
            int m;
            cin>> m;
            cin.ignore();
            cout << "Enter Hours" << endl;
            int h;
            cin >> h;
            cin.ignore();
            cout << "Enter Time to Complete (in minutes)" << endl;
            int completion;
            cin >> completion;
            cin.ignore();
            time* t1 = new time(h, m);
            node* a1 = new node(task, t1, completion);
            // time t1;
            // t1.sethour(h);
            // t1.setminute(m);
            // node* a1 = getNewNode(task, t1, completion);

            L1 -> insertathead(a1);

        }
        else if(c2 == 3)
        {
            L1 -> deleteatend(); // where the dot operator is replaced by -> because L1 is a node

        }
        else if(c2 == 4)
        {
           
            L1 -> deletefromstart(L1->gethead());

        }
        else if(c2 == 5)
        {
            L1 -> printlist(L1 -> gethead());
        }
        else if(c2 == 6)
        {
            cout << "Carry out insertion sort" << endl;
            L1 -> insertionsort();
        }
        else if (c2 == 7)
        {
            cout << "Exiting" << endl;
            c1 = false;
        }
    }
}