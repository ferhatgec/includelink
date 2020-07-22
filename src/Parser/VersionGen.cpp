/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <Parser/VersionGen.hpp>
#include <includeLink.hpp>

// Library
#include "../../Library/StringTools.h"

// const std::string compilation_time = __TIME__;
std::string ftime(__TIME__); // Convert

std::string
VersionGen::VersionGenerator() {
  return includeLink_Version + hyphen + includeLink_State + stringtools::EraseAllSubString(ftime, ":");
}
