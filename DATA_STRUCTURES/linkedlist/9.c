#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *head2= NULL;
struct node *temp=NULL;
struct node *temp2=NULL;
struct node *head3=NULL;
struct node *temp3=NULL;

struct node *listeyeekle(struct node *head , int data){
    temp=head;
    struct node *ekle=(struct node *)malloc(sizeof(struct node));
    ekle->data=data;
    ekle->next=NULL;

    if(head== NULL){
        head=ekle;
    }
    else{
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next= ekle;
        temp=temp->next;
    }
    return head;
}

void display( struct node *head){
    temp=head;
    if(head== NULL){
        printf("liste bos\n");
    }
    else{
        while(temp->next != NULL){
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
         printf("%d\n", temp->data);
    }
}

struct node *birlestir(struct node *head, struct node *head2){
    temp=head;
    temp2=head2;

    while(temp != NULL && temp2 != NULL){
        if(temp->data < temp2->data){
            if(head3== NULL){
            head3=(struct node *)malloc(sizeof(struct node));
            temp3=head3;
            }

            else{
                temp3->next=(struct node *)malloc(sizeof(struct node));
                temp3=temp3->next;
            }
            temp3->data=temp->data;
            temp3->next=NULL;
            temp=temp->next;
        }
        else{
            if(temp3== NULL){
            head3=(struct node *)malloc(sizeof(struct node));
            temp3=head3;
            }

            else{
                temp3->next=(struct node *)malloc(sizeof(struct node));
                temp3=temp3->next;
            }
            temp3->data=temp2->data;
            temp3->next=NULL;
            temp2=temp2->next;
        }
}
if(temp2 != NULL){
    temp3->next=temp2;
    temp3=temp3->next;
}

if(temp != NULL){
    temp3->next=temp;
    temp3=temp3->next;
}
return head3;
}

int main(){
    
    head=listeyeekle(head,3);
    head=listeyeekle(head,5);
    head=listeyeekle(head,7);
    
    head2=listeyeekle(head2,2);
    head2=listeyeekle(head2,4);
    head2=listeyeekle(head2,6);
    head2=listeyeekle(head2,8);
    printf("***************\n");
    display(head);
    printf("***************\n");
    display(head2);
    printf("***************\n");
    head3=birlestir(head,head2);
    display(head3);
    printf("***************\n");

    return 0;
}