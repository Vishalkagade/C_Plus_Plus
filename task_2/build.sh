#preprocess 

c++ -std=c++17 -c src/subtract.cpp -o subtract.o

#compiler

c++ -S main.i

# aseembly code

c++ -c main.s

# object file for linking

c++ main.o -o main

#execute the

./main