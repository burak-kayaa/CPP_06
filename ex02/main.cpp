#include "Base.hpp"
#include "AClass.hpp"
#include "BClass.hpp"
#include "CClass.hpp"

Base	*generate()
{
	int		rand = std::rand() % 3;
	std::cout << "rand: " << rand << std::endl;
	if (rand == 0)
		return new A;
	else if (rand == 1)
		return new B;
	else
		return new C;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	identify(&p);
}


int	main()
{
	Base	*base = new Base();
	Base	*gen[10];

	for (int i = 0; i < 10; i++)
	{
		gen[i] = generate();
		identify(gen[i]);
	}
	for (int i = 0; i < 10; i++)
		delete gen[i];
	delete base;
}