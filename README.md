# Welcome to the Simple Assembly Developer (sad)!

## Why `sad`?
Why waste precious moments of your life typing out long, convoluted commands to compile and link your assembly files like this:
```bash
nasm -f elf32 example.asm -o example.o && ld -m elf_i386 example.o -o example && ./example
```
Say goodbye to the old ways and embrace the simplicity of `sad`! With `sad`, you can compile and link your assembly code with just a single word, saving you time and frustration.

## Installation
Clone the `sad` repository and run the installation script:
```bash
git clone https://github.com/gnisrever/sad
cd sad
chmod +x install.sh
./install.sh
```

### Usage 
To compile your assembly code, simply type:
```bash
sad example.s
```
And voilà! Your assembly file is compiled into an executable binary. But why stop there? With `sad`, you can also execute your assembly file at the same time as compiling by using the `-e` flag:
```bash
sad example.s -e
```

## Contributions
We welcome contributions to make sad even better! Feel free to submit pull requests or open issues on our GitHub repository.

## Disclaimer
`sad` may cause feelings of sadness due to reminding the user that they are working with assembly.
