#include "Emulator.h"

int main(int argc, char* argv[])
{
	Emulator emulator{argv[1]};
	emulator.run();

	return 0;
}