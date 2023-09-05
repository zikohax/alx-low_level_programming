#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _strncmp - Compare two strings up to a given number of bytes.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes to compare.
 *
 * Return: 0 if the first n bytes of s1 and s2 are equal, otherwise non-zero.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    for (; n && *s1 && *s2; --n, ++s1, ++s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
    }
    if (n)
    {
        if (*s1)
            return (1);
        if (*s2)
            return (-1);
    }
    return (0);
}

/**
 * _close - Close a file descriptor and print an error message upon failure.
 * @fd: The file descriptor to close.
 */
void _close(int fd)
{
    if (close(fd) != -1)
        return;
    write(STDERR_FILENO, "Error: Can't close fd\n", 22);
    exit(98);
}

/**
 * _read - Read from a file descriptor and print an error message upon failure.
 * @fd: The file descriptor to read from.
 * @buf: The buffer to write to.
 * @count: The number of bytes to read.
 */
void _read(int fd, char *buf, size_t count)
{
    if (read(fd, buf, count) != -1)
        return;
    write(STDERR_FILENO, "Error: Can't read from file\n", 28);
    _close(fd);
    exit(98);
}

/**
 * elf_magic - Print ELF magic.
 * @buffer: The ELF header.
 */
void elf_magic(const unsigned char *buffer)
{
    unsigned int i;

    if (_strncmp((const char *)buffer, ELFMAG, 4))
    {
        write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
        exit(98);
    }

    printf("ELF Header:\n  Magic:   ");

    for (i = 0; i < 16; ++i)
        printf("%02x%c", buffer[i], i < 15 ? ' ' : '\n');
}


/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success.
 */
int main(int argc, const char *argv[])
{
    unsigned char buffer[18];
    unsigned int bit_mode;
    int big_endian;
    int fd;

    if (argc != 2)
    {
        write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Error: Can't read from file\n", 28);
        exit(98);
    }

    _read(fd, (char *)buffer, 18);

    elf_magic(buffer);
    bit_mode = elf_class(buffer);
    big_endian = elf_data(buffer);
    elf_version(buffer);
    elf_osabi(buffer);
    elf_abivers(buffer);
    elf_type(buffer, big_endian);

    lseek(fd, 24, SEEK_SET);
    _read(fd, (char *)buffer, bit_mode / 8);

    elf_entry(buffer, bit_mode, big_endian);

    _close(fd);

    return (0);
}

