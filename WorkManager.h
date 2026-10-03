#pragma once
#include"Worker.h"
#include "employee.h"
#include "Boss.h"
#include "Manager.h"
#include<iostream>
#include "File_Read_Write.h"



class WorkManager
{
public:

	File_Read_Write FRW;

	void clearFile();//清空文档

	void sort();//排序

	void modify_Emy();//修改员工

	void delete_Emy();//删除员工

	int Find_Emy();//查找员工

	int get_num();//总数

	void addEpy();//添加

	//显示员工
	void show_Emy();

	void show_menu();//显示选项

	void input();//输入

	void exitSystem();//退出系统

	void clearScreen();//清屏

	void inputClear();//输入缓冲区清理

	WorkManager();//构造

	~WorkManager();//析构


private:
	
	int allNum;
	Worker** arr;

};

