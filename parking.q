//This file was generated from (Academic) UPPAAL 4.1.4 (rev. 5535), March 2014

/*
Reachable
*/
E<> Car(0).Working && Car(1).Working

/*

*/
E<> entrance.Opened && exit.Opened

/*

*/
E<> Car(0).EnterRequest && Car(1).Entering && Car(2).Entered

/*

*/
E<> Car(0).ExitRequest && Car(1).Exiting && Car(2).Exited

/*
Safety
*/
A[] not deadlock

/*
mutex
2 cars can not request to enter at the same time
*/
A[] not (Car(0).EnterRequest && Car(1).EnterRequest) and not (Car(0).Entering && Car(1).Entering) and not (Car(0).Entered && Car(1).Entered) and not (Car(0).ExitRequest && Car(1).ExitRequest) and not (Car(0).Exiting && Car(1).Exiting) and not (Car(0).Exited && Car(1).Exited)

/*
limit size of parking
*/
A[] counter <= COUNTER_MAX && counter >= 0

/*
only 2 place
*/
A[] not (forall (i:car_t) Car(i).Inside)

/*
entrance gate should be opened when entering
*/
A[] exists (i:car_t) Car(i).Entering imply entrance.Opened

/*

*/
A[] exists (i:car_t) Car(i).Exiting imply exit.Opened

/*

*/
control: A[] money < 900

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
