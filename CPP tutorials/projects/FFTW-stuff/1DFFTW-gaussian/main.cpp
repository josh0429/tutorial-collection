#include <iostream>
#include <fstream>
#include <fftw3.h> 
#include <cmath>

/*
    Here we do a fourier transform on a gaussian.
*/


const double PI = 3.14159265359;

int main()
{
    int i;
    const int Npts = 16;
    double* in; //Real array of type double.
    fftw_complex* out; //Complex array of double[2]. real part: out[i][0]; imaginary part: out[i][1].
    fftw_plan p;

    /* Setting up of fftw plan */
    in = (double*) std::calloc(Npts, sizeof(double) * Npts);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * Npts/2 + 1); //For r2c plans, we only need an
    //output array of size N/2 + 1 since the rest of the output is redundant.
    

    p = fftw_plan_dft_r2c_1d(Npts, in, out, FFTW_ESTIMATE); //Real time-data to complex frequency-data

    /* 
        Setting up of cosine wave:
        Note that in the definition below, our function is defined on the domain [0,T] where T=1. In this
        case, the frequency sampling interval is delta_nu = 1/T = 1. Hence, we should expect a peak at 
        out[3][0], since index k=3 is the one that corresponds to frequency value 3: nu_3 = 3*delta_nu = 3.
    */
    for(i = 0; i < Npts; i++)
    {
        in[i] = cos(3 * 2 * PI * i/Npts);
    }

    /* Executing of fourier transform */
    fftw_execute(p);

    /* Printing of result */
    std::cout << std::endl;
    for(i = 0; i < (Npts/2 + 1); i++)
    {
        printf("freq: %3d %+9.5f %+9.5f I\n", i, out[i][0], out[i][1]);
    }

    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);
    

    return 0;
}