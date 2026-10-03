#include "WorkManager.h"
//using namespace std;
//显示系统
void WorkManager::show_menu() {

	std::cout << "欢迎使用员工管理系统" << std::endl;
	std::cout << "0.退出管理系统" << std::endl;
	std::cout << "1.增加职工信息" << std::endl;
	std::cout << "2.显示职工信息" << std::endl;
	std::cout << "3.删除职工信息" << std::endl;
	std::cout << "4.修改职工信息" << std::endl;
	std::cout << "5.查找职工信息" << std::endl;
	std::cout << "6.按照编号排序" << std::endl;
	std::cout << "7.清空所有文档" << std::endl;
	std::cout << "8.清理屏幕" << std::endl;
	 
	std::cout << std::endl;

}

//退出系统
void WorkManager::exitSystem() {

	//system("cls");//清屏
	std::cout << "欢迎下次使用员工管理系统" << std::endl;
	system("pause");//阻塞

	exit(0);//退出程序

}

//添加员工
void WorkManager::addEpy() {

	int inPutNum = 0;

	std::cout << "请输入要添加几人："<<std::endl;
	std::cin >> inPutNum;

	if (inPutNum!=0)
	{
		int new_size = this->allNum + inPutNum;

		Worker** new_arr = new Worker*[new_size];

		if (arr!=nullptr)//迁移旧数组
		{
			for (size_t i = 0; i < this->allNum ; i++)
			{
				new_arr[i] = arr[i];
			}

		}

			int id = 0;
			std::string name;
			int DeptName = 0;

			int pos = this->allNum;

		for (auto i = 0; i < inPutNum; i++)//增加员工
		{
			std::cout << "请输入你要添加的第"<<i+1 <<"个员工的id：" << std::endl;
			
			while(true){
			
				std::cin >> id;

				bool inputii = false;

				for (auto i = 0;i < allNum;i++)
				{
					if (arr != nullptr)
					{
						if (arr[i]->get_id() == id)
						{
							inputii = true;

							break;

						}

					}
				}

				if (inputii) {

					std::cout << "列表中已存在该编号的员工，请重新输入" << std::endl;

					this->inputClear();

				}
				else {
					break;
				}

			}

			std::cout << "请输入你要添加的第" << i + 1 << "个员工的姓名：" << std::endl;
			std::cin >> name;

			Worker* worker = nullptr;
			// 循环直到输入有效的部门编号并创建对应对象
			while (true) {
				std::cout << "请输入你要添加的第" << i + 1 << "个员工的部门：" << std::endl;
				std::cout << "1.总裁，2.经理，3.员工" << std::endl;
				std::cin >> DeptName;

				switch (DeptName) {
					case 1:
						worker = new Boss(id, name);
						break;
					case 2:
						worker = new Manager(id, name);
						break;
					case 3:
						worker = new Employee(id, name);
						break;
					default:
						worker = nullptr;
						break;
				}

				if (worker != nullptr) break;

				std::cout << "输入错误，请重新选择部门编号" << std::endl;
				this->inputClear();
			}

			if ((pos<new_size)&&(worker!=nullptr))//越界检查
			{
				new_arr[pos] = worker;//添加添加的元素
				pos++;
			}
			else {

				delete worker;
				i--;
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			
		}

		//释放旧内存
		delete[]this->arr;

		//指向新内存
		this->arr = new_arr;

		//更新大小
		this->allNum = new_size;

		std::cout << "本次添加了" << inPutNum << "个人" << std::endl;

		this->sort();//排序后写入文件
		
		FRW.file_write(this->arr,this->allNum);
		
	}
	else
	{
		std::cout << "输入错误" << std::endl;
		system("pause");
		system("cls");
		return;
	}

}

//显示员工
void WorkManager::show_Emy() {

	if (allNum == 0)//文件没有员工数据
	{
		std::cout << "文件没有员工数据" << std::endl;

		this->clearScreen();

		return;
	}
	
	for (size_t i = 0; i < allNum; i++)//显示所有员工数据
	{
		arr[i]->showinfo();

		std::cout << std::endl;

	}


	int isNo = 0;

	while (true) {
		std::cout << "是否继续显示员工信息？" << std::endl;
		std::cout << "1.是" << std::endl;
		std::cout << "0.否" << std::endl;
		std::cin >> isNo;

		if (isNo == 1)
		{
			return;
		}
		else if (isNo == 0) {
			this->clearScreen();
			break;
		}
		else {
			std::cout << "输入错误，请重新选择" << std::endl;
			//this->clearScreen();
			return;
		}
	}
	

}

//查找员工
int WorkManager::Find_Emy() {

	Worker** warry = nullptr;
	int* indexArr = nullptr;


	std::cout << "请选择员工编号或姓名：" << std::endl;
	std::cout << "1.按编号" << std::endl;
	std::cout << "2.按姓名" << std::endl;
	std::cout << std::endl;

	int choice = 0;
	std::cin >> choice;

	bool FindTF = false;
	int index = -1;


	if (choice==1)
	{	
		int id=0;

		std::cout << "请输入员工编号：" << std::endl;
		std::cin >> id;

		for (auto i = 0; i < allNum; i++)
		{
			if (arr[i]->get_id() == id)
			{
				std::wcout << "员工是：" << std::endl;
				arr[i]->showinfo();
				std::cout << std::endl;
				FindTF = true;
				return i;
				break;
			}
		}
		if (!FindTF)
		{
			std::cout << "不存在该编号的员工" << std::endl;
			return index;
		}
	}
	else if (choice == 2) {

		std::string name;

		std::cout << "请输入员工姓名：" << std::endl;
		std::cout << std::endl;
		std::cin >> name;

		std::cout << std::endl;

		/*Worker** warry = nullptr;
		int* indexArr = nullptr;*/

		int count = 0;
		
		for (auto i = 0; i < allNum; i++)
		{
			if (arr[i]->get_name() == name)
			{
				count++;
			}
		}

		std::cout << "一共找到" << count << "名员工：" << std::endl;

		if (count == 0) {
			std::cout << "没有这个人" << std::endl;
			std::cout << std::endl;
			this->clearScreen();
			return index;
		}

		////////////////////////////
		warry = new Worker * [count] {};
		indexArr = new int[count] {};
		int indexarr = 0;
		//
		for (auto i = 0; i < allNum; i++)
		{
			if (arr[i]->get_name() == name)
			{
				warry[indexarr] = arr[i];
				indexArr[indexarr] = i;
				indexarr++;
			}
		}

		for (auto i = 0; i < count; i++)
		{
			std::cout << "第" << i + 1 << "名员工信息：" << std::endl;
			warry[i]->showinfo();
			std::cout << std::endl;
		}
		
		int indexx = -1;

		while (true) {

			int select = 0;
			std::cout << "请选择要操作第几名员工：" << std::endl;
			std::cin >> select;

			if (select > 0 && select <= count)
			{
				indexx = indexArr[select - 1];
				std::cout << "你选择的员工信息是：" << std::endl;
				arr[indexx]->showinfo();
				std::cout << std::endl;
				//this->clearScreen();
				break;

			}
			else
			{
				std::cout << "输入错误，请重新输入：" << std::endl;
				this->inputClear();

			}

		}

		//std::cout << "indexx = " << indexx << std::endl;

		delete[] warry;
		delete[]indexArr;
		warry = nullptr;
		indexArr = nullptr;

		return indexx;
	}
	else
	{
		std::cout << "输入错误" << std::endl;

		return index;
	}

	return index;
}

//修改员工
void WorkManager::modify_Emy() {

	std::cout << "请先输入要修改的员工编号或姓名：" << std::endl;
	//this->Find_Emy();

	int result = this->Find_Emy();

	
	/*cout << "result = " << result << endl;
	cout << "allNum = " << allNum << endl;
	cout << "arr[result] 指针地址：" << arr[result] << endl;*/

	if (result!=-1)
	{
		int id = 0;
		
		//int oldId = arr[result]->get_id();
		//std::string oldName = arr[result]->get_name();


		while (true) {

			std::cout << "请输入要修改后员工编号：" << std::endl;

			std::cin >> id;

			if (id < 1) {
				std::cout << "输入错误，请重新输入：" << std::endl;
				this->inputClear();
				continue;
			}



			bool isIdNo = false;

			for (auto i = 0; i < allNum; i++)
			{
				if (i == result|| id == arr[i]->get_id()) {
					//continue;
					isIdNo = true;
					break;
				}

				/*if (id == arr[i]->get_id())
				{
					isIdNo = true;
					break;
				}*/
				
			}


			if (isIdNo)
			{
				std::cout << "id重复，请重新输入：" << std::endl;
				this->inputClear();
			}
			else if (!isIdNo)
			{
				break;
			}

		}

		int maxx=0;

		for (auto i = 0; i < allNum; i++)//找出最大id
		{
			if (arr[i]->get_id() > maxx) {
				maxx = arr[i]->get_id();
			}
		}

		if (id > maxx) {

			id = maxx;
			std::cout << "超出最大编号，已自动修改为最大编号 ，现在的id是：" << id << std::endl;

		}
		
		arr[result]->set_id(id);

		
		std::string name;

		std::cout << "请输入要修改后员工姓名：" << std::endl;

		std::cin >> name;

		arr[result]->set_name(name);

		// 循环直到输入有效的部门编号并创建对应对象
		Worker* worker = nullptr;

		while (true) {

			int DeptName = 0;

			std::cout << "请输入要修改后员工部门：" << std::endl;
			std::cout << "1.总裁，2.经理，3.员工" << std::endl;

			std::cin >> DeptName;

			switch (DeptName) {
			case 1:
				worker = new Boss(id, name);
				break;
			case 2:
				worker = new Manager(id, name);
				break;
			case 3:
				worker = new Employee(id, name);
				break;
			default:
				worker = nullptr;
				break;
			}

			if (worker != nullptr) {
				delete this->arr[result];
				this->arr[result] = worker;
				break;
			}

			std::cout << "输入错误，请重新选择部门编号" << std::endl;
			this->inputClear();
		}


		//修改的元素的后面元素，重新排列员工编号
		for (auto i = result + 1; i < allNum; i++)
		{

			arr[i]->set_id(arr[i]->get_id() - 1);

		}
	}

	std::cout << "修改成功" << std::endl;	


	this->sort();//排序后写入文件

	this->FRW.file_write(this->arr, this->allNum);

	/*system("pause");
	system("cls");*/
}

//删除员工
void WorkManager::delete_Emy() {

	std::cout << "请输入要删除的员工编号或姓名：" << std::endl;
	int tatal = this->Find_Emy();
	
	std::cout << "请确认是否是要删除的员工：" << std::endl;

	//arr[tatal]->showinfo();

	int isNo = 0;
	
	while (true) {
		
		std::cout << "1.是，0.否" << std::endl;
		std::cin >> isNo;
		
		if (isNo == 1) {

			if (tatal==-1)
			{
				std::cout << "没有找到员工，取消删除" << std::endl;
				this->clearScreen();
				return;
			}

			delete arr[tatal];

			for (auto i = tatal; i < allNum-1; i++)
			{
				arr[i] = arr[i + 1];
			}

			allNum--;

			std::cout << "删除成功" << std::endl;

			for (auto i = tatal; i < allNum; i++)
			{
				arr[i]->set_id(arr[i]->get_id() - 1);
			}

			std::cout << "已重新排列员工编号" << std::endl;

			this->FRW.file_write(this->arr, this->allNum);
			//this->clearScreen();
			break;
		}
		else if (isNo == 0)
		{
			std::cout << "不是要删除的员工" << std::endl;
			this->clearScreen();
			return;
		}
		else {
			std::cout << "输入错误，请重新选择" << std::endl;
			
			this->inputClear();
			this->clearScreen();
			
			return;

		}
	}

}

//文件总数
int WorkManager::get_num() {

	std::ifstream readf;
	readf.open(FiNm, std::ios::in);

	int id = 0;
	std::string name;
	std::string DeptName;

	int num = 0;
	while(readf>>id&&readf>>name&&readf>>DeptName)
	{
		num++;
	}

	readf.close();

	return num;

}

//清屏
void WorkManager::clearScreen() {
	
	system("pause");
	system("cls");

}

//排序
void WorkManager::sort() {

	for (auto i = 0; i < allNum; i++)
	{
		for (auto j = 0; j < allNum-i-1; j++)
		{
			if (arr[j]->get_id() > arr[j + 1]->get_id()) {

				Worker* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}

		}

	}

	std::cout << "排序成功" << std::endl;
	this->FRW.file_write(this->arr, this->allNum);
	this->clearScreen();
}

//清空文件
void WorkManager::clearFile() {

	if (allNum!=0)
	{
		for (auto i = 0; i < allNum; i++)
		{
			delete arr[i];
		}

		allNum = 0;

		this->FRW.file_write(this->arr, this->allNum);

		std::cout << "已清空所有文件数据" << std::endl;

		this->clearScreen();

	}
	else {

		std::cout << "文件为空" << std::endl;

		this->clearScreen();
	}

}

//输入缓冲区清理
void WorkManager::inputClear() {

	std::cin.clear();
	std::cin.ignore(1024, '\n');
}

//构造函数
WorkManager::WorkManager():allNum(0),arr(nullptr),FRW() {

	/*std::ifstream readf;

	readf.open(FiNm, std::ios::in);*/

	std::cout << "本列表一共有" << get_num() << "个员工" << std::endl;
	std::cout << std::endl;

	int total = get_num();


	if (total>0)
	{
			arr = new Worker * [total];
			allNum = total;
			FRW.file_read(arr, allNum);
	}
	else if (total == 0)
		{
			std::cout << "文件为空" << std::endl;
			FRW.FileNull = true;
			std::cout<<"请输入数据"<<std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
	}else{
		std::cout << "文件打开失败" << std::endl;
		FRW.FileNull = true;
		std::cout << "请输入数据以创建文件" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	//readf.close();

}

//析构函数
WorkManager::~WorkManager() {

	if (this->arr!=nullptr)
	{
		for (size_t i = 0; i < this->allNum; i++)
		{
			delete this->arr[i];
		}

		delete[] this->arr;

		this->arr = nullptr;
	}



}

