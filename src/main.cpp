#include <stdio.h>
#include <unistd.h>

#include <a/a.h>
#include <b/b.h>


int main()
{
	printf("hello word\n");

	B b;
	b.run();

	A a;
	printf("current date %s\n", a.date().c_str());
	sleep(10);

	return 0;
}
