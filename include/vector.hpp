#include <iostream>
template <typename T>
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

	void push_back(T value);
	void pop_back();

	T & operator [](std::size_t index);
	T operator [](std::size_t index) const;

	bool operator ==(vector_t const & other) const;
};
template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs);
