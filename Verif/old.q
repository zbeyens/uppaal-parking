//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*

*/
E[] not exists(i:worker_t) Worker(i).Burnout

/*

*/
A[] forall(i:worker_t) not Worker(i).Burnout

/*

*/
E[] not Company.Bankrupt

/*

*/
A[] not Company.Bankrupt

/*

*/
A[] wallet > 0

/*

*/
A[] (Worker(0).Working && Worker(1).Working)  imply counter_max>=2

/*

*/
A[] Company.Small imply not (Worker(0).Working && Worker(1).Working) 

/*

*/
E[] not rework && not exists(i:worker_t) Worker(i).Burnout

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

*/
E[] wallet < MONEY_MAX

/*

*/
E[] money < MONEY_MAX and wallet < MONEY_MAX

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
