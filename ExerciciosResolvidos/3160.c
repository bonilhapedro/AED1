#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    struct Node *next;
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, char* name) {
    Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertBefore(Node** head, char* target, Node* newFriends) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && strcmp(current->name, target) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) { 
        if (prev == NULL) {
            *head = newFriends;
        } 
        else {
            prev->next = newFriends;
        }
    } 
    else {
        if (prev == NULL) {
            Node* temp = newFriends;
            while (temp->next != NULL) temp = temp->next;
            temp->next = *head;
            *head = newFriends;
        } 
        else {
            prev->next = newFriends;
            Node* temp = newFriends;
            while (temp->next != NULL) temp = temp->next;
            temp->next = current;
        }
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s", temp->name);
        temp = temp->next;
        if (temp != NULL) printf(" ");
    }
    printf("\n");
}

int main() {
    char list[256], newList[256], friendName[50];
    Node* head = NULL;
    Node* newFriends = NULL;

    fgets(list, sizeof(list), stdin);
    list[strcspn(list, "\n")] = 0;

    fgets(newList, sizeof(newList), stdin);
    newList[strcspn(newList, "\n")] = 0;

    fgets(friendName, sizeof(friendName), stdin);
    friendName[strcspn(friendName, "\n")] = 0;

    char* token = strtok(list, " ");
    while (token != NULL) {
        insertEnd(&head, token);
        token = strtok(NULL, " ");
    }

    token = strtok(newList, " ");
    while (token != NULL) {
        insertEnd(&newFriends, token);
        token = strtok(NULL, " ");
    }

    if (strcmp(friendName, "nao") == 0) {
        Node* temp = head;
        if (temp == NULL) {
            head = newFriends;
        } else {
            while (temp->next != NULL) temp = temp->next;
            temp->next = newFriends;
        }
    } else {
        insertBefore(&head, friendName, newFriends);
    }

    printList(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
