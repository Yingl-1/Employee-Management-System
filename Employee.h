#pragma once
#include"Worker.h"
#include <string>
#include<iostream>
class Employee:public Worker
{
public:

	Employee(int id, std::string name);
	void showinfo() override;
		
	std::string getDeptName() override ;
	
private:
	int DeptName = 3;

};

