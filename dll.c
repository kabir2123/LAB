#include<stdio.h>
#include<stdlib.h>


struct node{
   int data;
   struct node* next;
   struct node* prev;

};

struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;

}

struct node* insertrear(struct node* head , int data){
    struct node* newnode = createnode(data);

    
    if(head == NULL){
        return newnode;
    } 
    struct node* current = head;
    while(current -> next != NULL){
        current = current ->  next;
    }
    current -> next = newnode;
    newnode -> prev = current;
    
    return head;
}
struct node* deleterear(struct node* head){
   struct node* current = head;
   while(current -> next != NULL){
    current = current -> next;
   }

   if(current -> prev == NULL){
    free(current);
    return NULL;
   }
   current -> prev -> next = NULL;
   free(current);
   return head;
}

int lengthlist(struct node* head){
    struct node* current = head;
    int len = 0;
    while(current != NULL){
        len++;
            current = current -> next;
            
    }
    return len;
}
   


void printlist(struct node* head){
    struct node* current = head;
    while(current != NULL){
        printf("%d\n" , current -> data);
        current = current -> next;
    }
    printf("\n");
}

struct node* insertatpos(struct node* head , int k , int data){
    struct node* newnode = createnode(data);
    struct node* current = head;
    for(int i=0;i<k-1;i++){
            current = current -> next;
    }
   
    newnode -> next = current -> next;
    newnode -> prev = current; //follow this order
    current -> next -> prev = newnode;
     current -> next = newnode;
    
    
    

    return head;}

struct node* deletepos(struct node* head , int k){
    struct node* current = head;
    for(int i=0;i<k-1;i++){
        current = current -> next;
    }
    current -> prev -> next = current -> next;
    current -> next -> prev = current -> prev;
    free(current);
    return head;
}

struct node* reverselist(struct node* head){
            struct node* current = head;
    struct node* temp = NULL;

   
    while (current != NULL) {
        
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

       
        current = current->prev; 
    }


    if (temp != NULL) {
        head = temp->prev; 
    }

    return head; 
}





int main(){
    struct node* head = createnode(2);
    head->next = createnode(3);
    head->next->prev = head;
    head->next->next = createnode(4);
    head->next->next->prev = head->next;
    head->next->next->next = createnode(5);
    head->next->next->next->prev = head->next->next;
   insertrear(head , 9);
   
  deleterear(head);
  
 printf("length is:%d\n",lengthlist(head)) ;
 insertatpos(head , 2 , 56);
  printlist(head);
 deletepos(head , 4);
 head = reverselist(head);
 printlist(head);
 
    
}
