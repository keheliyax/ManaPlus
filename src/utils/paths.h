/*
 *  The ManaPlus Client
 *  Copyright (C) 2011-2013  The ManaPlus Developers
 *
 *  This file is part of The ManaPlus Client.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UTILS_PATHS_H
#define UTILS_PATHS_H

#include <string>

#include "localconsts.h"

std::string getRealPath(const std::string &str) A_WARN_UNUSED;

bool isRealPath(const std::string &str) A_WARN_UNUSED;

bool checkPath(std::string path) A_WARN_UNUSED;

std::string &fixDirSeparators(std::string &str);

std::string removeLast(std::string str) A_WARN_UNUSED;

std::string getSelfName() A_WARN_UNUSED;

std::string getDesktopDir() A_WARN_UNUSED;

#endif // UTILS_PATHS_H
