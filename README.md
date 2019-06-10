# C++ Command Line Calculator

This is an extremely simple calculator I made while learning C++.

Download the repo, compile and run it:
```
$git clone https://github.com/christopher-siewert/cpp-calculator.git
$cd cpp-calculator
$make
```

For Windows users, I included my Code::Blocks project file, `Calculator.cbp`.
Open this with the [Code::Blocks](http://www.codeblocks.org/) IDE.

It has two modes, regular and scientific, that a user can switch between.

### Overview

The program has 2 classes. A simple calculator class called Calculator, and a class that inherits Calculator called Scientific.

Some of the member functions of Calculator are virtual and are overridden in the Scientific class.

The program polymorphically calls the appropriate member functions depending on the current mode (scientific vs simple).

The program flow is:
1. Prompt user for the desired operation (polymorphically determine the message based on the current mode; show more options while in scientific mode)
2. Get additional data from the user (if doing addition, get 2 numbers)
3. Perform calculation, print to screen
4. Repeat from (1)

#### Calculator Class

This is the base class for the calculator program. It has data members and member functions that will display messages to the screen, prompt for user input, and perform calculations.

Specifically, Calculator has 2 protected data members, `result` and `mem`. `result` stores the result of the last computation. `mem` is used by the user to store a number in memory and access it later for further computation. They are both doubles, and they are initialized to 0 in the constructor.

Public member functions `add`, `subtract`, `multiply`, `divide`, `square`, and `sqrt` perform all the calculations. They prompt the user for either 1 or 2 numbers depending on the function, perform the required calculation, store this in the protected variable result, and print out the result to the screen.

Calculator has 2 public member functions in order to use `mem`, a get and a set.

Then some helper member functions will be needed.
`welcome()` will print out the available options that can be entered. This is virtual so the derived class can output its own options.

`parseOperation()` takes in the user input string and calls the appropriate member function. This is to enable the user entering "+" or "log" and having the correct function called. This is also virtual so it can be overridden for the extra functions in the scientific calc.

`parseInput()` is used for the extra `result`/`mem` feature. I wanted the user to be able to type the words result and mem as if they are numbers. `parseInput()` looks for those strings and gets the values from memory to be used in any calculations.

As this class contains virtual functions, a virtual destructor will be included.

#### Scientific Class

Scientific inherits from the base class calculator. It calls the Calculator constructor to initialize `result` and `mem`.
It has many additional operation functions. `sin`, `cos`, `tan`, `ln`, `log`, `abs`, and `pow` all prompt the user for input, perform a calculation, save it in result, and print that result.

It overrides the 2 virtual functions of class Calculator. `welcome()` is overridden to show all the options for the scientific calculator, and `parseOperation()` is overridden to access the additional calculation functions.

A virtual destructor is also included.

#### Main

The class set up allows the program to polymorphically call object methods depending on the type of the object. The main program will be one user entry loop. In the loop, a base class Calculator pointer (`calcPtr`) pointed at a Calculator object is used to call the Calculator member functions.

The switch to scientific mode will be made by pointing this Calculator class pointer at a derived Scientific class object. Now the program dynamically calls different member functions based on the state.

This simplifies the main code as the statement `calcPtr->welcome()` will automatically call the right welcome function, detailing out the proper options for the current mode.

#### Nifty Features

1. Users are able to enter a range of inputs that correspond to each operation. For example: “+”, “add”, “addition”, “sum” all trigger the addition operation.
2. This calculator has a memory feature. The result of a previous calculation is always stored and can be accessed using the keyword `result`. This keyword can be used as a number. Thus, the user could enter: `sub` to choose the subtraction operation then type in `result` and `1` to take one away from the previous result. The `mem` keyword allows a user to store a number for later use. This is highly useful when doing long calculations. An important result can be stored into `mem`, then accessed later by using `mem` as an entry in your calculations.
