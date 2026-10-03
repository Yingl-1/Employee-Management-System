#pragma once
#include <fstream>
#include<string>
#include"Boss.h"
#include"Employee.h"
#include"Manager.h"
#include"Worker.h"

//class Worker;

const std::string FiNm = "员工数据.txt";

class File_Read_Write
{
public:

	void file_read(Worker**& arr, int& size);

	void file_write(Worker** arr, int size);

	bool FileNull;

};

