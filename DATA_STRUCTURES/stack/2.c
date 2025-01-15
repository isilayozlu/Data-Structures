#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_SIZE 5

struct node{
    char operation[20];
    struct node *next;
};

typedef struct{
    struct node *top;
    int counter;
}stack;

struct node *push(stack *s, char operation[]){
    if(s->counter==STACK_SIZE){
        printf("stack is full\n");
    }
    else{
    struct node *ekle;
    ekle=(struct node *)malloc(sizeof(struct node));
    strcpy(ekle->operation,operation);
    ekle->next=s->top;
    s->top=ekle;
    s->counter++;
    return s->top;
    }
}

struct node *pop(stack *s){
    if(s->top==NULL){
        printf("silinecek eleman yok");
    }
    else{
    struct node *temp=s->top;
    s->top=s->top->next;
    printf("%s elemani stackten cikartildi\n",temp->operation);
    printf("*******************\n");
    free(temp);
    s->counter--;
    }
    return s->top;
    
}

void top(stack *s){
    if(s->top==NULL){
        printf("stack is empty\n");
    }
    else{
        printf("top value is:%s\n", s->top->operation);
    }
}

void display(stack *s){
    struct node* temp;
    temp = s->top;
    if(temp == NULL){
        printf("stack is empty\n");
    }
    else{
        while(temp->next != NULL){
            printf("%s\n", temp->operation);
            temp=temp->next;
        }
        printf("%s\n", temp->operation);
    }

}

int main(){
    stack s;
    s.top=NULL;
    s.counter=0;
    push(&s, "Opened Google");
    push(&s, "Searched for Data Structures");
    push(&s, "Opened Stack Overflow");
    printf("\nyazdir\n");
    display(&s);
    printf("eleman sayisi:%d\n", s.counter);
    printf("\n****************\n");
    printf("\n elmani sil\n");
    pop(&s);
    printf("eleman sayisi:%d\n", s.counter);
    printf("\nyazdir\n");
    display(&s);
    printf("\n bastaki elmani göster\n");
    top(&s); 
    printf("\n elmani sil\n");
    pop(&s); 
    printf("eleman sayisi:%d\n", s.counter);
    printf("\n bastaki elmani göster\n");
    top(&s);
    printf("*******************************\n");
    printf("\nyazdir\n");
    display(&s);
    pop(&s);
    printf("\nyazdir\n");
    display(&s);
    pop(&s);

    return 0;
}