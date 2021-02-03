# Genetic Algorithm C++

This project is the capstone project of the Udacity C++ Nano Degree.

In this project, I wrote a code that is based on a genetic algorithm. This project is working as a functions optimizer. It will optimize any function. Whether it is a mathematical function or any general function that takes any parameters than perform a thing based on their values.


# How to compile

Downloade the fils into a folder. Then use these commands:
```
g++ .\main.cpp 
.\a.exe 
```
(Note: the MinGW compiler should be installed youe computer) 

A new file with a name of "The_Project.exe" will be genrated in the same folder. Double click on it to start the program.

# How to Use


## 1. Create a new class.

In order to use it you need to create a new class with any name you like. The class must contain:
1. A function called `unsigned long calculateScore()` to evaluate your function and return its score (higher score should mean better performance).
2. A function called `void mutate(int index)` to change to value of any parameters to a random value.
3. A function called `void printThis()` to print your parameters in the way you like and understand.
4. A variables called `vector<int> parameters`  and  "int _numberOfParamters = some_number;".
5. The constructor should be same of the examples.

(The new class can contains any more function or variables you need).

## 2. Include `GAmodule.h` to your code.
## 3. Create a new instance from `GAmodule`.
The `GAmodule` needs you to pass your new class name to it `GAmodule <yourClass>`. The constructor of it expect a three parameters to be passed to it. They are:
1. The number of generations.
2. The number of population in each generation.
3. The mutation rate.

## 4. Start the module by calling "myModule.startEvalotion()"
You can start it in a thread if you like.

## 5. Get the best results by calling "myModule.getBestResult()"
This will returns the best results with the type of your created class.




# Examples of an object class

Two examples are provided in the folder `Example`.

# Rubric Points

## Loops, Functions, I/O
1. A variety of control structures are used in the project. The project code is clearly organized into functions.

## Object Oriented Programming
1. The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
2. All class data members are explicitly specified as public, protected, or private.
3. All class members that are set to argument values are initialized through member initialization lists.
4. All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways. (they are documentd through function names)
5. Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.
6. One function is declared with a template that allows it to accept a generic parameter.
