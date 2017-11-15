#pragma once
#include <vector>

class Emulator
{
private:
	struct label
	{
		std::string name;
		int address;
	};

	enum { assign = 1, JE = 2, add_data_to_reg = 3, add_to_reg = 4, JMP = 5, div = 6, print = 7, end = 8 };
	enum class mem { data, prog };

	std::vector<std::string> vListing;
	std::vector<int> vProgram;
	std::vector<int> vData;
	std::vector<int> vRegisters;
	int program_counter;

	void parser();
	void command_interpreter();
	int cmd_id(std::string cmd);
	int comand_lenght(std::string cmd);
	std::vector<int> assign_str_to_bin(std::string str);
	std::vector<int> JE_str_to_bin(std::string str, const std::vector<label> & lab);
	std::vector<int> add_data_to_reg_str_to_bin(std::string str);
	std::vector<int> add_to_reg_str_to_bin(std::string str);
	std::vector<int> JMP_to_bin(std::string str, const std::vector<label> & lab);
	std::vector<int> div_str_to_bin(std::string str);
	std::vector<int> print_str_to_bin(std::string str);

public:
	enum class except { file_read_error, no_command };

	void load_file(std::string file_name);

	Emulator() = delete;
	Emulator(std::string file_name);
	~Emulator();

	void run();
};

