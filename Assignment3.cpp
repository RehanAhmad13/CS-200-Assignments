#include<iostream>
#include<string>
#include <limits>
using namespace std;



// int inp_validation(int inp, int low, int high)
// {
//     while(1)
//     {
//         if(cin.fail())
//         {
//             cin.clear();
//             cin.ignore(numeric_limits < streamsize>::max(),'\n');
//             cout << "Please enter an integer value: " << endl;
//             cin >> inp;
//         }
//         else if(!cin.fail())
// 		{
//             if (inp > high || inp < low)
//             {
//                 cout << "Please enter a value between " << low << " and " << high << " : "; 
//                 cin >> inp;
//                 inp = inp_validation(inp,low, high);
//             }
//             break;
//         }
     
//     }
//     return inp;
    
// }


struct Node
{
    string dish;
    int quantity; 
    int price_per_dish; 
    Node *next;
    Node* prev;
    Node();
    Node(string a, int b, int c);
};

//constructors
Node::Node()
{
    dish = "";
    quantity = -1;
    price_per_dish = -1;
    next=NULL;
    prev = NULL;

}
//parametrized constructor
Node::Node(string a,int b, int c)
{
    dish= a;
    quantity = b;
    price_per_dish = c; 
    next=NULL;
    prev = NULL;

}

class Menu 
{
    Node *head;
    public:
    
  
    Node* gethead();
    void sethead(Node *p);

    bool isMenuEmpty();
    bool isMenuFull();
    
    // 1. Constructors & Destructors 
    ~Menu();
    Menu();
    Menu(int size); // parametrized consturctor. Again, this is something you to think about. 
    Menu(const Menu &list); // copy constructor. check if this is working

    // 2. Insert New Dish to the lists  
    void InsertDish(Node* temp, Node* add);

    //3. Delete Dish 
    void Deletedish(string x);

    //4. Update Quantity 
    bool UpdateDish(Node* head, string x, int y);

    //5. Sum of all dishes
    int SumDishes (Node* head);

    //6. Quantity of dish
    int QuantityDish(Node*head, string x);

    //7.Update Price 
    bool UpdatePrice(Node*temp, string a, int b);

    //8. Display Menu
    void DisplayMenu(Node* head, int n);

    // question 2 functionalities 
    int PriceDish(Node*head, string x);
    int TotalSales(Node* head);
    int DishOrders(Node* head, string x);
    int CashReceived(Node* head, string x); 
    string MaximumDish(Node* head);
    string MinimumDish(Node* head); 
    void Today_Menu(int size);

  

};


//getters and setters 
Node* Menu :: gethead() // is this the correct getter? check again
{
     if (head == NULL)
    {
        return NULL;
    }
    return head;
}


void Menu :: sethead(Node* h)
{
    head = h; 
}
   
    
    
    

//constuctors and destructors 

Menu:: ~Menu()
{
    Node* temp = head; // startng from head remove/delete every element till the last one
    while(temp != NULL)
    {
        temp = head->next;        // move p to the next element -- p = p->next;
        delete temp;        // delete element at the head of the list
        head = temp;           // move head to the next element
    }
}


Menu::Menu()
{
    head = NULL;
}

// so I should specify the size of the linked list that the user wants to create the linked list. Then, once I have that, 
// I will have to somehow traverse the list. For example, suppose that the user says he want to create a linked list of size n. 
// then, I can say that while (!= n) , createnewNode(), populate with particular size and repeat. So you are mixing the gethead
// function with a loop. 

Menu:: Menu(int size)
{
    cout << "Specify the Dish to be inserted at Option 1 " << endl;
    string a; 
    cin >> a;

    cout << "Specify the Quantity of the Dish at Option 1" << endl;
    int b; 
    cin >> b; 

    cout << "Specify the Price Per dish of Option 1" << endl; 
    int c; 
    cin >> c; 

    Node* add = new Node(a, b, c);
    head = add;

    for (int i=0; i < size - 1; i++)
    {
        cout << "Specify the Dish to be inserted in Option " << i + 2 << endl;
        string a; 
        cin >> a;
        cout << "Specify the Quantity of the Dish at Option " << i + 2 << endl;
        int b; 
        cin >> b; 
        cout << "Specify the Price Per dish of Option " << i + 2 << endl; 
        int c; 
        cin >> c; 

        Node *traverse = head;
        while(traverse->next != NULL)
        {
            traverse = traverse->next;
        }

        Node* add = new Node(a, b, c);
        traverse->next = add;
        
    }
}





