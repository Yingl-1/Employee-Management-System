#include"Worker.h"

int Worker:: get_id()
{
	return id;
}

std::string  Worker::get_name() {

	return name;
}

int Worker::set_id(int id)
{
	this->id = id;
	return id;
}

std::string  Worker::set_name(std::string name) {
	
	this->name = name;
	return name;
}



Worker::Worker(int id, std::string name) {

	this->id = id;
	this->name = name;

}