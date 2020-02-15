/**
 * 二叉搜索树模块的接口
 **/ 
#define TREE_TYPE int // 树的值类型

/**
 * 向树添加一个新值，参考是需要被添加的值，他必须原先并不存在于树中
 **/ 
void insert(TREE_TYPE value);

/**
 * 查找一个特定的值，这个值作为第1个参数传递给函数
 **/ 
TREE_TYPE *find (TREE_TYPE value);

/**
 * 执行树的前序遍历，它的参数是一个回调函数指针，它所指向的函数将在树中处理
 * 每一个节点被调用，节点的值作为参数传递给这个函数。
 **/ 
void pre_order_traverse(void (*callback)(TREE_TYPE value));

