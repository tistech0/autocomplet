#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test7/Dic > ./functionnalTest/test7/ActualOutput < ./functionnalTest/test7/Input

#Compare the two files
if diff ./functionnalTest/test7/ActualOutput ./functionnalTest/test7/ExpectedOutput > /dev/null ; then
    echo -e "Test 7 -> 4 adresses 2 cities ${Green}OK${NC}"
else
    echo -e "Test 7 -> 4 adresses 2 cities ${RED}KO${NC}"
fi