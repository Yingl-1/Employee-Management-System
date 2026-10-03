#pragma once
#include "Worker.h"
#include<iostream>
#include <string>
class Manager :
    public Worker
{
public:

	Manager(int id, std::string name);
	void showinfo() override;

	std::string getDeptName() override;

private:
	int DeptName = 2;

};

