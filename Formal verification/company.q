//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*
Correctness
*/
//NO_QUERY

/*
Safety
*/
//NO_QUERY

/*

*/
A[] not deadlock

/*
true
*/
A[] (Worker(0).Working && Worker(1).Working)  imply counter_max>=2

/*
true
*/
A[] Company.Small imply not (Worker(0).Working && Worker(1).Working) 

/*

*/
A[] Worker(0).Burnout imply Worker(0).t_work >= T_BURNOUT

/*
Liveness
*/
//NO_QUERY

/*

*/
A<> (exists(i:worker_t) Worker(i).Working)

/*

*/
A<> (exists(i:worker_t) Worker(i).Sleep)

/*
false
*/
Worker(0).Home and Worker(0).t==TMAX_IDLE and counter==counter_max and  --> Worker(0).Holiday or Worker(0).Unemployed

/*
true
*/
Worker(0).Break and Worker(0).t_work == TMAX_BURNOUT --> Worker(0).Burnout

/*
Reachability
*/
//NO_QUERY

/*

*/
E<> budgetL and t_global<6 and Company.Big and wallet==MONEY_MAX

/*

*/
E<> budgetL and t_global<5 and Company.Big and wallet==MONEY_MAX

/*

*/
E<> budgetL and Company.Big

/*
false
*/
E<> budgetL and Company.Big and neverRework

/*

*/
E<> budgetM and Company.Big and neverRework

/*
Safety
*/
//NO_QUERY

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money > 0

/*

*/
A[] money > 0

/*

*/
A[] not exists(i:worker_t) Worker(i).Burnout 

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money>0 and budgetH

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money>0 and budgetH and neverRework

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money>0 and budgetM and neverRework

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money>0 and budgetH and neverCar

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money>0 and budgetM and neverCar 

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money>0 and budgetM and neverCar and neverBus

/*

*/
A[] wallet > 0

/*

*/
E[] wallet < MONEY_MAX

/*

*/
E[] money < MONEY_MAX and wallet < MONEY_MAX

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money>0 and neverCar and neverHoliday and neverLazy

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money>0 and neverBus and  neverCar and neverHoliday and neverLazy

/*
Liveness
*/
//NO_QUERY
