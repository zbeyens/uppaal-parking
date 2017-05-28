#include "model.h"
#include <string.h>

void model(){
	//initialization
	Worker *workers;
	workers = (Worker*)malloc(2*sizeof(Worker));
	WorkerFee *workerFees;
	workerFees = (WorkerFee*)malloc(2*sizeof(WorkerFee));
	Company *company;
	company = (Company*)malloc(sizeof(Company));
	initialization(&workers, &workerFees, company);
	while (1){
		if (!strategy(&workers, &workerFees, company)){
			//workerCase
			workerCase(&workers);
			//WorkerFeeCase
			workerFeeCase(&workerFees);
			//CompanyCase
			companyCase(company);
		}
		printf("update:\n");
		printf("worker n%d\n", workers[0].id);
		printf("\tstate : %s\n", workers[0].state);
		printf("\tWork time = %d\n\n",workers[0].t_work);
		printf("worker n%d\n", workers[1].id);
		printf("\tstate : %s\n", workers[1].state);
		printf("\tWork time = %d\n\n",workers[1].t_work);
		printf("worker fee n%d\n", workerFees[0].id);
		printf("\ts = %d\n\n", workerFees[0].s);
		printf("worker fee n%d\n", workerFees[1].id);
		printf("\ts = %d\n\n", workerFees[1].s);
		printf("Company:\n\tstate: %s\n\n", company->state);
		
	}
}


void initialization(Worker** workers, WorkerFee** workerFees, Company* company){
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

void workerCase(Worker** workers){
	int i1 = 0;	
	int i2 = 0;
	if ((i1 == 0 || i2 == 0) && (strcmp(workers[0]->state, "Home") || strcmp(workers[1]->state,"Home"))){
		if (strcmp(workers[0]->state,"Home") && i1 == 0){Home(workers[0]);i1++;}
		if (strcmp(workers[1]->state,"Home") && i2 == 0){Home(workers[1]);i2++;}
	}
	/**
	if ((i1 == 0 || i2 == 0) && (strcmp(workers[0]->state,"Outside") || strcmp(workers[1]->state,"Outside"))){
		if (strcmp(workers[0]->state,"Outside") && i1 == 0){Outside(workers[0]);i1++;}
		if (strcmp(workers[1]->state,"Outside") && i2 == 0){Outside(workers[1]);i2++;}
	}
	**/
	if ((i1 == 0 || i2 == 0) && (strcmp(workers[0]->state,"Working") || strcmp(workers[1]->state, "Working"))){
		if (strcmp(workers[0]->state,"Working") && i1 == 0){Working(workers[0]);i1++;}
		if (strcmp(workers[1]->state,"Working")  && i2 == 0){Working(workers[1]);i2++;}
	}
	if ((i1 == 0 || i2 == 0) && (strcmp(workers[0]->state, "Break") || strcmp(workers[1]->state , "Break"))){
		if (strcmp(workers[0]->state, "Break") && i1 == 0){Break(workers[0]);i1++;}
		if (strcmp(workers[1]->state, "Break") && i2 == 0){Break(workers[1]);i2++;}
	}
	if ((i1 == 0 || i2 == 0) && (strcmp(workers[0]->state, "Sleep") || strcmp(workers[1]->state,"Sleep"))){
		if (strcmp(workers[0]->state, "Sleep") && i1 == 0){Sleep(workers[0]);i1++;}
		if (strcmp(workers[1]->state, "Sleep") && i2 == 0){Sleep(workers[1]);i2++;}
	}
	if ((i1 == 0 || i2 == 0) && (strcmp(workers[0]->state, "Burnout") || strcmp(workers[1]->state , "Burnout"))){
		if (strcmp(workers[0]->state, "Burnout") && i1 == 0){Sleep(workers[0]);i1++;}
		if (strcmp(workers[1]->state, "Burnout") && i2 == 0){Sleep(workers[1]);i2++;}
	}
}

void workerFeeCase(WorkerFee** workerFees){
	Fee(workerFees[0]);
	Fee(workerFees[1]);
}

void companyCase(Company* company){
	int i = 0;	
	if (i == 0 && strcmp(company->state, "StartUp")){
		StartUp(company);
		i++;}
	if (i == 0 && strcmp(company->state, "Working")){
		WorkingCompany(company);
		i++;}
	if (i == 0 && strcmp(company->state, "Bankrupt")){
		Bankrupt(company);
		i++;}
	
}
