#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "Queue.cpp"
/*
test_suite* init_unit_test_suite( int , char* [] )
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	framework::master_test_suite().
		add(BOOST_TEST_CASE(BOOST_CHECK(true)));
	
	framework::master_test_suite().
		add(BOOST_TEST_CASE(BOOST_CHECK( q.front() == 1)));
	return 0;
}
*/


BOOST_AUTO_TEST_CASE( testOne )
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

    BOOST_CHECK( q.front() == 1 );
    BOOST_CHECK( q.back() == 3 ); 
	q.pop();
	q.pop();
	BOOST_CHECK( q.empty() == true );
	q.pop();
	BOOST_CHECK( q.empty() == true );
}

BOOST_AUTO_TEST_CASE( testTwo )
{
	Queue<int> q;
	BOOST_CHECK( q.empty() == false );
}
