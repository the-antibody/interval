# interval
JS-like interval &amp; timeout functions for C.

# About
Interval is a javascript-like library for C. It allows you to set timeouts and intervals in a similar fashion to how you would in native JavaScript.<br />
This project uses multithreading to allow for concurrent intervals.

# How to Use
**How to create a timeout (delay):**
```c
// create a timeout
interval_object timeout = {
  1000, // this is the delay (ms)
  function, // reference a function
};

// run the timeout
set_timeout(&timeout);
```
**How to create an interval (delayed repeating task):**
```c
// create an interval
interval_object interval = {
  1000, // this is the interval's delay (ms)
  function, // reference a function
};

// run the interval
set_interval(&interval);
```
