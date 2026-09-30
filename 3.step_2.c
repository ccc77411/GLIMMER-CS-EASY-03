#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;





TreeNode* create_node(int value){          
    TreeNode *Node=(TreeNode *)malloc(sizeof(TreeNode));       //为节点分配内存
    if (Node==NULL)
    {
        printf("内存分配错误\n");                          //判断是否分配失败
        exit(1);
    }
    Node->data=value;                    //赋值date
    Node->left=NULL;                    //使left和right指向NULL
    Node->right=NULL;
    return Node;                        //返回创造的节点
}


               
int main(){                               //构造链二叉树                  
    TreeNode *root;
    root=create_node(1);                     
    root->left=create_node(2);
    root->right=create_node(3);
    root->left->left=create_node(4);
    root->left->right=create_node(5);
    root->right->left=create_node(6);
    root->right->right=create_node(7);
    return 0;
}