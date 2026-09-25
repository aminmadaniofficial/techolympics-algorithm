#!/usr/bin/env bash

set -e

if [ -z "$1" ]; then
    echo "Usage: ./run.sh <ProblemLetter_or_File> [test_input_file]"
    echo "Example: ./run.sh A"
    echo "         ./run.sh A/sol.cpp"
    exit 1
fi

TARGET="$1"
INPUT="${2:-in.txt}"

if [ -d "$TARGET" ]; then
    DIR="$TARGET"
    SRC="$DIR/sol.cpp"
    IN="$DIR/$INPUT"
elif [ -f "$TARGET" ]; then
    SRC="$TARGET"
    DIR="$(dirname "$TARGET")"
    IN="$DIR/$INPUT"
else
    # Maybe passed just letter like 'A'
    DIR="$TARGET"
    SRC="$DIR/sol.cpp"
    IN="$DIR/$INPUT"
fi

BIN="/tmp/cp_solution"

echo "=== Compiling $SRC ==="
g++ -std=c++20 -O3 -Wall -Wextra -DLOCAL "$SRC" -o "$BIN"

echo "=== Running Solution ==="
if [ -f "$IN" ] && [ -s "$IN" ]; then
    echo "Input from $IN:"
    time "$BIN" < "$IN"
else
    echo "Waiting for standard input (Ctrl+D to finish):"
    time "$BIN"
fi
