  
#include<iostream>
using namespace std;

typedef struct node{
	int data;
    struct node *next;
}*Node;

Node create_node(){
	Node temp;
	temp=(Node)malloc(sizeof(Node));
	return temp;
}

Node insert_front(Node head){
    int ele;
    cout<<"Enter element:";
    cin>>ele;
    Node p = create_node();
    p->data = ele;
    p->next = head;
    if(head == NULL){
        return p;
    }
    head->next = (Node) ((uintptr_t)(head->next) ^ (uintptr_t)(p));
    return p;
}

Node insert_rear(Node head){
    int ele;
    cout<<"Enter element:";
    cin>>ele;
    Node p = create_node();
    p->data = ele;
    if(head == NULL){
        p->next = NULL;
        return p;
    }
    if(head->next == NULL){
        head->next = (Node) ((uintptr_t)(head->next) ^ (uintptr_t)(p));
        p->next = head;
        return head;
    }
    Node prevPointer = head;
    Node nextPointer = head->next;
    Node q;
    while(prevPointer != nextPointer->next){
        q = (Node) ((uintptr_t)(nextPointer->next) ^ (uintptr_t)(prevPointer));
        prevPointer = nextPointer;
        nextPointer = q;
    }
    nextPointer->next = (Node) ((uintptr_t)(nextPointer->next) ^ (uintptr_t)(p));
    p->next = nextPointer;
    return head;
}

Node delete_front(Node head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node p = head->next;
    p->next = (Node) ((uintptr_t)(p->next) ^ (uintptr_t)(NULL));
    free(head);
    return p;
}

void display(Node head){
    cout<<"\nElements: ";
    if(head->next == NULL){
        cout<<head->data;
    }
    else{
        Node prevPointer = head;
        Node nextPointer = head->next;
        Node q;
        while(prevPointer != nextPointer->next){
            cout<<prevPointer->data<<" ";
            q = (Node) ((uintptr_t)(nextPointer->next) ^ (uintptr_t)(prevPointer));
            prevPointer = nextPointer;
            nextPointer = q;
        }
        cout<<prevPointer->data<<" "<<nextPointer->data;
    }
    cout<<"\n";
}

int main(){
    Node head = NULL;
    int choice;
    do{
        cout<<"\n1)Insert Beginning\n2)Insert End\n3)Delete Beginning\n4)Exit\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1: head = insert_front(head);
                    display(head);
                    break;
            case 2: head = insert_rear(head);
                    display(head);
                    break;
            case 3: head = delete_front(head);
                    display(head);
                    break;
            case 4: exit(0);
        }
    }while(1);
}