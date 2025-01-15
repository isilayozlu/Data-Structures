// verilen bst treede max ve min elemanları bul ekrana yazdır

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;
struct node *root2=NULL;

struct node *kokolustur(int veri){
    root= (struct node *)malloc(sizeof(struct node));
    root->data=veri;
    root->left=NULL;
    root->right=NULL;

    return root;
}

struct node *elemanekle(struct node *root, int veri){
    if(root == NULL){
        root=kokolustur(veri);
    }
    else{
        if(veri < root->data)
        root->left=elemanekle(root->left, veri);

        else
        root->right=elemanekle(root->right, veri);   
    }
    return root;
}

void min(struct node *root){
    int min=root->data;
        while(root->left != NULL){
        min=root->left->data;
        root=root->left;
        }
        printf("min value is:%d\n", min);
}

void max(struct node *root){
    int max=root->data;
    while(root->right != NULL){
        max=root->right->data;
        root=root->right;
    }
    printf("max value is:%d\n", max);
}

//tek sayıları bir ağaca kopyalar
struct node *copyOdd(struct node *root, struct node *root2){
    if(root != NULL){
        if(root->data%2 == 1){
            root2=elemanekle(root2,root->data);
        }
        root2= copyOdd(root->left,root2);
        root2=copyOdd(root->right,root2);
    }
    return root2;
}


//Verilen bir ikili ağaç yapısının yüksekliğini bulan fonksiyonu yazınız? 
int height(struct node *root){ 
if (root==NULL) 
return-1; 
else{ 
int Lheight,Rheight; 
Lheight=height(root->left); 
Rheight=height(root->right); 
if (Rheight>Lheight) 
return Rheight+1; 
else 
return Lheight+1; 
} 
} 

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

int main(){
    int secim=0;
    int veri;


    root=elemanekle(root,1);
    root=elemanekle(root,7);
    root=elemanekle(root,9);
    root=elemanekle(root,32);
    root=elemanekle(root,2);
    root=elemanekle(root,12);
    root=elemanekle(root,15);
    min(root);
    max(root);
    inorder(root);

    root2=copyOdd(root,root2);

    printf("\ninorder odd tree:");
    inorder(root2);
    return 0;
}