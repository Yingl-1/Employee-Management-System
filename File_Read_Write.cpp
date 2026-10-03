#include "File_Read_Write.h"

//File_Read_Write FRW;

//read file
void File_Read_Write:: file_read(Worker**& arr, int &size) {

	std::ifstream readf;
	readf.open( FiNm, std::ios::in);

	/*if (!readf.is_open())
	{
		std::cout << "打开失败" << std::endl;

		arr = nullptr;
		this->FileNull = true;
		size = 0;

		readf.close();

		return;
	}*/

	int id;
	std::string name;
	std::string DeptName;

	int i = 0;

	while ((readf >> id >> name >> DeptName)&&(i<size)) {

		if (DeptName == "总裁")
		{
			arr[i] = new Boss(id, name);    // 在堆创建Boss对象，指针存入数组
		}
		else if (DeptName =="经理")
		{
			arr[i] = new Manager(id, name); // 在堆创建Manager对象
		}
		else if (DeptName == "普通员工")
		{
			arr[i] = new Employee(id, name);// 在堆创建Employee对象
		}

		i++;
		
	}

	readf.close();

}

//write file
void File_Read_Write::file_write(Worker** arr,int size) {

	std::ofstream writef;
	writef.open(FiNm, std::ios::out);

	if (!writef.is_open())
	{
		std::cout << "打开失败" << std::endl;
		return;
	}



	for (size_t i = 0;i < size; i++) {

		writef << arr[i]->get_id() <<" " << arr[i]->get_name()<<" " << arr[i]->getDeptName() << std::endl;

	}

	writef.close();

}
