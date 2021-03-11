#include <cs50.h> //cs50 library provided by Harvard University
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//ask user to prompt in a string
//if user didn't prompt in anything
//ask to prompt again

//iterate string to check each char
//convert char to ASCII numbers
//add key to each ASCII number
//convert ASCII number back to new char
//the new chars = ciphertext

int main(int argc, string argv[])
{
  //Check that program was run with one command-line argument. if argc == 1 means user didn't promt in any string.
  //argv[0] is the file name "./caesar", argv[1] is what the user prompted in
  if (argc == 2)
  {
    //iterate string to check if each char is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
      //if any char is not a digit, print error message and return 1 as exit code
      if (!isdigit(argv[1][i]))
      {
        printf("Usage: ./caesar key\n");
        return 1;
      }
    }

    // convert string back to digit, this is the key.
    int k = atoi(argv[1]);
    // printf("Success\n");
    // printf("%i\n", k);

    string text = get_string("plaintext: ");
    // printf("%s\n", text);

    for (int i = 0; i < strlen(text); i++)
    {
      if (isalpha(text[i]) && isupper(text[i]))
      {
        //convert text[i] to a decimal ASCII number using "(int)".
        //because upper case A starts from 65 and Z ends at 90, Z cannot become 91 thus need to rotate back to 90
        //if k is 1, plaintext is A: 65-65+1=1; 1 % 26 + 65= 66
        text[i] = ((int)text[i] - 65 + k) % 26 + 65;
        // printf("%i\n", text[i]);
      }
      else if (isalpha(text[i]) && islower(text[i]))
      {
        //convert text[i] to a decimal ASCII number using "(int)".
        //because lower case "a" starts from 97 and "z" ends at 122, "z" cannot become 123 thus need to rotate back to 97
        //if k is 1, plaintext is "a": 97-97+1=1; 1 % 26 + 97= 98
        text[i] = ((int)text[i] - 97 + k) % 26 + 97;
        // printf("%i\n", text[i]);
      }
      else
      {
        //If it is not alpha, print out the character as is
        printf("ciphertext: %s\n", text);
      }
    }
    printf("ciphertext: %s\n", text); //if everything works, print out the ciphertext
    return 0;                         //and exit 0 becase it's a success
  }
  else
  {
    printf("Usage: ./caesar key\n");
    return 1; //exit code is 1 if detected error
  }
}
