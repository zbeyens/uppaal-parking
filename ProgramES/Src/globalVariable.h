#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int WORKERS = 2;

const int MONEY_MAX = 7;
int money = 1;

const int BUDGETS[3] = {1,2,3};
int budget = 1;

const int counter_max = 1;
int counter = 0;

const int EPS = 1;
const int T_WALK=3;
const int T_BUS=2;
const int T_CAR=1;
const int T_SLEEP = 2;
const int TMAX_WALK=4;
const int TMAX_BUS=3;
const int TMAX_CAR=2;
const int TMAX_SLEEP = 3;

const int T_WORK = 1;
const int GAIN = 1;
const int T_FEE = 10;
const int T_BURNOUT = 8;