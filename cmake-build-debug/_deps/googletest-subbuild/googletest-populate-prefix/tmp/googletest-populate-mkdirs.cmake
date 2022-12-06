# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/evan/CLionProjects/ITMO/Programming labs/labwork2-ewvan/cmake-build-debug/_deps/googletest-src"
  "/Users/evan/CLionProjects/ITMO/Programming labs/labwork2-ewvan/cmake-build-debug/_deps/googletest-build"
  "/Users/evan/CLionProjects/ITMO/Programming labs/labwork2-ewvan/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/evan/CLionProjects/ITMO/Programming labs/labwork2-ewvan/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/evan/CLionProjects/ITMO/Programming labs/labwork2-ewvan/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/evan/CLionProjects/ITMO/Programming labs/labwork2-ewvan/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/evan/CLionProjects/ITMO/Programming labs/labwork2-ewvan/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/evan/CLionProjects/ITMO/Programming labs/labwork2-ewvan/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
