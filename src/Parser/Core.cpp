/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <Parser/Core.hpp>
#include <includeLink.hpp>

// Library
#include "../../Library/StringTools.h"
#include "../../Library/FileSystemPlusPlus.h"

void
CoreInit::CoreLink(std::string first, std::string second) {
  std::string link(fsplusplus::ReadFileWithReturn(second));
  fsplusplus::AppendLineToFile(first, link);
}
