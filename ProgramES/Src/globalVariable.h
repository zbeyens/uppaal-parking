#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void set_max_var();

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
  int t;
  int t_work;
  char *state;
} Worker;

typedef struct _wf {
  int id;
  int s;
  char *state;
} WorkerFee;

typedef struct _c {
  int id;
  char *state;
} Company;
