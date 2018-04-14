
## **this file is for the information about c++ grammar that is used on this _insertion sort project**

### include 'iostream'
**iostream is a built-in library that c++ supports**
**iostream inherited from 'istream' and 'ostream'**
> 'ios_base class' - 'ios class' - 'istream'
> 'ios_base class' - 'ios class' - 'ostream'

### ios_base : 
*handle input/output format processing.*

### ios :
*initialize input/output buffer space and handle input/output state using four flag*
> goodbit , badbit, eofbit, failbit

### istream :
*do something about input using input buffer space*
> 'cin' is an one of the instance object about istream class

### ostream :
*do something about output using output buffer space*

### iostream :
*guess what*

-----

### cin.fail() :
*check whether failbit or badbit are 'on' or 'off'*

### cin.clear() :
*change cin bit state(failbit or badbit) into goodbit*

### cin.ignore(100, '\n') :
*100 is a maximum character, '\n' means ignore characters on bufferspace until you find '\n'*


-----

### >> operator
*>>* operator overrided for supporting lots of variable type such as integer, float, string ....
**It return calling instance**
for example, > while (cin >> i)
_ void pointer -> null pointer -> It means false by compiler

If you don't know about void pointer reference below link(stackoverflow) :
[What does void* mean and how to use it?](https://stackoverflow.com/questions/11626786/what-does-void-mean-and-how-to-use-it/11629682)
[What is a void pointer and what is a null pointer?](https://stackoverflow.com/questions/4334831/what-is-a-void-pointer-and-what-is-a-null-pointer)