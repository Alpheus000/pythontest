#include <stdio.h>
#include <cs50.h>
#include <math.h>

int second_number();
int process();
int main(void)
{
  long long n; //Gets Credit Card Number
    do 
    {
        n = get_long_long("Enter Credit Card Number\n");
    }
    while (n < 0);
     //Starts checking sum
    int sum = 0;
    int second_digit; //declaring variables first
    long long x;
    long long y;
    for (int i = 1; i <= 16; i = (i+2)) //checks 16 digits max
    {
        if (n/(pow(10,i-1)) > 9) // checks if theres still numbers
        {
            long long power = pow(10,i);
            x = n % power; //Finds first number
            n = n - x; //Removes first number
            x = process(x);//Removes zeroes
            sum = sum + x;
        }
        
        else //Breaks if reach last number
        {
            n = process(n);
            sum = sum + n;
            second_digit = y; //Assigns second digit from alternate "if" for checker
            break;
        }
        
        if ( (n/(pow(10,i-1))) > 9)
        {
            long long power = pow(10,i+1);
            y = n % power; //Finds second number
            n = n - y; //Removes second number
            y = process(y);
            sum = sum + second_number(y);
        }
        else
        {
            n = process(n);
            sum = sum + (second_number(n));
            second_digit = x;
            break;
        }
    }
    
     //checks for type of card
    if (sum%10 == 0)
    {
        int checker = n*10 + second_digit;
        if (checker == 34 || checker == 37)
        {
            printf("AMEX\n");
        }
        
        else if (checker <=55 && checker >= 51)
        {
            printf("MASTER\n");
        }
        
        else if (n == 4)
        {
            printf("VISA\n");
        }
        
        else
        {
            printf("INVALID\n");
        }
        
    }
    
    else
    {
        printf("INVALID\n");
    }
    
    
    
}

int process(long long x) //Keeps dividing number by 10 until its below 10.
{
    while (x >= 10)
    {
        x = x/10;
    }
    return x;
}

int second_number(long long y) //Finds the digits of the product
{
    y =  2*y;
    int digit1 = y%10;
    y = y - digit1;
    int digit2 = y/10;
    return (digit1 + digit2);
}


current problem: second digit somehow doesnt register if card number too long