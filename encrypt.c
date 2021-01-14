//
// Created by Shimmy on 8/5/2018.
//

/**
 * @file encrypt.c
 * @author  Shimon Balsam <shimon.balsam1@mail.huji.ac.il>
 * @version 1.0
 * @date 7 Aug 2018
 *
 * @brief System to encrypt a text.
 *
 * @section DESCRIPTION
 * The system encrypts a text.
 * Input  : An encryption key and the text to encrypt.
 * Process: Scans the input and encrypts each ;etter by the encryption key constant.
 * Output : Prints the encryption.
 */

// ------------------------------ includes ------------------------------
#include <stdio.h>

// -------------------------- const definitions -------------------------
//@brief A macro that sets an error message if the encryption key given is not an int.
#define NON_INT_ERR "Encryption constant needs to be an int."

//@brief A macro that sets an error message if the encryption key given is not in the right range.
#define OUT_OF_BOUNDS_ERR "Encryption constand must be between -25 and 25."

//@brief A macro that sets the size of the buffer.
#define MAX_BUFFER_SIZE 256

//@brief A macro that defines the maximum value of encryption constant.
#define UPPER_BOUND_CONST 25

//@brief A macro that defines the minimum value of encryption constant.
#define LOWER_BOUND_CONST -25

//@brief A macro that defines the ascii value of Z.
#define CAPITAL_Z 90

//@brief A macro that defines the ascii value of A.
#define CAPITAL_A 65

//@brief A macro that defines the ascii value of z.
#define LOWCASE_Z 122

//@brief A macro that defines the ascii value of a.
#define LOWCASE_A 97


// ------------------------------ functions -----------------------------

// global arr buffer, used by all functions.
char buffer[MAX_BUFFER_SIZE];

/**
 * Encrypts the chars in the buffer.
 * @param encryption_key the constnat by which we encrypt the chars.
 * @param n the number of chars before EOF within the buffer.
 */
void encryptYourself(const int encryption_key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (buffer[i] >= CAPITAL_A && buffer[i] <= CAPITAL_Z)
        {
            if (buffer[i] + encryption_key >= CAPITAL_A && buffer[i] + encryption_key <= CAPITAL_Z)
            {
                printf("%c", buffer[i] + encryption_key);
            }
            else if (buffer[i] + encryption_key > CAPITAL_Z)
            {
                printf("%c", CAPITAL_A + buffer[i] + encryption_key - CAPITAL_Z - 1);
            }
            else
            {
                printf("%c", CAPITAL_Z + buffer[i] + encryption_key - CAPITAL_A + 1);
            }
        }
        else if (buffer[i] >= LOWCASE_A && buffer[i] <= LOWCASE_Z)
        {
            if (buffer[i] + encryption_key >= LOWCASE_A && buffer[i] + encryption_key <= LOWCASE_Z)
            {
                printf("%c", buffer[i] + encryption_key);
            }
            else if (buffer[i] + encryption_key > LOWCASE_Z)
            {
                printf("%c", LOWCASE_A + buffer[i] + encryption_key - LOWCASE_Z - 1);
            }
            else
            {
                printf("%c", LOWCASE_Z + buffer[i] + encryption_key - LOWCASE_A + 1);
            }
        }
        else
        {
            printf("%c", buffer[i]);
        }
    }
}

/**
 * Accepts user input for encripsion key and the text which mus be encrypted and encrypts said text.
 * @return returns 0 if the input is legal and the encryption fullfills. Otherwise returns 1.
 */
int main()
{
    int n;
    int encryption_const;
    if (scanf("%d ", &encryption_const) != 1)
    {
        fprintf(stderr, NON_INT_ERR);
        return 1;
    }
    else if (encryption_const > UPPER_BOUND_CONST || encryption_const < LOWER_BOUND_CONST)
    {
        fprintf(stderr, OUT_OF_BOUNDS_ERR);
        return 1;
    }
    else
    {
        while (scanf("%256c%n", buffer, &n) != EOF)
        {
            encryptYourself(encryption_const, n);
        }
    }
    return 0;
}