# Dynamic Table

Dynamic Table implementation written in C.

### Prerequisites

* gcc version 6.3.0 or higher
* python 3.5 or higher
* matplotlib 2.0.2 or higher

### Installing

First compile the project in your local system by:

```
make clean
make
```
For testing if it works, see Running tests below

## Running Tests

For automated tests, run:

``` 
python3 tester.py
```
It tests the various functionalities of the Dynamic Table and plots graphs for the different factors used

For manual tests, run:

``` 
./test [OPTION]... [PARAMETERS]...

OPTIONS:
    -i [INIT_SIZE] [FACTOR]
        get times for one million insertions.
    -d [INIT_SIZE] [FACTOR]
        get times for one million deletions.
    -r [INIT_SIZE] [FACTOR] [INSERT_TIMES] [DELETE_TIMES]
        get times for opertions: INSERT_TIMES insertions and DELETE_TIMES deletions
    
```

## Deployment

For using the dynamic table:

* Copy dynamic_table.h header file to the location of your source file.
* Include dynamic_table.h to your source file.
* Compile dynamic_table.c to obtain the obj file and compile your program:
 

## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language)) - The main backend used
* [Python](https://docs.python.org/3/) - Used for testing
* [Matplotlib](https://matplotlib.org/) - Used for testing

## Authors

* **Ganesh K.** - [DarkFate13](https://github.com/DarkFate13)

## Acknowledgments

This is developed as an assignment for Advanced Algorithms Course 
