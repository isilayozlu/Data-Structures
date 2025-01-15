// çift bağlı liste oluşturup, iki listeyi birleştirme

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ; 
    struct node*next;
    struct node*prev;
};

struct node *head=NULL,*temp, *temp2;
struct node *head2= NULL;


struct node *listeyeekle(struct node *head, int veri){

    if(head == NULL){
        temp=(struct node *)malloc(sizeof(struct node));
        head=temp;
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
    if(temp == NULL){
        printf("liste bos");
    }

    else{
        while(temp != NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
}

struct node *ikilisteyibirleştir(struct node *head, struct node *head2){
    struct node *result=NULL;
    if (head == NULL)
        return head2;
    else if (head2 == NULL)
        return head;

    if (head->data <= head2->data)
    {
        result = head;
        result->next = ikilisteyibirleştir(head->next, head2);
    }
    
    else {
        result = head2;
        result->next = ikilisteyibirleştir(head, head2->next);
    }
    printf("listeler başarıyla birleştirildi\n");

    return result;
    
}

int main(){

    head=listeyeekle(head, 5);
    head=listeyeekle(head, 6);
    head=listeyeekle(head, 9);

    display(head);
    printf("\n");

    head2=listeyeekle(head2, 12);
    head2=listeyeekle(head2, 7);
    head2=listeyeekle(head2, 32);

    display(head2);
    printf("\n");


    struct node * result=ikilisteyibirleştir(head,head2);
    display(result);
    printf("\n");
    return 0;
}