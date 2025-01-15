#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define stack_size 10

struct node{
    char operation[25];
    struct node *next;
};

typedef struct{
    struct node *top;   
    int counter;
}stack;

struct node *push(stack *s , char operation[]){
    struct node *ekle=(struct node *)malloc(sizeof(struct node));
    strcpy(ekle->operation, operation);

    if(s->counter == stack_size){
        printf("stack is full");
    }

    else{
        ekle->next=s->top;
        s->top=ekle;
        s->counter++;
    }
    return s->top;
}

struct node *pop(stack *s){
    if(s->top== NULL){
        printf("listede silinecek eleman yok");
    }
    else{
        struct node *temp=s->top;
        s->top=s->top->next;
        printf("%s stackten çıkartıldı\n", temp->operation);
        free(temp);
    }
    return s->top;
}

void top(stack *s){
    if(s->top == NULL){
        printf("there is no top value");
    }
    else{
        printf("TOP VALUE IS:%s" ,s->top->operation);
    }
}

void display(stack *s){
    struct node *temp=s->top;

    if(s->top == NULL){
        printf("stack bos\n");
    }
    else{
        while(temp != NULL){
            printf("%s\n", temp->operation);
            temp=temp->next;
        }
    }
}

int main(){
    stack s;
    s.top=NULL;
    s.counter=0;

    push(&s, "mustafa");
    push(&s, "emine");
    push(&s, "nazlican");
    pop(&s);
    push(&s, "ayse");
    push(&s, "nazlican");
    push(&s, "ışılay");
    push(&s, "zeynep");
    display(&s);
    top(&s);
    return 0;
}