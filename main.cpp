#include <iostream>

#include "Iterator.h"
#include "Person.h"

int main()
{
	Person row;
	std::ifstream file("FakeNames.csv");
	std::string dummyline;
	std::getline(file, dummyline);

	auto count = 0;
	for (Iterator loop(file); loop != Iterator(); ++loop)
	{
		//std::cout << "1st Element(" << (*loop)[0] << ")\n";
		count++;
	}
	std::ofstream fout ("summary.txt");
	fout << "Collection contains " << count << " records" << std::endl;
	fout << std::endl;
	
	//fout << "First person: " << (*loop)[0] << std::endl;
	fout.close();
	return 0;
}