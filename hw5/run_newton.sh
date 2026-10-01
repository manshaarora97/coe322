#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Error: you must give exactly one argument."
    exit 1
fi

echo "$1" | ./newton
