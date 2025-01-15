#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;
struct node *temp=NULL;

struct node *elemanolustur( struct node *head, int data){
    temp=head;
    struct node *eklenecek=(struct node *)malloc(sizeof(struct node));
    eklenecek->data=data;
    eklenecek->next=NULL;
    eklenecek->prev=NULL;

    if(head== NULL){
        head=eklenecek;
    }
    else{
        while(temp ->next != NULL){
            temp=temp->next;
        }
        temp->next=eklenecek;
        eklenecek->prev=temp->next;
        temp=temp->next;
    }

    return head;
}

struct node *fibonacci(struct node *head){
    temp=head;
    struct node *temp2=head->next;
    int counter =0;

    while(counter != 10){
        struct node *eklenecek=(struct node *)malloc(sizeof(struct node));
        eklenecek->data= temp->data+temp2->data;
        eklenecek->next=NULL;
        eklenecek->prev=NULL;

        temp2->next=eklenecek;
        eklenecek->prev=temp2->next;

        temp=temp2;
        temp2=eklenecek;
        counter++;
    }
    return head;
}

void display(struct node *head){
    temp=head;
    if(head== NULL){
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

int main(){
    head=elemanolustur(head,0);
    head=elemanolustur(head,1);
    display(head);
    printf("*******\n");

    head=fibonacci(head);
    display(head);
    return 0;
}