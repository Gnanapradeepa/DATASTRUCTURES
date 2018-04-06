#include<stdio.h>
#include<stdlib.h>
struct n
{
	int data;
	struct n *left;
	struct n *right;
};
typedef struct n node;
node *root;
void insert(node *temp,int data)
{
	node *newnode;
	if(temp->data>data&&temp->left!=NULL)
	{
		printf("traverse left\n");
		insert(temp->left,data);
	}
	else if(temp->data<data&&temp->right!=NULL)
	{
		printf("traverse right\n");
		insert(temp->right,data);
	}
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	if(temp->data>data&&temp->left==NULL)
	{
		temp->left=newnode;
		printf("inserted left\n");
	}
	else if(temp->data<data&&temp->right==NULL)
	{
		temp->right=newnode;
		printf("inserted right\n");
	}	
}
void preorder(node *temp)
{
	if(temp==NULL)
	return;
	printf("%d",temp->data);
	preorder(temp->left);
	preorder(temp->right);
}
void postorder(node *temp)
{
	if(temp==NULL)
	return;
	postorder(temp->left);
	postorder(temp->right);
	printf("%d",temp->data);
}
void inorder(node *temp)
{
	if(temp==NULL)
	return;
	inorder(temp->left);
	printf("%d",temp->data);
	inorder(temp->right);
}
int main(void)
{
	int ch,data;
	root=(node*)malloc(sizeof(node));
	printf("enter root node\n");
	scanf("%d",&root->data);
	root->left=NULL;
	root->left=NULL;
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:scanf("%d",&data);
			insert(root,data);
			break;
			case 2:preorder(root);
			break;
			case 3:postorder(root);
			break;
			case 4:inorder(root);
			break;
      case 5:exit(0);
		}
	}
}
