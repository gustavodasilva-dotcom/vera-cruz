#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

    return EXIT_SUCCESS;
}
