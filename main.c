#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int val;
    struct tree *left;
    struct tree *right;
}tree;

tree *create_tree(int val)
{
    tree *p = (tree*)malloc(sizeof(tree));
    
    p->val = val;
    p->left = p->right = NULL;
    
    return p;
}

void delete_tree(tree *root)
{
    if(!root) return;
    delete_tree(root->right);
    delete_tree(root->left);
    free(root);
}

tree *add_tree(tree *root, tree *p)
{    
    if(!root) return p;
    
    if(p->val < root->val){
        root->left = add_tree(root->left, p);
    }else{
        root->right = add_tree(root->right, p);
    }
    
    return root;
}

void show_tree(tree *p)
{
    if(p->left) show_tree(p->left);

    printf("%d %d %d\n", 
           p->val, 
           p->left  ? p->left ->val : 0,
           p->right ? p->right->val : 0
          );
    
    if(p->right) show_tree(p->right);
}

int main(int argc, char *argv[]) 
{
    char str[7];
    tree *root = NULL;
    
    while(fgets(str, sizeof(str), stdin)){
        root = add_tree(root, create_tree(atoi(str)));
    }
    
    if(root) show_tree(root);
    
    delete_tree(root);

    return 0;
}
