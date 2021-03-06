#include "model.h"

void set_max_var() {
  TMAX_WALK = T_WALK + EPS;
  TMAX_BUS = T_BUS + EPS;
  TMAX_CAR = T_CAR + EPS;
  TMAX_SLEEP = T_SLEEP + EPS;
}

int main() {
  // initialization
  FILE *fp;

   fp = fopen("../result.txt", "w+");

  Worker **workers = malloc(2 * sizeof(Worker));
  WorkerFee **workerFees = malloc(2 * sizeof(WorkerFee));
  for (int i = 0; i < 2 ; i++) {
    workers[i] = malloc(sizeof(Worker));
	workerFees[i] = malloc(sizeof(WorkerFee));
	}
  Company *company= malloc(sizeof(Company));
  set_max_var();
  initialization(workers, workerFees, company);
  int i =0;
  double step = 1;
  int f =0;
  while (i < 100) {
	fprintf(fp,"State System (%d):\n",i);
	fprintf(fp,"money = %d\n",money);
	fprintf(fp,"budget = %d\n", budget);
	fprintf(fp,"counter = %d\n", counter);
	fprintf(fp,"worker (%i)\n", workers[0]->id);
	fprintf(fp,"\tstate : %s,", workers[0]->state);
	fprintf(fp,"\tt= %f,", workers[0]->t);
	fprintf(fp,"\tWork time = %f\n\n", workers[0]->t_work);
	fprintf(fp,"worker (%i)\n", workers[1]->id);
	fprintf(fp,"\tstate : %s,", workers[1]->state);
	fprintf(fp,"\tt= %f,", workers[1]->t);
	fprintf(fp,"\tWork time = %f\n\n", workers[1]->t_work);
	fprintf(fp,"workerfee (%d)\n", workerFees[0]->id);
	fprintf(fp,"\ts = %f\n\n", workerFees[0]->s);
	fprintf(fp,"workerfee (%d)\n", workerFees[1]->id);
	fprintf(fp,"\ts = %f\n\n", workerFees[1]->s);
	fprintf(fp,"Company:\n\tstate: %s\n\n", company->state);
	int environnement =1;
	while (environnement != 0){
		int i1 = workerCase1(workers,0);
		int i2 = workerCase1(workers,1);
		int i3 = companyCase(company);
		workerFeeCase(workerFees);
		environnement = i1+i2+i3;
		f++;
	}
	char* previous_state0 = workers[0]->state;
	char* previous_state1 = workers[1]->state;
	while (strategy(workers, workerFees, company) == 1) {
		if (strcmp(previous_state0, "Break") && strcmp(workers[0]->state, "Working")){
			rework += 1;
			previous_state0 = workers[0]->state;
		}
		if (strcmp(previous_state1, "Break") && strcmp(workers[1]->state, "Working")){
			rework1 += 1;
			previous_state1 = workers[1]->state;
		}
		f++;
	}
	
	workers[0]->t += step;
	workers[1]->t += step;
	workers[0]->t_work += step;
	workers[1]->t_work += step;
	workerFees[0] ->s += step;
	workerFees[1] ->s += step;
     
    i++;
  }
  for (int i = 0; i <2; i++) {
    free(workers[i]);
	free(workerFees[i]);
	}
	free(workers);
	free(workerFees);
	free(company);
	fprintf(fp, "Walk: %i\n", take_walk);
	fprintf(fp, "Bus: %i\n", take_bus);
	fprintf(fp, "Car: %i\n", take_car);
	fprintf(fp, "rework worker0: %i %\n", rework);
	fprintf(fp, "rework worker1: %i %\n", rework1);
	fprintf(fp, "number of modification: %i\n", f);
	
	fclose(fp);
	return 0;
}

void initialization(Worker **workers, WorkerFee **workerFees,
                    Company *company) {
  workers[0]->id = 0;
  workers[0]->state = "Home";
  workers[0]->t_work = 0;
  workers[0]->t = 0;
  workers[1]->id = 1;
  workers[1]->state = "Home";
  workers[1]->t_work = 0;
  workers[1]->t = 0;
  workerFees[0]->id = 0;
  workerFees[0]->s = 0;
  workerFees[0]->state = "Fee";
  workerFees[1]->id = 1;
  workerFees[1]->s = 0;
  workerFees[1]->state = "Fee";
  company->id = 0;
  company->state = "StartUp";
}

int workerCase1(Worker **workers, int a){
	int i = 0;
	int ans =0;
	//int a = rand_a_b(0,2);
	if (strcmp(workers[a]->state, "Home")==0 && i == 0) {
		Home(workers[a]);
		if (strcmp(workers[a]->state, "Home")!=0){ans = 1;}
		i++;
	}
	if (strcmp(workers[a]->state,"Outside")==0 && i ==0){i++;}
	if (strcmp(workers[a]->state, "Working")==0 && i == 0) {
		Working(workers[a]);
		if (strcmp(workers[a]->state, "Working")!=0){ans = 1;}
		i++;
	}
	if (strcmp(workers[a]->state, "Break")==0 && i == 0) {
		Break(workers[a]);
		if (strcmp(workers[a]->state, "Break")!=0){ans = 1;}
		i++;
	}
	if (strcmp(workers[a]->state, "Sleep")==0 && i == 0) {
		sleep(workers[a]);
		if (strcmp(workers[a]->state, "Sleep")!=0){ans = 1;}
		i++;
    }
	if (strcmp(workers[a]->state, "Burnout")==0 && i == 0) {
      Burnout(workers[a]);
      i++;
    }
		
	return ans;
	
}

