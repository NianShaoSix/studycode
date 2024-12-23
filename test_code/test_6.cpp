#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;
//树节点
typedef struct Node {
    double value;
    struct Node* left;
    struct Node* right;
 } Node;
//创建树节点
Node* createNode(double value) {
    Node* node = new Node;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//插入节点
void insertNode(Node* root, double value) {
    if (root->value > value) {
        if (root->left == NULL) {
            root->left = createNode(value);
        } else {
            insertNode(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            root->right = createNode(value);
        } else {
            insertNode(root->right, value);
        }
    }
}
//统计叶子结点的个数
int countLeafNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
//求二叉树的深度
int depthOfThree(Node* root) {
    if(root==NULL) {
        return 0;
    }
    int leftDepth = depthOfThree(root->left);
    int rightDepth = depthOfThree(root->right);
    return (leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1));
    }
//是否为运算符
int isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
//是否为操作数
int isNumeric(char c){
    return isdigit(c) || c == '.';
}
// 将表达式转换为逆波兰表达式
char* toPostfix(char* expression) {
    int len = strlen(expression);
    char* postfix = (char*)malloc((len + 1) * sizeof(char)); // 分配足够的空间存储逆波兰表达式
    char* stack = (char*)malloc(len * sizeof(char)); // 运算符栈
    int top = -1; // 栈顶指针
    int idx = 0; // postfix数组索引

    for (int i = 0; i < len; i++) {
        char c = expression[i];
        if (isOperator(c)) {
            while (top >= 0 && stack[top] != '(' && ((c != '*' && c != '/') || (stack[top] != '+' && stack[top] != '-'))) {
                postfix[idx++] = stack[top--];
            }
            stack[++top] = c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[idx++] = stack[top--];
            }
            top--; // 弹出'('
        }
        else { // 操作数
            while (isNumeric(c)) { // 处理多位数
                postfix[idx++] = c;
                c = expression[++i];
            }
            postfix[idx++] = ' '; // 操作数之间用空格分隔
            i--; // 回退一个字符
        }
    }
    while (top >= 0) {
        postfix[idx++] = stack[top--];
    }
    postfix[idx] = '\0';
    return postfix;
}

//将逆波兰表达式转换为表达式二叉树
Node* toExpressionTree(char* postfix){
    Node* stack[100];
    int top = -1;
    for(int i = 0; postfix[i] != '\0'; i++){
        char c = postfix[i];
        if(isOperator(c)){
            Node* right = stack[top--];
            Node* left = stack[top--];
            Node* node = createNode(0);
            node->left = left;
            node->right = right;
            node->value = c;
            stack[++top] = node;
        }else if(isNumeric(c)){
            double num = atof(&postfix[i]);
            while(isNumeric(postfix[i])){
                i++;
            }
            i--;
            Node* node = createNode(num);
            stack[++top] = node;
        }
    }
    return stack[top];
}
//计算表达式二叉树的值
double evaluate(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->value;
    }
    double leftVal = evaluate(root->left);
    double rightVal = evaluate(root->right);
    char op = (char)root->value;
    switch(op){
        case '+':
            return leftVal + rightVal;
        case '-':
            return leftVal - rightVal;
        case '*':
            return leftVal * rightVal;
        case '/':
            return leftVal / rightVal;
        default:
            return 0;
    }

}
int main() {
    char expression[100];

    while(1) {
        cout << "请输入表达式：";
        cin >> expression;
        if(strcmp(expression, "exit") == 0) {
            break;
        }
        char* postfix = toPostfix(expression);
        cout << "逆波兰表达式：" << postfix << endl;
        Node* root = toExpressionTree(postfix);
        cout << "表达式二叉树的值：" << evaluate(root) << endl;
        cout << "叶子结点的个数：" << countLeafNodes(root) << endl;
        cout << "二叉树的深度：" << depthOfThree(root) << endl;
    }
    return 0;
}
