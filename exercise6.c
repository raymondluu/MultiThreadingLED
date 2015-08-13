//exercise6.c

/* Program: Multi-threading class with LED's
   Purpose: Exercise 6
   File: exercise6.c
   Programmer: Raymond Luu
   Date: 11/15/2013
   Description: To learn Multithreaded programming for RPi GPIO
*/

#include <stdio.h>
#include <pthread.h>
#include <wiringPi.h>

void* led_one();
void* led_two();

// mutex
pthread_mutex_t lock_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Function: main
   Uses library: stdio.h, pthread.h, wiringPi.h
   Recieves: void
   Returns: int
*/

int main(void)
{    
    pthread_t led_one_thread;
    pthread_t led_two_thread;
    
    int led_one_thread_ret = pthread_create(&led_one_thread, NULL, led_one, NULL);
    int led_two_thread_ret = pthread_create(&led_two_thread, NULL, led_two, NULL);
    
    if(led_one_thread_ret != 0)
    {
        printf("Thread fail to create! Error: %d", led_one_thread_ret);
        return 1;
    }
    if(led_two_thread_ret != 0)
    {
        printf("Thread fail to create! Error: %d", led_two_thread_ret);
        return 1;
    }
    
    pthread_join(led_one_thread, NULL);
    pthread_join(led_two_thread, NULL);
    
    pthread_mutex_destroy(&lock_mutex);
    pthread_exit(NULL);
    
    return 0;
}

/* Function: LED one thread
   Uses library: stdio.h, pthread.h, wiringPi.h
   Recieves: void parameter
   Returns: void*
*/
void* led_one(void)
{
    int i = 0;
    
    if (wiringPiSetup() == -1)
    {
        return (void*) 1;
    }
    
    pinMode (0, OUTPUT);
    
    for (;;) //(i = 0; i < 5; i++)
    {
        // lock mutex
        pthread_mutex_lock(&lock_mutex);
        
        // LED 1 ON
        digitalWrite(0, 1);
        delay(2000);
        
        // unlock mutex
        pthread_mutex_unlock(&lock_mutex);
        
        // LED 1 OFF
        digitalWrite(0, 0);
        delay(2000);
    }
}

/* Function: LED two thread
   Uses library: stdio.h, pthread.h, wiringPi.h
   Recieves: void parameter
   Returns: void*
*/

void* led_two(void)
{
    int i = 0;
    
    if (wiringPiSetup() == -1)
    {
        return (void*) 1;
    }
    
    pinMode (1, OUTPUT);
    
    for (;;) //(i = 0; i < 5; i++)
    {
        // lock mutex
        pthread_mutex_lock(&lock_mutex);
        
        // LED 2 ON
        digitalWrite(1, 1);
        delay(2000);
        
        // unlock mutex
        pthread_mutex_unlock(&lock_mutex);
        
        // LED 2 OFF
        digitalWrite(1, 0);
        delay(2000);
    }
}