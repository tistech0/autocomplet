#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test17/Dic > ./functionnalTest/test17/ActualOutput

#Compare the two files
if diff ./functionnalTest/test17/ActualOutput ./functionnalTest/test17/ExpectedOutput > /dev/null ; then
    echo -e "Test 17 ->  adress before city ${Green}OK${NC}"
    exit 1
else
    echo -e "Test 17 ->  adress before city ${RED}KO${NC}"
    exit 0
fi