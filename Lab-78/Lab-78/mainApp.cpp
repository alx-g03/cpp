#include "repository.h"
#include "service.h"
#include "UI.h"
#include "tests.h"

int main()
{
	testAll();
	Repository repo;
	Service service(repo);
	UI ui(service);
	ui.runMeniu();
	return 0;
}
