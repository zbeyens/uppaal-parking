//This file was generated from (Academic) UPPAAL 4.1.4 (rev. 5535), March 2014

/*

*/
A[] not (car1.Parked && car2.Parked && car3.Parked)

/*

*/
control: A[] car1.ExitRequest imply (not car2.ExitRequest)

/*

*/
control: A[] car1.EnterRequest imply (not car2.EnterRequest)

/*

*/
control: A[] car1.Entering imply (entrance.Opened)

/*

*/
control: A[] car1.Inside && car2.Inside imply (not entrance.Opened)

/*

*/
A[] car1.Entering imply (not entrance.Closed)

/*

*/
A[] car1.Parked && car2.Parked imply (not entrance.Opened)
