#include <fstream>
#include "headers/iof.h"
#include "headers/de_allocate.h"
#include "headers/init_functions.h"
#include "headers/lax.h"

using namespace std;

/*
    Simulate a one-dimensional transport equation
        ∂u/∂t + a * ∂u/∂x = 0,
    where advection rate a = 1.
    Initial conditions:
                  0.4,        x < 0.4,
        u(0, x) = 0.8,  0.4 ≤ x ≤ 0.6,
                  0.4         x > 0.6.
    Boundary conditions are periodic, in a region x ∈ [0; 1].
*/

int main()
{
// Model parameter initialization:

    double a, x_L, x_R, C; // a is advection rate
                           // x_L, x_R are coordinates of the left and right boundary of the solution search area
                           // C is Courant number
    int N, M;              // numbers of nodes and time layers, respectively

    data_input(a, x_L, x_R, N, M, C);

// Allocation of memory to dynamic variables:

    double ** u = create_array(N, M);     // array of function values u
    double * coordinates = new double[N]; // array of x coordinates
    double * time_layers = new double[M]; // t time array

// Computational grid initialization:

    double delta_x = (x_R - x_L) / (N - 1); // grid step
    double delta_t = delta_x * C / a;       // time step

    init_grid(coordinates, time_layers, N, M, delta_x, delta_t, x_L, x_R);

// Time counter initialization:

    double t = time_layers[1];
    double t_stop = 1; // can't be greater than time_layers[M-1]

// Setting initial conditions:

    set_ic(u, N, M, delta_x);

// Main calculation cycle:

    Lax(t, t_stop, delta_t, N, u, C);

// Shutdown:

    save_results(coordinates, time_layers, N, M, u);

// Freeing allocated memory:

    free_array(u);
    delete [] coordinates;
    delete [] time_layers;

    return 0;
}
