Raymond Luu
11/15/2013
TCES 422
Exercise 6

In this assignment I went about completing it by combining my knowledge from exercise 5 and tutorial 3. I first started out by getting the threads set up so that both LED's were blinking similar to tutorial 3 at .5sec and it worked. Then I moved onto changing the time to match the assignment and watched them work. After that I followed the instructions in adding mutexes to the threads where I thought it needed to lock and unlock for the LED's to light up alternating. Only place they could really go is in between the time it turns on and off for both threads. Thats about all I had to do to accomplish this assignment.

1) When the threads blinked at 2 second intervals, both LED's ran in sync with each other both lighting up at the same time and then turning off at the same time.

2) Using the mutexes made the LED's alternate because whichever thread started first because of the race condition, the other would be on hold and pretty much delayed until it can get that lock on the mutex and continue. That made the lights alternate as one turned on the other was waiting to turn on and from there just made it alterate.