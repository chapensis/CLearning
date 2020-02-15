/**
 * 一个堆栈模块的接口
 **/ 
#define STACK_TYPE int // 堆栈所存储的值的类型

/**
 * 创建堆栈，参数指定堆栈可以保存多少个元素
 * 注意：这个函数并不用于静态数组版本的堆栈
 **/ 
void create_stack(int stack_size);

/**
 * 销毁堆栈，他释放独占所使用的内存
 * 注意：这个函数也不用于静态数组版本的堆栈
 **/ 
void destroy_stack(void);

/**
 * 将一个新值压入到堆栈中，他的参数是需要被压入的值
 **/ 
void push(STACK_TYPE value);

/**
 * 从堆栈中弹出一个元素
 **/ 
STACK_TYPE pop(void);

/**
 * 返回堆栈顶部元素的值，但不对堆栈进行修改
 **/ 
STACK_TYPE top(void);

/**
 * 如果堆栈为空，返回True,否则返回false
 **/ 
int is_empty();

/**
 * 如果堆栈已满，返回True,否则返回false
 **/ 
int is_full();