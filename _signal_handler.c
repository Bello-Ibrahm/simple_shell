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


/**
 * signal_handler2 - handles ctrl + c during cmd exec
 * @x: unused value
 *
 * Return: No return
 */
void signal_handler2(int x)
{
	UNUSED(x);

	write(1, "\n", 1);
}
