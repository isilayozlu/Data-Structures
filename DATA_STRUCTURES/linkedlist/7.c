#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char model[25];
    int year;
    struct node *next;
    struct node *prev;
};

typedef struct node node;
node *head=NULL;
node *temp=NULL;
node *p=NULL;

node *basaEkleme(node *head, char model[], int year){
    node *eklenecek=(node *)malloc(sizeof(node));
    eklenecek->year=year;
    strcpy(eklenecek->model,model);
    eklenecek->prev=NULL;
    eklenecek->next=NULL;

    if(head== NULL){
        head=eklenecek;
    }

    else{
    eklenecek->next=head;
    head->prev=eklenecek;
    head=eklenecek;
    }
    return head;
}

node *sonaEkle(node *head, char model[], int year){
    temp=head;
    node *eklenecek=(node *)malloc(sizeof(node));
    eklenecek->year=year;
    strcpy(eklenecek->model,model);
    eklenecek->prev=NULL;
    eklenecek->next=NULL;

    if(head== NULL){
        head==eklenecek;
    }
    else{
        while(temp-> next != NULL){
            temp=temp->next;
        }
        temp->next=eklenecek;
        eklenecek->prev=temp;
    }
    return head;
}

node  *arayaekle(node *head, char model[], int year){
    int konum;
    int counter=0;
    temp=head;

    node *eklenecek=(node *)malloc(sizeof(node));
    eklenecek->year=year;
    strcpy(eklenecek->model,model);
    eklenecek->prev=NULL;
    eklenecek->next=NULL;


    while(temp != NULL){
        temp=temp->next;
        counter++;
    }

    printf("eklemek istediğiniz konumu giriniz:");
    scanf("%d",& konum);

    if(konum == counter +1){
        head=sonaEkle(head,model ,year);
    }

    else if(konum == 1){
        head=basaEkleme(head,model,year);
    }   

    else if (konum > 1 && konum <= counter) {
        temp = head;
        for (int i = 1; i < konum - 1; i++) {
            temp = temp->next;
        }
        
        node *p = temp->next;
        temp->next = eklenecek;
        eklenecek->prev = temp;
        eklenecek->next = p;
        
        if (p != NULL) { // Sonraki düğüm NULL değilse, bağlantıyı güncelle
            p->prev = eklenecek;
        }
    }
    else {
        printf("Listede böyle bir konum bulunmuyor.\n");
        free(eklenecek);
    }
    return head;
}

node *bastansil(node *head){
    if(head== NULL){
        printf("listede silinecek eleman yok");
    }
    else{
    temp=head;
    head=head->next;
    free(temp);
    }
    return head;
}

node *sondansil(node *head){
    temp=head;
    if(head== NULL){
        printf("listede silinecek eleman yok");
    }
    else{
        while(temp->next->next != NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
        temp=temp->next;
    }
    return head;
}

node *aradansil(node *head, int konum){
    temp=head;
    int counter=0;

    while(temp!= NULL){
        counter++;
        temp=temp->next;
    }
    
    if(head== NULL){
        printf("listede silinecek eleman yok");
    }

    else if(konum == 1){
        head=bastansil(head);
    }

    else if(konum== counter){
        head=sondansil(head);
    }

    else if(konum > 1 && konum <= counter){
        temp=head;
        for(int i=1; i< konum -1; i++ ){
            temp=temp->next;
        }
        node *p =temp->next->next;
        free(temp->next);
        temp->next=p;
        p->prev=temp;
    }
    else{
        printf("listede öyle bir konum yok\n");
    }
    return head;
}

node *belirlisilme(node *head, char model[], int year) {
    temp = head;

    while (temp != NULL && (strcmp(temp->model, model) != 0 || temp->year != year)) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Listede öyle bir eleman yok\n");
        return head;
    }

    // Silinecek düğüm baştaysa
    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    }
    // Silinecek düğüm ortada veya sondayken
    //ANLAMADIM ÇOK
    else {
        if (temp->next != NULL) { // Eğer silinecek düğüm son düğüm değilse
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(temp);
    }

    printf("Eleman başarıyla silindi\n");
    return head;
}

void dislpay(node *head){
    temp=head;
    if(head== NULL){
        printf("liste bos\n");
    }
    else{
        while(temp != NULL){
            printf("%s, %d\n", temp->model, temp->year);
            temp=temp->next;
        }
    }
}

int main(){ 
    int konum;

    head=basaEkleme(head, "TOYOTA", 2016);
    head=basaEkleme(head, "FIAT", 2020);
    head=sonaEkle(head, "MERCEDES", 2010);
    dislpay(head);
    printf("*********************\n");
    head=arayaekle(head, "AUDI", 2013);
    dislpay(head);
    printf("******************\n");
    printf("bastan sil çalısiyor\n");
    head=bastansil(head);
    dislpay(head);
    printf("******************\n");
    printf("sondan sil çalısiyor\n");
    head=sondansil(head);
    dislpay(head);
    printf("*****************\n");
    head=basaEkleme(head, "BMW", 2009);
    head=basaEkleme(head, "TOFAŞ", 2017);
    head=basaEkleme(head, "FORD", 2013);
    dislpay(head);
    printf("**************************\n");

    printf("aradan silmek istediğiniz elemanın konumunu giriniz");
    scanf("%d",& konum);
    head=aradansil(head, konum);
    dislpay(head);

    printf("**************************\n");
    head=belirlisilme(head, "BMW", 2009);
    dislpay(head);

     
    printf("**************************\n");
    head=belirlisilme(head, "TOFAŞ", 2017);
    dislpay(head);
    printf("*******************\n");



    return 0; 
} 