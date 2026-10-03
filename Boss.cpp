#include "Boss.h"

Boss::Boss(int id, std::string name) :Worker(id, name) {

}

void Boss::showinfo() {
	std::cout << "职工id是:" << get_id() << std::endl;
	std::cout << "职工姓名是:" << get_name() << std::endl;
	std::cout << "职工部门是:" << this->getDeptName() <<" " << "管理公司事务" << std::endl;

};

std::string Boss::getDeptName() {

	return std::string("总裁");
};