//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*

*/
A[] not deadlock

/*

*/
A[] not (car1.Parked && car2.Parked && car3.Parked)

/*

*/
E<> car1.Parked && car2.Parked

/*

*/
A[] car1.WaitingToLeave imply (not car2.WaitingToLeave)

/*

*/
A[] car1.WaitingToEnter imply (not car2.WaitingToEnter)

/*

*/
A[] car1.Entering imply (entrance.Opened)

/*

*/
A[] car1.Inside && car2.Inside imply (not entrance.Opened)

/*

*/
A[] car1.Entering imply (not entrance.Closed)

/*

*/
A[] car1.Parked && car2.Parked imply (not entrance.Opened)
