#!/usr/bin/env bash

rm render 2> /dev/null
find src/ -name "*.cpp" -not -path "src//build*" | xargs g++ -Isrc/world -Isrc/geometricobjects -Isrc/tracers -Isrc/utility -Isrc/build -o render && ./render