Menu::Menu(const Menu &list)
{
    if (list.head == NULL)
    {
        head = NULL;
        return;
    }

    Node* temp = list.head; // temp points to head of list
    Node* newNode = NULL; 

    while(temp != NULL)
    {
        newNode = new Node();
        newNode -> dish = temp -> dish;
        newNode -> quantity = temp -> quantity;
        newNode -> next = NULL; 

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            head -> next = newNode;

        }

        temp = temp -> next;    
        }
}




// for error handling

bool Menu::isMenuEmpty()
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

bool Menu::isMenuFull()
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
void Menu:: InsertDish(Node* temp, Node* add)
{
    
    if(head == NULL)
    {
        head = add;
    }
    else
    {
        Node *traverse = head;
        while(traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        // now q is the last element
        traverse->next = add;    // inset new node next to the last node

    }

}






void Menu:: Deletedish(string x)
{
  
    if (head == NULL) 
    {
        cout << "The PDC Menu is empty" << endl;
        return;
    }

    Node* p = head; // pointer to traverse list 
    if (head -> dish == x)
    {
        head = head -> next;
        delete p;
    }

    Node* n = NULL; // trailing node

    while(p != NULL && p->dish != x)
    {
        n = p;
        p = p -> next;
    }

    // to check if we found the targetvalue

    if (p != NULL)
    {
        cout << "Dish found!" << endl;
        n -> next = p -> next;
        delete p;
    }


    
}



bool Menu:: UpdateDish(Node* head, string x, int y)
{
    if (head == NULL)
    {
        return false;
    }

    if (head -> dish == x)
    {
       
        head -> quantity = y; 
        return true;

    }

    return UpdateDish(head -> next, x, y);

}



//sum of all dishes 

int Menu:: SumDishes (Node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + SumDishes(head -> next));
    }
}

// Quantity of dish
int Menu:: QuantityDish(Node*head, string x)
{
    if (head == NULL)
    {
        cout << "The Menu is empty" << endl;
        return -1;
    }

    if (head ->dish == x)
    {
        cout << "Dish found" << endl;
        int y = head -> quantity; 
        return y;

    }

    return QuantityDish(head -> next, x);

}


int Menu:: PriceDish(Node* head, string x)
{
    if (head == NULL)
    {
        cout << "The Menu is empty" << endl;
        return -1;
    }

    if (head ->dish == x)
    {
        int y = head -> price_per_dish; 
        return y;
    }

    return PriceDish(head -> next, x);

}





bool Menu:: UpdatePrice(Node*temp, string a, int b)
{
    if (head == NULL)
    {
        cout << "The Menu is Empty" << endl;
        return false;
    }
    else if (head -> dish == a)
    {
        head -> price_per_dish = b;
        return true; 
    }
    else if(temp -> dish == a)
    {
        temp -> price_per_dish = b;
        return true;
    }

    return UpdatePrice(temp-> next, a, b);

}












// this is printing the list recursively. Try fixing it up
void Menu :: DisplayMenu (Node* head, int n)
{
    if (head == NULL)
    {
        return;
        cout << "There is no content inside the List" << endl;
    }

    if (head -> quantity != 0)
    {
        cout << endl;
        cout << "The name of the dish at Slot " << n << ":"  << head -> dish << endl; 
        cout << "The quantity of the dish is: " << head -> quantity << endl;
        cout << "The price per dish is: " << head -> price_per_dish << endl;
        n = n + 1; 

    }

    
    DisplayMenu(head -> next, n);

}



int Menu:: TotalSales (Node* head)
{
    if (head == NULL)
    {
        cout << "There have been no sales" << endl;
        return 0; 
    }

    int total;
    Node* p = head; // pointer to traverse list 
    while(p != NULL)
    {
        int x = p -> price_per_dish;
        int y = p -> quantity;
        total = total + x*y; 
        p = p -> next;
    }

    return total; 
}

