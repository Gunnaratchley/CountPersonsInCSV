#pragma once
#include "Person.h"
class Iterator
{
public:
	typedef std::input_iterator_tag     iterator_category;
	typedef Person                      value_type;
	typedef std::size_t                 difference_type;
	typedef Person* pointer;
	typedef Person& reference;

	Iterator(std::istream& str) :m_str(str.good() ? &str : NULL) { ++(*this); }
	Iterator() :m_str(NULL) {}

	// Pre Increment
	Iterator& operator++();
	// Post increment
	Iterator operator++(int);
	Person const& operator*()	const;
	Person const* operator->()	const;

	bool operator==(Iterator const& rhs);
	bool operator!=(Iterator const& rhs);
private:
	std::istream* m_str;
	Person m_row;
};

