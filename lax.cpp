#include <cmath>
#include <iostream>
#include "headers/lax.h"
#include "headers/iof.h"
#include "headers/de_allocate.h"
#include "headers/init_functions.h"

using namespace std;

// The function of saving the program result to a file

// x, t are arrays of coordinates (N size) and time (M_size), respectively
// func is unknown function

int Lax(double time_counter, double t_stop, double time_step, int N, double** func, double parameter)
{
    while (time_counter <= t_stop)
    {
        // calculation of the grid solution at a new time layer
        int n = round((double)time_counter / time_step);
        for (int j = 1; j != N - 1; ++j)
        {
            func[j][n] = 0.5 * (func[j + 1][n - 1] + func[j - 1][n - 1]) - 
                      0.5 * parameter * (func[j + 1][n - 1] - func[j - 1][n - 1]);
        }

        // periodic boundary conditions
        func[0][n] = func[N - 2][n];
        func[N - 1][n] = func[1][n];

        // time counter update
        time_counter += time_step;
    }

    return 0;
}
