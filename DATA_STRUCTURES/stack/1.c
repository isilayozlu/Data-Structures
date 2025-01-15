#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 3

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *top;
    int counter;
}stack;

struct node *push(stack *s, int data){
    if(s->counter== size){
        printf("stack is full, you can not add any elements in the stack\n");
    }
    else{
        struct node *ekle=(struct node*)malloc(sizeof(struct node));
        ekle->data=data;
        ekle->next=s->top;
        s->top=ekle;
        s->counter++;
    }
    return s->top;
}

struct node *pop (stack *s){
    if(s->top==NULL){
        printf("there is no element for pop\n");
    }
    else{
        struct node *temp;
        temp=s->top;
        printf("%d elemanı stackten çıkartıldı\n", temp->data);
        free(temp);
        s->top=s->top->next;
        s->counter--;
        return s->top;
    }
   
}

void display(stack *s){
    if(s->top==NULL){
        printf("stack is empty\n");
    }
    else{
        struct node *temp=s->top;
        while(temp->next != NULL){
            printf("%d\n", temp->data);
            temp=temp->next;
        }
        printf("%d\n", temp->data);
    }
}

void top(stack *s){
    if(s->top==NULL){
        printf("stack is empty");
    }
    else{
        printf("top value is:%d\n", s->top->data);
    }
}

int main(){
    stack s;
    s.top=NULL;
    s.counter=0;
    int secim=0;
    int veri;

    while(secim!=5){
        printf("yapmak istediğiniz işlemi seciniz:\n");
        printf("1-eleman ekle\n2-eleman çıkar\n3-yazdir\n4-bastaki elemanı göster\n5-çıkış");
        scanf("%d" ,& secim);

        switch (secim)
        {
        case 1:
        printf("eklemek istediğiniz elemani giriniz:");
        scanf("%d", & veri);
        push(&s,veri);
        break;
        case 2:pop(&s);break;
        case 3:display(&s);break;
        case 4:top(&s);break;
        case 5:break;  
        default:printf("hatali giriş, tekrar deneyiniz");break;
        }}
        printf("\n*************************************\n");
    return 0;
}