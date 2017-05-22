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
true
*/
A[] (Worker(0).Working && Worker(1).Working)  imply counter_max>=2

/*
true
*/
A[] Company.Small imply not (Worker(0).Working && Worker(1).Working) 

/*
Safety
*/
//NO_QUERY

/*

*/
E[] not exists(i:worker_t) Worker(i).Burnout and money > 0

/*

*/
A[] money > 0

/*

*/
A[] not exists(i:worker_t) Worker(i).Burnout 

/*

*/
E[] (not exists(i:worker_t) Worker(i).Burnout) and money>0 and budgetH and neverCar

/*

*/
E[]  money > 5 and budgetH and not exists(i:worker_t) (Worker(i).Burnout)

/*

*/
E[] wallet >0 

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
//NO_QUERY

/*

*/
E<> Worker(i).Burnout and money > 0 and budgetH

/*

*/
//NO_QUERY

/*
! not burnout trivial
*/
E<> rework && not exists(i:worker_t) Worker(i).Burnout

/*

*/
E<> wallet == MONEY_MAX

/*

*/
A[] Worker(0).Burnout imply Worker(0).t_work >= T_BURNOUT

/*
Safety
*/
//NO_QUERY

/*

*/
E<> budgetL && t_global < 13 && money == MONEY_MAX

/*

*/
E<> budgetL && t_global < 12 && money == MONEY_MAX

/*

*/
E<> budgetM && t_global < 5 && money == MONEY_MAX

/*

*/
E<> budgetM && t_global < 4 && money == MONEY_MAX

/*

*/
E<> budgetH && t_global < 3 && money == MONEY_MAX

/*

*/
E<> budgetH && t_global < 2 && money == MONEY_MAX

/*

*/
A[] (wallet<WALLET_CRITICAL) imply not (Worker(0).Home and Worker(1).Home)

/*

*/
A<> (Worker(0).Working or Worker(1).Working)

/*

*/
A[] Worker(0).Lazy imply counter==counter_max

/*

*/
A[] not deadlock
