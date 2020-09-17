#include <iostream>
#include "matrix.h"
#include "convolutional.h"
#include <string>

int main()
{
    Matrix input(1, 32, 32);
    input.read_from_file("Patterninput_1x32x32.txt");
    Matrix core(1, 5, 5);
    core.read_from_file("Patterncore_1x5x5.txt");
    Matrix output(input.getZ(), input.getY() - core.getY() + 1, input.getX() - core.getX()+1);
    run_convolutional(input, core, output);
    output.write_to_file("Patternoutput_1x28x28.txt");
    output.display_matrix();
    std::cout << "test passed correctly" << std::endl;
    return 0;
}
