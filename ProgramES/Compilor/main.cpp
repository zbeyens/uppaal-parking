#include "compilor.h"

int main (int argc, char *argv[]){
	if (argc < 2){
		std::cout<<"Input file missing"<<std::endl;
	}
	else{
		Compilor comp(argv[1]);
		
	}
	return 	0;
}