#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
protected:
    struct studentNode *start, **now;

public:
    LinkedList();
    ~LinkedList();
    void InsNode(char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    void GoFirst();
    void GoLast();
    void ShowAll();
    int FindNode(char n[]);
    struct studentNode *NowNode();
    void EditNode(char n[], int a, char s, float g);
};

void EditData(LinkedList *ll);
void AddData(LinkedList *ll);
void FindData(LinkedList *ll);
void readfile(LinkedList *ll);
void writefile(LinkedList *ll);

int main() {
    LinkedList listA;
    int menu;
    readfile(&listA);

    printf(" Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
    scanf("%d", &menu);

    while (menu != 0) {
        switch (menu) {
        case 1:
            AddData(&listA);
            break;
        case 2:
            EditData(&listA);
            break;
        case 3:
            listA.DelNode();
            break;
        case 4:
            FindData(&listA);
            break;
        case 5:
            listA.ShowAll();
            break;
        }

        printf(" Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
        scanf("%d", &menu);
    }

    writefile(&listA);
    return 0;
}

LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    struct studentNode *temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    struct studentNode *newNode = new studentNode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    *now = newNode;
    now = &newNode->next;
}

void LinkedList::DelNode() {
}

void LinkedList::GoNext() {
    if (*now != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::GoFirst() {
    now = &start;
}

void LinkedList::GoLast() {
    while ((*now)->next != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::ShowAll() {
    struct studentNode *temp = start;
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
}

int LinkedList::FindNode(char n[]) {
    return 0;
}

struct studentNode *LinkedList::NowNode() {
    return *now;
}

void LinkedList::EditNode(char n[], int a, char s, float g) {
}

void EditData(LinkedList *ll) {
    char name[20];
    int age;
    char sex;
    float gpa;

    printf("Enter name to edit: ");
    scanf("%s", name);

    int found = ll->FindNode(name);
    if (found) {
        printf("Enter new data for %s:\n", name);
        printf("Age: ");
        scanf("%d", &age);
        printf("Sex: ");
        scanf(" %c", &sex);
        printf("GPA: ");
        scanf("%f", &gpa);

        ll->EditNode(name, age, sex, gpa);
        printf("Data for %s edited successfully.\n", name);
    } else {
        printf("Student not found.\n");
    }
}

void AddData(LinkedList *ll) {
    char name[20];
    int age;
    char sex;
    float gpa;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter sex (M/F): ");
    scanf(" %c", &sex);
    printf("Enter GPA: ");
    scanf("%f", &gpa);

    ll->InsNode(name, age, sex, gpa);
    printf("Data added successfully.\n");
}

void FindData(LinkedList *ll) {
    char name[20];

    printf("Enter name to find: ");
    scanf("%s", name);

    int found = ll->FindNode(name);
    if (found) {
        printf("Student found.\n");
    } else {
        printf("Student not found.\n");
    }
}

void readfile(LinkedList *ll) {
}

void writefile(LinkedList *ll) {
}
