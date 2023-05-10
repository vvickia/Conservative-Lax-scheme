#ifndef IFUN_INCLUDED
#define IFUN_INCLUDED

int init_grid(double* x, double* t, int N, int M, double grid_step, double time_step, double a, double b);
int set_ic(double** func, int N, int M, double grid_step);

#endif