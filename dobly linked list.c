#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;  // If the list is empty, the new node is the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;  // Link the last node to the new node
        newNode->prev = temp;  // Set the previous pointer of the new node
    }
}

// Function to delete a node by its value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list!\n");
        return;
    }

    // Update the previous and next pointers
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to print the list (head to tail)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("List after insertion: ");
    printList(head);

    // Delete a node with value 20
    deleteNode(&head, 20);
    printf("List after deleting 20: ");
    printList(head);

    return 0;
}
