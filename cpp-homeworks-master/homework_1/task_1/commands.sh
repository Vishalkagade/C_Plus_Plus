#Task 1 
#!/usr/bin/env bash

wc -l < data.dat
grep "d*lor" data.dat | wc -l
wc -w < data.dat
grep "\<mol" data.dat | wc -l
