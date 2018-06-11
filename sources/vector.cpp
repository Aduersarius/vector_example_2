#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
        size = 0;
	capacity = 0;
	els= nullptr;
}

vector_t::vector_t(vector_t const & other)
{
	capacity = other.capacity_();
	size = other.size_();
        els = new int [other.capacity_()];
	for (int i = 0; i < capacity; i++)
	els[i] = other.els[i];
}

vector_t & vector_t::operator =(vector_t const & other)
{
        for (int i = 0; i < other.size_(); i++)
		els[i] = other.els[i];
	size = other.size;
	capacity = other.capacity;
	
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{       if (capacity == other.capacity_()){
	for (int i = 0; i < capacity; i++)
		if (els[i] != other.els[i]) return false;
		return true;
        }
        return false;
}

vector_t::~vector_t()
{
       delete []els;
}

std::size_t vector_t::size_() const
{
    return size;
}

std::size_t vector_t::capacity_() const
{
    return capacity;
}

void vector_t::push_back(int value)
{
	if (!els) {
		size = 1;
		capacity = 1;
		els = new int [capacity];
		els[0] = value;
	}
	else {
	if (size == capacity){
		capacity *= 2;
		int* tmp = new int[capacity];
		for (int i = 0; i < size; i++)
	        tmp[i] = els[i];
		delete [] els;
		int* els = new int[capacity];
		for (int i = 0; i < size; i++)
	        els[i] = tmp[i];
		delete [] tmp;
		els[size] = value;
		size++;
	}
	else {  els[size] = value;
	        size++;
	     }
        }
}
void vector_t::pop_back()
{       if (size != 0) {
	size--;
	if (size <= (capacity/2)){
		capacity = capacity / 2;
		int* tmp = new int[capacity];
		for (int i = 0; i < size; i++)
	        tmp[i] = els[i];
		delete [] els;
		int* els = new int[capacity];
		for (int i = 0; i < size; i++)
	        els[i] = tmp[i];
		delete [] tmp;
	}
}	
}

int & vector_t::operator [](std::size_t index)
{
	return els[index];
}

int vector_t::operator [](std::size_t index) const
{
	return els[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	if (lhs == rhs) return false;
	else return true;
		
}
