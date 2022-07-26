#!/bin/bash

Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White
NC='\033[0m'              # NC

clear ; make re -j1 ; make clean ; clear

#Launch test
echo -e "${Cyan}1 - City (simple)${NC}"
./functionnalTest/test1/test.sh
./functionnalTest/test2/test.sh
./functionnalTest/test3/test.sh
./functionnalTest/test4/test.sh
echo -e "${Cyan}2- Address (simple)${NC}"
./functionnalTest/test5/test.sh
./functionnalTest/test6/test.sh
./functionnalTest/test7/test.sh
echo -e "${Cyan}2- Address (same street)${NC}"
./functionnalTest/test14/test.sh
echo -e "${Cyan}3- Error management${NC}"
./functionnalTest/test8/test.sh
./functionnalTest/test9/test.sh
./functionnalTest/test10/test.sh
./functionnalTest/test11/test.sh
./functionnalTest/test12/test.sh
./functionnalTest/test13/test.sh
echo -e "${Cyan}4- Error correction${NC}"
./functionnalTest/test15/test.sh
./functionnalTest/test16/test.sh
./functionnalTest/test17/test.sh
./functionnalTest/test18/test.sh
