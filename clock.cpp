#include <iostream>
#include <iomanip> 
/*
 * 
 * Damian Ackley 
 * 2/27/2022
 * CS-210-H7826 Programming Languages 22EW3
 */

using namespace std;

// placing integers hours, minutes and seconds.
int Clock() { 
    int hours;
    int min;
    int sec;

    cout << "Enter Hours" << endl;
    cin >> hours;
    cout << "Enter Minutes" << endl;
    cin >> min;
    cout << "Enter Seconds" << endl;
    cin >> sec;
    int setTime = hours*60*60 + min*60 + sec;
    return setTime; // should show what the adjusted time will be.
}
int setHours(){ // will return actual value
    int hours = 10;
    return hours;
}
int setMinutes(){ // will return actual value
    int minutes = 17;
    return minutes;
}
int setSeconds(){ // will return actual value
    int seconds = 22;
    return seconds;
}
int clockDisplay(int hours, int min, int sec){
    string timeAllocation;
    int standardTime;
    int input = 0;
    while(input != 4) {

        if (hours >= 12 && hours <= 24) { //will change am to pm or vise versa
            timeAllocation = "PM";
        } else {
            timeAllocation = "AM";
        }
        if (hours > 12) {
            standardTime = hours - 12; //will change to standard
        } else {
            standardTime = hours;
        }
        if (sec > 59) { // will add one min if secs go over 60
            min += 1;
            sec -= 60;
        }
        if (min > 59) { // will add one hour if min go over 60
            hours += 1;
            standardTime += 1;
            min -= 60;
        }
        if (hours > 24){ // will change to 0 when hours exceed 23:59
            hours = 0;
            standardTime = 0;
        }

        input = 0; //will reset

        while (input == 0) {
            sec += 1;
            // building in format with file
            cout.fill('0');
            cout << "**************************    **************************" << endl
                 << "*      12-Hour Clock     *    *      24-Hour Clock     *" << endl <<
                 "*      " << setw(2) << standardTime << ":" << setw(2) << min << ":" << setw(2) << sec << " "
                 << timeAllocation << "       *" << "    *      " << setw(2) << hours << ":" << setw(2) <<  min << ":"
                 << setw(2) <<  sec << "          *" << endl
                 << "**************************    **************************"  << endl;
            cout << "**************************" << endl << "* 1 - Add One Hour       *" << endl
                 << "* 2 - Add One Minute     *" << endl << "* 3 - Add One Second     *" << endl
                 << "* 4 - Exit Program       *" << endl << "**************************" << endl;
            cin >> input;
            continue;
        }
        switch (input) { // this wil allow adjustment
            case 1:
                hours += 1;
                break; // allows for selection to stop
            case 2:
                min += 1;
                break; // allows for selection to stop
            case 3:
                sec += 1;
                break; // allows for selection to stop
            case 4:
                break; // allows for selection to stop
                cout << "Please enter a valid selection" << endl;
                break; // allows for selection to stop
        }
        continue; // keeps switch going while inputs are placed
    }
    return 0; // will stop the program after no more inputs are placed

}
int main() {
    clockDisplay(setHours(), setMinutes(), setSeconds());