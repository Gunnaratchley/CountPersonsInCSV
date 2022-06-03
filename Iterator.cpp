#include "Iterator.h"
#include "Person.h"

Iterator& Iterator::operator++() 
{ if (m_str) { if (!((*m_str) >> m_row)) { m_str = NULL; } }return *this; }

Iterator Iterator::operator++(int)
{ Iterator    tmp(*this); ++(*this); return tmp; }

Person const& Iterator::operator*()   const
{ return m_row; }
Person const* Iterator::operator->()  const
{ return &m_row; }

bool Iterator::operator==(Iterator const& rhs) 
{ return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL))); }
bool Iterator::operator!=(Iterator const& rhs) 
{ return !((*this) == rhs); }

