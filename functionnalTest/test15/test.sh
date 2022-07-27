#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test15/Dic > ./functionnalTest/test15/ActualOutput

#Compare the two files
if diff ./functionnalTest/test15/ActualOutput ./functionnalTest/test15/ExpectedOutput > /dev/null ; then
    echo -e "Test 15 -> missing coma ${Green}OK${NC}"
    exit 1
else
    echo -e "Test 15 -> missing coma ${RED}KO${NC}"
    exit 0
fi