int Menu:: DishOrders(Node* head, string x)
{
     
    if (head == NULL)
    {
        cout << "The Dish has not been ordered" << endl; 
        return 0; 
    }

    Node* temp = head;
    int total; 

    while(temp != NULL)
    {
        if(temp->dish == x)
        {
            total = total + 1; 
        }
        temp = temp -> next;
    }
    return total; 

}

int Menu:: CashReceived(Node* head, string x)
{
    if (head == NULL)
    {
        cout << "The Dish has not been ordered" << endl; 
        return 0; 
    }

    Node* temp = head;
    int cash;

    while(temp != NULL)
    {
        if(temp->dish == x)
        {
            int x = temp -> quantity;
            int y = temp -> price_per_dish; 
            cash = cash + x*y; 
        }
        temp = temp -> next;
    } 

    return cash; 

}

// string Menu:: MaximumDish(Node* head)
// {
//     if (head == NULL)
//     {
//         cout << "The PDC Menu is Empty" << endl;
//         return "";
//     }

//     Node* p = head;
//     int max_count = -1;
//     int count = 0; 
//     string fav;
//     while(p!= NULL)
//     {
//         Node *temp = p -> next; // for traversal 
//         while(temp != NULL)
//         {
//             if(p->dish == temp->dish)
//             {
//                 count ++;
//             }     
//             temp = temp -> next;   
//         }

//         if (count < max_count)
//         {
//             max_count = count;
//             fav = p -> dish;

//         }
//         p = p -> next;

      
//     }
//     return fav; 


// }


// string Menu:: MinimumDish(Node* head)
// {
//     if (head == NULL)
//     {
//         cout << "The PDC Menu is Empty" << endl;
//     }

//     int total_count;
//     int min_count;
//     string dish;
//     Node* p = new Node();
//     while(p!= NULL)
//     {
//         int count = 1;
//         Node *temp = new Node;
//         temp = p -> next; // for traversal 
//         while(temp != NULL)
//         {
//             if(p->dish == temp->dish)
//             {
//                 count ++;
//             }
//         temp = temp -> next; 
        
//         }

//         if (count < min_count)
//         {
//             min_count = count;
//             dish = p -> dish;

//         }
//         p = p -> next;
//         total_count++;

//         if(min_count <= total_count/2)
//         {
//             return dish;
//         }
//     }

//     return "No Dish"; 



// }


void Menu:: Today_Menu(int size)
{
    cout << "Specify the Dish to be inserted at Option 1 " << endl;
    string a; 
    cin >> a;

    cout << "Specify the Quantity of the Dish at Option 1" << endl;
    int b; 
    cin >> b; 

    cout << "Specify the Price Per dish of Option 1" << endl; 
    int c; 
    cin >> c; 

    Node* add = new Node(a, b, c);
    head = add;

    for (int i=0; i < size - 1; i++)
    {
        cout << "Specify the Dish to be inserted in Option " << i + 2 << endl;
        string a; 
        cin >> a;
        cout << "Specify the Quantity of the Dish at Option " << i + 2 << endl;
        int b; 
        cin >> b; 
        cout << "Specify the Price Per dish of Option " << i + 2 << endl; 
        int c; 
        cin >> c; 

        Node *traverse = head;
        while(traverse->next != NULL)
        {
            traverse = traverse->next;
        }

        Node* add = new Node(a, b, c);
        traverse->next = add;
        
    }
}








int admin_menu()
{
    cout << "Welcome to the Admin Menu System" << endl;
    cout << "1) Specify Today's PDC Menu (Note that this would reset the existing Menu)" << endl; 
    cout << "2) Insert New Dish in the PDC Menu" << endl; 
    cout << "3) Update Quantity of Dish in the PDC Menu" << endl; 
    cout << "4) Total Number of Dishes Ordered" << endl; 
    cout << "5) Quantity of a Particular Dish in the PDC Menu" << endl; 
    cout << "6) Update Price of a Dish in the PDC menu" << endl; 
    cout << "7) Total Sales" << endl;
    cout << "8) Total Number of Orders per dish" << endl;
    cout << "9) Total Cash received per dish" << endl;
    cout << "10) Most favorite (ordered) dish" << endl;
    cout << "11) Least favorite (ordered) dish " << endl;
    cout << "12) Display PDC Menu" << endl; 
    cout << "13) Display Orders" << endl; 
    cout << "14) Quit" << endl;
    int choice; 
    cin >> choice; 
    return choice;

}


