#include "Manager.h"

Manager::Manager(int id, std::string name):Worker(id,name) {
	

};

void Manager::showinfo() {
	std::cout << "职工id是:" << get_id()<< std::endl;
	std::cout << "职工姓名是:" << get_name() << std::endl;
	std::cout << "职工部门是:" << this->getDeptName() <<" " << "完成老板给的任务，并下发任务给员工" << std::endl;

};

std::string Manager::getDeptName() {

	return std::string("经理");
};