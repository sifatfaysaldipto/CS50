#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // Prompt user to enter credit card number
    printf("credit: ");
    long long cc = get_long_long();
    long long digits = cc;
    int f_sum = 0 ;
    int the_result = 0 ;
    int count = 0 ;
    int multi ;
    int array [2];

    // Check if the credit card number is negative
    if(cc < 0)
    {
        printf("Enter Valid credit card number");
    }
    else
    {
        // Count number of digits in the credit card number
        while (digits > 0 )
        {
            digits = digits / 10;
            count = count + 1;
        }

        // Array to store individual digits of the credit card number
        int number[count];
        for (int i = 0; i < count; i++)
        {
            // Extract each digit from the credit card number and store it in the array
            number[i] = cc % 10;
            cc = cc / 10;
        }

        // Calculate the sum of digits in even positions multiplied by 2
        for (int i = 1; i < count; i = i + 2)
        {
            multi =  number[i] * 2;
            if(multi > 9)
            {
                for (int j = 0; j < 2; j++)
                {
                    // Split the double digit number into individual digits
                    array[j] = multi % 10;
                    multi = multi / 10;
                    f_sum = f_sum + array[j];
                }
            }
            f_sum = f_sum + multi;
        }

        // Calculate the sum of digits in odd positions
        for (int k = 0; k < count; k = k + 2)
        {
            the_result = the_result + number[k];
        }

        // Check if the credit card number is valid using Luhn's Algorithm
        int check = the_result + f_sum;
        int first_digit = number[count - 1];
        int second_digit = number[count - 2];
        if (check % 10 == 0)
        {
            if (count == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7))
            {
                printf("Amex\n");
            }
            else if (count == 16 && first_digit == 5 && (second_digit >= 1 && second_digit <= 5))
            {
                printf("MasterCard\n");
            }
            else if ((count == 13 || count == 16) && first_digit == 4)
            {
                printf("Visa\n");
            }
        }
        else
        {
            printf("This card is not valid\n");
        }
    }
}