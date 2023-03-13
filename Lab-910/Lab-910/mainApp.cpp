#include "UI.h"

int main()
{
	RepoFile repo("produse.txt");
	RepoFileValuta repoFileValuta("valute.txt");
	Service service(repo, repoFileValuta);
	UI ui(service);
	ui.runMeniu();
	return 0;
}
