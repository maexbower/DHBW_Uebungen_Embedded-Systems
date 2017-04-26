include config.mk
all: build
build:  UE01 UE02 UE03
UE01: ./01/src/CmdLineOptParser.cpp ./01/src/main.cpp ./01/include/OptParser.h
	$(CXX) $(CXXFLAGS) -o ./01/bin/01 ./01/src/*.cpp -I ./01/include/
	@echo 01. CC 01
UE02: ./02/src/main.cpp ./02/src/Printf.cpp ./02/include/Printf.h
	$(CXX) $(CXXFLAGS) -o ./02/bin/02 ./02/src/*.cpp -I ./02/include/
	@echo 02. CC 02
UE03: ./03/src/main.cpp ./03/src/Printf.cpp ./03/include/PreAllocString.h ./03/include/Printf.h
	$(CXX) $(CXXFLAGS) -o ./03/bin/03 ./03/src/*.cpp -I ./03/include/
	@echo 03. CC 03
start:
	$(SILENT_MKDIR)mkdir ./01/bin
	$(SILENT_MKDIR)mkdir ./02/bin
	$(SILENT_MKDIR)mkdir ./03/bin
