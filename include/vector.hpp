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



template <typename T>

vector_t<T>::vector_t()

{

        size = 0;

	capacity = 0;

	els= nullptr;

}



template <typename T>

vector_t<T>::vector_t(vector_t const & other)

{

	capacity = other.capacity_();

	size = other.size_();

        els = new T [other.capacity_()];

	for (std::size_t i = 0; i < capacity; i++)

	els[i] = other.els[i];

}



template <typename T>

T & vector_t<T>::at(std::size_t index) const

{

    if(index >= capacity){

        throw "Выход за пределы массива!"; 

    }

    return els[index];

}



template <typename T>

vector_t<T> & vector_t<T>::operator =(vector_t const & other)

{

	if (this != &other) {

		delete [] els;

		els = new T [other.capacity_()];

        for (std::size_t i = 0; i < other.size_(); i++)

		els[i] = other.els[i];

	size = other.size_();

	capacity = other.capacity_();

	}

	return *this;

}



template <typename T>

bool vector_t<T>::operator ==(vector_t const & other) const

{       if (size == other.size_()){

	for (std::size_t i = 0; i < size; i++)

		if (els[i] != other.els[i]) return false;

		return true;

        }

        return false;

}



template <typename T>

vector_t<T>::~vector_t()

{

       delete []els;

}



template <typename T>

std::size_t vector_t<T>::size_() const

{

    return size;

}



template <typename T>

std::size_t vector_t<T>::capacity_() const

{

    return capacity;

}



template <typename T>

void vector_t<T>::push_back(T value)

{

	if (!els) {

		size = 1;

		capacity = 1;

		els = new T [capacity];

		els[0] = value;

	}

	else {

	if (size == capacity){

		size++;

		capacity *= 2;

     		T* tmp = new T[capacity];

		for (std::size_t i = 0; i < size; i++)

	        tmp[i] = els[i];

		delete [] els;

		els = new T[capacity];

		for (std::size_t i = 0; i < size-1; i++)

	        els[i] = tmp[i];

		delete [] tmp;

		els[size-1] = value;

	}

	else {  els[size] = value;

	        size++;

	     }

        }

}



template <typename T>

void vector_t<T>::pop_back()

{       if (size != 0) {

	size--;

	if (size <= (capacity/4)){

		capacity = capacity / 2;

		T* tmp = new T[capacity];

		for (std::size_t i = 0; i < size; i++)

	        tmp[i] = els[i];

		delete [] els;

		els = new T[capacity];

		for (std::size_t i = 0; i < size; i++)

	        els[i] = tmp[i];

		delete [] tmp;

	}

}	

}



template <typename T>

T & vector_t<T>::operator [](std::size_t index)

{

	return els[index];

}



template <typename T>

T vector_t<T>::operator [](std::size_t index) const

{

	return els[index];

}



template <typename T>

bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs)

{

	if (lhs == rhs) return false;

	else return true;

		

}
