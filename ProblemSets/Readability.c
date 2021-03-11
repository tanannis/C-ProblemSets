#include <cs50.h> //cs50 library provided by Harvard University
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
  float letterCount = 0;
  float wordCount = 1; //word count should start at 1 to include the last word, due to there's no space after the last word.
  float sentenceCount = 0;

  string text = get_string("Text: ");

  //prints out a count of the number of letters in the text.
  for (int i = 0; i < strlen(text); i++)
  {
    if (isalpha(text[i]))
    {
      letterCount++;
    }
    else if (isspace(text[i]))
    {
      wordCount++;
    }
    else if (text[i] == '.' || text[i] == '?' || text[i] == '!') //must use single quotation marks for each one, do not use ""
    {
      sentenceCount++;
    }
  }
  // printf("LETTERS: %f.\n", letterCount);
  // printf("WORDS: %f.\n", wordCount);
  // printf("SENTENCES: %f.\n", sentenceCount);

  float L = letterCount / wordCount * 100;
  // printf("L: %.2f\n", L);

  float S = sentenceCount / wordCount * 100;
  // printf("S: %.2f\n", S);

  //apply the Coleman-Liau index formula
  float index = 0.0588 * L - 0.296 * S - 15.8;
  // printf("index: %f.\n", index);

  int grade = round(index);
  if (grade >= 16)
  {
    printf("Grade 16+\n");
  }
  else if (grade < 1)
  {
    printf("Before Grade 1\n");
  }
  else
  {
    printf("Grade %i\n", grade);
  }
}
