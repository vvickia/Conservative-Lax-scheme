#include <iostream>
#include <fstream>
#include "headers/iof.h"
#include "headers/de_allocate.h"
#include "headers/init_functions.h"
#include "headers/lax.h"

using namespace std;

// The function of reading data from a file

// a, b are left and right boundaries of the solution search area, respectively
// N, M are sizes of arrays of coordinates and time, respectively

bool data_input(double& advection_rate, double& a, double& b, int& N, int& M, double& Courant_number)
{
    ifstream input("input.txt");
    if (!input.is_open())
    {
        cout << "Error opening file " << "input.txt" << endl;
        return false;
    }

    if (!(input >> advection_rate >> a >> b >> N >> M >> Courant_number))
    {
        cout << "Error reading data from file " << "input.txt" << endl;
        return false;
    }
    input.close();

    return true;
}

// The function of saving the program result to a file

// x, t are arrays of coordinates (N size) and time (M_size), respectively
// func is unknown function

bool save_results(double* x, double* t, int N, int M, double** func)
{
    ofstream output("results.txt");
    if (output.is_open())
        for (size_t n = 0; n != M; ++n)
            for (size_t j = 0; j != N; ++j)
                output << x[j] << " " << t[n] << " " << func[j][n] << endl;
    output << '\n';
    output.close();

    return true;
}
