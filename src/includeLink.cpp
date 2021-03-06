/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <includeLink.hpp>
#include <Parser/VersionGen.hpp>
#include <Parser/Core.hpp>

// Libraries
#include "../Library/FileSystemPlusPlus.h"
#include "../Library/StringTools.h"

/* Hello World && Hello includeLink Text File Link
*  helloworld.include (link name)
*  	helloworld.text = @Hello World!@
*  	helloworld.type = @.md@
*  helloworld.end (link end)
*  hellolink.include (link name)
*  	hellolink.text = @Hello includeLink!@
*  	hellolink.type = @.txt@
*  hellolink.end (link end)
*
*/

std::string
includeLink::ParseLink(std::string args, std::string version) {
	std::string link;
	link.append(args);
	link.append(".inclink\n");
	link.append(args);
	link.append(".text = @");
	link.append(fsplusplus::ReadFileWithReturn(args));
	link.append("@\n");
	link.append(args);
	link.append(".type = @.txt@\n");
	link.append(args);
	link.append(".end");
	return link;
	//return "null.include\nnull.text = @null@\nnull.type = @.txt@\nnull.end";
}

std::string
includeLink::Path(std::string name) {
	std::string path;
    	path.append(fsplusplus::GetCurrentWorkingDir());
    	path.append("/");
    	path.append(name);
}

void
includeLink::Interpreter(std::string args, std::string version) {
	std::string line;
        std::ifstream readfile((fsplusplus::GetCurrentWorkingDir() + "/" + args).c_str());
    	if(readfile.is_open()) {
        while (std::getline(readfile, line)) {
        	if(strstr(line.c_str(), ".txt.text")) {
        		fsplusplus::CreateFile(stringtools::EraseAllSubString(args, ".inclink"), stringtools::GetBetweenString(line, "text = @", "@"));
        	}
        }
        readfile.close();
    	} else {
        	printf("Unable to open file\n");
    	}
}


void
includeLink::CreateLink(std::string args, std::string version) {
	fsplusplus::CreateFile(args + ".inclink", ParseLink(args, version));
	std::cout << "Nice!";
}

void
includeLink::HelpFunction() {
	std::cout << "includeLink <args>\n--g : Generates includeLink file.\n" <<
	"--r : Reads and generates file from includeLink\n" <<
	"--v : Shows includeLink's version and build number\n" <<
  "--l : Links file from file\n" <<
	"--h : Shows here.\n";
}

int main(int argc, char** argv) {
	includeLink link;
	 if(argc > 1) {
		for(int i = 1; i < argc; i++) {
			std::string arg(argv[i]);
			if(arg.substr(0, 2) == "--") {
				if(arg == "--g") {
					std::string args;
        				std::getline(std::cin, args);
        				link.CreateLink(args, args);
				} else if(arg == "--r") {
					std::string args;
					std::getline(std::cin, args);
					link.Interpreter(args, args);
				} else if(arg == "--v") {
					VersionGen version;
					std::cout << version.VersionGenerator() << "\n";
				} else if(arg == "--h") {
					link.HelpFunction();
				} else if(arg == "--l") {
					std::cout << "First: ";
					std::string first, second;
					std::getline(std::cin, first);
					std::cout << "Second: ";
					std::getline(std::cin, second);
					CoreInit core;
					core.CoreLink(first, second);
				} else {
					link.HelpFunction();
				}
			} else {
				link.HelpFunction();
			}
		}
	} else {
		link.HelpFunction();
	}
}
