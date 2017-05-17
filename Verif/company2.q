//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*

*/
A[] forall(i:car_t) not Car(i).Burnout

/*

*/
A[] not Company.Bankrupt

/*

*/
E<> LBudget && now < 45 && money == MONEY_MAX

/*

*/
E<> MBudget && now < 37 && money == MONEY_MAX

/*

*/
E<> HBudget && now < 21 && money == MONEY_MAX

/*

*/
E<> now < 37 && money == MONEY_MAX

/*

*/
A[] not deadlock
