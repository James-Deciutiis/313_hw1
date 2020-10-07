# CSCI_313 HW1 Question 1
### Author: James Deciutiis <br> Team Members: Jacob A Brown, Tamzid Chowdhury, Tania Chowdhury, Victoria Danyel Cortes
## The Question: 
1) Test whether a vector or a list is faster by timing them via: 
 <br></br>
 a. Filling them with random numbers
 <br></br>
 b. Filling them with random strings (use ascii)
 <br></br>
 c. Doing the above with move semantics when filling with random strings
## Methodology:
I created 5 classes to break up the problem: 
- A class for an array of random integers
- A class for a vector of random integers
- A class for an array of random strings
- A class for a vector of random strings
- And finally a class that takes random integer/string arrays and random integer/string vectors
 and times how it take to fill them and cout's the results.

Reasoning: I felt that separating the problem into classes would reduce the clutter in main.cpp,
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
I assumed that the only ascii values to be desired were values of the english alphabet, capitalizations included. So I created a method called randAscii that would return the string "a" plus a random value from 0-94 (which guarantees we get a desired character).

```c++
string randAscii(){
 return "a" + (rand() % 94);
}
```

## Timing 
At first when looking for a way to time how long each operation would take, I thought to use the std::clock_t function from the <ctime> library. However after doing some research on it, I found out that this measures CPU time and not the actual elapsed time. This would be problematic since we're only interested in how long the array/vector operations would take and don't want to add any unnecessary variables that would skew the results. So I settled on using the chrono library instead which measures the true time elapsed. 

For parts a, and b I was fine using milliseconds to measure how long each trial took. But for the move semantics part I needed to use microseconds since the operations were so quick that it couldn't be measured properly. 

The timeTrial class takes in an int parameter for the amount of trials to do on parts a and b by default this is set to 3 trials.

## Compile 

```
g++ main.cpp -std=c++11 -o <desired_name_of_output>
```

## Closing thoughts
I think this question really demonstrated the power of using move semantics to populate new arrays and vectors over making a copy of them. The time difference was very significant and, to me, is absolutely worth setting up the operator=/move constructor.
