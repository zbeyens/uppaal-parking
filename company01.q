//This file was generated from (Academic) UPPAAL 4.1.4 (rev. 5535), March 2014

/*
control: A[ (not exists (i:car_t) Car(i).Burnout) and Company.Working U money==10]
*/
//NO_QUERY

/*
control: A[] (not exists (i:car_t) Car(i).Burnout) and Company.Working and rework==false
*/
//NO_QUERY

/*

*/
control: A[] (not exists (i:car_t) Car(i).Burnout) and Company.Working

/*
(Company.Startup and (money == MIN_UPGRADE)) --> Company.Upgraded
*/
//NO_QUERY

/*
Car(0).Outside --> Car(0).Working
*/
//NO_QUERY

/*
A[] not(Car(0).Working and Car(1).Working and Company.Startup)
*/
//NO_QUERY

/*
E<> Car(0).Working && Car(1).Working
Reachable
*/
//NO_QUERY

/*
E<> Car(0).Outside && Car(1).Working
*/
//NO_QUERY

/*
E<> Car(0).Exited && Car(1).Working
*/
//NO_QUERY

/*
A[] not deadlock
*/
//NO_QUERY

/*
A[] counter <= counter_max && counter >= 0
*/
//NO_QUERY

/*
A[] not (forall (i:car_t) Car(i).Working)
*/
//NO_QUERY

/*

*/
//NO_QUERY

/*
control: A[] exit.Opened imply exitIn.Activated
*/
//NO_QUERY

/*
??
control: A[] counter == COUNTER_MAX imply E<> exit.Opened
*/
//NO_QUERY

/*
??
control: A< (not entrance.Opened) U (car1.Entering or car2.Entering or car3.Entering)>
*/
//NO_QUERY

/*

*/
//NO_QUERY
