void preorder(TreeNode*t){    //前序遍历
    printf("%d ",t->data);
    if (t->left!=NULL)
    {
        preorder(t->left);
    }
    if (t->right!=NULL)
    {
         preorder(t->right);
    }
}



void inorder(TreeNode*t){      //中序遍历
    if (t->left!=NULL)
    {
        inorder(t->left);
    }
    printf("%d ",t->data);
    if (t->right!=NULL)
    {
         inorder(t->right);
    }
}



void postorder(TreeNode*t){     //后序遍历
    if (t->left!=NULL)
    {
        postorder(t->left);
    }
     if (t->right!=NULL)
    {
         postorder(t->right);
    }
    printf("%d ",t->data);
}




int depth(TreeNode *root, int current_depth, int max_depth){
    if (root==NULL)
    {
        return 0;          //判断根节点是否为空
    }
    current_depth++;             //深度加一
    if (current_depth>max_depth)   //使max_depth始终为最大的
    {
        max_depth=current_depth;   
    }
    if (root->left!=NULL)      //探测左子树的深度  
    {
       max_depth=depth(root->left ,current_depth,  max_depth);    //把返回值赋值给max_depth来实现max_depth值的变更
    }
    if (root->right!=NULL)      //同理
    {
       max_depth=depth(root->right,current_depth,  max_depth);
    }
    return max_depth; 
}





typedef struct Stack {       //定义了一个结构体
    TreeNode **arr;         //指针型数组，用来存放入栈的元素
    int top;                 //top为数组的下标，表示当前入栈元素的下标
    int capacity;             //表示这个栈的容量
} Stack;
Stack *createStack(int capacity) {                  //定义了创建栈的函数
    Stack *stack = malloc(sizeof(Stack));              //为结构体分配内存
    stack->arr = malloc(sizeof(TreeNode *) * capacity);    //为数组分配内存
    stack->top = -1;                  //top为-1表示是空栈
    stack->capacity = capacity;
    return stack;
}
int isEmpty(Stack *stack) {             //定义了判断栈是否为空栈的函数
    return stack->top == -1;
}
void push(Stack *stack, TreeNode *node) {            //定义了入栈的函数
    if (stack->top == stack->capacity - 1) {          //判断栈是否满了
        return;
    }
    stack->arr[++stack->top] = node;                  //让元素入栈
}
TreeNode *pop(Stack *stack) {               //定义了一个出栈的函数
    if (isEmpty(stack)) {                      //判断栈是否为空
        return NULL;
    }                         
    return stack->arr[stack->top--];             //返回存在栈中的元素即出栈
}

void preorderTraversal(TreeNode *root) {         
    int capacity=100;                    //定义栈的容量，这里随手定义了100.
    Stack*stack=createStack(capacity);    //创建栈结构体
    TreeNode*p=root;                       //定义个指针代替根指针移动
    while(p!=NULL||!isEmpty(stack)){       //判断是否为空节点或是否栈为空
    while (p!=NULL)                      //判断是否左边走到叶节点
    {  
       printf("%d ",p->data);  
       push(stack, p);                   //入栈
       p=p->left;

    }
    p=pop(stack);                      //出栈，回到上一存储的节点
    p=p->right;                        //向右移动
}
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
    preorderTraversal(root);                  //调用preorderTraversal
    return 0;
}

