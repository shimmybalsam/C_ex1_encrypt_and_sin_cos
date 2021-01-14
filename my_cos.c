//
// Created by Shimmy on 8/2/2018.
//

/**
 * @file my_cos.c
 * @author  Shimon Balsam <shimon.balsam1@mail.huji.ac.il>
 * @version 1.0
 * @date 7 Aug 2018
 *
 * @brief System to calculates the cos function.
 *
 * @section DESCRIPTION
 * The system calculates the cos function.
 * Input  : A number.
 * Process: calculates the cos of the input.
 * Output : Prints the result of the calculation.
 */

// ------------------------------ includes ------------------------------
#include <stdio.h>

// -------------------------- const definitions -------------------------

//@brief A macro that defines value of PI.
#define PI 3.141529

//@brief A macro that sets an error message if the input given is not a double.
#define ERR_BAD_INPUT_MSG "Illegal input, needs to be a double."

//@brief A macro function that calculates the power of three of a given input.
#define POWER_BY_THREE(x) ((x) * (x) * (x))


// ------------------------------ functions -----------------------------
/**
 * Converts input from sin to be eligable for cos, using identity cos(x) = sin(pi/2 +x).
 * @param x user's input to be converted.
 * @return the identity as written above: cos(x) = sin(pi/2 +x).
 */
double updateForCos(double x)
{
    return PI / 2 + x;
}

/**
 * calculates cos(x) in a recursive manner.
 * @param x user's input to be calculated.
 * @return the solution to the calculation of cos(x).
 */
double cosinus(double x)
{
    if ( x < 0.01 && x > -0.01)
    {
        return x;
    }
    double temp = cosinus(x / 3);
    return 3*temp - 4*POWER_BY_THREE(temp);
}

/**
 * Accepts user input and prints the cosinus of the input.
 * @return 1 if the input is not a double, 0 otherwise.
 */
int main()
{
    double input;
    if (scanf("%lf", &input) == 1)
    {
        printf("%lf", cosinus(updateForCos(input)));
        return 0;
    }
    else
    {
        fprintf(stderr, ERR_BAD_INPUT_MSG);
        return 1;
    }
}
