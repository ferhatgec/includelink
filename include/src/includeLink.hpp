/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef INCLUDE_LINK_HPP
#define INCLUDE_LINK_HPP

#include <iostream>
#include <cstring>

#define includeLink_Version "0.1"
#define includeLink_State "beta-1"

static std::string hyphen("-");

class includeLink {
public:
	// args, version
	std::string ParseLink(std::string, std::string);
	void Interpreter(std::string, std::string);
	// args
	std::string Path(std::string);
	void CreateLink(std::string, std::string);

	// Help
	void HelpFunction();
};

#endif // INCLUDE_LINK_HPP
