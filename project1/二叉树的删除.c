#include <stdio.h>
#include <stdlib.h>
typedef struct bintree{
    int data;
    struct bintree *left,*right;
}node;

node * findmin(node *root){
    if(!root){
        return NULL;
    }
    while(root->left){
        root=root->left;
    }
    return root;
}
node *Delete(node *root,int val){
    node *temp = NULL;  // ³õÊ¼»¯ temp Îª NULL
    if(!root){
        printf("Not Found");
    }
    else{
        if(val<root->data){
            root->left=Delete(root->left,val);
        }
        else if(val>root->data){
            root->right=Delete(root->right,val);
        }
        else{
            if(root->left&&root->right){
                temp=findmin(root->right);
                root->data=temp->data;
                root->right=Delete(root->right,temp->data);
            }
            else{
                temp = root; 
                if(root->right){
                    root=root->right;
                }
                else{
                    root=root->left;
                }
                free(temp);
            }
        }
    }
    return root;
}
int main(){
    return 0;
}

