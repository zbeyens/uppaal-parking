//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*

*/
A[] LBudget==true imply not exists (i:car_t)  Car(i).Burnout

/*

*/
E[] MBudget==true && not exists (i:car_t)  Car(i).Burnout

/*

*/
E[] LBudget==true && not exists (i:car_t)  Car(i).Burnout

/*

*/
A[] forall(i:car_t) not Car(i).Burnout

/*

*/
A[] not Company.Bankrupt

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
