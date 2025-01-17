/*
 * Deskflow -- mouse and keyboard sharing utility
 * Copyright (C) 2012-2016 Symless Ltd.
 * Copyright (C) 2002 Chris Schoeneman
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "base/XBase.h"
#include "base/String.h"

#include <cerrno>
#include <cstdarg>
#include <cstring>

//
// XBase
//

XBase::XBase() : std::runtime_error("")
{
  // do nothing
}

XBase::XBase(const std::string &msg) : std::runtime_error(msg)
{
  // do nothing
}

XBase::~XBase() _NOEXCEPT
{
  // do nothing
}

const char *XBase::what() const _NOEXCEPT
{
  if (const char *what = std::runtime_error::what(); what != nullptr && what[0] != '\0') {
    return what;
  }

  m_what = getWhat();
  return m_what.c_str();
}

std::string XBase::format(const char * /*id*/, const char *fmt, ...) const throw()
{
  // FIXME -- lookup message string using id as an index.  set
  // fmt to that string if it exists.

  // format
  std::string result;
  va_list args;
  va_start(args, fmt);
  try {
    result = deskflow::string::vformat(fmt, args);
  } catch (...) {
    // ignore
    result.clear();
  }
  va_end(args);

  return result;
}
