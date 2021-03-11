# C problem sets

1. **Cash: Implement a program that first asks the user how much change is owed and then prints the minimum number of coins with which that change can be made.**
   (Passed all tests in the CS50 system, including below test cases)

- -1.00 (or other negative numbers)?
- 0.00?
- 0.01 (or other positive numbers)?
- letters or words?
- no input at all, when you only hit Enter?

2. **Caesar: Implement a program that encrypts messages using Caesar’s cipher,**

- Design and implement a program, caesar, that encrypts messages using Caesar’s cipher.
  (Passed all tests in the CS50 system)

3. **Readability: Implement a program that computes the approximate grade level needed to comprehend some text,**
   (Passed all tests in the CS50 system)

- The Coleman-Liau index is computed using the formula:
  index = 0.0588 _ L - 0.296 _ S - 15.8

4. **Plurality: Implement a program that runs a plurality election**
   (Passed all below tests in the CS50 system)

- An election with any number of candidate (up to the MAX of 9)
- Voting for a candidate by name
- Invalid votes for candidates who are not on the ballot
- Printing the winner of the election if there is only one
- Printing the winner of the election if there are multiple winners

5. **Runoff: Implement a program that runs a runoff election**
   (Passed all below tests in the CS50 system)

- An election with any number of candidate (up to the MAX of 9)
- Voting for a candidate by name
- Invalid votes for candidates who are not on the ballot
- Printing the winner of the election if there is only one
- Not eliminating anyone in the case of a tie between all remaining candidates

6. **Recover: Implement a program that recovers JPEGs from a forensic image**
   (Passed all below tests in the CS50 system)

- Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
- If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.
- If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.
- The files you generate should each be named ###.jpg, where ### is a three-digit decimal number, starting with 000 for the first image and counting up.
- Your program, if it uses malloc, must not leak any memory.