void workerCase(Worker **workers) {
  int i1 = 0;
  int i2 = 0;
  if ((i1 == 0 && i2 == 0) && (strcmp(workers[0]->state, "Home")==0 ||
                               strcmp(workers[1]->state, "Home")==0)) {
    if (strcmp(workers[0]->state, "Home")==0 && i1 == 0) {
      Home(workers[0]);
      i1++;
    }
    if (strcmp(workers[1]->state, "Home")==0 && i2 == 0) {
      Home(workers[1]);
      i2++;
    }
  }
  if ((i1 == 0 && i2 == 0) && (strcmp(workers[0]->state,"Outside")==0 ||
  strcmp(workers[1]->state,"Outside"))){
          if (strcmp(workers[0]->state,"Outside")==0 && i1 ==
  0){i1++;}
          if (strcmp(workers[1]->state,"Outside")==0 && i2 ==
  0){i2++;}
  }

  if ((i1 == 0 && i2 == 0) && (strcmp(workers[0]->state, "Working")==0 ||
                               strcmp(workers[1]->state, "Working")==0)) {
    if (strcmp(workers[0]->state, "Working")==0 && i1 == 0) {
		Working(workers[0]);
		i1++;
    }
    if (strcmp(workers[1]->state, "Working")==0 && i2 == 0) {
		Working(workers[1]);
		i2++;
    }
  }
  if ((i1 == 0 && i2 == 0) && (strcmp(workers[0]->state, "Break")==0 ||
                               strcmp(workers[1]->state, "Break")==0)) {
    if (strcmp(workers[0]->state, "Break")==0 && i1 == 0) {
		Break(workers[0]);
		i1++;
    }
    if (strcmp(workers[1]->state, "Break")==0 && i2 == 0) {
		Break(workers[1]);
		i2++;
    }
  }
  if ((i1 == 0 && i2 == 0) && (strcmp(workers[0]->state, "Sleep")==0 ||
                               strcmp(workers[1]->state, "Sleep")==0)) {
    if (strcmp(workers[0]->state, "Sleep")==0 && i1 == 0) {
		sleep(workers[0]);
		i1++;
    }
    if (strcmp(workers[1]->state, "Sleep")==0 && i2 == 0) {
		sleep(workers[1]);
		i2++;
    }
  }
  if ((i1 == 0 && i2 == 0) && (strcmp(workers[0]->state, "Burnout")==0 ||
                               strcmp(workers[1]->state, "Burnout")==0)) {
    if (strcmp(workers[0]->state, "Burnout")==0 && i1 == 0) {
      Burnout(workers[0]);
      i1++;
    }
    if (strcmp(workers[1]->state, "Burnout")==0 && i2 == 0) {
      Burnout(workers[1]);
      i2++;
    }
  }
}

void workerFeeCase(WorkerFee **workerFees) {
  Fee(workerFees[0]);
  Fee(workerFees[1]);
}

int companyCase(Company *company) {
  int i = 0;
  int ans = 0;
  if (i == 0 && strcmp(company->state, "StartUp")==0) {
    StartUp(company);
	if (strcmp(company->state, "StartUp")!=0){ans = 1;}
    i++;
  }
  if (i == 0 && strcmp(company->state, "Working")==0) {
    WorkingCompany(company);
	if (strcmp(company->state, "Working")!=0){ans = 1;}
    i++;
  }
  if (i == 0 && strcmp(company->state, "Bankrupt")==0) {
    Bankrupt(company);
    i++;
  }
  return ans;
}

