# Deskflow -- mouse and keyboard sharing utility
# Copyright (C) 2024 Chris Rizzitello <sithlord48@gmail.com>
# Copyright (C) 2012-2024 Symless Ltd.
# Copyright (C) 2009-2012 Nick Bolton
#
# This package is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# found in the file LICENSE that should have accompanied this file.
#
# This package is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

set(target deskflow-core)

add_executable(${target} "${target}.cpp")
if(WIN32)
  target_sources(${target} PRIVATE
    "${target}.exe.manifest"
    "${PROJECT_BINARY_DIR}/src/version.rc"
  )
endif()

target_link_libraries(
  ${target}
  arch
  base
  client
  io
  mt
  net
  ipc
  platform
  server
  app
  ${libs})

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY $<TARGET_BUNDLE_CONTENT_DIR:Deskflow>/MacOS)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  install(TARGETS ${target} DESTINATION bin)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  install(
    TARGETS ${target}
    RUNTIME_DEPENDENCY_SET coreDeps
    DESTINATION .
  )
  install(RUNTIME_DEPENDENCY_SET coreDeps
    PRE_EXCLUDE_REGEXES
      "api-ms-win-.*"
      "ext-ms-.*"
      "^hvsifiletrust\\.dll$"
    POST_EXCLUDE_REGEXES
      ".*system32.*"
    RUNTIME DESTINATION .
  )
endif()
