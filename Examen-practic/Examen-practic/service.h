#ifndef SERVICE_H
#define SERVICE_H

#include "incapere.h"
#include "robot_template.h"

class Service {
private:
	RobotTemplate<Incapere> robot;
public:
	Service();
	Service(const RobotTemplate<Incapere>& r);
	~Service();
	bool removeIncapere(int timp, char* mod);
	std::vector<Incapere> getAll();
};

#endif