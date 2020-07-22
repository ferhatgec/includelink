# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
#

# PATHS
SRCPARSERDIREC = ./src/Parser/
SRCDIREC = ./src/
PREFIX = /bin/

INCLUDEDIR = ./include/src/
CFLAGS = -c -Wall -I$(INCLUDEDIR)

GCC = gcc
GPP = g++
COMP = g++ -c
HECOMP = g++ -c -Wall $< -std=gnu++17 -o

# CLEAN
CLEANALL = inclink
CLEAN = *.o
HEADERFILE = VersionGen.o

ifeq ($(OS),Windows_NT)
	echo Windows_NT is not supported!
	#CLEAN := del $(CLEAN)
	#CLEANALL := del $(CLEANALL)
else
	CLEAN := rm -f $(CLEAN)
	CLEANALL := rm -f $(CLEANALL)
endif


all: headersfile main clean

allp: headersfile mainc clean

removeall: uninstall cleanall

runall: all run

gra: runall git

git:
	git add .
	git commit -a
	git push origin master

push:
	git push origin master

nall: cleanall

headersfile: $(HEADERFILE)

%.o: $(SRCPARSERDIREC)%.cpp
	$(GPP) -Wno-unused-function -Wno-unused-value $(CFLAGS) -c $< -o $@

main: $(SRCDIREC)includeLink.cpp
	$(GPP) -I$(INCLUDEDIR) -Wno-unused-function -Wno-unused-value $< $(HEADERFILE) -o inclink
	echo includeLink building successfully!

mainc: $(SRCDIREC)includeLink.cpp
	$(GPP) -I$(INCLUDEDIR) -Wno-unused-function -Wno-unused-value $< $(HEADERFILE) -o /bin/inclink
	echo includeLink building successfully in Bin Directory!

uninstall:
	rm -f /bin/inclink

run:
	./inclink

clean:
		$(CLEAN)

cleanall:
		echo Cleaning build directory!
		$(CLEANALL)
