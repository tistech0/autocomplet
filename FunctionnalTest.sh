#!/bin/bash

Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Cyan='\033[0;36m'         # Cyan
NC='\033[0m'              # NC

clear ; make re -j1 ; make clean ; clear

nbGoodTest=0

function incrementGoodTest () {
  if [ $1 -eq 1 ]
    then
        nbGoodTest=$((nbGoodTest+1))
  fi
  return $nbGoodTest
}

#Launch test
echo -e "${Cyan}1 - City (simple)${NC}"

./functionnalTest/test1/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test2/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test3/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test4/test.sh
returnvalue=$?
incrementGoodTest $returnvalue

echo -e "${Cyan}2- Address (simple)${NC}"

./functionnalTest/test5/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test6/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test7/test.sh
returnvalue=$?
incrementGoodTest $returnvalue

echo -e "${Cyan}2- Address (same street)${NC}"

./functionnalTest/test14/test.sh
returnvalue=$?
incrementGoodTest $returnvalue

echo -e "${Cyan}3- Error management${NC}"

./functionnalTest/test8/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test9/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test10/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test11/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test12/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test13/test.sh
returnvalue=$?
incrementGoodTest $returnvalue

echo -e "${Cyan}4- Error correction${NC}"

./functionnalTest/test15/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test16/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test17/test.sh
returnvalue=$?
incrementGoodTest $returnvalue
./functionnalTest/test18/test.sh
returnvalue=$?
echo
incrementGoodTest $returnvalue
echo -e "${Cyan}You pass ${nbGoodTest}/18 ${NC}"
if [ ${nbGoodTest} -eq 18 ]; then
    echo -e "${Green}You pass all test !${NC}"
    exit 0
else
    exit 84
fi
