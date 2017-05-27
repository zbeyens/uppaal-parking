#include "character.h"

int takeTransition(Worker *w, char* edge);
int rand_a_b(int a, int b);
void Home(Worker *w);
void Working(Worker *w);
void Break(Worker *w);
void Sleep(Worker *w);
void Burnout(Worker *w);
void StartUp(Company *c);
void WorkingCompany(Company *c);
void Bankrupt(Company *c);
void Fee(WorkerFee *f);
void addMoney();
void giveMoney();