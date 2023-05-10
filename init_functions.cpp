#include "headers/init_functions.h"
#include "headers/iof.h"
#include "headers/de_allocate.h"
#include "headers/lax.h"

// Spatial grid initialization function

// x, t are arrays of coordinates (N size) and time (M_size), respectively
// grid_step is grid spacing
// time_step is time step
// a, b are left and right boundaries of the solution search area, respectively

int init_grid(double* x, double* t, int N, int M, double grid_step, double time_step, double a, double b)
{
    x[0] = a;
    for (size_t j = 1; j != N - 1; ++j) {
        x[j] = j * grid_step;
    }
    x[N - 1] = b;

    t[0] = 0.0;
    for (size_t n = 1; n != M; ++n) {
        t[n] = n * time_step;
    }

    return 0;
}

// Initial condition setting function

// N, M are sizes of arrays of coordinates and time, respectively
// grid_step is grid spacing
// func is unknown function

int set_ic(double** func, int N, int M, double grid_step)
{
    for (size_t j = 0; j != N; ++j)
    {
        double x = j * grid_step;
        if ((x < 0.4) || (x > 0.6))
            func[j][0] = 0.4;
        else if ((0.4 <= x) && (x <= 0.6))
            func[j][0] = 0.8;
    }

    return 0;
}
