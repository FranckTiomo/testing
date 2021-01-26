#include <iostream>
#include <string>

using namespace std;

class Entity
{
private:
	int m_X, m_Y;
	mutable int var; // var can be modified inside a const function
public:
	int GetX() const // promising that the function will not modify any attribute
	{
		var = 9;
		return m_X;
	}

	int setX(int x)
	{
		m_X = x;
	}
};

void PrintEntity(const Entity& e)
{
	/* The Entity reference must not change. GetX() is a constant function, so it can be called because it promises that
	Entity class wil not be modified. However, the function SetX() cannot be called because it is not constant */

	cout << e.GetX() << endl;
}

#if 0
int main()
{
	const int MAX_AGE = 90;

	const int* a = new int; // Cannot modify the content of that pointer but the value of the pointer can sill be modified
	int const* a1 = new int; // Same fonctionnality as const int*

	int* const a2 = new int; // Conversely, here, the content can change but the pointer cannot point to something else

	const int* const a3 = new int; // Cannot change the content and cannot change the actual pointer itself to point to something else

	/*
						WHAT I AM MODIFYING

						int* a = new int;

			1. THE CONTENT:	*a = 2; // referencing 'a' and assign it a value (contenu à l'adresse pointée par'a')

			2.	THE POINTER ITSELF: a = (int*)&MAX_AGE; // re-assigning the pointer so that it points to something else
									std::cout << *a << std::endl;
	*/

	/*
						HOW TO READ SOME DECLARATIONS

		->	const int * A; ==> "A is a pointer to an int that is constant."
			(or, depending on how you prefer to write it)
			int const* A; ==> "A is a pointer to a const int"

		->	int * const A; ==> "A is a const pointer to an int."
		->	const int* const A; ==> "A is a const pointer to an int that is constant".

	*/
	Entity e;
	PrintEntity(e);

	cin.get();
}
#endif