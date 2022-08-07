#include <stdio.h>

#include "interval.h"

// declare functions
void timeout_function();
void interval_function();

int main()
{
    // print timeout
    printf("Setting timeout delay for 2 seconds...\n");

    // create timeout
    interval_object timeout = {
        2000,
        timeout_function
    };

    // set timeout
    set_timeout(&timeout);

    // print interval
    printf("Creating repeating interval every second...\n");

    // create interval
    interval_object interval = {
        1000,
        interval_function
    };

    // set interval
    set_interval(&interval);

    return 0;
}

/**
 * @brief The function for the timeout
 */
void timeout_function()
{
    printf("%s\n", "Timeout complete.");
}

/**
 * @brief The function for the interval
 */
void interval_function()
{
    printf("Interval repeat.\n");
}
