#include <stdio.h>

void function(char * p,int x)
{
	printf("p is %s and x is %d",p,x);
}

int main()
{
	char * v1 = "Hello";
	char * v2 = "World!";
	printf("Hello, World!\n");
	printf("%s %s\n",v1,v2);
	int x = 5;
	function(v1,x);
	return 0;
}