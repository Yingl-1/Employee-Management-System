#include"WorkManager.h"

void WorkManager::input() {

	int inonce=0;
	
	while (true) {

		//系统显示并输入
		this->show_menu();
		std::cout << "请输入选择："<<std::endl;
		std::cin >> inonce;
		
		/*"0.退出管理系统" 
		 "1.增加职工信息" 
		"2.显示职工信息" 
		"3.删除职工信息" 
		"4.修改职工信息" 
		"5.查找职工信息" 
		"6.按照编号排序"
		"7.清空所有文档" */
		switch (inonce) {

			case 0:
/*				//退出管理系统
				system("cls");//清屏
				std::cout << "欢迎下次使用员工管理系统"<<std::endl;
				system("pause");//阻塞
				
				exit(0);//退出程序*/

				this->exitSystem();
				break;
			case 1:
				this->addEpy();
				//增加职工信息
				break;
			case 2:
				this->show_Emy();
				//显示职工信息
				break;
			case 3:
				this->delete_Emy();
				//删除职工信息
				break;
			case 4:
				this->modify_Emy();
				//修改职工信息
				break;
			case 5:
				//查找职工信息
				this->Find_Emy();
				break;
			case 6:
				this->sort();
				//按照编号排序
				break;
			case 7:
				this->clearFile();
				//清空文档信息
				break;
			case 8:
				this->clearScreen();
				break;
			default:
				
				system("cls");
				break;

		}

	}

}