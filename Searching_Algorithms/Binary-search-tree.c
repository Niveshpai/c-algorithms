// C program to implement Binary Search tree in C

#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree TREE;

TREE * insert(TREE *,int );
void inorder(TREE *);
void preorder(TREE *);
void postorder(TREE *);
TREE * Delete(TREE *,int );
void printIndegreeofrootnode();
void printOutdegreeofrootnode();
void printAddressofrootnode(TREE *);
void minimumvaluefromtree(TREE *);

int main()
{
    TREE *root = NULL;
    int choice,ch,data;
   while(1)
    {
        printf("MENU\n");
        printf("1-Insert into BST\n2-Inorder\n3-Preorder\n4-Postorder\n5-Delete\n6-Otherfunctions\n7-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the item to insert\n");
                    scanf("%d",&data);
                    root = insert(root,data);
                    break;
            case 2: if(root == NULL)
                    printf("Empty Tree\n");
                    else
                    {
                        printf("Inorder traversal is\n");
                        inorder(root);
                    }
                    break;
            case 3: if(root == NULL)
                    printf("Empty Tree\n");
                    else
                    {
                        printf("Preorder traversal is\n");
                        preorder(root);
                    }
                    break;
            case 4: if(root == NULL)
                    printf("Empty Tree\n");
                    else
                    {
                        printf("Postorder traversal is\n");
                        postorder(root);
                    }
                    break;
            case 5: printf("Enter the item to delete\n");
                    scanf("%d",&data);
                    root = Delete(root,data);
                    break;
            case 6: printf("1-print in-degree of root node\n2-print out-degree of root node\n3-print address of root node\n4-minimum value of tree\n");
                    scanf("%d",&ch);
                    if(ch==1)
                        printIndegreeofrootnode();
                    else if(ch==2)
                        printOutdegreeofrootnode();
                    else if(ch==3)
                        printAddressofrootnode(root);
                    else if(ch==4)
                        minimumvaluefromtree(root);
                    break;
            case 7:exit(0);
        }
    }
    return 0;
}

TREE * insert(TREE * root,int data)
{
    TREE *newnode;
    newnode=(TREE *)malloc(sizeof(TREE));
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
        return root;
    }
  
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        printf("Root inserted successfully\n");
        return newnode;
    }

    TREE *curr,*parent;
    curr=root;
    parent=NULL;
    while(curr!=NULL)
    {
        parent=curr;
        if(newnode->data<curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    if(newnode->data<parent->data)
        parent->left=newnode;
    else
        parent->right=newnode;
    printf("Root inserted successfully\n");
    return root;
}

void inorder(TREE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void preorder(TREE *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TREE *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
TREE * Delete(TREE *root,int data)
{
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return root;
    }
    TREE *curr,*par;//par=parent
    par=NULL;
    curr=root;
    while(curr!=NULL && data!=curr->data)
    {
        par=curr;
        if(data<curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    if(curr==NULL)
    {
        printf("Item not found\n");
        return root;
    }
    TREE *p,*succ;
    if(curr->left==NULL)
        p=curr->right;
    else if(curr->right==NULL)
        p=curr->left;
    else
    {
        succ=curr->right;
        while(succ->left!=NULL)
            succ=succ->left;
        succ->left=curr->left;
        p=curr->right;
    }
    if(par==NULL)
    {
        free(curr);
        return p;
    }
    if(curr==par->left)
        par->left=p;
    else
        par->right=p;
    free(curr);
    return root;
}

void printIndegreeofrootnode()
{
    printf("The in-degree of root node is 0\n");
}

void printOutdegreeofrootnode()
{
    printf("The Out-degree of root node is 2\n");
}

void printAddressofrootnode(TREE *root)
{
        printf("Address of root node is %d\n",&root);
}

void minimumvaluefromtree(TREE *root)
{
    TREE *temp;
    temp=(TREE *)malloc(sizeof(TREE));
    if(root==NULL)
    {
        printf("Tree empty\n");
    }
    temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    printf("Minimum value is %d\n",temp->data);
    free(temp);
}
