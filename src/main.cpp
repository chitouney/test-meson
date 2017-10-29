#include <stdio.h>
#include <unistd.h>

#include <a/a.h>

int main()
{
	printf("hello word\n");

	A a;
	printf("current date %s\n", a.date().c_str());

	sleep(10);

	return 0;
}


