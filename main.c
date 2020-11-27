#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node* next;
};

struct Node* head; //global variable
struct Node* head = NULL; //global variable

// void Insert(int x) {
//   struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//   temp->data = x;
//   temp->next = NULL;
//   if(head != NULL) temp->next = head;
//   head = temp;
// }
//Insert at beginning linklist
void insertAtStart(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}

//Insert at End of the linklist
void insertAtEnd(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if(head == NULL) {
    head = newNode;
  } else {
    struct Node* lastNode = head;
    while(lastNode->next!=NULL) {
      lastNode = lastNode->next;
    }
    lastNode->next = newNode;
  }
}

int length() {
  struct Node* temp = head;
  int count = 0;
  while(temp != NULL) {
    temp = temp->next;
    count++;
  }
  return count;
}

//Append the linklist at a postion
void append(int position,int data) {
  int listLength = length();
  if(position<=listLength) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if(position==1) {
    head = newNode;
  } else {
    struct Node* temp = head;
    struct Node* next;
    for(int i=0;i<position-2;i++) {
      temp = temp->next;
    }
    next = temp->next;
    temp->next = newNode;
    newNode->next = next; 
  }
  } else {
    printf("List is shorter for appending\n");
  }
  
}

//Update the linklist at a position
void update(int position,int data) {
  struct Node* temp = head;
  for(int i=0;i<position-1;i++){
    temp = temp->next;
  }
  temp->data = data;
}

// delete nodes at a position
void delete(int position) {
  int listLength = length();
  if(position<=listLength) {
    struct Node* temp = head;
  if(position==1){
    head = temp->next;
    free(temp);
  } else {
    struct Node* temp1;
    for(int i=0;i<position-2;i++){
      temp = temp->next;
    }
    temp1 = temp->next;
    free(temp->next);
    temp->next = temp1->next;
  }
  } else {
    printf("Invalid position for deletion\n");
  }
  
  

}

// Print the linklist
void Print() {
  struct Node* temp = head;
  while(temp != NULL) {
    printf(" %d",temp->data);
    temp = temp->next;
  }
  printf("\n");
}



int main(void) {
  head = NULL;
  int n,i,x;
  printf("How many numbers?:\n");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter a number?:");
    scanf("%d",&x);
    // insertAtStart(x);
    insertAtEnd(x);
    Print();
  }
  append(5,5);
  // Print();
  // update(2,25);
  Print();
  delete(10);
  // Print();
  int len = length();
  printf("Length = %d",len);
  return 0;
}