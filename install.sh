#!/bin/bash

# Compile sad.c
gcc -o sad sad.c

# Move sad executable to /usr/local/bin/
sudo mv sad /usr/local/bin/

# Set permissions
sudo chmod +x /usr/local/bin/sad

echo "Installation complete. You can now use 'sad' command to compile your assembly files."
