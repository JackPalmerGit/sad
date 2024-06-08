#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_SIZE 512
#define MAX_FILE_NAME_SIZE 256

void compile_and_link(const char *file, const char *fileName) {
    char command[MAX_COMMAND_SIZE];
    snprintf(command, sizeof(command), "nasm -f elf64 %s && ld %s.o -o %s", file, fileName, fileName);
    
    if (system(command) != 0) {
        fprintf(stderr, "Error: Compilation or linking failed.\n");
        exit(EXIT_FAILURE);
    }
}

void execute(const char *fileName) {
    char command[MAX_COMMAND_SIZE];
    snprintf(command, sizeof(command), "./%s", fileName);

    if (access(fileName, X_OK) == -1) {
        fprintf(stderr, "Error: Executable file '%s' not found or not executable.\n", fileName);
        exit(EXIT_FAILURE);
    }

    if (system(command) != 0) {
        fprintf(stderr, "Error: Execution failed for file '%s'.\n", fileName);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("simple assembly developer (sad) -> developed by gnisrever\n");
        fprintf(stderr, "Usage: %s <assembly-file> [-e/--execute]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *file = argv[1];
    char *valid_extensions[] = {".s", ".S", ".asm", ".ASM", ".nas", ".NASM"};
    int execute_flag = 0;

    for (int i = 2; i < argc; ++i) {
        if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--execute") == 0) {
            execute_flag = 1;
        } else {
            fprintf(stderr, "Invalid option: %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }

    int valid_file = 0;
    for (int i = 0; i < sizeof(valid_extensions) / sizeof(valid_extensions[0]); ++i) {
        if (strstr(file, valid_extensions[i])) {
            valid_file = 1;
            break;
        }
    }

    if (!valid_file) {
        fprintf(stderr, "Error: Invalid file format. Only .s, .S, .asm, .ASM, .nas, or .NASM files are supported.\n");
        exit(EXIT_FAILURE);
    }

    char fileName[MAX_FILE_NAME_SIZE];
    strcpy(fileName, file);
    char *ext = strrchr(fileName, '.');
    if (ext) {
        *ext = '\0';
    }

    compile_and_link(file, fileName);

    if (execute_flag) {
        execute(fileName);
    }

    return 0;
}
