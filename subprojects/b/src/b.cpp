
#include <stdio.h>
#include <sstream>
#include <iostream>

#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/custom_reaction.hpp>

#include "b/b.h"

namespace mpl = boost::mpl;


struct EvMisc : sc::event<EvMisc>
{
	EvMisc()
	{
	}

	virtual ~EvMisc()
	{
	}

	std::string name() const { return "EvtMisc"; }
};


B::B()
{
}

B::~B()
{
}

void B::run()
{
	EvMisc* evt = new EvMisc();
	printType(*evt);
	delete evt;
}

void B::printType(const sc::event_base & ev)
{
	std::cout << "event:" << ev.custom_dynamic_type_ptr<EvMisc>()->name() << "\n" << std::endl;
}

