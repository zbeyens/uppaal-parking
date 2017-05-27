#include "globalVariable.h"

typedef struct{
	int id;
	int t;
	int t_work;
	char* state;
}Worker;

typedef struct{
	int id;
	int s;
	char* state;
}WorkerFee;

typedef struct{
	int id;
	char* state;
}Company;