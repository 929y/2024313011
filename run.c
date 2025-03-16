#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* istSort(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode-> data = value;
    newNode-> next = NULL;

    if (head == NULL || head-> data >= value) {
        newNode-> next = head;
        return newNode;
    }

    Node* current = head;
    while (current-> next != NULL && current-> next-> data < value) {
        current = current-> next;
    }

    newNode-> next = current-> next;
    current-> next = newNode;

    return head;
}

int main() {
    Node* head = NULL;
    int num;

    while (scanf("%d", &num) == 1) {
        head = istSort(head, num);
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current-> data);
        current = current-> next;
    }
    printf("\n");

    while (head != NULL) {
        Node* temp = head;
        head = head-> next;
        free(temp);
    }

    return 0;
}
