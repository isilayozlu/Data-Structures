// soru 4 n. elemanı sil
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *temp=NULL;

struct node *elemanekle(struct node *head, int veri){
    if(head == NULL){
        head=(struct node *)malloc(sizeof(struct node));
        temp=head;
    }
    else{
        temp->next=(struct node*)malloc(sizeof(struct node));
        temp=temp->next;
    }
    temp->data=veri;
    temp->next=NULL;

    return head;
}

struct node *sil(struct node *head){

    if (head == NULL) {
        printf("Liste bos. Silinecek eleman yok.\n");
        return head;
    }

    int n, i=1;
    temp=head;
    struct node *prev=NULL;

    printf("kaçıncı elemanı silmek istiyorsunuz:");
    scanf("%d", & n);

    while(temp != NULL && i<n){
        prev=temp;
        temp=temp->next;
        i++;
    }

    if(temp== NULL){
        printf("n. eleman listede yok\n");
    }
    else{
        if (prev == NULL) {
            // İlk eleman siliniyor
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp); // Silinen düğümün belleğini serbest bırak
        printf("%d. eleman silindi.\n", n);
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

int main(){
    head=elemanekle(head,7);
    head=elemanekle(head,8);
    head=elemanekle(head,435);
    head=elemanekle(head,2);
    display(head);
    printf("\n");
    head=sil(head);
    display(head);
}