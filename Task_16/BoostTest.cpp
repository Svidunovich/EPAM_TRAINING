#define BOOST_TEST_MODULE classQueue
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

BOOST_AUTO_TEST_SUITE(classQueue)

BOOST_AUTO_TEST_CASE(push)
{
	Queue<int> q;
	q.push(1);
    BOOST_REQUIRE( q.front() == 1 );
}

BOOST_AUTO_TEST_CASE(empty)
{
	Queue<int> q;
	BOOST_REQUIRE( q.empty() == false );
}

BOOST_AUTO_TEST_CASE(find)
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	BOOST_CHECK(q.find(2) == 2);
}

BOOST_AUTO_TEST_SUITE_END()
