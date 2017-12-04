
#include <string>
#include <boost/thread.hpp>
#include <boost/statechart/event.hpp>

namespace sc = boost::statechart;

class B
{
public:
	B();
	~B();

	void run();

private:
	void printType(const sc::event_base & ev);

};
