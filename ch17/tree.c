/**
 * 一个使用静态数组实现的二叉搜索树，数组的长度只能通过修改 #define定义
 * 并对模块进行重新编译来实现
 **/
#include "tree.h"
#include <assert.h>
#include <stdio.h>

#define TREE_SIZE 100 // 定义树的最大节点数
#define ARRAY_SIZE (TREE_SIZE + 1)

static TREE_TYPE tree[ARRAY_SIZE];

/**
 * 计算左孩子的下标
 **/
static int left_child(int current)
{
    return current * 2;
}

/**
 * 计算右孩子的下标
 **/
static int right_child(int current)
{
    return current * 2 + 1;
}

/**
 * 向树添加一个新值，参考是需要被添加的值，他必须原先并不存在于树中
 **/
void insert(TREE_TYPE value)
{
    /**
     * 从根节点开始
     **/
    int current = 1;
    /**
     * 确保值为非0，因为0用于表示一个未使用的节点
     **/
    assert(value != 0);

    /**
     * 从何时的子树开始，直到达到一个叶子节点
     **/
    while (tree[current] != 0)
    {
        if (value < tree[current])
        {
            current = left_child(current);
        }
        else
        {
            assert(current != tree[current]);
            current = right_child(current);
        }
        assert(current < ARRAY_SIZE);
    }
    tree[current] = value;
}

/**
 * 查找一个特定的值，这个值作为第1个参数传递给函数
 **/
TREE_TYPE *find(TREE_TYPE value)
{
    /**
     * 从根节点开始寻找
     **/
    int current = 1;
    while (current < ARRAY_SIZE && tree[current] != value)
    {
        if (value < tree[current])
        {
            current = left_child(current);
        }
        else
        {
            current = right_child(current);
        }
    }
    if (current < ARRAY_SIZE)
    {
        return tree + current;
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
static void do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value)) {
    if(current < ARRAY_SIZE && tree[current] != 0) {
        callback(tree[current]);
        do_pre_order_traverse(left_child, callback);
        do_pre_order_traverse(right_child, callback);
    }
}

/**
 * 执行树的前序遍历，它的参数是一个回调函数指针，它所指向的函数将在树中处理
 * 每一个节点被调用，节点的值作为参数传递给这个函数。
 **/ 
void pre_order_traverse(void (*callback)(TREE_TYPE value)) {
    do_pre_order_traverse(1, callback);
}