int menu()
{
    cout << "Welcome to the PDC System" << endl;
    cout << "1) Customer View" << endl;
    cout << "2) Admin View" << endl;
    cout << "3) Exit" << endl; 
    int choice;
    cin >> choice;
    return choice; 
}





int main()
{
    Menu* PDC = new Menu(); // this is the object that contains the menu for today
    Menu* Orders = new Menu(); // the object that contains the total order

    bool c1 = true;
    while (c1 == true)
    {
        int c2 = menu();
       

        if (c2 == 1)
        {
            cout << "Welcome to the Customer Menu System" << endl; 
            cout << "The Menu for Today is..." << endl; 
            PDC -> DisplayMenu(PDC-> gethead(),1);
            cout << endl;
            cout << "Do you want to Place an Order" << endl;
            cout << "1) Yes" << endl;
            cout << "2) No" << endl;
            int c3;
            cin >> c3;
            if (c3 == 1)
            {
                if (PDC->gethead() == NULL)
                {
                    cout << "The PDC Menu is Empty" << endl;
                    cout << "Please Wait for it to be Updated!" << endl;
                }
                else
                {
                    cout << "Please Enter the Name of the dish you want to Order" << endl;
                    string dish;
                    cin.ignore();
                    cin.clear();
                    getline(cin, dish);
                    cout << "Please Enter the Quantity of the Dish you want to Order" << endl;
                    int quantity;
                    int x = PDC -> QuantityDish(PDC->gethead(), dish);
                    bool flag = true;
                    while(flag == true)
                    {
                        cin >> quantity;
                        if(x < quantity)
                        {
                            cout << "The quantity ordered exceeds the amount present. Please enter reasonable amount" << endl;                        }
                        else
                        {
                            flag = false; 
                        }
                    }
                    
                    int price_per_dish = PDC -> PriceDish(PDC->gethead(), dish);
                    Node* a1 = new Node(dish,quantity,price_per_dish);
                    Orders -> InsertDish(Orders-> gethead(), a1);
                    int new_quantity = x - quantity; 
                    PDC -> UpdateDish(PDC -> gethead(), dish, new_quantity); 

                }

            }
            else if(c3 == 2)
            {
                cout << "Exiting" << endl;
            }

        }
        else if (c2 == 2)
        {
            int c4 = admin_menu();
            if (c4 == 1)
            {
                cout << "Specify the number of dishes you would like to add to the Menu" << endl;
                int n;
                cin >> n;
                PDC -> Today_Menu(n);
                
            }
            else if(c4 ==2)
            {
                cout << "Enter the Name of dish" << endl;
                string dish;
                cin.ignore();
                cin.clear();
                getline(cin, dish);
                cout << "Enter Quantity" << endl;
                int quantity;
                cin >> quantity;
                cin.ignore();
                cout << "Enter Price Per Dish" << endl;
                int price_per_dish;
                cin >> price_per_dish;
                Node* a1 = new Node(dish,quantity,price_per_dish);
                PDC -> InsertDish(Orders-> gethead(), a1);

            }
            else if(c4 == 3)
            {
                cout << "Enter the Name of the dish whose Quantity you want to update" << endl;
                string dish;
                cin.ignore();
                cin.clear();
                getline(cin, dish);
                cout << "Enter the New Quantity" << endl;
                int quantity; 
                cin >> quantity; 
                PDC -> UpdateDish(PDC -> gethead(), dish, quantity);

            }
            else if(c4 == 4)
            {
                 cout << "The sum of all dishes is" << endl;
                 int x = Orders -> SumDishes(Orders -> gethead());
                 cout << x << endl; 

            }
            else if(c4 == 5)
            {
                cout << "Please Enter the Name of dish whose Quantity you want to know" << endl;
                string dish;
                cin.ignore();
                cin.clear();
                getline(cin, dish);
                int y = PDC -> QuantityDish(PDC -> gethead(), dish);
                cout << "The Quantity of the Dish: " << dish << " is: " << y << endl;

            }
            else if(c4 == 6)
            {
                cout << "Enter the Name of the dish whose Price you want to update" << endl;
                string dish;
                cin.ignore();
                cin.clear();
                getline(cin, dish);
                cout << "Enter the Price you want to add" << endl;
                int price; 
                cin >> price;
                cout << "Updating its value" << endl;
                bool x = Orders -> UpdatePrice(Orders -> gethead(), dish, price);


            }
            else if (c4 == 7)
            {
                cout << "The total number of sales are:" << endl; 
                int y = Orders -> TotalSales(Orders->gethead());
                cout << y << " dollars" << endl;  

            }
            else if(c4 == 8)
            {
                string dish;
                cout << "Type the name of the dish of whose amount of orders you want to know" << endl;
                cin.ignore();
                cin.clear();
                getline(cin, dish); 
                cout << "The total number of times the dish has been ordered is " << endl;
                int y = Orders -> DishOrders(Orders->gethead(),dish);
                cout << y << endl; 

            }
            else if(c4 == 9)
            {
                string dish;
                cout << "Type the name of the dish of whose amount of cash you want to know" << endl;
                cin.ignore();
                cin.clear();
                getline(cin, dish); 
                cout << "The total cash received by the dish is " << endl;
                int y = Orders -> CashReceived(Orders->gethead(),dish);
                cout << y << endl; 

            }
            else if(c4 == 10)
            {
                int max_count = 0; 
                string max_dish;

                cout << "is it working" << endl; 

                Node *temp = PDC ->gethead();
                while (temp-> next != NULL)// note that it is important to do temp -> next to deal with the corner case. Keep that in mind bcz otherwise at the end
                // of the node this would cause problem
                {
                    string dish_1 = temp -> dish;
                    string dish_2 = temp -> next -> dish; 
                    int order1 = Orders -> DishOrders(Orders -> gethead(), dish_1);
                    int order2 = Orders -> DishOrders(Orders-> gethead(), dish_2);
                    if (order1 > order2)
                    {
                        if (order1 > max_count)
                        {
                            max_count = order1;
                            max_dish = dish_1; 
                        }
                    }
                    else 
                    {
                        if (order2 > max_count)
                        {
                            max_count = order2;
                            max_dish = dish_2; 
                        }
                    }
                    
                    temp = temp -> next; 
                }

                cout << "The most favorite dish is " << max_dish << endl;
                cout << "The amount the dish was ordered is " << max_count << endl;  


            }
            else if(c4 == 11)
            {
                int min_count = INT_MAX; 
                string min_dish; 
                Node *temp = PDC->gethead();
                while (temp -> next != NULL) // note that it is important to do temp -> next to deal with the corner case. Keep that in mind bcz otherwise at the end
                // of the node this would cause problem
                {
                    string dish_1 = temp -> dish;
                    string dish_2 = temp -> next -> dish; 
                    int order1 = Orders -> DishOrders(Orders -> gethead(), dish_1);
                    int order2 = Orders -> DishOrders(Orders-> gethead(), dish_2);
                    if (order1 > order2)
                    {
                        if (order2 < min_count)
                        {
                            min_count = order2;
                            min_dish = dish_2; 
                        }
                    }
                    else 
                    {
                        if (order1 < min_count)
                        {
                            min_count = order1;
                            min_dish = dish_1; 
                        }
                    }
                    
                    temp = temp -> next; 
                }

                cout << "The least favorite dish is " << min_dish << endl;
                cout << "The amount the dish was ordered is " << min_count << endl; 
                

            }
            else if (c4 == 12)
            {
                PDC -> DisplayMenu(PDC -> gethead(),1);
                cout << endl;
                
            }
            else if (c4 == 13)
            {
                Orders -> DisplayMenu(Orders->gethead(),1);
                cout << endl; 
            }
            else if (c4 == 14)
            {
                cout << "Exiting" << endl; 
            }



        }
        else if(c2 == 3)
        {
            c1 = false;
        }
    }
}










