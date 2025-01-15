#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};
typedef struct node avltree;

avltree *kökdüğümolustur(int data){
    avltree *x=(avltree *)malloc(sizeof(avltree));
    x->data=data;
    x->left=NULL;
    x->right=NULL;
    x->height=1;

    return x;
}

int height(avltree *x){
    if(x==NULL)
    return 0;

    return x->height;
}

int getBalance(avltree *x) {
    if (x == NULL)
        return 0;
    return height(x->left) - height(x->right);
}

int max(int a, int b){
    if(a>b)
    return a;

    else
    return b;
}


avltree *rightRotate(avltree *x) {

    avltree *y= x->left;
    x->left=y->right;
    y->right=x;

    // Yükseklikleri güncelleme
    y->height = max(height(y->left), height(y->right)) + 1; //max fonksiyonu hangi tarafın h ı daha büyükse onu döndürür
    x->height = max(height(x->left), height(x->right)) + 1;

    // Yeni kök döndürme
    return y;
}

avltree *leftRotate(avltree *x){
    avltree *y=x->right;
    x->right=y->left;

    y->left=x;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return y;
}

void inorder (avltree *x){
    if(x!= NULL){
        inorder(x->left);
        printf("%d -> ", x->data);
        inorder(x->right);
    }
}

avltree *elemanekle(avltree *x, int data){
    if(x==NULL){
        x=kökdüğümolustur(data);
    }

    else{
        if(data > x->data){
            x->right=elemanekle(x->right, data);
        }

        else{
            x->left=elemanekle(x->left, data);
        }
    }

    x->height = 1 + max(height(x->left), height(x->right));
    int balance = getBalance(x);

    //sol sol durumu
    if (balance > 1 && data < x->left->data)
    return rightRotate(x);

    // Sağ sağ durumu
    if (balance < -1 && data > x->right->data)
        return leftRotate(x);

    // Sol sağ durumu
    if (balance > 1 && data > x->left->data) {
        x->left = leftRotate(x->left);
        return rightRotate(x);
    }

    // Sağ sol durumu
    if (balance < -1 && data < x->right->data) {
        x->right = rightRotate(x->right);
        return leftRotate(x);
    }

    return x;
}

int main() {
    avltree *root = NULL;

    // AVL ağacına eleman ekleme
    root = elemanekle(root, 10);
    root = elemanekle(root, 20);
    root = elemanekle(root, 30);
    root = elemanekle(root, 40);
    root = elemanekle(root, 50);
    root = elemanekle(root, 25);

    printf("%d", root->height);

    // AVL ağacını inorder olarak yazdırma
    printf("Inorder AVL tree is:\n");
    inorder(root);

    return 0;
}