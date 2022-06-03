#include "Person.h"

std::string const& Person::operator[](std::size_t index) const
{
	return m_data[index];
}
std::size_t Person::size() const
{
	return m_data.size();
}
void Person::readNextRow(std::istream& str)
{
	std::string line;
	std::getline(str, line);
	std::stringstream lineStream(line);
	std::string cell;
	
	m_data.clear();
	while (std::getline(lineStream, cell, ','))
	{
		m_data.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		m_data.push_back("");
	}
}

std::istream& operator>>(std::istream& str, Person& data)
{
	data.readNextRow(str);
	return str;
}