#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void swapNodes(struct Node** head, int positionA, int positionB) {
    if (*head == NULL || (*head)->next == NULL || positionA == positionB) {
        printf("Unable to switch\n");
        return;
    }
    if (positionA > positionB) {
        int temp = positionA;
        positionA = positionB;
        positionB = temp;
    }
    if (positionA < 0 || positionB < 0) {
        printf("The specified location is not correct\n");
        return;
    }
    int count = 0;
    struct Node* current = *head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    if (positionA >= count || positionB >= count) {
        printf("The specified location is not correct\n");
        return;
    }
    int minPos = (positionA < positionB) ? positionA : positionB;
    int maxPos = (positionA > positionB) ? positionA : positionB;

    struct Node* prevA = NULL;
    struct Node* nodeA = *head;
    for (int i = 0; i < minPos; i++) {
        prevA = nodeA;
        nodeA = nodeA->next;
    }
    struct Node* prevB = NULL;
    struct Node* nodeB = *head;
    for (int i = 0; i < maxPos; i++) {
        prevB = nodeB;
        nodeB = nodeB->next;
    }
    if (prevA != NULL) {
        prevA->next = nodeB;
    } else {
        *head = nodeB;
    }
    if (prevB != NULL) {
        prevB->next = nodeA;
    } else {
        *head = nodeA;
    }

    struct Node* temp = nodeA->next;
    nodeA->next = nodeB->next;
    nodeB->next = temp;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    struct Node* head = NULL;
    struct Node* current = NULL;

    for (int i = 1; i <= size; i++) {
        if (head == NULL) {
            head = createNode(i);
            current = head;
        } else {
            current->next = createNode(i);
            current = current->next;
        }
    }

    printf("Linked List before swap: ");
    printList(head);

    int positionA, positionB;
    printf("Enter the positions to swap (separated by space): ");
    scanf("%d %d", &positionA, &positionB);

    swapNodes(&head, positionA, positionB);
    printf("Linked List after swap: ");
    printList(head);

    return 0;
}
