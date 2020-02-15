#include <stdlib.h>
#define QUEUE_TYPE int // 队列元素类型

/**
 * 创建一个队列，参数指定队列可以存储的元素的最大数量
 * 注意：这个函数只适用于使用动态分配数组的队列
 **/ 
void create_queue(int size);

/**
 * 销毁一个队列，注意：这个函数只适用于使用动态分配数组的队列
 **/ 
void destroy_queue(void);

/**
 * 向队列中添加一个新元素，参数就是需要添加的元素
 **/ 
void insert(QUEUE_TYPE value);

/**
 * 从队列中移除一个元素并将其丢弃
 **/ 
QUEUE_TYPE delete();

/**
 * 返回队列中的第一个元素，但不修改队列本身
 **/ 
QUEUE_TYPE first(void);

/**
 * 如果队列为空，返回True,否则返回False
 **/ 
int is_empty(void);

/**
 * 如果队列已满，返回True,否则返回False
 **/ 
int is_full(void);
