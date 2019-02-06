// Joshua F. Mathews
// Project 1
// Operating Systems Design
// 6 February 2019
//
// This program calculates the current date and time
// in milliseconds, then times the babylonian squareroot
// of 42.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct timespec spec;

void printTime() {
    // C99 Was giving me an error for 
    // this array being a global.
    const char *month[12];
    month[0] = "January";
    month[1] = "February";
    month[2] = "March";
    month[3] = "April";
    month[4] = "May";
    month[5] = "June";
    month[6] = "July";
    month[7] = "August";
    month[8] = "September";
    month[9] = "October";
    month[10] = "November";
    month[11] = "December";

    time_t t = time(NULL);
    struct tm tm = * localtime(&t);
    clock_gettime(CLOCK_REALTIME, &spec);
    long ms = spec.tv_nsec / 1000000;
    printf("Current Time: %d %s, %d %d:%d:%d.%ld\n", tm.tm_mday, month[tm.tm_mon], tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, ms);
}

double sqrt(double n) {
    double x = n;
    double y = 1;
    double e = 0.000001;
    while( x - y > e) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

int main() {
    printTime();
    clock_t start, end;
    double delta_t;
    start = clock();
    fprintf(stdout, "The square root of %f is %f\n", 42.0, sqrt(42.0));
    end = clock();
    delta_t = ((double) (end - start)) / (CLOCKS_PER_SEC * 1e-3);
    fprintf(stdout, "This took %lf milliseconds.\n", delta_t);
    return 0;
}