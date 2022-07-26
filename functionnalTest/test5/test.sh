#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test5/Dic > ./functionnalTest/test5/ActualOutput < ./functionnalTest/test5/Input

#Compare the two files
if diff ./functionnalTest/test5/ActualOutput ./functionnalTest/test5/ExpectedOutput > /dev/null ; then
    echo -e "Test 5 -> 2 adresses 1 city ${Green}OK${NC}"
else
    echo -e "Test 5 -> 2 adresses 1 city ${RED}KO${NC}"
fi