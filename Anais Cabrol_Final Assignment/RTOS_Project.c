#include <stdio.h>
#include <windows.h> // utile car on travail sur windows

// Define the tasks
#define NUM_TASKS 4

#define TASK1_PERIOD_MS 1000
#define TASK2_PERIOD_MS 2000
#define TASK3_PERIOD_MS 3000
#define TASK4_PERIOD_MS 4000

#define LIST_SIZE 50
#define SEARCH_ELEMENT 25

// Declare mutex
HANDLE hMutex;

// Task control block
typedef struct {
    void (*task)(void);
    unsigned long period;
    unsigned long last_run;
} Task;

// Function declarations
void task1(void);
void task2(void);
void task3(void);
void task4(void);

// Define the tasks
Task tasks[NUM_TASKS] = {
    {&task1, TASK1_PERIOD_MS, 0},
    {&task2, TASK2_PERIOD_MS, 0},
    {&task3, TASK3_PERIOD_MS, 0},
    {&task4, TASK4_PERIOD_MS, 0}
};

// Task 1: "Working" car c'est working
void task1(void) {
    printf("Task 1  :  it seems that everythingin this RTOS is working very well\n");
} 

// Task 2: Conversion farhenheit -> celsius
void task2(void) {
    float fahrenheit;

    printf("Task 2  :  Enter the temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    float celsius = (fahrenheit - 32) * 5 / 9; // conversion (32 °F − 32) × 5/9 = 0 °C
    printf("    %.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
}

// Task 3: Multiplication
void task3(void) {
    WaitForSingleObject(hMutex, INFINITE);

    long int a;
    long int b;

    printf("Task 3  :  Enter a first long number: ");
    scanf("%ld", &a);
    printf("    Now enter a second long number whih will mutliply the first one : ");
    scanf("%ld", &b);

    long long c = a * b;
    printf("    Result : %.2lf * %.2lf = %lld\n", (double)a, (double)b, c);
    ReleaseMutex(hMutex);
}



// Task 4: Binary search a list of 50 elements
void task4(void) {
    WaitForSingleObject(hMutex, INFINITE);

    int list[LIST_SIZE];
    for (int i = 0; i < LIST_SIZE; i++) {
        list[i] = i;
    }

    int first = 0, last = LIST_SIZE - 1, middle;

    while (first <= last) {
        middle = (first + last) / 2;
        if (list[middle] == SEARCH_ELEMENT) {
            printf("Task 4  :  Element %d found at index %d\n", SEARCH_ELEMENT, middle);
            break;
        } else if (list[middle] < SEARCH_ELEMENT) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }
    }

    ReleaseMutex(hMutex);
}

// Scheduler
DWORD WINAPI scheduler(LPVOID lpParam) {
    while (1) {
        for (int i = 0; i < NUM_TASKS; i++) {
            if ((unsigned long)(GetTickCount() - tasks[i].last_run) >= tasks[i].period) {
                tasks[i].task();
                tasks[i].last_run = GetTickCount();
            }
        }
        Sleep(1);
    }
    return 0;
}


// main
int main() {
    HANDLE scheduler_thread;

    hMutex = CreateMutex(NULL, FALSE, NULL);
    if (hMutex == NULL) {
        printf("CreateMutex error: %d\n", GetLastError());
        return 1;
    }

    scheduler_thread = CreateThread(NULL, 0, scheduler, NULL, 0, NULL);
    if (scheduler_thread == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return 1;
    }

    WaitForSingleObject(scheduler_thread, INFINITE);

    CloseHandle(hMutex);

    return 0;
}


//