#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *temp=NULL;

struct node *elemanekle(struct node *head, int data){
    struct node *eklenecek=(struct node *)malloc(sizeof(struct node));
    eklenecek->data=data;
    eklenecek->next= NULL;

    if(head == NULL)
    head=eklenecek;

    else{
        eklenecek->next=head;
        head=eklenecek;
    }

    return head;
}

void display(struct node *head){
    temp=head;
    if(head->next == NULL){
        printf("liste bos\n");
    }
    else{
        while(temp ->next != NULL){
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
         printf("%d\n", temp->data);
    }
}



int findmin( struct node *head){
    temp=head;
    int min;
    if(head== NULL){
        printf("liste bos min değer yok\n");
    }
    else{
        min=temp->data;
        temp=temp->next;
        while(temp!= NULL){
            if(min> temp->data){
                min=temp->data;
            }
            temp=temp->next;
        }
    }
    printf(" min dğer: %d\n", min);
    return min;
}

struct node *subtrackMin(struct node *head){
    int min=findmin(head);
    temp=head;

    while(temp != NULL){
        temp->data-=min;
        temp=temp->next;
    }
    return head;
}

int main(){
    head=elemanekle(head,1);
    head=elemanekle(head,2);
    head=elemanekle(head,7);
    head=elemanekle(head,42);
    head=elemanekle(head,8);
    head=elemanekle(head,23);
    display(head);
    printf("*************\n");
    head=subtrackMin(head);
    display(head);

    return 0;
}