int takeTransition(Worker *w, char *edge) {
  int e1 = strcmp(
      edge, "counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
  int e2 = strcmp(edge, "t_work<T_BURNOUT,t:=0");
  int e3 = strcmp(edge, "t>=T_CAR&&t<=TMAX_CAR,t:=0");
  int e4 = strcmp(edge, "t>=T_BUS&&t<=TMAX_BUS,t:=0");
  int e5 = strcmp(edge, "t>=T_WALK&&t<=TMAX_WALK,t:=0");
  int e6 = strcmp(edge, "t_work<T_BURNOUT,t:=0,counter-=1");
  w->t = 0;
  if (e1==0) {
    w->t_work = 0;
    counter += 1;
  } else if (e2==0 || e3==0 || e4==0 || e5==0) {
	  if (e3 ==0){
		  take_car += 1;
		  
	  }
	  else if (e4 ==0){
		  take_bus += 1;
	  }
	  else if (e5==0){
		  take_walk +=1;
	  }
  }

  else if (e6==0) {
    counter -= 1;
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
void sleep(Worker *w) {
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

int strategy(Worker **worker, WorkerFee **workerfee, Company *company){
	/** Automatically generated**/

	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((3<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<7 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((3<=worker[0]->t_work && 7<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<5 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=3 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<6 && worker[1]->t_work<=worker[0]->t_work && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<6 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=worker[1]->t_work && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<6 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=worker[1]->t_work && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((5<=worker[0]->t_work && worker[0]->t==3 && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<=3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<workerfee[0]->s && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==5 && worker[0]->t_work-worker[0]->t==2 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==3) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=3 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 7<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (3<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=3 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=3 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((3<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<-3 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<=3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work==-2 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work-workerfee[0]->s<-1 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=6 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<worker[0]->t && 1<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work-worker[0]->t_work<-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<2 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<6 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<2 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<=5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=-4 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && 1<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<4 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t<2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=-5 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<5 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work<7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && 9<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-4 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t<8 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t==2 && worker[0]->t_work<=6 && worker[0]->t==worker[1]->t_work && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<4 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-4 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<9 && workerfee[0]->s-worker[0]->t_work<4 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<9 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[0]->t<3 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<5 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<4 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<8 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-5 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[1]->t_work<8 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work<8 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work-worker[0]->t_work<5 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[0]->t_work && 8<=workerfee[0]->s && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<6 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[0]->t<4 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && 4<workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work<workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<6 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<6 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<5 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 6<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 6<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<2 && workerfee[0]->s<5 && workerfee[0]->s-worker[1]->t_work<-1 && workerfee[0]->s-worker[1]->t<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && worker[0]->t_work==worker[0]->t && worker[0]->t-worker[1]->t_work==-2 && worker[1]->t_work-worker[1]->t==2 && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==2) || (worker[0]->t_work==2 && 2<=worker[1]->t && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<3 && worker[1]->t-worker[0]->t_work<=1 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s-worker[1]->t<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<=2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<6 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=-3 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<5 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[0]->t<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<1 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<-2 && worker[1]->t_work<8 && workerfee[0]->s<5 && workerfee[0]->s-worker[1]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<=worker[1]->t_work && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (5<=worker[1]->t_work && worker[0]->t_work<4 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<3 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t<5 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=6 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=6 && workerfee[0]->s<4 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=5 && workerfee[0]->s<4 && workerfee[0]->s-worker[0]->t<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<=worker[1]->t_work && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<4 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<6 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s-worker[0]->t<5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<=worker[1]->t_work && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<6 && worker[1]->t_work-worker[0]->t<5 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (5<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-worker[1]->t_work<-4 && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-workerfee[0]->s==-10 && worker[1]->t_work<=5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t==workerfee[0]->s && worker[1]->t_work<=5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<8 && workerfee[0]->s<6 && workerfee[0]->s-worker[0]->t<5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 5<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-workerfee[0]->s==-10 && worker[1]->t_work<=6 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 5<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t==workerfee[0]->s && worker[1]->t_work<=6 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 6<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t-workerfee[0]->s==-10 && worker[1]->t_work<=7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 6<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t==workerfee[0]->s && worker[1]->t_work<=7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s<7 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<8 && workerfee[0]->s<7 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-5 && worker[0]->t-workerfee[0]->s==-10 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-5 && worker[0]->t==workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[0]->t_work && 5<worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-workerfee[0]->s==-10 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<=worker[0]->t_work && 5<worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t==workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<3 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work==3 && 5<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s<=3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<=3 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 3<workerfee[0]->s && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-5 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<8 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<8 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<8 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<8 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<8 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<4 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<8 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=5 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work-worker[1]->t<3 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-worker[1]->t<4 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-worker[1]->t<3 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s<2 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<6 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<5 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((1<=workerfee[0]->s && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work==-2 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<6 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<1 && workerfee[0]->s<6 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<5 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && worker[0]->t==3 && 5<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((5<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-workerfee[0]->s<=-5 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<7 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<=5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=6 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<=6 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (6<worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=7 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<=7 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<worker[0]->t_work && worker[1]->t_work==3 && worker[0]->t_work<6 && worker[1]->t_work-workerfee[0]->s==-7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<worker[0]->t_work && worker[1]->t_work==3 && worker[0]->t_work<6 && worker[1]->t_work-workerfee[0]->s==3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (6<worker[0]->t_work && worker[1]->t_work==3 && worker[0]->t_work<7 && worker[1]->t_work-workerfee[0]->s==-7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<worker[0]->t_work && worker[1]->t_work==3 && worker[0]->t_work<7 && worker[1]->t_work-workerfee[0]->s==3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (7<worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 3<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((3<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<4 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=6 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<7 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<5 && worker[1]->t_work<8 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==4 && worker[0]->t_work-worker[1]->t_work==2 && worker[1]->t_work==worker[1]->t && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==2) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (6<=worker[0]->t_work && worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((6<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && 1<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((6<=worker[0]->t_work && worker[1]->t_work==2 && 4<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && 3<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<6 && worker[0]->t_work==worker[1]->t_work && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<5 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s<=2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<6 && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (3<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<4 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<4 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=6 && worker[1]->t_work<=3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<=6 && worker[1]->t_work<=3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<1 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (6<worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<1 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<6 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<5 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<5 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-workerfee[0]->s<1 && workerfee[0]->s<5 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && worker[0]->t_work==worker[0]->t && worker[0]->t-worker[1]->t_work==-2 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==2) || (worker[0]->t_work==2 && 2<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<5 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<1 && workerfee[0]->s<5 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-workerfee[0]->s==-10 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t==workerfee[0]->s && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<3 && worker[1]->t_work<7 && workerfee[0]->s<5 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<1 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<4 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((3<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=5 && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<4 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=6 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<8 && workerfee[0]->s<4 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<4 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t_work && worker[1]->t_work==worker[1]->t && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==4 && worker[0]->t_work-worker[1]->t_work==2 && worker[1]->t_work==worker[1]->t && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==2) || (2<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<4 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[0]->t_work && worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((5<=worker[0]->t_work && 3<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-workerfee[0]->s==-10 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t==workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t<workerfee[0]->s && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<=5 && worker[0]->t_work-worker[0]->t==2 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s-worker[0]->t_work==-2) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work<=5 && worker[0]->t_work-worker[0]->t==2 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s-worker[0]->t_work==-2) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s-worker[1]->t<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s<=-3 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && 9<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t<=3 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && 9<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<8 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 6<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=7 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<5 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<6 && worker[0]->t_work-worker[1]->t_work==2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s-worker[0]->t_work==-2) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s<=-3 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 6<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t==3 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<6 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t==3 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 7<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s-worker[1]->t<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 2<worker[1]->t && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 2<worker[1]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work-workerfee[0]->s<=5 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=6 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s<2 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=7 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-5 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=6 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<=worker[1]->t_work && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<3 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work==3 && 5<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=5 && worker[1]->t==3 && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 7<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work==3 && 1<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t==3 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==4 && worker[0]->t_work-worker[0]->t==2 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==worker[1]->t && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==2) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t && worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s-worker[0]->t<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==4 && worker[0]->t_work-worker[0]->t==2 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==worker[1]->t && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==2) || (2<=worker[0]->t && worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<9 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work<workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[0]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=5 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<=5 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=6 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<=6 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (6<worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<=7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<6 && worker[0]->t==worker[1]->t_work && worker[1]->t_work-workerfee[0]->s==-7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<6 && worker[0]->t==worker[1]->t_work && worker[1]->t_work-workerfee[0]->s==3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (6<worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work-workerfee[0]->s==-7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work-workerfee[0]->s==3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<4 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<4 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[0]->t==3 && 4<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work-workerfee[0]->s==-7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work-workerfee[0]->s==3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && 7<=workerfee[0]->s && worker[0]->t_work<6 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t-workerfee[0]->s<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<5 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<7 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t-workerfee[0]->s==-7 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<4 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t-worker[1]->t_work<=-4 && worker[1]->t-workerfee[0]->s<=-2 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 6<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((worker[0]->t_work==3 && 7<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-worker[1]->t<3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-workerfee[0]->s<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 6<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (6<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<6 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[0]->t_work && worker[0]->t_work<6 && worker[0]->t_work<worker[1]->t_work && worker[1]->t_work<8 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<8 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-worker[1]->t<3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<8 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-5 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-worker[1]->t<4 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<8 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 5<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=6 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 5<worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=6 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 6<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 6<worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=5 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=5 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && worker[1]->t-workerfee[0]->s<=-2 && workerfee[0]->s<6 && workerfee[0]->s-worker[1]->t<4 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<4 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<6 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<1 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<4 && worker[0]->t_work==worker[1]->t_work && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<5 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && worker[0]->t_work==worker[0]->t && worker[0]->t-worker[1]->t_work==-2 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==2) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=6 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && worker[1]->t_work==worker[1]->t && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((3<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<4 && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<4 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 3<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=6 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<3 && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<1 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<4 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t<workerfee[0]->s && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<workerfee[0]->s && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<6 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-5 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<6 && worker[1]->t_work<=worker[0]->t_work && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 6<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=6 && workerfee[0]->s<4 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<4 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s-worker[0]->t<3 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work==-2 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<-3 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<=3 && worker[0]->t_work-worker[1]->t_work==-2 && worker[1]->t_work-worker[1]->t==2 && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((3<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<7 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<-1 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-4 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<4 && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((5<=worker[0]->t_work && 1<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<5 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<1 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((5<=worker[0]->t_work && worker[1]->t_work==2 && 2<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t<5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[1]->t<5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[1]->t<5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 7<=worker[1]->t_work && 5<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=-5 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 6<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s-worker[1]->t_work==-2) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s<4 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<6 && worker[0]->t_work-worker[1]->t_work==2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s-worker[0]->t_work==-2) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<4 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<3 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<4 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=worker[0]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t_work-worker[0]->t<3 && worker[0]->t<3 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t) || (2<=worker[0]->t && worker[0]->t_work<=5 && worker[0]->t_work-worker[0]->t<3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s-worker[0]->t<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t==3 && 2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<6 && worker[1]->t_work<=3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<worker[0]->t_work && 2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-3 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=1 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t-workerfee[0]->s<=-5 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<4 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-worker[1]->t<3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s-worker[1]->t_work<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && worker[0]->t==3 && 4<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<4 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[0]->t==3 && 4<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<6 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<worker[0]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s-worker[1]->t<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=7 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t_work<6 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<4 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (worker[0]->t_work<5 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<3 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 7<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<3 && worker[1]->t_work==workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t==3 && workerfee[0]->s<6 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t-workerfee[0]->s<=-5 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<=3 && worker[0]->t_work-worker[1]->t_work==-2 && worker[1]->t_work-worker[1]->t==2 && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<2 && worker[1]->t<=3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=7 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<-7 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<5 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t<1 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work<7 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-7 && worker[1]->t_work<6 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<4 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=6 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=1 && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<6 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=2 && workerfee[0]->s<2 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=7 && workerfee[0]->s<1 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s<worker[0]->t && workerfee[0]->s-worker[1]->t_work<-7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<5 && workerfee[0]->s<1 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<1 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<4 && workerfee[0]->s<1 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[1]->t_work==2 && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-workerfee[0]->s==-10 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t==workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t<5 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t<2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<3 && worker[1]->t_work==workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<=-5 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && 9<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<4 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((3<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<7 && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-5 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && 5<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<4 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<4 && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[1]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<2 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=6 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=7 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-5 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<-7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=7 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<3 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t_work && worker[1]->t_work==worker[1]->t && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<8 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s<8 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-5 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<4 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && 2<=worker[1]->t_work && 8<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<3 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<worker[0]->t_work && worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<5 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t-worker[1]->t_work<=-4 && worker[1]->t-workerfee[0]->s<=-2 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (workerfee[0]->s==10 && worker[0]->t_work<=7 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work<=7 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && worker[1]->t-workerfee[0]->s<=-2 && workerfee[0]->s<5 && workerfee[0]->s-worker[1]->t<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-worker[1]->t_work<=-4 && worker[1]->t-workerfee[0]->s<=-3 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<6 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (6<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<worker[0]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<5 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==4 && worker[0]->t_work-worker[1]->t_work==2 && worker[1]->t_work==worker[1]->t && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==2) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((6<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<-1 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s-worker[1]->t_work==-2) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<4 && workerfee[0]->s-worker[1]->t_work<-1 && workerfee[0]->s-worker[1]->t<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<4 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && worker[0]->t==3 && 3<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s-worker[0]->t<3 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=6 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t && 2<=worker[1]->t_work && worker[0]->t_work<=6 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && worker[0]->t==3 && 3<=workerfee[0]->s && worker[0]->t_work<6 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t==3 && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t-workerfee[0]->s<=-3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t==2 && worker[0]->t_work<=6 && worker[0]->t==worker[1]->t_work && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t==2 && worker[0]->t_work<=6 && worker[0]->t==worker[1]->t_work && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (6<worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<6 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s<=worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (1<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<4 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<8 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=3 && worker[0]->t_work-worker[1]->t_work==-2 && worker[1]->t_work-worker[1]->t==2 && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s<=worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t<workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<2 && worker[1]->t<=3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && worker[1]->t-workerfee[0]->s<=-2 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<1 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && 9<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<5 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-worker[1]->t<4 && worker[1]->t_work==workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<1 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-7 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=7 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<1 && worker[0]->t_work==worker[1]->t_work && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (6<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<6 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (5<=worker[0]->t_work && worker[0]->t_work<6 && worker[0]->t_work<worker[1]->t_work && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<2 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<5 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<5 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<4 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<=3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<4 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 6<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 6<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<1 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<4 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<6 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[0]->t_work && worker[0]->t_work<worker[1]->t_work && worker[1]->t_work<5 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && worker[1]->t_work==2 && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (5<worker[0]->t_work && 3<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<3 && workerfee[0]->s<3 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=7 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s<1 && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-5 && workerfee[0]->s-worker[0]->t_work<-7 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<-4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=6 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=1 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<3 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((5<=worker[0]->t_work && worker[0]->t==3 && 1<=workerfee[0]->s && worker[0]->t_work-workerfee[0]->s<=5 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && worker[0]->t==3 && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t==3 && 1<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((5<=worker[0]->t_work && 3<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[1]->t_work==2 && 2<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-worker[1]->t<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (worker[0]->t_work==3 && 6<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-workerfee[0]->s<=-4 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<4 && workerfee[0]->s-worker[1]->t<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 7<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t<=3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-worker[1]->t<5 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work<=worker[0]->t_work && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s-worker[1]->t<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && 5<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=6 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 5<worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=6 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[1]->t_work==7 && 2<worker[1]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s==-3 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[1]->t_work==7 && 2<worker[1]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s==7 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==3 && 5<worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t-workerfee[0]->s==-7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==3 && 5<worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t-workerfee[0]->s==3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==3 && 6<worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s==-7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==3 && 6<worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s==3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<=workerfee[0]->s && worker[1]->t==3 && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-4 && worker[1]->t-workerfee[0]->s<=-2 && workerfee[0]->s-worker[1]->t<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 6<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s<7 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 7<worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t-workerfee[0]->s==-7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==3 && 7<worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t-workerfee[0]->s==3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[1]->t<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=5 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=5 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 6<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 6<worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=workerfee[0]->s && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s<=-4 && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<=5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<-4 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-5 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<4 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 6<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s-worker[1]->t_work<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work<5 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work-workerfee[0]->s<=-8 && worker[1]->t_work<7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 6<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 5<=worker[1]->t_work && 9<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s<10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Startup")==0 && money==1 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work==worker[1]->t_work && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==0) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<6 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=worker[1]->t_work && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((5<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<6 && workerfee[0]->s-worker[1]->t<5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<=5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-workerfee[0]->s==-10 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<=5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t==workerfee[0]->s && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<=6 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t-workerfee[0]->s==-10 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<=6 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t==workerfee[0]->s && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (6<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<=7 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t-workerfee[0]->s==-10 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<=7 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t==workerfee[0]->s && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-worker[1]->t<3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-5 && worker[1]->t-workerfee[0]->s==-10 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-5 && worker[1]->t==workerfee[0]->s && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<worker[0]->t_work && 3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-workerfee[0]->s==-10 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<worker[0]->t_work && 3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t==workerfee[0]->s && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-worker[1]->t<3 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t-workerfee[0]->s<2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s<=worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work-worker[1]->t_work<-2 && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<6 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s-worker[1]->t<4 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<5 && worker[1]->t_work<workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((3<worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<4 && workerfee[0]->s-worker[1]->t_work<-1 && workerfee[0]->s-worker[1]->t<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=6 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=6 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<4 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<6 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=worker[1]->t_work && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<=3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-worker[1]->t<4 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-workerfee[0]->s<=-3 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-5 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work-worker[1]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-4 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((1<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && worker[0]->t_work<6 && worker[0]->t_work-worker[1]->t_work==2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s-worker[0]->t_work==-2) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<4 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<=7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<=7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<4 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && worker[0]->t==3 && 3<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t==3 && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<6 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<=5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<=5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 5<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<=6 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 5<worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<=6 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 6<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 6<worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 6<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 5<worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<=6 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 5<worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<=6 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-4 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<4 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-5 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<=-4 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (7<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-worker[1]->t_work<-6 && worker[0]->t-workerfee[0]->s<=-3 && worker[1]->t_work<8 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=5 && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t<4 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<6 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s<6 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (6<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<=worker[1]->t_work && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<5 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && 6<=workerfee[0]->s && worker[0]->t_work<5 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<6 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-workerfee[0]->s<=-4 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-worker[0]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 6<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=-2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 6<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=-4 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<4 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-5 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<5 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<4 && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<6 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<6 && workerfee[0]->s-worker[1]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (5<=worker[0]->t_work && worker[0]->t_work<worker[1]->t_work && worker[1]->t_work<6 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=7 && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<=7 && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<worker[0]->t_work && 5<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<=7 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<=7 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && 7<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<=worker[0]->t_work && 7<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && worker[0]->t_work==worker[0]->t && worker[0]->t-worker[1]->t_work==-2 && worker[1]->t_work-worker[1]->t==2 && worker[1]->t==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==2) || (worker[0]->t_work==2 && 2<=worker[1]->t && 2<workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t-workerfee[0]->s==-10 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t==workerfee[0]->s && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && worker[1]->t-workerfee[0]->s<=-2 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s-worker[1]->t<6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[1]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-4 && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-3 && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work==3 && 6<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t==3 && workerfee[0]->s<=3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 2<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t-workerfee[0]->s==-7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t-workerfee[0]->s==3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((worker[0]->t_work==3 && 7<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s<=3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t-worker[1]->t_work<=-2 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<=3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 3<workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t==3 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<7 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<8 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s-worker[0]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work-workerfee[0]->s<=-8 && worker[1]->t_work<7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<3 && worker[0]->t_work-worker[1]->t_work<4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work-worker[0]->t_work<=-5 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && 1<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-7 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<9 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-worker[0]->t<3 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && 9<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 3<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<3 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<5 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && 3<workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((3<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==2 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (3<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s<6 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<-3 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=5 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<6 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<=3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<5 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t==3 && workerfee[0]->s<=3 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 6<=worker[1]->t_work && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t==3 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 5<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t==3 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 6<=worker[1]->t_work && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<4 && worker[1]->t<=3 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<3 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 2<workerfee[0]->s && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=2 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[1]->t<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<workerfee[0]->s && worker[1]->t<=3 && workerfee[0]->s-worker[1]->t<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Outside";
			return takeTransition(worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=7 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<5 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<4 && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-4 && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<-1 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (1<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<8 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-8 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<5 && worker[1]->t_work<8 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<8 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=worker[0]->t && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<4 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((5<=worker[0]->t_work && worker[0]->t==3 && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=-4 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t && 1<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<3 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t_work<workerfee[0]->s && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t-workerfee[0]->s<=-3 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s-worker[0]->t<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[1]->t_work==2 && 2<workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t<=3 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<7 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-workerfee[0]->s<=-1 && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=5 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<=5 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (5<worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && 1<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) || (5<worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (5<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-workerfee[0]->s<=-5 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-workerfee[0]->s<=-4 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 6<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-3 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<=-4 && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==-8 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t-workerfee[0]->s==2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=5 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t==3 && worker[0]->t_work<6 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<1 && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t==3 && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<-7 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=6 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<1 && workerfee[0]->s-worker[0]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t==3 && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-3 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work-workerfee[0]->s<1 && workerfee[0]->s<worker[0]->t && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s<worker[1]->t && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && worker[0]->t_work==worker[1]->t && worker[1]->t_work<6 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<1 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && worker[0]->t_work==worker[1]->t && worker[1]->t_work<7 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && worker[0]->t_work==worker[1]->t && worker[1]->t_work<8 && worker[1]->t==3 && workerfee[0]->s-worker[1]->t_work<-7 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<=6 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<1 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<=-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<1 && worker[1]->t_work-worker[1]->t<=3 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t-worker[1]->t_work<-3 && worker[1]->t<=workerfee[0]->s && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && 2<=workerfee[0]->s && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<6 && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[1]->t_work==2 && 2<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<3 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work<8 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<6 && worker[1]->t_work<=worker[0]->t_work && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<7 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<7 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work-workerfee[0]->s<4 && worker[1]->t_work<8 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<4 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=3 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<8 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 2<workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work-worker[0]->t_work<2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && 5<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<=6 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 5<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<=6 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-worker[0]->t_work<3 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[1]->t_work==7 && worker[0]->t_work<=3 && worker[1]->t_work-workerfee[0]->s==-3 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[1]->t_work==7 && worker[0]->t_work<=3 && worker[1]->t_work-workerfee[0]->s==7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[0]->t_work-workerfee[0]->s<=-2 && worker[1]->t_work<8 && workerfee[0]->s<7 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<8 && workerfee[0]->s<7 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<7 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-5 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 7<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-5 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[0]->t_work && 7<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((3<worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<=5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<=5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && 6<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[0]->t_work && 6<worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work==3 && 5<worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-7 && worker[1]->t_work<6 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==3 && 5<worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==3 && worker[1]->t_work<6 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=workerfee[0]->s && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<6 && workerfee[0]->s<8 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==3 && 6<worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==-7 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work==3 && 6<worker[1]->t_work && worker[0]->t_work-workerfee[0]->s==3 && worker[1]->t_work<7 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<3 && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<7 && workerfee[0]->s-worker[1]->t_work<1 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<7 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t_work-workerfee[0]->s<=-8 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((5<=worker[0]->t_work && worker[1]->t_work==2 && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<3 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-workerfee[0]->s<=-4 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<4 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-worker[0]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s-worker[0]->t_work<7 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<9 && workerfee[0]->s-worker[1]->t_work<4 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[0]->t_work-workerfee[0]->s<=-7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<9 && workerfee[0]->s-worker[1]->t_work<3 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=-2 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=-1 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s<9 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==7 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-5 && worker[1]->t_work<=2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work-workerfee[0]->s<=-4 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<5 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[1]->t_work<2 && worker[1]->t_work==worker[1]->t && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((5<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<=-4 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<5 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-3 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<=10 && workerfee[0]->s-worker[0]->t_work<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==5 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((7<=worker[0]->t_work && worker[0]->t==3 && 1<=workerfee[0]->s && worker[0]->t_work<8 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t==3 && 2<=workerfee[0]->s && worker[0]->t_work<6 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<3 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && 3<workerfee[0]->s && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<2 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work-worker[0]->t<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==10) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((6<=worker[0]->t_work && worker[0]->t==3 && 2<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<=3 && workerfee[0]->s==workerfee[1]->s) || (5<=worker[0]->t_work && worker[0]->t==3 && 1<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s<2 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t==3 && 3<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t==worker[1]->t_work && worker[1]->t_work==3 && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-3 && worker[0]->t<=workerfee[0]->s && worker[1]->t_work<3 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s<=10 && workerfee[0]->s-worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t<=3 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=worker[0]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==6 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (7<=worker[0]->t_work && 2<worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work-worker[1]->t_work<4 && worker[1]->t_work<=3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<4 && worker[1]->t_work<=3 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (3<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (6<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((3<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (3<worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-4 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work-worker[0]->t_work<=-3 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<3 && worker[1]->t_work-worker[0]->t_work<=-3 && worker[1]->t_work-workerfee[0]->s<=-1 && workerfee[0]->s<5 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<3 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && 2<=workerfee[0]->s && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==1 && budget==2 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 4<=workerfee[0]->s && worker[0]->t_work<3 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<7 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[1]->t_work && worker[0]->t_work<4 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s==2 && worker[1]->t_work<8 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s-worker[0]->t_work==-2) || (2<=worker[0]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<4 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<8 && workerfee[0]->s<4 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work<4 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<8 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Break")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (7<=worker[0]->t_work && 2<worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[1]->t_work==2 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s-worker[0]->t_work==-2) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[1]->t_work<5 && worker[1]->t_work<workerfee[0]->s && workerfee[0]->s-worker[0]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==-8 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (4<=worker[0]->t_work && worker[1]->t_work==2 && worker[0]->t_work<8 && worker[1]->t_work-workerfee[0]->s==2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work<=workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<5 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (4<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<5 && worker[1]->t_work<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (4<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (7<=worker[0]->t_work && 2<=worker[1]->t_work && worker[0]->t_work<8 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<5 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Sleep";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if ((2<=worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s<=worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) || (2<worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (2<worker[1]->t_work && worker[0]->t_work<7 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-workerfee[0]->s<2 && worker[1]->t_work<4 && worker[1]->t_work-worker[0]->t_work<=-2 && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 6<=worker[1]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<7 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t<=3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s<5 && workerfee[0]->s-worker[1]->t<3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<6 && worker[1]->t_work-workerfee[0]->s<=3 && worker[1]->t-worker[1]->t_work<=-3 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[0]->t_work<=worker[1]->t && worker[1]->t_work-workerfee[0]->s<1 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<5 && workerfee[0]->s<worker[1]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && worker[1]->t-workerfee[0]->s<=-1 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<=workerfee[0]->s && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 2<=worker[1]->t && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<1 && worker[1]->t-worker[1]->t_work<=-3 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Home")==0 && strcmp(worker[1]->state,"Sleep")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==1 && counter==0 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((workerfee[0]->s==10 && worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (worker[0]->t_work-worker[1]->t_work<2 && worker[0]->t_work==workerfee[0]->s && worker[1]->t_work<6 && worker[1]->t_work<=worker[0]->t_work && worker[1]->t_work-worker[1]->t<5 && worker[1]->t-worker[1]->t_work<=-4 && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[0]->t_work) || (worker[0]->t_work<8 && worker[1]->t_work-worker[0]->t_work<=-2 && worker[1]->t_work-worker[1]->t<5 && worker[1]->t<=3 && worker[1]->t-worker[1]->t_work<=-2 && workerfee[0]->s<=10 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Outside";
			return takeTransition(worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (strcmp(worker[0]->state,"Sleep")==0 && strcmp(worker[1]->state,"Outside")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==4 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[1]->t_work && worker[0]->t_work<5 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<7 && workerfee[0]->s==workerfee[1]->s) || (5<worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=6 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (5<worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<=6 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (6<=worker[0]->t_work && 1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (6<=worker[0]->t_work && 1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[1]->t_work && workerfee[0]->s==10 && worker[0]->t_work<=5 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==10 && workerfee[1]->s==0) || (1<=worker[1]->t_work && worker[0]->t_work<=5 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s-workerfee[1]->s==-10 && workerfee[1]->s==10) || (1<=worker[1]->t_work && worker[0]->t_work<=workerfee[0]->s && worker[0]->t-worker[0]->t_work<=-3 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<6 && workerfee[0]->s-worker[0]->t_work<1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<7 && worker[0]->t_work-worker[0]->t<5 && worker[0]->t-worker[0]->t_work<=-4 && worker[0]->t-workerfee[0]->s<=-2 && worker[1]->t_work<=2 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<6 && workerfee[0]->s-worker[0]->t<4 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[1]->t_work && worker[0]->t_work<6 && worker[0]->t-workerfee[0]->s<=-4 && worker[1]->t_work<=worker[0]->t && worker[1]->t_work==worker[1]->t && workerfee[0]->s<worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((2<=worker[0]->t && worker[1]->t_work==2 && worker[0]->t_work-workerfee[0]->s<=-1 && worker[0]->t-worker[0]->t_work<=-2 && worker[1]->t_work==worker[1]->t && worker[1]->t==2 && workerfee[0]->s<6 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[1]->state = "Working";
			return takeTransition(worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (strcmp(worker[0]->state,"Break")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==2 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((2<=worker[0]->t_work && 1<=workerfee[0]->s && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=2 && worker[1]->t_work<7 && workerfee[0]->s<3 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=6 && workerfee[0]->s-worker[0]->t_work<-1 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && worker[0]->t_work<4 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<7 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s-worker[1]->t_work<-5 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[0]->t_work-workerfee[0]->s<=1 && worker[1]->t_work-workerfee[0]->s<=4 && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t_work<=-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<=worker[1]->t_work && worker[1]->t_work<3 && worker[1]->t_work==workerfee[0]->s && workerfee[0]->s==workerfee[1]->s && workerfee[1]->s==worker[1]->t_work) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if ((1<=workerfee[0]->s && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=5 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<=5 && workerfee[0]->s<1 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=6 && workerfee[0]->s<3 && workerfee[0]->s<=worker[0]->t_work && workerfee[0]->s==workerfee[1]->s) || (4<=worker[0]->t_work && worker[0]->t_work<5 && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work<8 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-4 && worker[1]->t_work<8 && worker[1]->t_work-workerfee[0]->s<=7 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-5 && worker[1]->t_work<8 && workerfee[0]->s-worker[1]->t_work<-7 && workerfee[0]->s==workerfee[1]->s) || (3<=worker[0]->t_work && 7<=worker[1]->t_work && worker[0]->t_work-worker[1]->t_work<=-3 && worker[1]->t_work<8 && workerfee[0]->s-worker[0]->t_work<-2 && workerfee[0]->s-worker[1]->t_work<-6 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work-worker[1]->t_work<=-2 && worker[1]->t_work-workerfee[0]->s<2 && workerfee[0]->s<3 && workerfee[0]->s==workerfee[1]->s) || (2<=worker[0]->t_work && worker[0]->t_work<workerfee[0]->s && worker[1]->t_work<8 && workerfee[0]->s<3 && workerfee[0]->s-worker[1]->t_work<-4 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Sleep";
			return takeTransition(worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (strcmp(worker[0]->state,"Outside")==0 && strcmp(worker[1]->state,"Home")==0 && strcmp(workerfee[0]->state,"Fee")==0 && strcmp(workerfee[1]->state,"Fee")==0 && strcmp(company->state,"Working")==0 && money==3 && budget==3 && counter==1 && worker[0]->id==0 && worker[1]->id==1 && workerfee[0]->id==0 && workerfee[1]->id==1)
	{
		if ((1<=worker[0]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && 3<=workerfee[0]->s && worker[0]->t_work<=2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<7 && worker[1]->t_work-workerfee[0]->s<=3 && workerfee[0]->s<5 && workerfee[0]->s-worker[1]->t_work<=-1 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 4<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (1<=worker[0]->t_work && 5<=worker[1]->t_work && worker[0]->t_work<2 && worker[0]->t_work==worker[0]->t && worker[1]->t_work-workerfee[0]->s<1 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if ((worker[0]->t_work==2 && 3<=workerfee[0]->s && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<7 && workerfee[0]->s-worker[1]->t_work<-3 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 4<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work<=workerfee[0]->s && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) || (worker[0]->t_work==2 && 5<=worker[1]->t_work && worker[0]->t_work==worker[0]->t && worker[0]->t==2 && worker[1]->t_work-workerfee[0]->s<1 && workerfee[0]->s<5 && workerfee[0]->s==workerfee[1]->s) )
		{
			worker[0]->state = "Working";
			return takeTransition(worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	return 0;
}