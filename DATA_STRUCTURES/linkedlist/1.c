// tek yönlü bağlı liste oluşturup max değri bulma

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL,*temp=NULL;

struct node *elemanEkle(struct node *head,int veri){
    if(head==NULL){
        head=(struct node *)malloc(sizeof(struct node));
        temp=head;
    }

    else{
        temp->next=(struct node *)malloc(sizeof(struct node));
        temp=temp->next;
    }
    temp->data=veri;
    temp->next=NULL;

    return head;
}

void display(struct node *head){
    temp=head;
    if(head==NULL){
        printf("liste bos");
    }

    else{
        while(temp ->next != NULL){
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
        printf("%d", temp->data);
    }
}

int max(struct node *head){
    temp=head;
    int max=temp->data;

    while(temp ->next != NULL){
        if(max < temp->next->data){
            max=temp->next->data;
        }
        temp=temp->next;
    }
    printf("\nmax value is:%d\n", max);

    return 0;
}

int main(){
    head=elemanEkle(head,6);
    head=elemanEkle(head,546);
    head=elemanEkle(head,23);
    head=elemanEkle(head,87);
    head=elemanEkle(head,130);
    head=elemanEkle(head,9990);

    display(head);
    max(head);
    return 0;
}