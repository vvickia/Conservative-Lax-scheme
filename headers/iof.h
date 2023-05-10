#ifndef IOF_INCLUDED
#define IOF_INCLUDED

bool data_input(double& advection_rate, double& a, double& b, int& N, int& M, double& Courant_number);
bool save_results(double* x, double* t, int N, int M, double** func);

#endif
