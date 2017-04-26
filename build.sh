#! /usr/bin/env bash
#   author: Cellebyte alias Marcel Fest
# --> Fixed issue mentioned by @desyon
# ----> Script is returning Error Code <----
# ------> local build and test is also possible <------


# For building and testing the whole folder:
# -> INSTALL
#   sudo apt-get install build-essential software-properties-common -y && \
#   sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
#   sudo apt-get update && \
#   sudo apt-get install gcc-6 g++-6 -y && \
#   gcc -v
#
# -> Run ./build.sh

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color]]'


touch Makefile
touch config.mk

for i in $(ls */); do (
    if [ -d $i/bin ]
    then
        rm -rf $i/bin
    fi
); done


COUNTER=1

echo 'CXX=g++' > config.mk
echo 'CXXFLAGS=-Werror -Wall -Wextra -fno-exceptions -Wno-format -fno-rtti -std=c++1y' >> config.mk
echo 'SILENT_MKDIR=' >> config.mk


echo 'include config.mk' > Makefile
echo 'all:' >> Makefile
echo '  build' >> Makefile

for i in $(ls -d */); do (
    echo '	@set -e; $(CXX) $(CXXFLAGS) -o '"${i%%/}"'/bin/'"${i%%/}"' '"${i%%/}"'/src/*.cpp -I '"${i%%/}"'/include/' >> Makefile
    echo '	@echo' "$COUNTER"'. CC '"${i%%/}" >> Makefile
    (( COUNTER++ ))
); done

echo 'start:' >> Makefile
for i in $(ls */); do (
    echo '	$(SILENT_MKDIR)mkdir $i/bin' >> Makefile
); done


make start
make build

echo ""

if [ $? -eq 0 ]
then
    echo -e "$GREEN Successfully Build!$NC"
else
    echo -e "--> $RED Build failed!$NC <--" >&2
    exit 1
fi

echo ""

COUNTER=1

for i in $(ls */); do (
    echo "$COUNTER. Test"
    $i/bin/$i
    echo ''
    (( COUNTER++ ))
); done

if [ $? -eq 0 ]
then
    echo -e "$GREEN Successfully Tested!$NC"
    exit 0
else
    echo -e "-> $RED Test Fail!$NC <-" >&2
    exit 1
fi
