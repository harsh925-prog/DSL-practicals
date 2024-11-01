//Harsh Gangadhar Chakote
//SE-II (Q)
//Roll No.: 31
//PRN: F23112034
/*
Pizza parlor accepting maximum M orders.
Orders are served in first come first served basis. Order once placed can not be cancelled.
Write C++ program to simulate the system using circular queue using array.
*/
#include<iostream>
#include<cstdlib>
using namespace std;
class pizza{
    int front, rear, q[5];
    public:
    pizza(){
        front=-1;
        rear=-1;
    }
    int isFull(){
        if((front==0 && rear==4) || front==rear+1){
            return 1;
        }
        else{
            return 0;
        }
    }
    int isEmpty(){
        if(front==-1 && rear==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    void add(){
        if(isFull()==0){
            cout<<"\nEnter the Pizza ID: ";
            if(front==-1 && rear==-1){
                front = 0;
                rear = 0;
                cin>>q[rear];
            }
            else{
                rear=(rear+1)%5;
                cin>>q[rear];
            }
            char c;
            cout<<"Do you want to add another order? (y/n) :  \n";
            cin>>c;
            if(c=='y' || c=='Y'){
                add();
            }
        }
        else{
            cout<<"\nOrders are full."<<endl;
        }
    }
    void serve(){
        if(isEmpty()==0){
            if(front==rear){
                cout<<"\nOrder served is: "<<q[front]<<endl;
                front=-1;
                rear=-1;
            }
            else{
                cout<<"\nOrder served is: "<<q[front]<<endl;
                front=(front+1)%5;
            }
        }
        else{
            cout<<"\nOrders are empty."<<endl;
        }
    }
    void display(){
        if(isEmpty()==0){
            for(int i=front; i!= rear; i= (i+1)%5){
                cout<<q[i]<<"<- ";
            }
            cout<<q[rear]<<endl;
        }
        else{
            cout<<"\nOrders are empty."<<endl;
        }
    }
    void check(){
        int ch;
        cout<<"\n\n* * * * PIZZA PARLOUR * * * *\n\n";
        cout<<"\n1. Add Pizza \n2. Display Orders \n3. Serve Pizza \n4.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
            add();
            break;
            case 2:
            display();
            break;
            case 3:
            serve();
            break;
            case 4:
            exit(0);
            default:
            cout<<"Invalid choice.";
            check();
        }
        char ch1;
        cout<<"Do you want to continue? (y/n) : ";
        cin>>ch1;
        if(ch1=='y' || ch1=='Y'){
            check();
        }
    }
};
int main(){
    pizza p1;
    p1.check();
    return 0;
}

//Output:
/*
* * * * PIZZA PARLOUR * * * *


1. Add Pizza 
2. Display Orders 
3. Serve Pizza 
4.Exit
Enter your choice: 1

Enter the Pizza ID: 23
Do you want to add another order? (y/n) :  
y

Enter the Pizza ID: 24
Do you want to add another order? (y/n) :
n
Do you want to continue? (y/n) : y


* * * * PIZZA PARLOUR * * * *


1. Add Pizza
2. Display Orders
3. Serve Pizza
4.Exit
Enter your choice: 2
23<- 24
Do you want to continue? (y/n) : y


* * * * PIZZA PARLOUR * * * *


1. Add Pizza
2. Display Orders
3. Serve Pizza
4.Exit
Enter your choice: 3

Order served is: 23
Do you want to continue? (y/n) : n
*/