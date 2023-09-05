#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: Name of the file.
 * @text_content: NULL-terminated string to append to the end of the file (can be NULL).
 *
 * Return: 1 on success, -1 on failure.
 *         If filename is NULL, return -1.
 *         If text_content is NULL, do not add anything to the file.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, n_print, len = 0;

	/* Check for invalid filename */
	if (filename == NULL)
		return (-1);

	/* Open the file in write-only mode, append mode, or create if it doesn't exist */
	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	/* Write text_content to the file if provided */
	if (text_content)
	{
		while (text_content[len])
			len++;

		n_print = write(fd, text_content, len);

		if (n_print == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

