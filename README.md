# 313_hw1
 
Author: James Deciutiis
CSCI HW1 Question 1

Test whether a vector or a list is faster by timing them via:
a. Filling them with random numbers
b. Filling them with random strings (use ascii)
c. Doing the above with move semantics when filling with random strings

Methodology:
I created 5 classes to break up the problem. 
 - A class for an array of random integers
 - A class for a vector of random integers
 - A class for an array of random strings
 - A class for a vector of random strings
 - And finally a class that takes random integer/string arrays and random integer/string vectors
 and times how it take to fill them and cout's the results.

Reasoning: I felt that seperating the problem into classes would reduce the cluter in main.cpp,
improve readability, and help set myself up for the final part of the question which was to 
fill up a random string array and random string vector using move semantics (I used the classes operator= for this)


