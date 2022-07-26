#!/bin/bash

#Define Color
Green="\033[32m"
RED='\033[0;31m'
NC='\033[0m'

#Laucn test
./autoCompletion ./functionnalTest/test13/Dic > ./functionnalTest/test13/ActualOutput 2>&1 < ./functionnalTest/test13/Input
returnvalue=$?
echo $returnvalue >> ./functionnalTest/test13/ActualOutput

#Compare the two files
if diff ./functionnalTest/test13/ActualOutput ./functionnalTest/test13/ExpectedOutput > /dev/null ; then
    echo -e "Test 13 -> bad city after 2 letters ${Green}OK${NC}"
else
    echo -e "Test 13 -> bad city after 2 letters ${RED}KO${NC}"
fi