# CSCI_313 HW1 Question 1
## Author: James Deciutiis <br> Team Members: Jacob A Brown, Tamzid Chowdhury, Tania Chowdhury, Victoria Danyel Cortes
 
1) Test whether a vector or a list is faster by timing them via: 
 <br></br>
 a. Filling them with random numbers
 <br></br>
 b. Filling them with random strings (use ascii)
 <br></br>
 c. Doing the above with move semantics when filling with random strings

## Methodology:
<br></br>
I created 5 classes to break up the problem: 
- A class for an array of random integers
- A class for a vector of random integers
- A class for an array of random strings
- A class for a vector of random strings
- And finally a class that takes random integer/string arrays and random integer/string vectors
 and times how it take to fill them and cout's the results.

Reasoning: I felt that separating the problem into classes would reduce the cluter in main.cpp,
improve readability, and help set myself up for the final part of the question which was to 
fill up a random string array and random string vector using move semantics (I used the classes operator= for this)

## Random Integers and Random Strings
Integers:
<br>
For the random integer array/vector I filled them using the standard rand function.
<br>
<br>
Strings:
<br>
For the random string array/vectors I filled them using a modified version of the rand fuction.
I assumed that the only ascii values to be desired were values of the english alphabet, capitalizations included. So I made a method called randomAscii that would return the string "a" plus a random value from 0-94 (which guarantees we get a desired character).
