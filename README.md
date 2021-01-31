# Genetic Algorithm C++

This project is the capstone project of the Udacity C++ Nano Degree.

In this project, I wrote a code that is based on a genetic algorithm. This project is working as a functions optimizer. It will optmize any function. Whether it is a mathmatical function or any genral function that takes any paramters than perform a thing based on thire values.



# Examples

two examples are provided in the folder `Example`.

# How to Use


## 1. Create a new class.

In oreder to use it you need to create a new class with any name you like. The class must contain:
1. A function called `unsigned long calculateScore()` to evaluate your function and return its score (higher score sould mean better performance).
2. A function called `void mutate(int index)` to change to value of any paramters to a randome value.
3. A function called `void printThis()` to print your paramters in the way you like and understande.
4. A variables called `vector<int> paramters`  and  "int _numberOfParamters =8".
5. the constructor sould be same of the examples.

( the new class can contains any more function or variables you need).

## 2. Include `GAmodule.h` to your code.
## 3. Create a new instance from `GAmodule`.
The `GAmodule` needs you to pass your new class name to it `GAmodule <yourClass>`. The constructor of it expect a three paramters to be passed to it. They are:
1. the number of generations.
2. the number of population in each genration.
3. the mutation rate.

## 4. Start the module by calling "myModule.startEvalotion()"
You cann start it in athread if you like.

## 5. get the best results by calling "myModule.getBestResult()"
this will returns the best results with the type of your created class.




