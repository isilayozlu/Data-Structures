#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root= NULL;

struct node *kokolustur(int veri){
    struct node *eklenecek=(struct node *)malloc(sizeof(struct node));
    eklenecek->data=veri;
    eklenecek->left=NULL;
    eklenecek->right=NULL;

    root=eklenecek;

    return root;
}

struct node *elemanekle( struct node *root, int veri){
    if(root== NULL){
        root=kokolustur(veri);
    }
    else{
        if(root->data > veri){
            root->left=elemanekle(root->left, veri);
        }
        else{
            root->right=elemanekle(root->right, veri);
        }
    }
    return root;
}

void inorder(struct node *root){ // küçüktenbüyüğe sıralar
    if(root!= NULL){
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d -> ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ", root->data);
        }
}

int minValue(struct node *root){
    int min;
    while(root->left != NULL){
        min=root->left->data;
        root=root->left;
    }
    return min;
}

int maxValue(struct node *root){
    int max;
    while(root->right != NULL){
        max=root->right->data;
        root=root->right;
    }
    return max;
}

int main(){

    root=elemanekle(root, 5);
    root=elemanekle(root, 1);
    root=elemanekle(root, 6);
    root=elemanekle(root, 13);
    root=elemanekle(root, 22);
    root=elemanekle(root, 7);


    printf("\ninorder: ");
    inorder(root);
    printf("\npreorder:");
    preorder(root);
    printf("\npostorder: ");
    postorder(root);
    printf("\n");

    printf("max value is: %d\n ", maxValue(root));
     printf("min value is: %d\n", minValue(root));
}