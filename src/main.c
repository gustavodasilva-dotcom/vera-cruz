#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "tokenization/tokenizer.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Incorrect usage.\nvera <input.vera>\n");
        return EXIT_FAILURE;
    }

    char *file_name = argv[1];
    char *ext = strrchr(file_name, '.');

    if (ext == NULL || strcmp(ext, ".vera") != 0)
    {
        fprintf(stderr, "Invalid Vera Cruz file.\n");
        return EXIT_FAILURE;
    }

    if (access(file_name, F_OK) == -1)
    {
        fprintf(stderr, "The file %s does not exist.\n", file_name);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open file %s", file_name);
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL)
    {
        fprintf(stderr, "Error allocating memory to read file.");
        fclose(fp);
        return EXIT_FAILURE;
    }

    size_t bytes_read = fread(buffer, 1, file_size, fp);
    if (bytes_read != file_size)
    {
        printf("Error reading file.");
        free(buffer);
        fclose(fp);
        return EXIT_FAILURE;
    }

    buffer[file_size] = '\0';

    fclose(fp);

    tokenize(buffer);

    free(buffer);

    return EXIT_SUCCESS;
}
