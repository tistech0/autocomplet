#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test10/Dic arg 2> ./functionnalTest/test10/ActualOutput < ./functionnalTest/test10/Input

#Compare the two files
if diff ./functionnalTest/test10/ActualOutput ./functionnalTest/test10/ExpectedOutput > /dev/null ; then
    echo -e "Test 10 -> too many arguments ${Green}OK${NC}"
else
    echo -e "Test 10 -> too many arguments ${RED}KO${NC}"
fi