#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100
/*
 * 顺序存储二叉树结点
 * - data：结点数据
 * - used：当前位置是否有结点
 */
typedef struct {
    int data;
    bool used;
} SeqTreeNode;

/*
 * 顺序存储二叉树
 * - nodes：结点数组
 * - size：数组最大容量
 */
typedef struct {
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;  

/*
 *让二叉树的大小为MAX_TREE_SIZE
 *让全部节点设置为空，大小为0*/


void init_tree(SeqBiTree *tree){
    tree->size=MAX_TREE_SIZE;
    int i=0;
    while (i<MAX_TREE_SIZE)
    {
        tree->nodes[i].data=0;
        tree->nodes[i].used=false;
        i++;
    }
}

/*
 *建根节点，在节点数组1处设置根节点
 *传入根节点的data
 *让used为true*/



bool set_root(SeqBiTree *tree, int value){
    tree->nodes[1].data=value;
    tree->nodes[1].used=true;
}

/*
 *创建左孩子
 *2*parent_node为其下标
 *让used为true*/




bool set_left_child(SeqBiTree *tree, int parent_node, int value){
    tree->nodes[2*parent_node].data=value;
     tree->nodes[2*parent_node].used=true;
}
  
/*创建右孩子
 *2*parent_node+1为其下标
 *让used为true*/



bool set_right_child(SeqBiTree *tree, int parent_node, int value){
     tree->nodes[2*parent_node+1].data=value;
     tree->nodes[2*parent_node+1].used=true;
}

/*实现层序遍历*/


void level_order(SeqBiTree *tree){
    int i=1;
    int m=1;                   //这里的m是用来判断i是否走到了每层的最后看是否要换行
    while (i<MAX_TREE_SIZE)
    {
        if (tree->nodes[i].used==false)    //判读是否为空节点
        {
            printf("-1 ");
        }
        else{
            printf("%d ",tree->nodes[i].data);
        }
        if (i==m)                     //判断是否到每层的最后一个节点
        {
            printf("\n",tree->nodes[i].data);
            m=2*m+1;                //表示了每层最后一个节点的下标规律
        }
        i++;
    }
    return;
}


/*
 *在主函数中构造出一个三层的二叉树并层序遍历*/


int main(){
    int a=1;
    int b=2;
    int c=3;
    int d=4;
    int e=7;
    int p1=1;
    int p2=2;
    int p3=3;
    SeqBiTree tree;
    SeqBiTree *p=&tree;
    init_tree(p);
    set_root(p, a);
    set_left_child(p, p1 ,b);
    set_right_child(p,  p1, c);
    set_left_child(p, p2 ,d);
    set_right_child(p, p3,e);
    level_order(p);
    return 0;
}