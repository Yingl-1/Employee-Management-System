#pragma once
#include "Worker.h"
#include <string>
#include<iostream>

class Boss :
    public Worker
{
public:

	Boss(int id, std::string name);
	void showinfo() override;

	std::string getDeptName() override;

private:
	int DeptName = 1;
};

