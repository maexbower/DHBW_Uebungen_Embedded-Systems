#! /usr/bin/bash
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

for i in $(ls -d */); do (
    if [ -d $i/bin ]
    then
        rm -rf $i/bin
    fi
); done


echo 'CXX=g++' > config.mk
echo 'CXXFLAGS=-Werror -Wall -Wextra -fno-exceptions -Wno-format -fno-rtti -std=c++1y' >> config.mk
echo 'SILENT_MKDIR=' >> config.mk


echo 'include config.mk' > Makefile
echo 'all: build' >> Makefile
printf 'build: ' >> Makefile
for i in $(ls -d */); do (
    printf ' UE'${i: : -1} >> Makefile
); done

printf "\n"  >> Makefile

for i in $(ls -d */); do (
    CPPFILES=""
    HEADERFILES=""
    for f in $(ls ${i}src/*.cpp); do CPPFILES="${CPPFILES}./${f} " ; done
    for f in $(ls ${i}include/*.h); do HEADERFILES="${HEADERFILES}./${f} " ; done
    echo 'UE'${i: : -1}": "${CPPFILES}${HEADERFILES} >> Makefile
    echo '	$(CXX) $(CXXFLAGS) -o ./'"${i%%/}"'/bin/'"${i%%/}"' ./'"${i%%/}"'/src/*.cpp -I ./'"${i%%/}"'/include/' >> Makefile
    echo '	@echo' "${i: : -1}"'. CC '"${i%%/}" >> Makefile
); done

echo 'start:' >> Makefile
for i in $(ls -d */); do (
    echo '	$(SILENT_MKDIR)mkdir ./'"${i%%/}"'/bin' >> Makefile
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

for i in $(ls -d */); do (
    echo "Test "${i: : -1}
    ./${i}bin/${i: : -1}
    retval=$?
    if [ $retval -eq 0 ]
    then
        echo ""
        echo -e "$GREEN Successfully Tested!$NC"
    else
        echo ""
        echo -e "-> $RED Test Fail!$NC <-" >&2
    fi
    echo ""
); done
if [ $? -ne 0 ]; then
  exit 1
fi
exit 0
