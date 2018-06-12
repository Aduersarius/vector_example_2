#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("creating vector")
{
	vector_t<int> vector;
	REQUIRE( vector.size_() == 0 );
	REQUIRE( vector.capacity_() == 0 );
}

TEST_CASE("copying vector")
{
	vector_t<int> vector;
	vector.push_back(1);

	vector_t<int> copy(vector);
	REQUIRE( copy == vector );
}

TEST_CASE("assigning vector")
{
	vector_t<int> vector1;
	vector_t<int> vector2;

	vector1.push_back(1);
	vector2.push_back(2);

	vector1 = vector2;
	REQUIRE( vector1 == vector2 );
}

TEST_CASE("equaling vector")
{
	vector_t<int> vector1;
	vector_t<int> vector2;

	vector1.push_back(1);
	vector2.push_back(1);

	REQUIRE( vector1 == vector2 );

	vector1.push_back(2);
	REQUIRE( vector1 != vector2 );
}

TEST_CASE("indexing vector")
{
	vector_t<int> vector;

	vector.push_back(1);

	REQUIRE( vector[0] == 1 );

	vector_t<int> const copy(vector);
	REQUIRE( copy[0] == 1 );
}

TEST_CASE("pushing elements")
{
	vector_t<int> vector;

	vector.push_back(1);
	REQUIRE( vector.size_() == 1 );
	REQUIRE( vector.capacity_() == 1 );

	vector.push_back(2);
	REQUIRE( vector.size_() == 2 );
	REQUIRE( vector.capacity_() == 2 );

	vector.push_back(3);
	REQUIRE( vector.size_() == 3 );
	REQUIRE( vector.capacity_() == 4 );

	vector.push_back(4);
	REQUIRE( vector.size_() == 4 );
	REQUIRE( vector.capacity_() == 4 );

	vector.push_back(5);
	REQUIRE( vector.size_() == 5 );
	REQUIRE( vector.capacity_() == 8 );
}

TEST_CASE("poping elements")
{
	vector_t<int> vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	vector.push_back(6);

	vector.pop_back();
	REQUIRE( vector.size_() == 5 );
	REQUIRE( vector.capacity_() == 8 );

	vector.pop_back();
	REQUIRE( vector.size_() == 4 );
	REQUIRE( vector.capacity_() == 8 );

	vector.pop_back();
	REQUIRE( vector.size_() == 3 );
	REQUIRE( vector.capacity_() == 8 );

	vector.pop_back();
	REQUIRE( vector.size_() == 2 );
	REQUIRE( vector.capacity_() == 4 );

	vector.pop_back();
	REQUIRE( vector.size_() == 1 );
	REQUIRE( vector.capacity_() == 2 );

	vector.pop_back();
	REQUIRE( vector.size_() == 0 );
	REQUIRE( vector.capacity_() == 1 );
}

TEST_CASE("type_testing")
{
  	vector_t<int> vector;
	vector_t<float> vector1;
    	vector_t<double> vector2;
    	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	vector.push_back(6);

	vector.pop_back();
	REQUIRE( vector.size_() == 5 );
	REQUIRE( vector.capacity_() == 8 );

	vector.pop_back();
	REQUIRE( vector.size_() == 4 );
	REQUIRE( vector.capacity_() == 8 );

	vector.pop_back();
	REQUIRE( vector.size_() == 3 );
	REQUIRE( vector.capacity_() == 8 );

	vector.pop_back();
	REQUIRE( vector.size_() == 2 );
	REQUIRE( vector.capacity_() == 4 );

	vector.pop_back();
	REQUIRE( vector.size_() == 1 );
	REQUIRE( vector.capacity_() == 2 );

	vector.pop_back();
	REQUIRE( vector.size_() == 0 );
 	REQUIRE( vector.capacity_() == 1 ); 
    	vector1.push_back(1);
	vector1.push_back(2);
	vector1.push_back(3);
	vector1.push_back(4);
	vector1.push_back(5);
	vector1.push_back(6);

	vector1.pop_back();
	REQUIRE( vector1.size_() == 5 );
	REQUIRE( vector1.capacity_() == 8 );

	vector1.pop_back();
	REQUIRE( vector1.size_() == 4 );
	REQUIRE( vector1.capacity_() == 8 );

	vector1.pop_back();
	REQUIRE( vector1.size_() == 3 );
	REQUIRE( vector1.capacity_() == 8 );

	vector1.pop_back();
	REQUIRE( vector1.size_() == 2 );
	REQUIRE( vector1.capacity_() == 4 );

	vector1.pop_back();
	REQUIRE( vector1.size_() == 1 );
	REQUIRE( vector1.capacity_() == 2 );

	vector1.pop_back();
	REQUIRE( vector1.size_() == 0 );
 	REQUIRE( vector1.capacity_() == 1 );
	vector2.push_back(1);
	vector2.push_back(2);
	vector2.push_back(3.4435647);
	vector2.push_back(4);
	vector2.push_back(5);
	vector2.push_back(6);

	vector2.pop_back();
	REQUIRE( vector2.size_() == 5 );
	REQUIRE( vector2.capacity_() == 8 );

	vector2.pop_back();
	REQUIRE( vector2.size_() == 4 );
	REQUIRE( vector2.capacity_() == 8 );

	vector2.pop_back();
	REQUIRE( vector2.size_() == 3 );
	REQUIRE( vector2.capacity_() == 8 );

	vector2.pop_back();
	REQUIRE( vector2.size_() == 2 );
	REQUIRE( vector2.capacity_() == 4 );

	vector2.pop_back();
	REQUIRE( vector2.size_() == 1 );
	REQUIRE( vector2.capacity_() == 2 );

	vector2.pop_back();
	REQUIRE( vector2.size_() == 0 );
 	REQUIRE( vector2.capacity_() == 1 ); 
}

TEST_CASE("Exception"){
   vector_t<int> vector;
   vector.push_back(1);
   vector.push_back(2);
   int a;
   REQUIRE_NOTHROW(a = vector[1]);
}
