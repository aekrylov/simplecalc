#simplecalc - a simple calculator

Supports complex expressions with +, -, *, / operations and brackets.

###Usage:
    
    ./simplecalc
    >19.7   +( 3,25/2)

###How to build:

    cd build
    cmake ..
    make
    
###How to test (GTest required):

    make
    make test
    
Or

    make simplecalc_test
    ./test/simplecalc_test
    
