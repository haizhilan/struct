#include "link.h"

// 初始化
Status initList (SqlList *L,int size, int inc){
	L->elem = (Elemtype *)malloc(size * sizeof(Elemtype));
	if (! L->elem) {
		return ERROR;
	}
	L->length = 0;
	L->listsize = size;
	L->increment = inc;

	return TRUE;
}

// 添加元素
Status addList (SqlList *L,Elemtype data) {
	if (L->length >= L->listsize) {
		L->elem = (Elemtype *)realloc(L->elem,(L->listsize + L->increment) * sizeof(Elemtype) );
		L->listsize = L->listsize + L->increment;
	}

	if (! L->elem ) {
		return FALSE;
	}

	L->elem[L->length] = data;
	L->length++;

	return TRUE;
}

//　插入元素
Status insertList (SqlList *L,Elemtype data, int site) {
	if (L->length >= L->listsize) {
		L->elem = (Elemtype*)realloc(L->elem,(L->listsize + L->increment) * sizeof(Elemtype));
		L->listsize = L->listsize + L->increment;
	}

	if (!L->elem) {
		return FALSE;
	}

	if (L->length  < site){
		return FALSE;
	}

	if (L->length == site) {
		L->elem[L->length++] = data;
		return TRUE;
	}
	
	for (int i = L->length;  i >= site ; --i)
	{
		
		L->elem[i] = L->elem[i-1];
		if (i == site) {
			L->elem[i] = data;
		}
	}
	L->length++;

	return TRUE;
}
// 更新元素
Status updateList (SqlList *L,Elemtype data,int site) {
	if (L->length -1 < site || site < 0) {
		return FALSE;
	}	

	L->elem[site] = data;

	return TRUE;
}

//删除元素
Status deleleList (SqlList *L,int site) {
	if (L->length -1 < site || site < 0) {
		return FALSE;
	}	

	if (L->length-1 == site){

		L->length--;
		return TRUE;
	}

	for (int i = site; i < L->length; ++i)
	{
		L->elem[i] = L->elem[i+1];
	}
	L->length--;
	return TRUE;

}
// 清空顺序表
Status clearList(SqlList *L) {
	if (L->length < 0) {
		return FALSE;
	}
	L->length = 0;
	return TRUE;
}
// 销毁顺序表
Status destroyList(SqlList *L) {
	if (L) {
		for (int i = 0; i < L->length; ++i)
		{
			L->elem[i] = 0;
		
		}
		free(L);
		L = NULL;
		return TRUE;
	} else {
		return FALSE;
	}
}
// 遍历链表
void printList (SqlList L) {
	for (int i = 0; i < L.length; ++i)
	{
		printf("顺序存储结构的值 %d= %d\n", i,L.elem[i]);
	}
}