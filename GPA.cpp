#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
	
	char line[100];
	
	double time = 2.44523335;
	
	gcvt(time, 3, line);
	
	printf("%s", line);
	
	return 0;
} 
