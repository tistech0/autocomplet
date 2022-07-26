#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test1/Dic1 > ./functionnalTest/test1/ActualOutput

#Compare the two files
if diff ./functionnalTest/test1/ActualOutput ./functionnalTest/test1/ExpectedOutput > /dev/null ; then
    echo -e "Test 1 -> 1 adress ${Green}OK${NC}"
else
    echo -e "Test 1 -> 1 adress ${RED}KO${NC}"
fi