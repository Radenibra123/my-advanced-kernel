#include "task.h"

#define MAX_TASKS 10

typedef struct {
    void (*task_func)();
    int active;
} task_t;

static task_t tasks[MAX_TASKS];
static int current_task = 0;
static int task_count = 0;

void add_task(void (*task_func)()) {
    if (task_count < MAX_TASKS) {
        tasks[task_count].task_func = task_func;
        tasks[task_count].active = 1;
        task_count++;
    }
}

void schedule() {
    if (task_count == 0) return;
    if (tasks[current_task].active) {
        tasks[current_task].task_func();
    }
    current_task = (current_task + 1) % task_count;
}
