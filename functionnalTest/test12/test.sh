#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test12/Dic arg 2> ./functionnalTest/test12/ActualOutput < ./functionnalTest/test12/Input
returnvalue=$?
echo $returnvalue > ./functionnalTest/test12/ActualOutput

#Compare the two files
if diff ./functionnalTest/test12/ActualOutput ./functionnalTest/test12/ExpectedOutput > /dev/null ; then
    echo -e "Test 12 -> bad city after 1 letter ${Green}OK${NC}"
    exit 1
else
    echo -e "Test 12 -> bad city after 1 letter ${RED}KO${NC}"
    exit 0
fi