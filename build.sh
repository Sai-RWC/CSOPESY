#!/usr/bin/env bash
x86_64-w64-mingw32-g++ -static -static-libgcc -static-libstdc++ -std=c++20 ./*.cpp  -o main.exe
