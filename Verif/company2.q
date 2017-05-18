//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

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
A[] not (Person(0).Working && Person(1).Working)

/*

*/
E[] not rework && not exists(i:car_t) Person(i).Burnout

/*

*/
E<> rework && not exists(i:car_t) Person(i).Burnout

/*

*/
E<> wallet == MONEY_MAX

/*

*/
E<> now > 50 imply money < MONEY_MAX

/*

*/
E<> LBudget && now < 20 && money == MONEY_MAX

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
