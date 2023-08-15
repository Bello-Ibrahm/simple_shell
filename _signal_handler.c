#include "main.h"
/**
 * signal_handler - This handle ctrl + c
 * @x: This is unused value
 *
 * Return: No return
 */
void signal_handler(int x)
{
	UNUSED(x);

	write(1, "\n$ ", 3);
}
