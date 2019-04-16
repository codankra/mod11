# mod11
Determine if a number is divisible by 11, find its remainder and mod11 congruence (Without using / or % operators :)

Currently *only* implemented for numbers between -99999999 and 99999999 (If anyone has a general pattern to derive a formula for all larger numbers, I would love to hear it).

### Why am I doing this?
I think that doing a simple task and imposing challenging restrictions on myself really helps me get familiar with looking at an unconventional way of doing things. Also, this has made me more comfortable with syntax and intracacies of these languages and some of the interesting, lesser-known things that can be done with them at a low level. For this reason, I plan on implementing this algorithim with a wide variety of languages, including ones I have been unfamiliar with up to this point.
Also, as far as I know, I am the first one on Github or anywhere that has done *mod* of a number this with these restrictions.

## How it Works
1. Make input positive. *Keep track of if it was negative to start*
2. If the result is less than 11, all my work is done 
  - If result is 2 digits, take digit2 - digit1.
  - If result is 3 digits, take digit1 - digit2 + digit3. 
  - If result is 4 digits, take 10(digit1) - 10(digit2) - digit3  + digit4.
  - If result is 5 digits, take digit1 - digit2 + digit3 - digit4 + digit5.
  - If result is 6 digits, take (-)digit1 + digit2 - digit3 + digit4 - digit5 + digit6.
  - If result is 7 digits, take 1000(digit1) - 100(digit2) + 100(digit3) - 10(digit4) + 10(digit5) - digit6 + digit7.
  - If result is 8 digits, take (-)digit1 + digit2 - digit3 + digit4 - digit5 + digit6 - digit7 + digit8.
3. If the result of step 2 is negative, add 11 until it is 0 or positive to get the modular congruence x. 11 - x will be the remainder. If result > 10, subtract 11 until it is between 0 and 10 to get the remainder.

## Uses
- You have an agenda against the / and % operators
- You want a unique way to implement a hash function for a hash table of size 11
- You are interested in trivial code and enjoy taking advantage of my wasted time


## Milestones
- 2019-03-03: Implemented for C (and C++)!
- 2019-03-03: First User
- 2019-04-14: Developed logic for up to 8 digits
