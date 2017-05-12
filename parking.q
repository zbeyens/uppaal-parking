//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*

*/
E<> car1.Parked && car2.Parked

/*

*/
A[] car1.Waiting imply (not car2.Waiting)

/*

*/
A[] car1.Parked && car2.Parked imply (not entrance.Opened)
