//tek yönlü liste oluşturup başa ve sona ekleme, baştan ve sondan silme, eleman sayısını ve elemanların toplamını bulma

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;
node *head=NULL, *p;

struct node *addhead(node *head, int key){
    node *eklenecek=(node *)malloc(sizeof(node));

    eklenecek->data=key;
    eklenecek->next=head;
    head=eklenecek;

    return head;
}

struct node *addlast(node*head, int key){

        node *eklenecek=(node *)malloc(sizeof(node));
        eklenecek->data=key;
        eklenecek->next=NULL;
        p=head;
        while(p->next != NULL){
        p=p->next;
        }
        p->next=eklenecek;
        p=p->next;
        head=p;
    return head;
}

struct node *bastansil(node* head){
    p=head;

        head=head->next;
        free(p);
        
    return head;
}

struct node *sondansil(node *head){
    p=head;

        while(p->next->next != NULL){
            p=p->next;
        }
        free(p->next);
        p->next=NULL;
        head=p;

    return head;
}

int count(node *head){
    p=head;
    int i=0;

    if(head==NULL){
    }

    else{
    while(p->next != NULL){
        i++;
        p=p->next;
    }
    i++;
    }
printf("\nNUMBER OF ELEMENTS:%d", i);
}

int toplam(node *head){
    p=head;
    int toplam=0;
    if(p==NULL){
        printf("toplam:%d\n", toplam);
    }

    else if(p->next == NULL){
        toplam=p->data;
        printf("toplam:%d\n", toplam);
    }
    else{
        while(p->next!=NULL){
            toplam=toplam+ (p->data);
            p=p->next;
        }
        toplam=toplam+(p->data);

        printf("toplam:%d\n", toplam);
    }
    return 0;

}

void listele(struct node *head) {
    p = head;

    if(head==NULL){
        printf("ELEMAN YOK!");
    }

    else{
        while (p->next != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("%d -> ", p->data);
    printf("NULL");
}}


int main(){
    int secim=0,sayi;

    while(secim!=8){

    printf("\n***************************");
    printf("\n1-basa  sayi ekle\n2-sona sayi ekle\n3-bastan sayi sil\n4-sondan sayi sil\n5-kaç değer var\n6-girilen deperlerin toplamı \n7-listele\n8-çikiş\n");
    scanf("%d",& secim);
    printf("***************************\n");

    switch (secim)
    {
    case 1:
    printf("eklemek istediğiniz sayiyi giriniz:");
    scanf("%d",& sayi);
    head=addhead(head,sayi);
    listele(head);
    count(head);
    break;

    case 2:
    printf("eklemek istediğiniz sayiyi giriniz:");
    scanf("%d",& sayi);
    if(head==NULL){
        head=addhead(head,sayi);
    }
    else{
    addlast(head,sayi);}

    listele(head);
    count(head);
    break;

    case 3:
    if(head==NULL){
        printf("listede silinecek eleman yok");
    }
    else{
    head=bastansil(head);
    listele(head);
    }
    
    count(head);
    break;

    case 4:
    if(head==NULL){
    printf("listede silinecek eleman yok");}

    else if(head->next==NULL){
        head=bastansil(head);
        listele(head);}

    else{
    sondansil(head);
    listele(head);}
    count(head);
    break;

    case 5:count(head);break;
    case 6:toplam(head);break;
    case 7:listele(head);break;
    case 8:break;  
    default:printf("yanlis secim yaptiniz");break;
    }}

    return 0;
}