#!/bin/bash

# Check if gcc is installed
if ! command -v gcc &> /dev/null; then
    echo "Error: gcc is not installed. Please install gcc before running this script."
    exit 1
fi

# Compile sad.c
if ! gcc -o sad sad.c; then
    echo "Error: Compilation failed. Please check your sad.c file for errors."
    exit 1
fi

# Move sad executable to /usr/local/bin/
if ! sudo mv sad /usr/local/bin/; then
    echo "Error: Failed to move sad executable to /usr/local/bin/. Please check permissions."
    exit 1
fi

# Set permissions
if ! sudo chmod +x /usr/local/bin/sad; then
    echo "Error: Failed to set executable permissions on /usr/local/bin/sad. Please check permissions."
    exit 1
fi

echo "Installation complete. You can now use 'sad' command to compile your source files."
