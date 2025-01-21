//Single Linked List

#include <stdio.h>

//Ex 1:

//Suppose we want to store a list of numbers: 23, 54, 98, 90

//Create four different nodes 


//Self referential structure
struct abc {
    int a;
    char b;
    struct abc *self;
};

//Creating a linked list

struct node {
    int data;
    struct node *link; // Pointer to another node
};

int main() {
    //Create a pointer for the node
    struct node *head = (struct node *)malloc(sizeof(struct node));

    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current -> data = 3;
    current -> link = NULL;

    head->link->link = current;
}
