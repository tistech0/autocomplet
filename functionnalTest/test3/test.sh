#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test3/Dic > ./functionnalTest/test3/ActualOutput < ./functionnalTest/test3/Input

#Compare the two files
if diff ./functionnalTest/test3/ActualOutput ./functionnalTest/test3/ExpectedOutput > /dev/null ; then
    echo -e "Test 3 -> 2 adresses 2 cities ${Green}OK${NC}"
else
    echo -e "Test 3 -> 2 adresses 2 cities ${RED}KO${NC}"
fi