#ifndef LINK_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define LINK_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
	typedef int Elemtype;
	typedef int Status;	
//定义顺序表类型
typedef struct 
{
	Elemtype * elem;
	int length;// 当前链表大小
	int listsize;// 链表的存储空间
	int increment;// 增长因子
}SqlList;
Status initList (SqlList *L,int size, int inc);// 初始化
Status addList (SqlList *L,Elemtype data);// 添加元素
Status insertList (SqlList *L,Elemtype data, int site);//插入元素
Status updateList (SqlList *L,Elemtype data,int site);// 更新元素
Status deleleList (SqlList *L,int site);//删除元素
Status clearList(SqlList *L);// 清空顺序表
Status destroyList(SqlList *L);// 销毁顺序表
Elemtype findList(SqlList L,int site);// 查找顺序表的值
int findValueList(SqlList L,Elemtype data);// 值是否在顺序表中
void printList (SqlList L);// 遍历链表
#endif