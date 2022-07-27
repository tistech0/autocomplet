#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test14/Dic > ./functionnalTest/test14/ActualOutput < ./functionnalTest/test14/Input

#Compare the two files
if diff ./functionnalTest/test14/ActualOutput ./functionnalTest/test14/ExpectedOutput > /dev/null ; then
    echo -e "Test 14 -> 1 adresses 3 cities ${Green}OK${NC}"
    exit 1
else
    echo -e "Test 14 -> 1 adresses 3 cities ${RED}KO${NC}"
    exit 0
fi