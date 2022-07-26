#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test11/Dico arg 2> ./functionnalTest/test11/ActualOutput < ./functionnalTest/test11/Input

#Compare the two files
if diff ./functionnalTest/test11/ActualOutput ./functionnalTest/test11/ExpectedOutput > /dev/null ; then
    echo -e "Test 11 -> bad argument ${Green}OK${NC}"
else
    echo -e "Test 11 -> bad argument ${RED}KO${NC}"
fi