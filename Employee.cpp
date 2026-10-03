#include "Employee.h"

Employee::Employee(int id, std::string name) :Worker(id,name){
	
	
	};
	
void Employee::showinfo() {
	std::cout << "职工id是:" << get_id() << std::endl;
	std::cout << "职工姓名是:" << get_name() << std::endl;
	std::cout << "职工部门是:" << this->getDeptName() <<" " << "完成经理给的任务" << std::endl;

};

std::string Employee::getDeptName() {

	return std::string("普通员工");
};