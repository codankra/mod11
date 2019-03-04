# mod11
Determine if a number is divisible by 11, or its remainder and mod11 congruence (Without using / or % operators :)

Currently only implemented for numbers between -999 and 999

## How it Works
1. Take the absolute value of the input (removes negative if exists). --I might work on this more to get rid of the need for this step.--
2. If result is less than 11, all my work is done 
  - If result is less than 100, take digit2 - digit1.
  - If result is less than 1000, take digit3 + digit1 - digit2. 
  - If result is less than 10000, take digit4 + digit1 - digit2 - digit3.
3. If the result of step 2 is negative, add 11 until it is 0 or positive to get the remainder. If result > 10, subtract 11 until it is between 0 and 10 to get the remainder.

## Uses
- You have an agenda against the / and % operators
- You want a unique way to implement a hash function for a hash table of size 11
- You are interested in trivial code and enjoy taking advantage of my wasted time

### Why am I doing this?
I think that doing a simple task and imposing challenging restrictions on myself really helps me get familiar with looking at an unconventional way of doing things. Also, this has the added benefit of making me more comfortable with syntax and intracacies of these languages and some of the interesting, lesser-known things that can be done with them at a low level.

## Milestones
- 2019-03-03: Implemented for C (and C++)!
- 2019-03-03: First User
