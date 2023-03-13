#include <iostream>
#include <assert.h>
#include "tranzactie.h"
#include "repository.h"
#include "service.h"

void testConstructorFaraParametri()
{
	Entitate t;
	assert((t.getZi() == 0) && (t.getSuma() == 0) && (t.getTip() == 0) && (t.getDescriere() == nullptr));
}

void testConstructorCuPametri()
{
	Entitate t(22, 100, 1, "incasare card");
	assert((t.getZi() == 22) && (t.getSuma() == 100) && (t.getTip() == 1) && (*t.getDescriere() == *"incasare card"));
}

void testConstructorDeCopiere()
{
	Entitate t1(22, 100, 1, "incasare card");
	Entitate t2(t1);
	assert((t2.getZi() == 22) && (t2.getSuma() == 100) && (t2.getTip() == 1) && (*t2.getDescriere() == *"incasare card"));
}

void testSetGet()
{
	Entitate t;
	t.setZi(22);
	t.setSuma(100);
	t.setTip(1);
	t.setDescriere("incasare card");
	assert((t.getZi() == 22) && (t.getSuma() == 100) && (t.getTip() == 1) && (*t.getDescriere() == *"incasare card"));
}

void testEqual()
{
	Entitate t1(22, 100, 1, "incasare card"), t2(15, 500, 0, "retragere numerar"), t3;
	t2 = t1;
	t3 = t1;
	assert(t1 == t2);
	assert(t2 == t3);
}

void testRepository()
{
	Entitate t0(1, 55, 0, "plata numerar");
	Entitate t1(22, 100, 1, "incasare card");
	Entitate t2(15, 500, 0, "retragere numerar");
	Entitate t3(3, 250, 0, "plata card");
	Entitate x1[] = { t1, t2, t3 };
	Entitate x2[] = { t2, t3 };
	Entitate x3[] = { t2, t1 };
	Repository repo, repoCopy;
	repo.add(t1);
	repo.add(t2);
	repo.add(t3);
	assert(repo.getSize() == 3);
	assert(repo.find(t0) == false);
	assert(repo.find(t1) == true);
	assert(repo.find(t2) == true);
	assert(repo.find(t3) == true);
	assert(*repo.getAll() == *x1);
	repo.remove(t1);
	assert(repo.getSize() == 2);
	assert(*repo.getAll() == *x2);
	repo.update(t3, t1);
	assert(repo.getSize() == 2);
	assert(*repo.getAll() == *x3);
	repo.remove(t1);
	assert(repo.getSize() == 1);
	assert(*repo.getAll() == t2);
	repoCopy = repo;
	assert(repoCopy == repo);
}

void testService()
{
	Entitate t1(22, 100, 1, "incasare card");
	Entitate t2(15, 500, 0, "retragere numerar");
	Entitate t3(3, 250, 0, "plata card");
	Entitate x1[] = { t1, t2, t3 };
	Entitate x2[] = { t2, t3 };
	Entitate x3[] = { t2, t1 };
	Repository repo;
	Service service(repo);
	service.addTranzactie(22, 100, 1, "incasare card");
	service.addTranzactie(15, 500, 0, "retragere numerar");
	service.addTranzactie(3, 250, 0, "plata card");
	assert(service.numberOfTransactions() == 3);
	assert(*service.getAllTransactions() == *x1);
	assert(service.findTranzactie(1, 55, 0, "plata numerar") == false);
	assert(service.findTranzactie(22, 100, 1, "incasare card") == true);
	assert(service.findTranzactie(15, 500, 0, "retragere numerar") == true);
	assert(service.findTranzactie(3, 250, 0, "plata card") == true);
	service.removeTranzactie(22, 100, 1, "incasare card");
	assert(service.numberOfTransactions() == 2);
	assert(*service.getAllTransactions() == *x2);
	service.updateTranzactie(3, 250, 0, "plata card", 22, 100, 1, "incasare card");
	assert(service.numberOfTransactions() == 2);
	assert(*service.getAllTransactions() == *x3);
	service.removeTranzactie(22, 100, 1, "incasare card");
	assert(service.numberOfTransactions() == 1);
	assert(*service.getAllTransactions() == t2);
}

void testAll()
{
	testConstructorFaraParametri();
	testConstructorCuPametri();
	testConstructorDeCopiere();
	testSetGet();
	testEqual();
	testRepository();
	testService();
	std::cout << "Toate testele au rulat cu succes!" << std::endl;
}
