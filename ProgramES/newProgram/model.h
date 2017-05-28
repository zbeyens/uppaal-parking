#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int WORKERS = 2;

const int MONEY_MAX = 7;
int money = 1;

const int BUDGETS[3] = {1, 2, 3};
int budget = 1;

const int counter_max = 1;
int counter = 0;

const int EPS = 1;
const int T_WALK = 3;
const int T_BUS = 2;
const int T_CAR = 1;
const int T_SLEEP = 2;

const int T_WORK = 1;
const int GAIN = 1;
const int T_FEE = 10;
const int T_BURNOUT = 8;

int TMAX_WALK;
int TMAX_BUS;
int TMAX_CAR;
int TMAX_SLEEP;

typedef struct _w {
  int id;
  double t;
  double t_work;
  char *state;
} Worker;

typedef struct _wf {
  int id;
  double s;
  char *state;
} WorkerFee;

typedef struct _c {
  int id;
  char *state;
} Company;

void set_max_var();
void initialization(Worker **workers, WorkerFee **workerfees, Company *company);
void companyCase(Company *company);
void workerFeeCase(WorkerFee **workerFees);
void workerCase(Worker **workers);
int strategy(Worker **worker, WorkerFee **workerfee, Company *company);
int model();
int takeTransition(Worker *w, char *edge);
int rand_a_b(int a, int b);
void Home(Worker *w);
void Working(Worker *w);
void Break(Worker *w);
void sleep(Worker *w);
void Burnout(Worker *w);
void StartUp(Company *c);
void WorkingCompany(Company *c);
void Bankrupt(Company *c);
void Fee(WorkerFee *f);
void addMoney();
void giveMoney();

