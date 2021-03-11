#include <cs50.h> //cs50 library provided by Harvard University
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
  string name;
  int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
  // Check for invalid usage
  if (argc < 2)
  {
    printf("Usage: plurality [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates, copies command-line arguments into the array candidates
  candidate_count = argc - 1;

  if (candidate_count > MAX)
  {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++)
  {
    candidates[i].name = argv[i + 1]; //if i=0, argv[0]=./plurality.c. argv[0 + 1]=argv[1]= first element in array
    candidates[i].votes = 0;
  }

  //asks the user to type in the number of voters.
  int voter_count = get_int("Number of voters: ");

  // Loop over all voters
  for (int i = 0; i < voter_count; i++)
  {
    string name = get_string("Vote: "); //each voter should input a candidate's name to vote for

    // Check for invalid vote
    if (!vote(name))
    {
      printf("Invalid vote.\n");
    }
  }

  // Display winner of election
  print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
  // TODO
  for (int i = 0; i < candidate_count; i++)
  {
    if (strcmp(candidates[i].name, name) == 0)
    {
      candidates[i].votes++;
      // printf("%i\n", candidates[i].votes);
      return true;
    }
  }
  return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
  // TODO
  int most_votes = 0;

  for (int i = 0; i < candidate_count; i++)
  {
    // most_votes = candidates[i].votes;
    if (candidates[i].votes > most_votes)
    {
      most_votes = candidates[i].votes;
    }
  }

  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].votes == most_votes)
    {
      // printf("Most Vote: %i\n", most_votes);
      printf("%s\n", candidates[i].name);
    }
  }
  return;
}
