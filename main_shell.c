#include "simple_shell.h"

int main(void)
{
	char command [150];
	while (true)
	{
		prompt_display();
		read_input(command, sizeof(command));
		execute_command(command);
	}
	return 0;
}
