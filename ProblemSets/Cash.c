#include <cs50.h> //cs50 library provided by Harvard University
#include <stdio.h>
#include <math.h>

//Using Greedy Algorithm
int main(void)
{
  //first asks the user how much change is owed
  float change;
  do
  {
    change = get_float("Change owed: ");
  } while (change <= 0);
  // printf("%.2f.\n", change);

  int cents = round(change * 100);
  printf("%i\n", cents);

  int quarters = 25;
  int dimes = 10;
  int nickles = 5;
  int pennies = 1;

  int coins = 0;

  while (cents >= 25)
  {
    cents -= 25;
    coins++;
  }

  while (cents >= 10)
  {
    cents -= 10;
    coins++;
  }

  while (cents >= 5)
  {
    cents -= 5;
    coins++;
  }

  while (cents >= 1)
  {
    cents -= 1;
    coins++;
  }

  printf("total coins: %i.\n", coins);
}
