#include <iostream>
bool controlCondition(Worker[] Worker, WorkerSalary[] WorkerSalary, Company Company){
	/** Automatically generated**/
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<5 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work<4 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work-WorkerSalary[0].s==1 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-3) || (2<=Worker[1].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work<5 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<5 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=WorkerSalary[0].s && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work-WorkerSalary[0].s==1 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-3) || (5<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<5 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<4 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<-1 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<1 && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(3<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-8 && Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=-7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work<5 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work<4 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(3<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=6 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (5<Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<=6 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (6<Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=7 && Worker[1].t_work-Worker[0].t_work<=-4 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (6<Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<=7 && Worker[1].t_work-Worker[0].t_work<=-4 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<Worker[0].t_work && Worker[1].t_work==3 && Worker[0].t_work<6 && Worker[1].t_work-WorkerSalary[0].s==-7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (5<Worker[0].t_work && Worker[1].t_work==3 && Worker[0].t_work<6 && Worker[1].t_work-WorkerSalary[0].s==3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (6<Worker[0].t_work && Worker[1].t_work==3 && Worker[0].t_work<7 && Worker[1].t_work-WorkerSalary[0].s==-7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (6<Worker[0].t_work && Worker[1].t_work==3 && Worker[0].t_work<7 && Worker[1].t_work-WorkerSalary[0].s==3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work<5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<-1 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-5 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-5 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && 3<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s<=2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==-8 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<5 && WorkerSalary[0].s<2 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-Worker[1].t<4 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-5 && Worker[1].t-WorkerSalary[0].s<=-3 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s-Worker[1].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=WorkerSalary[0].s && Worker[0].t_work<3 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<4 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[0].t_work-WorkerSalary[0].s<-1 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<4 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work-WorkerSalary[0].s<=5 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t<=2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=6 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=7 && WorkerSalary[0].s-Worker[1].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-5 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=6 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<3 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(3<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 3<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work<5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && 3<WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) || (5<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-WorkerSalary[0].s<=7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-Worker[1].t<=5 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<1 && WorkerSalary[0].s<Worker[1].t && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[0].t_work<-5 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<-6 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 1<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=6 && Worker[1].t==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t==2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=5 && Worker[1].t==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[1].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 2<WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(2<=Worker[0].t_work && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<7 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<5 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work<4 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<-1 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<5 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=5 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<8 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s<5 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<4 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work<=3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=-7 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-5 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[1].t_work && Worker[0].t_work<=5 && Worker[0].t_work-WorkerSalary[0].s<-4 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<9 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Startup" &&  && money==1 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-4 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-5 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t-Worker[0].t_work<=-5 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==Worker[1].t_work && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==0) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-5 && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[0].t && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<4 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t-WorkerSalary[0].s<1 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && 2<WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<5 && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<1 && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<2 && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[0].t_work<4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[0].t_work-WorkerSalary[0].s<=-7 && Worker[1].t_work-WorkerSalary[0].s<=-4 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[0].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[0].t_work-WorkerSalary[0].s<=-7 && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<9 && WorkerSalary[0].s-Worker[1].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[0].t_work-WorkerSalary[0].s<=-7 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s<9 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t-Worker[1].t_work<=-5 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(5<=Worker[0].t_work && Worker[1].t_work==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(5<=Worker[0].t_work && 1<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[1].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[0].t && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t-WorkerSalary[0].s<1 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t==2 && 2<WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && 2<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && Worker[0].t==2 && 2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[0].t==2 && 4<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && Worker[0].t==2 && 4<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && 9<=WorkerSalary[0].s && Worker[0].t_work<5 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==4 && Worker[0].t_work-Worker[0].t==2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && 2<WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && Worker[0].t==2 && 2<WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<3 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && 3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-4 && Worker[1].t-WorkerSalary[0].s<=-2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-WorkerSalary[0].s==-10 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t-WorkerSalary[0].s<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[1].t<3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[1].t<3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[1].t<3 && Worker[1].t_work==WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(1<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-Worker[0].t<4 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t-WorkerSalary[0].s<-4 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[0].t==2 && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[0].t-WorkerSalary[0].s<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && 9<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[0].t==2 && 4<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<4 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-Worker[1].t<4 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-5 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-5 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=Worker[0].t && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t<WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t<WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && 2<WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t_work<5 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-8 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work-Worker[1].t_work==-2 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<=6 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && 1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[0].t<4 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<4 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-5 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-5 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-2) || (2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-4 && WorkerSalary[0].s-Worker[1].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && 2<WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<5 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<5 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && Worker[1].t-Worker[1].t_work<=-5 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && 9<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && 4<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<6 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[1].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && Worker[0].t_work<=Worker[1].t_work && Worker[0].t<=2 && Worker[1].t_work<6 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (Worker[0].t_work<5 && Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (Worker[0].t_work<5 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-WorkerSalary[0].s==-10 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t==WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[0].t-WorkerSalary[0].s<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<2 && Worker[1].t==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<4 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t-WorkerSalary[0].s<1 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && Worker[0].t_work==Worker[0].t && Worker[0].t-Worker[1].t_work==-2 && Worker[1].t_work-Worker[1].t==2 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (Worker[0].t_work==2 && 2<WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<2 && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work-WorkerSalary[0].s<=-5 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work-WorkerSalary[0].s<=-4 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 6<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work-WorkerSalary[0].s<=-4 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && Worker[1].t-Worker[1].t_work<=-5 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t-Worker[0].t_work<=-4 && Worker[0].t-WorkerSalary[0].s<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-5 && Worker[0].t-WorkerSalary[0].s<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[0].t-WorkerSalary[0].s<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=5 && WorkerSalary[0].s<5 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<4 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<4 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (6<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (6<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<5 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<=6 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<=6 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=2 && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 6<Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 6<Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=2 && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<5 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[0].t-Worker[1].t_work==-2 && Worker[1].t_work-Worker[1].t==2 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<5 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<5 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t<WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<4 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=6 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-4 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<4 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<4 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==-8 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work-WorkerSalary[0].s<=-8 && Worker[1].t_work<7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && Worker[0].t_work==Worker[0].t && Worker[0].t-Worker[1].t_work==-2 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (1<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<5 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<5 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 2<WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && Worker[0].t_work==Worker[0].t && Worker[0].t-Worker[1].t_work==-2 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (Worker[0].t_work==2 && 2<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<5 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<5 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<5 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (2<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<4 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (5<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<5 && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-4 && WorkerSalary[0].s-Worker[1].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<3 && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<-1 && Worker[1].t==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<4 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<5 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work<3 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work<7 && WorkerSalary[0].s<4 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s==2 && Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-2) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work<3 && Worker[1].t_work<8 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<4 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<5 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<7 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<5 && Worker[0].t_work-Worker[1].t_work==-2 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (2<=Worker[0].t_work && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<5 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (2<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<4 && Worker[1].t_work<6 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<5 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<4 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<8 && WorkerSalary[0].s<5 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s-Worker[1].t_work<-4 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 5<=WorkerSalary[0].s && Worker[0].t_work<4 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<4 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(1<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s==2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-2) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && 8<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<-2 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t-Worker[1].t_work<=-5 && Worker[1].t-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<=6 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[1].t<3 && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==4 && Worker[0].t_work-Worker[0].t==2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (Worker[0].t==2 && 2<WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-Worker[0].t<3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t-Worker[0].t_work<=-5 && Worker[0].t-WorkerSalary[0].s<=-3 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-Worker[0].t<5 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-Worker[0].t<4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(5<=Worker[0].t_work && Worker[0].t==2 && 9<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t==2 && 1<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<=6 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==4 && Worker[0].t_work-Worker[0].t==2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==1 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==1) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t==2 && 1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && 1<WorkerSalary[0].s && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t==2 && 2<WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<5 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[0].t && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<=4 && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work==Worker[1].t && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=Worker[0].t && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<5 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==4 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work==Worker[1].t && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[1].t_work==2 && 2<WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[0].t-Worker[1].t_work==-2 && Worker[1].t_work-Worker[1].t==2 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (1<=Worker[0].t_work && 2<WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<5 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && Worker[0].t_work==Worker[0].t && Worker[0].t-Worker[1].t_work==-2 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<5 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-Worker[1].t<3 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-5 && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<5 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<4 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-Worker[1].t<4 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t-Worker[1].t_work<=-5 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(5<=Worker[0].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && 6<=WorkerSalary[0].s && Worker[0].t_work<5 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[0].t_work && Worker[0].t_work<5 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<6 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-WorkerSalary[0].s==-10 && Worker[1].t_work<=5 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t==WorkerSalary[0].s && Worker[1].t_work<=5 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[0].t<5 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<8 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t-WorkerSalary[0].s==-10 && Worker[1].t_work<=7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t==WorkerSalary[0].s && Worker[1].t_work<=7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 5<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t-WorkerSalary[0].s==-10 && Worker[1].t_work<=6 && Worker[1].t_work-Worker[0].t_work<4 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && 5<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t==WorkerSalary[0].s && Worker[1].t_work<=6 && Worker[1].t_work-Worker[0].t_work<4 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-5 && Worker[0].t-WorkerSalary[0].s<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<5 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-5 && Worker[0].t-WorkerSalary[0].s==-10 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && 7<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-5 && Worker[0].t==WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[0].t_work && 5<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-WorkerSalary[0].s==-10 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<=Worker[0].t_work && 5<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t==WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-WorkerSalary[0].s<=-4 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[0].t<3 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-5 && Worker[1].t_work<6 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s<=Worker[1].t && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && Worker[0].t_work==Worker[0].t && Worker[0].t-Worker[1].t_work==-2 && Worker[1].t_work-Worker[1].t==2 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && 5<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && 8<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(2<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=6 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-4 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work-WorkerSalary[0].s==1 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-3) || (2<=Worker[1].t_work && Worker[0].t_work<3 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=6 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=7 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=7 && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s<3 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-5 && WorkerSalary[0].s-Worker[0].t_work<-7 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work<3 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<4 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<=5 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<=5 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 5<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 5<Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 6<=Worker[1].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 5<Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==-8 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 5<Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (6<Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<=6 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<=6 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (6<=Worker[0].t_work && Worker[0].t==2 && 4<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 6<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<5 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-2) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==-8 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==3 && 5<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-7 && Worker[1].t_work<6 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<4 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<4 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==3 && 5<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==3 && Worker[1].t_work<6 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-8 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[1].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<4 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work<4 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<7 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-Worker[1].t<5 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-WorkerSalary[0].s==-10 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<=6 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t-WorkerSalary[0].s==-10 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (5<Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<=6 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<=7 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t-WorkerSalary[0].s==-10 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (6<Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<=7 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-5 && Worker[1].t-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-Worker[1].t<3 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work<5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-5 && Worker[1].t-WorkerSalary[0].s==-10 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-5 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<Worker[0].t_work && 3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-WorkerSalary[0].s==-10 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (5<Worker[0].t_work && 3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<6 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && Worker[1].t-Worker[1].t_work<=-5 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && 6<=WorkerSalary[0].s && Worker[0].t_work<5 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<=-3 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<5 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-2) || (2<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s-Worker[1].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<-1 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=5 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<7 && WorkerSalary[0].s<3 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work-WorkerSalary[0].s<=6 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-4 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<3 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work-WorkerSalary[0].s<=5 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=6 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work-WorkerSalary[0].s<=7 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[1].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=7 && WorkerSalary[0].s<3 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<4 && WorkerSalary[0].s-Worker[1].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-5 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-7 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(1<=Worker[1].t_work && Worker[0].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[0].t-WorkerSalary[0].s<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<5 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-4 && WorkerSalary[0].s-Worker[1].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<4 && Worker[0].t_work==Worker[1].t_work && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=6 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t<=2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=7 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-5 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<-7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<3 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<5 && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<1 && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 7<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=6 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s<2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-Worker[1].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work<7 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-4 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-5 && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<5 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-5 && Worker[0].t-WorkerSalary[0].s<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[0].t<4 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-5 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[0].t<3 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<8 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t-Worker[0].t_work<=-5 && Worker[1].t_work<8 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[0].t<4 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work-Worker[0].t_work<4 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<Worker[0].t_work && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t-Worker[1].t_work<=-4 && Worker[1].t-WorkerSalary[0].s<=-2 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-5 && Worker[1].t-WorkerSalary[0].s<=-2 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (WorkerSalary[0].s==10 && Worker[0].t_work<=7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work<=7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-4 && Worker[1].t-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (6<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (6<Worker[0].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<5 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(3<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[0].t_work && 7<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s-Worker[1].t_work<-4 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<3 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work<3 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-8 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<7 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<-2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work<5 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<7 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work<5 && Worker[1].t_work<8 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (5<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<8 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(5<=Worker[0].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=2 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=2 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work-Worker[0].t_work<4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work-WorkerSalary[0].s<=-7 && Worker[1].t_work-WorkerSalary[0].s<=-4 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work-Worker[0].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work-WorkerSalary[0].s<=-7 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 6<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work-WorkerSalary[0].s<=-7 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work<5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work<5 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (5<=Worker[0].t_work && Worker[0].t_work<Worker[1].t_work && Worker[1].t_work<6 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=7 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<=7 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<Worker[0].t_work && 5<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<=7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<=7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && 7<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (5<=Worker[0].t_work && 7<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && 2<=WorkerSalary[0].s && Worker[0].t_work<5 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(5<=Worker[0].t_work && Worker[0].t==2 && 2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<4 && WorkerSalary[0].s-Worker[1].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=6 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=5 && WorkerSalary[0].s<4 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<4 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<4 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && 8<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-4 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-4 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-5 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<4 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[1].t_work && Worker[0].t_work<3 && Worker[1].t_work-Worker[0].t_work<5 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-5 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<4 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && 8<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work<5 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work-Worker[1].t_work==-2 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work<=4 && Worker[0].t_work-Worker[0].t==2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-2) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[0].t && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-8 && Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && 2<WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work<4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-4 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<4 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-4 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<=5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-WorkerSalary[0].s<=-5 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-5 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 5<Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<6 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 5<Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<6 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<=5 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<=5 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<6 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<5 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (5<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<5 && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 2<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work<5 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=5 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<=5 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (5<Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && 1<=Worker[1].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (5<Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t_work==2 && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[1].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<2 && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=6 && Worker[1].t==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(5<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[1].t<3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<2 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-3 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<4 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-4 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work<5 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<8 && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<4 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t_work && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==4 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work==Worker[1].t && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (2<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<4 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (4<=Worker[0].t_work && Worker[1].t_work==2 && 2<WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(5<=Worker[0].t_work && Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t-WorkerSalary[0].s<1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[1].t<3 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 2<WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=2 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work<=Worker[1].t_work && Worker[0].t<=2 && Worker[1].t_work<5 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (Worker[0].t_work<4 && Worker[0].t_work<=Worker[1].t_work && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<6 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<4 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<3 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[0].t<=5 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=7 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<5 && WorkerSalary[0].s<1 && WorkerSalary[0].s<Worker[0].t && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t-Worker[1].t_work<-5 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s<1 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(1<=Worker[0].t_work && 6<=Worker[1].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 6<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work-WorkerSalary[0].s<=-7 && Worker[1].t_work<5 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work-WorkerSalary[0].s<=-8 && Worker[1].t_work<7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<5 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (4<=Worker[0].t_work && Worker[0].t_work<Worker[1].t_work && Worker[1].t_work<5 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 5<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 1<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<5 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t==2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<6 && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (6<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<5 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[1].t_work<5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<-1 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<5 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s-Worker[1].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-4 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(2<=WorkerSalary[0].s && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=5 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (6<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (4<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work<Worker[1].t_work && Worker[1].t_work<8 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (6<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (5<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work<Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && 8<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && Worker[0].t==2 && 5<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && Worker[1].t-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-WorkerSalary[0].s==-10 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t==WorkerSalary[0].s && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=4 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[1].t_work==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 1<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==-8 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t-WorkerSalary[0].s==2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t<WorkerSalary[0].s && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[1].t<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=7 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<1 && Worker[0].t_work==Worker[1].t_work && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<-1 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work<5 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (2<=Worker[0].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<7 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<8 && WorkerSalary[0].s<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-8 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<6 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && 6<=WorkerSalary[0].s && Worker[0].t_work<5 && Worker[1].t_work<8 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t-WorkerSalary[0].s==-10 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t==WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(3<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work<7 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work-WorkerSalary[0].s==1 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-3) || (4<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[1].t_work<3 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work<4 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(3<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=5 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work<3 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<4 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<=6 && Worker[1].t_work-Worker[0].t_work<=-3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 3<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s<4 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-4 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (7<=Worker[0].t_work && 4<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-5 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<4 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[1].t<4 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-4 && Worker[1].t-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=2 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<=6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=2 && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t-Worker[0].t_work<=-5 && Worker[0].t-WorkerSalary[0].s<=-3 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[1].t_work && Worker[0].t_work<5 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t_work && Worker[1].t<=2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (Worker[0].t_work<6 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<4 && Worker[1].t_work<=Worker[0].t_work && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<8 && Worker[0].t_work-WorkerSalary[0].s<3 && Worker[1].t_work<4 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<6 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work<6 && Worker[0].t_work==Worker[1].t_work && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[1].t_work==2 && 9<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[1].t_work==2 && 4<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<5 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && 1<=Worker[1].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<6 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<5 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(2<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-8 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && 2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-Worker[0].t<3 && Worker[0].t<=2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<2 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=3 && Worker[1].t==2 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && 9<=WorkerSalary[0].s && Worker[0].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && 6<=WorkerSalary[0].s && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==2 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (7<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<8 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==2 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[1].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && 2<=WorkerSalary[0].s && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(3<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-8 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<-2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work-Worker[0].t_work<=3 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (3<=Worker[0].t_work && 7<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work<3 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[1].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work<4 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-Worker[0].t_work<3 && Worker[1].t_work-WorkerSalary[0].s<=3 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-8 && Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work-Worker[0].t_work<2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Break" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<8 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<2 && WorkerSalary[0].s<4 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(2<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[1].t_work==-2) || (7<=Worker[0].t_work && 2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<4 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s<4 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work<6 && Worker[0].t_work-Worker[1].t_work==2 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s-Worker[0].t_work==-2) || (2<=Worker[1].t_work && 4<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work<3 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Sleep";
			return takeTransition(Worker[1],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work-Worker[1].t_work<2 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<6 && Worker[1].t_work<=Worker[0].t_work && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-4 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[1].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-5 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t-Worker[1].t_work<=-5 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 6<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<1 && Worker[1].t==2 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 9<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t==2 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[0].t_work-WorkerSalary[0].s<-3 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-4 && Worker[1].t-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[0].t_work<5 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-Worker[0].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t-WorkerSalary[0].s<=-5 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-4 && Worker[1].t-WorkerSalary[0].s<=-2 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work==WorkerSalary[0].s && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t_work && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[0].t_work) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work-WorkerSalary[0].s<=5 && WorkerSalary[0].s<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=5 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<4 && WorkerSalary[0].s<5 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<8 && Worker[1].t_work-WorkerSalary[0].s<=6 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<8 && WorkerSalary[0].s<4 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[1].t_work<8 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && 7<=Worker[1].t_work && 1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-5 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<=2 && Worker[1].t_work<7 && WorkerSalary[0].s<4 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work-WorkerSalary[0].s<1 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<4 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==4 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-2 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-3 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t-Worker[1].t_work<=-5 && Worker[1].t-WorkerSalary[0].s<=-3 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-Worker[1].t<5 && Worker[1].t_work<=WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-4 && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-3 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && Worker[1].t<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<6 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t && Worker[1].t_work<7 && Worker[1].t_work<WorkerSalary[0].s && Worker[1].t<=2 && Worker[1].t-Worker[1].t_work<=-2 && WorkerSalary[0].s<9 && WorkerSalary[0].s-Worker[1].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<=Worker[0].t_work && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<WorkerSalary[0].s && Worker[1].t_work<7 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<5 && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==7 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && Worker[0].t_work==Worker[0].t && Worker[0].t-Worker[1].t_work==-2 && Worker[1].t_work-WorkerSalary[0].s==2 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==2) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && 2<WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s<=Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-5 && Worker[1].t_work<=2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-4 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[1].t_work<2 && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==1 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(5<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work-WorkerSalary[0].s<=-4 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 2<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s-Worker[1].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<7 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 5<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s-Worker[1].t_work<2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work-WorkerSalary[0].s<=-2 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 6<=Worker[1].t_work && Worker[0].t_work<=2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<6 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (6<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Sleep" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==2 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<3 && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<5 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-Worker[1].t_work<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-4 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s<=-3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-3 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<9 && WorkerSalary[0].s-Worker[0].t_work<4 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t-Worker[0].t_work<=-5 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<9 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-Worker[0].t<5 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-4 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work-WorkerSalary[0].s<=-7 && WorkerSalary[0].s<9 && WorkerSalary[0].s-Worker[0].t_work<3 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(5<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<=2 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<5 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && Worker[0].t==2 && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t==Worker[1].t_work && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Sleep" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==1 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<5 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<-2 && Worker[0].t<=WorkerSalary[0].s && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && Worker[1].t_work<WorkerSalary[0].s && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<Worker[0].t_work && 1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work-Worker[0].t<3 && Worker[0].t_work-WorkerSalary[0].s<=3 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<=2 && WorkerSalary[0].s-Worker[0].t_work<=-2 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<=WorkerSalary[0].s && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && 7<=WorkerSalary[0].s && Worker[0].t_work<6 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[1].t_work && Worker[0].t_work<7 && Worker[0].t_work-WorkerSalary[0].s<2 && Worker[0].t<=2 && Worker[0].t-Worker[0].t_work<=-2 && Worker[1].t_work<2 && Worker[1].t_work<=Worker[0].t && Worker[1].t_work==Worker[1].t && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<7 && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
	}
	if (Worker[0].state == "Outside" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t-WorkerSalary[0].s==-8 && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==10) || (Worker[0].t_work==2 && 7<=Worker[1].t_work && Worker[0].t_work==Worker[1].t && Worker[1].t_work<8 && Worker[1].t==2 && WorkerSalary[0].s<10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
		if(Worker[0].t_work==2 && 4<=Worker[1].t_work && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==2 && 5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work==Worker[0].t && Worker[0].t==2 && Worker[1].t_work<7 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==6 && salary==1 && counter==0 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(1<=Worker[0].t_work && 4<=Worker[1].t_work && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) || (1<=Worker[0].t_work && 5<=Worker[1].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work<2 && Worker[0].t_work==Worker[0].t && Worker[1].t_work<7 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t>=T_CAR&&t<=TMAX_CAR,t:=0");
		}
		if(4<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[0].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Outside";
			return takeTransition(Worker[1],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
	}
	if (Worker[0].state == "Break" && Worker[1].state == "Home" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==5 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(4<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (4<=Worker[1].t_work && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (4<=Worker[1].t_work && 2<=WorkerSalary[0].s && Worker[0].t_work<8 && Worker[1].t_work-Worker[0].t_work<=-2 && WorkerSalary[0].s<=10 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Outside";
			return takeTransition(Worker[0],"counter<counter_max&&t_work<T_BURNOUT,t:=0,t_work:=0,counter+=1");
		}
		if(4<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work<8 && WorkerSalary[0].s<6 && WorkerSalary[0].s-Worker[1].t_work<=-1 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[1].t_work<=7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[1].t_work<=7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 5<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<=6 && Worker[1].t_work-Worker[0].t_work<4 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && 5<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work<=6 && Worker[1].t_work-Worker[0].t_work<4 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (Worker[0].t_work==3 && 5<Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-7 && Worker[1].t_work<6 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==3 && 5<Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==3 && Worker[1].t_work<6 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (5<=Worker[0].t_work && 3<=WorkerSalary[0].s && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<Worker[0].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[0].t_work-WorkerSalary[0].s<=-1 && Worker[1].t_work<8 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[0].t_work<5 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[0].t_work-WorkerSalary[0].s<-1 && Worker[1].t_work-Worker[0].t_work<3 && WorkerSalary[0].s<7 && WorkerSalary[0].s<Worker[1].t_work && WorkerSalary[0].s==WorkerSalary[1].s) || (Worker[0].t_work==3 && 6<Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==-7 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (Worker[0].t_work==3 && 6<Worker[1].t_work && Worker[0].t_work-WorkerSalary[0].s==3 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && 7<Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-5 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && 7<Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-5 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (3<=Worker[0].t_work && 7<=Worker[1].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<=Worker[0].t_work && 7<=Worker[1].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-4 && Worker[0].t_work-WorkerSalary[0].s<=-2 && Worker[1].t_work<8 && WorkerSalary[0].s<7 && WorkerSalary[0].s==WorkerSalary[1].s) || (2<=Worker[0].t_work && Worker[0].t_work<3 && Worker[0].t_work-Worker[1].t_work<=-3 && Worker[1].t_work-Worker[0].t_work<4 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) || (5<=Worker[0].t_work && Worker[0].t_work<=Worker[1].t_work && Worker[1].t_work<6 && Worker[1].t_work==WorkerSalary[0].s && WorkerSalary[0].s==WorkerSalary[1].s && WorkerSalary[1].s==Worker[1].t_work) 
		{
			Worker[0].state = "Sleep";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0,counter-=1");
		}
	}
	if (Worker[0].state == "Home" && Worker[1].state == "Outside" && WorkerSalary[0].state == "Salary" && WorkerSalary[1].state == "Salary" && Company.state == "Working" &&  && money==3 && salary==3 && counter==1 && Worker[0].id==0 && Worker[1].id==1 && WorkerSalary[0].id==0 && WorkerSalary[1].id==1)
	{
		if(3<Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (3<Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<7 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && WorkerSalary[0].s==10 && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<=5 && WorkerSalary[0].s-WorkerSalary[1].s==10 && WorkerSalary[1].s==0) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<=5 && WorkerSalary[0].s-WorkerSalary[1].s==-10 && WorkerSalary[1].s==10) || (2<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<6 && Worker[1].t_work-WorkerSalary[0].s<=-1 && WorkerSalary[0].s<8 && WorkerSalary[0].s==WorkerSalary[1].s) || (3<=Worker[0].t_work && Worker[0].t_work-Worker[1].t_work<=-2 && Worker[1].t_work<=WorkerSalary[0].s && WorkerSalary[0].s<7 && WorkerSalary[0].s-Worker[1].t_work<1 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[0].state = "Working";
			return takeTransition(Worker[0],"t_work<T_BURNOUT,t:=0");
		}
		if(Worker[1].t_work==2 && 3<=WorkerSalary[0].s && Worker[0].t_work<7 && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s-Worker[0].t_work<-3 && WorkerSalary[0].s==WorkerSalary[1].s) || (4<=Worker[0].t_work && Worker[1].t_work==2 && Worker[0].t_work<=WorkerSalary[0].s && Worker[1].t_work==Worker[1].t && Worker[1].t==2 && WorkerSalary[0].s<5 && WorkerSalary[0].s==WorkerSalary[1].s) 
		{
			Worker[1].state = "Working";
			return takeTransition(Worker[1],"t>=T_BUS&&t<=TMAX_BUS,t:=0");
		}
}