// question2: iki lsteyi birleştir ve srıala

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
struct node *temp=NULL;
struct node *temp2=NULL;

struct node *elemanekle(struct node *head, int veri) {
    struct node *yeni = (struct node*)malloc(sizeof(struct node));
    yeni->data = veri;
    yeni->next = NULL;

    if (head == NULL) {
        return yeni;  // Eğer liste boşsa, yeni düğümü başa döndür
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = yeni;
    }
    return head;
}


void display(struct node *head){
    temp=head;
    if(head==NULL){
        printf("liste bos");
    }
    else{
        while(temp->next != NULL){
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
        printf("%d", temp->data);
    }
}

struct node *birlestir(struct node *head, struct node *head2){
    temp=head;
    temp2=head2;

    while(temp != NULL && temp2 != NULL){
        if(temp->data > temp2->data){
            head3=elemanekle(head3, temp2->data);
            temp2=temp2->next;
        }
        else{
            head3=elemanekle(head3, temp->data);
            temp=temp->next;
        }
    }

    while(temp != NULL){
        head3=elemanekle(head3, temp->data);
        temp=temp->next;
    }
    while(temp2 != NULL){
        head3=elemanekle(head3, temp2->data);
        temp2=temp2->next;
    }

    return head3;
}

struct node *sirala(struct node *head, struct node *head2){
    temp=head;
    temp2=head2;
    int first;

    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=head2;
    temp=head;
    while(temp != NULL){
        temp2=temp;
        while(temp2!= NULL){
            if(temp2->data < temp->data){
                first=temp->data;
                temp->data=temp2->data;
                temp2->data=first;
            }
            else
            temp2=temp2->next;
        }
        temp=temp->next;
    }

    return head;
}

int main(){
    head=elemanekle(head,8);
    head=elemanekle(head,10);
    head=elemanekle(head,2);
    printf("\n");
    display(head);
    printf("\n");


    head2=elemanekle(head2,7);
    head2=elemanekle(head2,35);
    head2=elemanekle(head2,16);
    head2=elemanekle(head2,20);
    printf("\n");
    display(head2);
    printf("\n");

    head3=birlestir(head,head2);
    display(head3);
    printf("\n");
    head3=sirala(head,head2);
    printf("\n");
    printf("\n");
    display(head3);
    return 0;
}