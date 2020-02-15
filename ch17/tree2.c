/**
 * 一个使用动态分配的链式结构实现的二叉搜索树
 **/
#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

typedef struct TREE_NODE
{
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} TREE_NODE;

/**
 * 指向根节点的指针
 **/
static TREE_NODE *tree = NULL;

/**
 * 向树添加一个新值，参考是需要被添加的值，他必须原先并不存在于树中
 **/
void insert(TREE_TYPE value)
{
    TREE_NODE *current;
    TREE_NODE **link;

    *link = &tree;
    /**
     * 从何时的子树开始，直到达到一个叶子节点
     **/
    while ((current = *link) != NULL)
    {
        if (value < current->value)
        {
            link = &current->left;
        }
        else
        {
            assert(value != current->value);
            link = &current->right;
        }
    }
    current = malloc(sizeof(TREE_NODE));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    // 讲关联链接上
    *link = current;
}

/**
 * 查找一个特定的值，这个值作为第1个参数传递给函数
 **/
TREE_TYPE *find(TREE_TYPE value)
{
    /**
     * 从根节点开始寻找
     **/
    TREE_NODE *current = tree;
    while (current != NULL && current->value != value)
    {
        if (value < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (current != NULL)
    {
        return &current->value;
    }
    else
    {
        return NULL;
    }
}

/**
 * 执行树的前序遍历，它的参数是一个回调函数指针，它所指向的函数将在树中处理
 * 每一个节点被调用，节点的值作为参数传递给这个函数。
 **/
static void do_pre_order_traverse(TREE_NODE *current, void (*callback)(TREE_TYPE value))
{
    if (current != NULL)
    {
        callback(current -> value);
        do_pre_order_traverse(current -> left, callback);
        do_pre_order_traverse(current -> right, callback);
    }
}

/**
 * 执行树的前序遍历，它的参数是一个回调函数指针，它所指向的函数将在树中处理
 * 每一个节点被调用，节点的值作为参数传递给这个函数。
 **/
void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
    do_pre_order_traverse(tree, callback);
}
