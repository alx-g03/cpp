#include "UI.h"

int main()
{
	Incapere i1(5, "rapid");
	Incapere i2(2, "mediu");
	Incapere i3(20, "rapid");

	RobotTemplate<Incapere> robot;

	robot.add(i1);
	robot.add(i2);
	robot.add(i3);

	Service service(robot);
	UI ui(service);
	ui.runMeniu();
	return 0;
}
