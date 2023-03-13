#include "service.h"

Service::Service() {}

Service::Service(const RobotTemplate<Incapere>& r)
{
	this->robot = r;
}

Service::~Service() {}

bool Service::removeIncapere(int timp, char* mod)
{
	Incapere i(timp, mod);
	return this->robot.remove(i);
}

std::vector<Incapere> Service::getAll()
{
	return this->robot.getAll();
}
