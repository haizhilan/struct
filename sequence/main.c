#include "link.h"

// 编译指令： gcc -o main main.c link.c -fexec-charset=gbk

int main(int argc, char const *argv[])
{
	SqlList L;

	initList(&L, 3, 3);// 初始化
	//添加元素
	addList (&L,1);
	addList (&L,2);
	printf("length=%d\n", L.length);
	printf("listsize=%d\n", L.listsize);
	addList (&L,3);
	addList (&L,4);
	
	// 插入元素
	insertList(&L,5,4);
	insertList(&L,6,1);
	insertList(&L,7,2);
	// 更新元素
	updateList(&L,8,2);
	updateList(&L,8,10);
	updateList(&L,8,-1);
	// 删除元素
	printList(L);
	deleleList(&L,7);
	// 清空
	// clearList(&L);
	// 销毁
	// destroyList(&L);
	// 查找值
	Elemtype data = findList(L,7);
	printf("查到的值：%d\n", data);
	//值是否在
	findValueList(L,10);
	printf("还有只啊=%d\n", L.elem[1]);
	printf("length=%d\n", L.length);
	printf("listsize=%d\n", L.listsize);
	printList(L);

	return 0;
}
