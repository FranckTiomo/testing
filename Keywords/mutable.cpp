#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0; // table allows constant methods to modify the value.
public:
	const std::string& GetName() const
	{
		m_DebugCount++;
		return m_Name;
	}
};

#if 0
int main()
{
	const Entity e; // this instance can just call functions that are marked const
	e.GetName();

	int x = 8;

	// [=] : x is passed by value; [&] : x is passed by reference
	auto f = [=]() mutable// mutable allows the lambda function to change the parameter
	{						// that is passed by value

		x++;
		std::cout << x << std::endl;
	};

	f();
	// x = 8 (x has not changed because it was not passed by reference )

	std::cin.get();
}
#endif