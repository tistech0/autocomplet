#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test18/Dic > ./functionnalTest/test18/ActualOutput

#Compare the two files
if diff ./functionnalTest/test18/ActualOutput ./functionnalTest/test18/ExpectedOutput > /dev/null ; then
    echo -e "Test 18 ->  misplaced street type ${Green}OK${NC}"
    exit 1
else
    echo -e "Test 18 ->  misplaced street type ${RED}KO${NC}"
    exit 0
fi