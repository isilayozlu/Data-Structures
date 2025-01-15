// tek yönlü liste oluşturup sıralı ekleme yapan kod

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *head=NULL, *temp=NULL, *head2=NULL;

struct node *listeolustur(struct node *head,int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    // Liste boşsa veya yeni düğüm başa eklenmeliyse
    if (head == NULL || head->data >= data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        struct node *temp = head;
        // Doğru pozisyonu bulana kadar ilerle
        while (temp->next != NULL && temp->next->data < data) {
            temp = temp->next;
        }
        // Yeni düğümü doğru pozisyona ekle
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
    }


void display(struct node *head){
    temp=head;
    if(head== NULL){
        printf("liste bos");
    }

    else{
        while(temp ->next != NULL){
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
        printf("%d ", temp->data);
    }
}

int main(){
    head=listeolustur(head,7);
    head=listeolustur(head,17);
    head=listeolustur(head,12);
    display(head);
    printf("\n");

    head2=listeolustur(head2,56);
    head2=listeolustur(head2,3);
    head2=listeolustur(head2,45);
    display(head2);

    return 0;
}