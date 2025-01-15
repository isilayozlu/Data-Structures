//polindrom
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char operation;
    struct node *next;
};

typedef struct{
    struct node *top;
    int counter;
}stack;

typedef struct{
    struct node *front;
    struct node *rear;
    int counter;
}queue;

void push(stack *s, char cumle[]){
    for(int i=0; cumle[i] !='\0'; i++ ){
        struct node *ekle=(struct node *)malloc(sizeof(struct node));
        ekle->operation=cumle[i];
        ekle->next=s->top;
        s->top=ekle;
        s->counter++;
    }
    printf("cumla basariyle stacke atandı\n");
}

void enqueue(queue *q , char cumle[]){
    for(int i=0; cumle[i]!= '\0'; i++){
        struct node *ekle=(struct node *)malloc(sizeof(struct node));
        ekle->operation=cumle[i];
        ekle->next=NULL;
        if(q->front==NULL){
            q->front=q->rear=ekle;
        }
        else{
            q->rear->next=ekle;
            q->rear=q->rear->next;
        }
    }
    printf("cumle basarıyla kuyruğa eklendi\n");
}

void polindrom(stack *s , queue *q){
    int kontrol=0;
    struct node *stemp= s->top;
    struct node *qtemp=q->front;

    while(stemp != NULL && qtemp != NULL){
        if(stemp->operation != qtemp->operation){
            printf("polindrom deildir\n");
            kontrol=1;
            break;
        }
        stemp=stemp->next;
        qtemp=qtemp->next;
    }
    if(kontrol == 0){
        printf("polindromdur");
    }
}

int main(){
    stack s;
    s.top=NULL;
    s.counter=0;

    queue q;
    q.counter=0;
    q.front=NULL;
    q.rear=NULL;

    char cumle[15];
    printf("cümle giriniz:");
    scanf("%s", & cumle);

    push(&s, cumle);
    enqueue(&q, cumle);
    polindrom(&s, &q);
    return 0;
}