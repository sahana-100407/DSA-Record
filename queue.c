#include <stdio.h>
#define MAX 5  // Define the maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to enqueue (add) an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot add %d\n", value);
    } else {
        if (front == -1) {  // If the queue is empty, set front to 0
            front = 0;
        }
        queue[++rear] = value;  // Increment rear and add the element
        printf("%d enqueued to queue\n", value);
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! The queue is empty\n");
        return -1;
    } else {
        int value = queue[front];
        front++;  // Move the front pointer to the next element
        if (front > rear) {
            front = rear = -1;  // Reset the queue if it becomes empty
        }
        printf("%d dequeued from queue\n", value);
        return value;
    }
}

// Function to peek at the front element of the queue
int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue[front];
    }
}

// Function to display all elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();  // Display the queue

    dequeue();
    dequeue();

    display();  // Display the queue again

    printf("Front element is %d\n", peek());  // Show the front element

    return 0;
}

