//Author: Dhrubo Roy Partho
//Date: 11/10/2023
//Outcome: learning linked list.

#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;
int elm_ct = 0;

void insertAtEnd(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        tail->next = newNode;
    }
    tail = newNode;
    cout<<"Value "<<value<<" addded at the end."<<endl;
    return;
}

void prepend(int value)
{
    Node* newNode = (Node*)malloc(sizeof(newNode));
    newNode->data = value;
    if(tail == NULL){
        tail = newNode;
    }
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    cout<<"Prepend "<<value<<" is complete"<<endl;
    return;
}

void insertAtIndex(int value, int pos)
{
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    int i=1;
    Node* ptr = head;
    Node* prePtr = NULL;
    while(ptr != NULL){
        if(i == pos){
            if(ptr == head){
                newNode->next = head;
                head = newNode;
            }
            else if(ptr == tail){
                prePtr->next = newNode;
                newNode->next = tail;
            }
            else{
                prePtr->next = newNode;
                newNode->next = ptr;
            }
            return;
        }
        i++;
        prePtr = ptr;
        ptr = ptr->next;
    } 
}

void deleteByValue(int value)
{
    Node *prePtr = head;
    Node *ptr = prePtr->next;
    if(prePtr->data == value){
        head = ptr;
        free(prePtr);
        return;
    }
    while(ptr != NULL){
        if(ptr == tail && ptr->data == value){
            tail = prePtr;
            tail->next = NULL;
            free(ptr);
            return;
        }
        else if(ptr->data == value && ptr != tail){
            prePtr->next = ptr->next;
            free(ptr);
            return;
        }
        prePtr = ptr;
        ptr = ptr->next; 
    }
    cout<<"Value "<<value<<" is successfully deleted."<<endl;
    return;
}

void displayData()
{
    Node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
    return;
}

void free_memory()
{
    Node* ptr = head;
    while(head != NULL){
        ptr = ptr->next;
        free(head);
        head = ptr;
    }

    //For animation
    cout<<"Clearing Memory.";
    for(int i=0;i<3;++i){
        Sleep(100);
        cout<<" .";
    }
    cout<<endl;
    //Animation End

    return;
}

int calculate_length()
{
    Node* ptr = head;
    int i=0;
    while(ptr != NULL){
        i++;
        ptr = ptr->next;
    }
    return i;
}

int main()
{
    while(1){
        int n;
        cout<<"What do you want to do\n\t1. Insert single data at the end\n";
        cout<<"\t2. Insert Multiple data at the end\n";
        cout<<"\t3. Insert data at beginning\n";
        cout<<"\t4. Insert at an index\n";
        cout<<"\t5. Delete element based on value\n";
        cout<<"\t6. Display data\n";
        cout<<"\t7. Calculate Length\n";
        cout<<"\t8. Exit\n";
        cout<<"Select> ";
        cin >> n;
        switch(n){
            case 1:{
                cout<<"Enter a integer data to store at the end: ";
                cin>>n;
                insertAtEnd(n);
                break;
            }

            case 2:{
                int x;
                cout<<"How many data do you wnat to enter: ";
                cin>>x;
                for(int i=0;i<x;i++){
                    int q;
                    cin>>q;
                    insertAtEnd(q);
                }
                cout<<"All inserted."<<endl;
                break;
            }

            case 3:{
                cout<<"Enter a integer data to store at the beginnig: ";
                cin>>n;
                prepend(n);
                break;
            }

            case 4:{
                cout<<"Enter a value and index for insert: ";
                int pos;
                cin>>n>>pos;
                insertAtIndex(n, pos);
                break;
            }

            case 5:{
                cout<<"Enter a value for delete: ";
                cin>>n;
                deleteByValue(n);
                break;
            }

            case 6:{
                cout<<"Data: \n";
                displayData();
                break;
            }

            case 7:{
                cout<<"Length: "<<calculate_length()<<endl;
                break;
            }

            case 8:{
                free_memory();
                cout<<"Closing program.";
                for(int i=0;i<4;i++){
                    Sleep(300);
                    cout<<" .";
                }
                exit(1);
                return 0;
                break;
            }
            default:{
                cout<<"You have entered a wrong number. Try Again."<<endl;
                break;
            }
        }
    }
}
