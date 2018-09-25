#include <iostream>
#include "Shared_ptr.hpp"
#define q(x)x*x;

class Person
{
	int age;
	char* pName;

public:
	Person(): pName(0),age(0)
	{
	}
	Person(char* pName, int age): pName(pName), age(age)
	{
	}
	~Person()
	{
	}

	void Display()
	{
		printf("Name = %s Age = %d \n", pName, age);
	}
	void Shout()
	{
		printf("Ooooooooooooooooo");
	}
};


int main()
{

	Shared_ptr<Person> p(new Person("Scott", 25));
	Shared_ptr<Person> v(std::move(Shared_ptr<Person>(new Person("Josh", 30))));
	p->Display();
	{
		Shared_ptr<Person> q = p;
		q->Display();
		// Destructor of q will be called here..

		Shared_ptr<Person> r;
		r = p;
		r->Display();
		// Destructor of r will be called here..
	}
	p->Display();
	// Destructor of p will be called here
	// and person pointer will be deleted
	int i = 2;
	int b  = q(++i);
	std::cout <<  b << std::endl;
	return 0;
}