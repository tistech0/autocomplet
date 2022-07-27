#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test2/Dic2 > ./functionnalTest/test2/ActualOutput < ./functionnalTest/test2/Input

#Compare the two files
if diff ./functionnalTest/test2/ActualOutput ./functionnalTest/test2/ExpectedOutput > /dev/null ; then
    echo -e "Test 2 -> 2 adresses 2 cities ${Green}OK${NC}"
    exit 1
else
    echo -e "Test 2 -> 2 adresses 2 cities ${RED}KO${NC}"
    exit 0
fi