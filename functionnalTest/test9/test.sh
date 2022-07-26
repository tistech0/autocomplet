#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion 2> ./functionnalTest/test9/ActualOutput < ./functionnalTest/test9/Input

#Compare the two files
if diff ./functionnalTest/test9/ActualOutput ./functionnalTest/test9/ExpectedOutput > /dev/null ; then
    echo -e "Test 9 -> no argument ${Green}OK${NC}"
else
    echo -e "Test 9 -> no argument ${RED}KO${NC}"
fi