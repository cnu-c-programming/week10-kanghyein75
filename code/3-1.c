#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int score;
    struct Student* next;
} Student;

Student* head = NULL; 

void add(char* name, int score) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Student* current = head;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete_student(char* name) {
    Student* current = head;
    Student* previous = NULL;

    if (current == NULL) return; 

    if (strcmp(current->name, name) == 0) {
        head = current->next;
        free(current);
        return;
    }

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        previous->next = current->next;
        free(current);
    }
}

void print_list() {
    Student* current = head;
    while (current != NULL) {
        printf("%s %d\n", current->name, current->score);
        current = current->next;
    }
}

void free_all() {
    Student* current = head;
    Student* nextNode;
    while (current != NULL) {
        nextNode = current->next; 
        free(current);            
        current = nextNode;       
    }
    head = NULL;
}

int main() {
    char command[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_student(name);
        } else if (strcmp(command, "print") == 0) {
            print_list();
        } else if (strcmp(command, "quit") == 0) {
            free_all();
            break; 
        }
    }

    return 0;
}
