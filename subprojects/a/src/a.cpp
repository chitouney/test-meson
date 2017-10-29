
#include <stdio.h>
#include <sstream>
#include <iostream>

#include <boost/chrono.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "a/a.h"

namespace pt = boost::posix_time;

void wait(int seconds)
{
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread()
{
  for (int i = 0; i < 100; ++i)
  {
    wait(1);
    std::cout << "A thread running count: "<< i << '\n';
  }
}

A::A():
		mt(thread)
{
	mt.detach();
}

A::~A()
{
	mt.interrupt();
}

std::string A::date()
{
	pt::ptime now = pt::second_clock::local_time();
	std::stringstream ss;
	ss << static_cast<int>(now.date().month()) << "/" << now.date().day()
	    << "/" << now.date().year();
	return ss.str();
}
