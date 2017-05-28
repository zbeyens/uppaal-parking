#include "moves.h"

int takeTransition(Worker *w, char *edge) {
  int e1 = strcmp(
      edge, "counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
  int e2 = strcmp(edge, "t_work<T_BURNOUT,t:=0");
  int e3 = strcmp(edge, "t>=T_CAR&&t<=TMAX_CAR,t:=0");
  int e4 = strcmp(edge, "t>=T_BUS&&t<=TMAX_BUS,t:=0");
  int e5 = strcmp(edge, "t>=T_WALK&&t<=TMAX_WALK,t:=0");
  int e6 = strcmp(edge, "t_work<T_BURNOUT,t:=0,counter-=1");
  if (e1) {
    w->t = 0;
    w->t_work = 0;
    counter += 1;
  } else if (e2 || e3 || e4 || e5) {
    w->t = 0;
  }

  else if (e6) {
    counter -= 1;
    w->t = 0;
  }

  return 1;
}

int rand_a_b(int a, int b) {
  srand(time(NULL));
  return rand() % (b - a) + a;
}

void Home(Worker *w) {
  if (w->t_work >= T_BURNOUT) {
    w->state = "Burnout";
  }
}

void Working(Worker *w) {
  w->t += rand_a_b(0, T_WORK + 1);
  if (w->t > T_WORK) {
    w->t = T_WORK;
  }
  w->t_work += w->t;
  if (w->t == T_WORK) {
    w->t = 0;
    addMoney();
    w->state = "Break";
  }
}
void Break(Worker *w) {
  if (w->t_work >= T_BURNOUT) {
    w->state = "Burnout";
  }
}
void Sleep(Worker *w) {
  w->t += rand_a_b(0, TMAX_SLEEP + 1);
  if (w->t >= T_SLEEP) {
    w->t = 0;
    w->state = "Home";
  }
}
void Burnout(Worker *w) { w->state = "Burnout"; }
void StartUp(Company *c) {
  int n = rand_a_b(0, 3);
  budget = BUDGETS[n];
  c->state = "Working";
}

void WorkingCompany(Company *c) {
  if (money == 0) {
    c->state = "Bankrupt";
  }
}

void Bankrupt(Company *c) { c->state = "Bankrupt"; }

void Fee(WorkerFee *f) {
  f->s += rand_a_b(0, T_FEE + 1);
  if (f->s > T_FEE) {
    f->s = T_FEE;
  }
  if (f->s == T_FEE) {
    f->s = 0;
    giveMoney();
  }
}

void addMoney() {
  int temp = money;
  temp += GAIN;
  if (temp <= MONEY_MAX) {
    money = temp;
  } else {
    money = MONEY_MAX;
  }
}

void giveMoney() {
  int temp = money;
  temp -= budget;

  if (temp >= 0) {
    money = temp;
  } else {
    money = 0;
  }
}
