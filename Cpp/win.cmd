@echo off

set BUILD_DIR=build
set PROJECT_NAME=CppProject

IF not exist %BUILD_DIR% (mkdir %BUILD_DIR%)

pushd %BUILD_DIR%
  cmake .. && .\%PROJECT_NAME%.sln
popd
