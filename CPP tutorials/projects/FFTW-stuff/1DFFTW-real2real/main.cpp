#include <iostream>
#include <fstream>
#include <fftw3.h> 
#include <cmath>

using namespace std;

/*
    Here we do a fourier transform on real data with real output. For more information, see fftw3 documenta-
    tion pp. 10-13. Important optimizations--along with subtleties--arise for even or odd input functions.
*/


const double PI = 3.14159265359;

int main()
{
    int i = 0;
    const int Npts = 16;
    double* in = (double*) calloc(Npts, sizeof(double)); //Real input array of type double.
    double* out = (double*) calloc(Npts, sizeof(double)); //Real output array of type double
    fftw_r2r_kind kind = FFTW_REDFT00;
    fftw_plan p = fftw_plan_r2r_1d(Npts, in, out, kind, FFTW_ESTIMATE);
    
    /* 
        Setting up of cosine wave:
        Since cosine is an even function, we use the real even DFT. Also, our data is sampled in such a way
        that the function is even about the in[0] element, so we use the FFTW_REDFT00 kind. Sometimes, the 
        data is sampled in such a way such that the function is not even exactly around in[0] but around 
        a "hypothetical index -0.5", i.e., the in[0] value is offseted from the y-axis by half a sample dist-
        ance. In that case, we use FFTW_REDFT10 kind. See fftw3 documentation for more information. 
    */
   
    for(i = 0; i < Npts; i++)
    {
        in[i] = cos(3 * 2 * PI * i/Npts); //Even about the in[0] value.
    }

    /* Printing of input */
    /*
    for(i = 0; i < Npts; i++)
    {
        printf("input: %3d %+9.5f\n", i, in[i]);
    }
    */

    /* Executing of fourier transform */
    fftw_execute(p);

    /* Printing of result */
    printf("\n");
    
    for(i = 0; i < Npts; i++)
    {
        printf("freq: %3d %+9.5f\n", i, out[i]);
    }

    /* PROBLEM: The output is not what I expected. Why are there non-zero values for k!=3 and k!=13?
                Also, the output changes depending on whether kind is defined before or after the plan
                definition. I must have some undefined behavior somewhere.
                See: https://stackoverflow.com/questions/70617062/c-output-depends-on-global-variable-initialization
     */

    fftw_destroy_plan(p);
    free((void*)in); free((void*)out);

    return 0;
}