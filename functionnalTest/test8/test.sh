#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test8/Dic 2> ./functionnalTest/test8/ActualOutput < ./functionnalTest/test8/Input

#Compare the two files
if diff ./functionnalTest/test8/ActualOutput ./functionnalTest/test8/ExpectedOutput > /dev/null ; then
    echo -e "Test 8 -> empty file ${Green}OK${NC}"
else
    echo -e "Test 8 -> empty file ${RED}KO${NC}"
fi