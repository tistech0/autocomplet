#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test6/Dic > ./functionnalTest/test6/ActualOutput < ./functionnalTest/test6/Input

#Compare the two files
if diff ./functionnalTest/test6/ActualOutput ./functionnalTest/test6/ExpectedOutput > /dev/null ; then
    echo -e "Test 6 -> 2 adresses 1 city ${Green}OK${NC}"
else
    echo -e "Test 6 -> 2 adresses 1 city ${RED}KO${NC}"
fi