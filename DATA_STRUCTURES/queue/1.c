// queueu eleman ekleme silme
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *front;
    struct node *rear;
}queue;

void enqueue( queue *q, int veri){
    struct node *eklenecek=(struct node *)malloc(sizeof(struct node));
    eklenecek->data=veri;
    eklenecek->next=NULL;

    if(q->front == NULL){
        q->front=eklenecek;
        q->rear=eklenecek;
    }

    else{
        q->rear->next=eklenecek;
        q->rear=q->rear->next;
    }
}

void dequeue(queue *q){//bastan siler

    if(q->front == NULL){
        printf("kuyruk bos\n");
    }
    else{
    struct node *temp=q->front;
    q->front=q->front->next;
    printf("%d kuyruktan çıkarıldı\n", temp->data);
    free(temp);
    }
}

void display(queue *q){
    if(q->front== NULL){
        printf("kuyruk bos\n");
    }

    else{
        struct node *temp=q->front;

        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    queue q;
    q.front=NULL;
    q.rear=NULL;

    enqueue(&q, 5);
    enqueue(&q, 7);
    enqueue(&q, 9);
    enqueue(&q, 13);
    enqueue(&q, 324);
    display(&q);
    printf("\n*******************************\n");
    dequeue(&q);
    display(&q);

    return 0;
}
