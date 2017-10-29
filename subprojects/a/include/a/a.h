
#include <string>
#include <boost/thread.hpp>


class A
{
public:
	A();
	~A();

	std::string date();

private:
	boost::thread mt;
};
