#include "convolutional.h"
#include "matrix.h"
/** 
 *@file convolutional.cpp
 *@brief convolutional realization with run_convolutional function
 *@function run_convolutional()
 */
void run_convolutional(const Matrix& input, const Matrix& core, Matrix& out)
{
    int sum = 0;
    int ax=0;
    int ay=0;
    int cy=0;
    int cx=0;
    for (int k = 0; k < out.getZ(); k++)
    {
        for (int i = 0; i < out.getY(); i++)
        {
            for (int j = 0; j < out.getX(); j++)
            {
                ax = j;
                ay = i;
                cy = 0;
                cx = 0;
                while (ay < i + core.getY())
                {
                    while (ax < j + core.getX())
                    {
                        sum += core.get_matrix_value(k,cy,cx) * input.get_matrix_value(k, ay, ax);
                        cx++;
                        ax++;
                    }
                    ay++;
                    cy++;
                    cx = 0;
                    ax = j;
                }
                out.set_matrix_with_value(k,i,j,sum);
                sum = 0;
            }
        }
    }

  
}
