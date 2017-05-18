//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*

*/
A[] LBudget==true imply not exists (i:car_t)  Person(i).Burnout

/*

*/
E[] not exists(i:car_t) Person(i).Burnout

/*

*/
A[] forall(i:car_t) not Person(i).Burnout

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
Person(0) ne travaille jamais
*/
E[] not Person(0).Working

/*

*/
E<> now > 5 

/*

*/
E<> LBudget && now < 10 && money == MONEY_MAX

/*

*/
E<> MBudget && now < 15 && money == MONEY_MAX

/*

*/
E<> HBudget && now < 35 && money == MONEY_MAX

/*

*/
E<> now < 37 && money == MONEY_MAX

/*

*/
A[] not deadlock
