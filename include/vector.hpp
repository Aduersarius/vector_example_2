#include <iostream>
template <class T>
class vector_t
{
private:
	T * els;
	std::size_t size;
	std::size_t capacity;
public:
	vector_t();
	vector_t(vector_t const & other);
	vector_t & operator =(vector_t const & other);
	~vector_t();

	std::size_t size_() const;
	std::size_t capacity_() const;
	
	T & at(std::size_t index) const;

	void push_back(int value);
	void pop_back();

	T & operator [](std::size_t index);
	T operator [](std::size_t index) const;

	bool operator ==(vector_t const & other) const;
};

bool operator !=(vector_t const & lhs, vector_t const & rhs);
