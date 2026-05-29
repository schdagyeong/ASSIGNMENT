#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
typedef struct TreeNode
{
	char data[10];
	struct TreeNode* left, * right;
}TreeNode;

//전위
preorder(TreeNode* root)
{
	if (root)
	{
		printf("%s", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//중위
inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("%s", root->data);
		inorder(root->right);
	}
}
//후위
postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%s", root->data);
	}
}
void main(void)
{
	/*
	printf("이진 트리의 노드의 개수 N (1<= N <=26)");
	int N;
	scanf("%d", &N);
	printf("\N");
	*/


	TreeNode* A, * B, * C, * D, * E, * F, * G;
	A = (TreeNode*)malloc(sizeof(TreeNode));
	B = (TreeNode*)malloc(sizeof(TreeNode));
	C = (TreeNode*)malloc(sizeof(TreeNode));
	D = (TreeNode*)malloc(sizeof(TreeNode));
	E = (TreeNode*)malloc(sizeof(TreeNode));
	F = (TreeNode*)malloc(sizeof(TreeNode));
	G = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* root = A;
	strcpy(A->data, "A");
	A->left = B;
	A->right = C;
	strcpy(B->data, "B");
	B->left = D;
	B->right = NULL;
	strcpy(C->data, "C");
	C->left = E;
	C->right = F;
	strcpy(D->data, "D");
	D->left = NULL;
	D->right = NULL;
	strcpy(E->data, "E");
	E->left = NULL;
	E->right = NULL;
	strcpy(F->data, "F");
	F->left = NULL;
	F->right = G;
	strcpy(G->data, "G");
	G->left = NULL;
	G->right = NULL;
	printf("전위 순회 = ");
	preorder(root);
	printf("\n");
	printf("중위 순회 = ");
	inorder(root);
	printf("\n");
	printf("후위 순회 = ");
	postorder(root);
	printf("\n");
	free(A); free(B); free(C); free(D); free(E); free(F); free(G);
	return 0;
}