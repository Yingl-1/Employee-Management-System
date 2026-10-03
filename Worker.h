#pragma once
#include<string>
//抽象父类
class Worker
{
public:

	//显示个人信息
	virtual void showinfo()=0;
	
	virtual std::string getDeptName() =0;

	//虚析构
	virtual  ~Worker()=default;

	int set_id(int id);

	std::string set_name(std::string name);


	Worker(int id,std::string name);

	int get_id();
	
	std::string get_name();

private:

	int id=0;
	std::string name;
	
};

