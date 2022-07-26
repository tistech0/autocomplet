#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test16/Dic > ./functionnalTest/test16/ActualOutput

#Compare the two files
if diff ./functionnalTest/test16/ActualOutput ./functionnalTest/test16/ExpectedOutput > /dev/null ; then
    echo -e "Test 16 -> misplaced number ${Green}OK${NC}"
else
    echo -e "Test 16 -> misplaced number ${RED}KO${NC}"
fi