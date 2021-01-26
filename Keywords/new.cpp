// NOTES : the new keyword is used to instanciate 4 bytes of memory on the heap

#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name;  }
};

int main()
{
	int a = 2;
	int* b = new int; // single 4-byte integer allocated memory
	int* c = new int[50]; // 50 * 4 = 200 bytes 
	Entity* e = new Entity[50]; // allocating 50 Entity in a row of memory
	
	Entity* e2 = new Entity(); // call the constructor
	Entity* e3 = (Entity*)malloc(sizeof(Entity)); // does not call the constructor
												  // allocate the memory for the object and gives back a pointer to that memory

	// Once you use the new keyword, you must also use delete
	// delete calls the destructor
	// the deallocation have to be done manyally by calling delete
	delete e2; // calls the function free(e) to free the block of memory that was allocated
	
	delete[] e; // the [] was necessary because new used them to allocate

}