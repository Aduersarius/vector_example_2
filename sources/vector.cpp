#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t(int size {0}, int capacity {0}, els{NULL})
{
   
}

vector_t::vector_t(vector_t const & other)
{
	 capacity = other.capacity;
	size = other size;
         vector_t  vr = new vector_t [capacity];
	for (int i = 0; i < size; i++)
	{vr[i] = other.els[i];
}

vector_t & vector_t::operator =(vector_t const & other)
{
	vector_t  vr = new vector_t [other.capacity];
        for (int i = 0; i < other.size; i++)
		vr[i] = other.els[i];
	size = other.size;
	capacity = other.capacity;
	
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	vector_t  vr = new vector_t [other.capacity];
	for (int i = 0; i < other.capacity; i++){
		if (vr[i] != other.els[i]) return false;
		return true;
}

vector_t::~vector_t()
{
	return delete []vr;
}

std::size_t vector_t::size() const
{
    return size;
}

std::size_t vector_t::capacity() const
{
    return capacity;
}

void vector_t::push_back(int value)
{
	if (size == capacity){
		vector_t  vr = new vector_t[2*capacity];
		 for (int i = 0; i < size; i++)
		 {vr[i] = els[i];}
		vr[size + 1] = value;
	}
	else { vector_t  vr = new vector_t [capacity];
		 for (int i = 0; i < size; i++)
		 vr[i] = els[i];
		vr[size + 1] = value;
}

void vector_t::pop_back()
{
	if (size =< capacity/2){
		int vr = new int[capacity/2];
		for (int i = 0; i < size; i++)
		 {vr[i] = els[i];}
		size -= 1;
	}
	else {
		int vr = new int[capacity];
		size -= 1;
	}
		
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[0];
}

int vector_t::operator [](std::size_t index) const
{
	return 0;
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	if (lhs.capacity =< rhs.capacity){
	for (int i = 0; i < lhs.capacity; i++){
		if (rhs.els[i] != lhs.els[i]) return true;
		return false;}
	}
	else for (int i = 0; i < rhs.capacity; i++){
		if (rhs.els[i] != lhs.els[i]) return true;
		return false;}
		
}
