#include <iostream>

int main()
{
	std::cout << "Hello World!\n";

	std::string r = "some_text";
	r[0] = toupper(r[0]);
	std::cout << r;
	return 0;
}
