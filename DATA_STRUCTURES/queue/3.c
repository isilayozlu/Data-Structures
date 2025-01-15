#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *front;
    struct node *rear;
}queue;

void enqueue(queue *q, int data){
    struct node *ekle=(struct node *)malloc(sizeof(struct node));
    ekle->data=data;
    ekle->next=NULL;

    if(q->front == NULL){
        q->front=q->rear=ekle;
    }
    else{
        q->rear->next=ekle;
        q->rear=q->rear->next;
    }
}

void display(queue *q){
    struct node *temp=q->front;
    if(q->front == NULL){
        printf("kuyruk bos\n");
    }
    else{
        while(temp->next != NULL){
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
        printf("%d\n", temp->data);

    }
}

void tekcift(queue *q){
    queue q1,q2;
    q1.front=NULL;
    q1.rear=NULL;

    q2.front=NULL;
    q2.rear=NULL;

    struct node *temp=q->front;

    while(temp != NULL){
        if(temp->data % 2 != 0){
            enqueue(&q1,temp->data);
        }
        else{
            enqueue(&q2, temp->data);
        }
        temp=temp->next;
    }
    printf("tek elemanlar: ");
    display(&q1);
    printf("çift elemanlar: ");
    display(&q2);

}

int main(){
    queue q;
    q.front=NULL;
    q.rear=NULL;

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    enqueue(&q,6);
    enqueue(&q,7);
    enqueue(&q,8);
    display(&q);
    printf("********\n");

    tekcift(&q);


    return 0;

}