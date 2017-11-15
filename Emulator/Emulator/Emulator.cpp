#include "Emulator.h"
#include <fstream>
#include <string>

#include <iostream>

std::string delete_white_char(std::string str);

void Emulator::command_interpreter()
{
	int current_addr = 0;

	while (current_addr < vProgram.size())
	{
		switch (vProgram[current_addr])
		{
		case assign:
			vRegisters[vProgram[current_addr + 1]-1] = vProgram[current_addr + 2];
			current_addr += 3;
			break;
		case JE:
			if (vRegisters[vProgram[current_addr + 1]-1] == vRegisters[vProgram[current_addr + 2]-1])
				current_addr = vProgram[current_addr + 3];
			else current_addr += 4;
			break;
		case add_data_to_reg:
			vRegisters[vProgram[current_addr + 1]-1] += vData[vRegisters[vProgram[current_addr + 2]-1]];
			current_addr += 3;
			break;
		case add_to_reg:
			vRegisters[vProgram[current_addr + 1]-1] += vProgram[current_addr + 2];
			current_addr += 3;
			break;
		case JMP:
			current_addr = vProgram[current_addr + 1];
			break;
		case div:
			vRegisters[vProgram[current_addr+1]-1] /= vRegisters[vProgram[current_addr + 2]-1];
			current_addr += 3;
			break;
		case print:
			std::cout << vRegisters[vProgram[current_addr + 1]-1] << std::endl;
			current_addr += 2;
			break;
		case end:
			current_addr = vProgram.size();
			break;
		default:
			break;
		}
	}

	std::cin.get();
	std::cin.get();
}

void Emulator::parser()
{
	std::vector<label> labels;

	mem actual_mem = mem::prog;
	int current_addr = 0;

	for (int i = 0; i < vListing.size(); ++i)
	{
		std::string line = delete_white_char(vListing[i]);

		if (line == ".data") { actual_mem = mem::data; continue; }
		if (line == ".prog") { actual_mem = mem::prog; continue; }
		
		if (line.find(':') != std::string::npos) {
			labels.push_back(label{ line.substr(0, line.find(':')), current_addr });
		}

		if (actual_mem == mem::prog) {
			current_addr += comand_lenght(line);
		}
	}

	actual_mem = mem::prog;

	for (int i = 0; i < vListing.size(); ++i)
	{
		std::string line = delete_white_char( vListing[i] );

		if (std::empty(line)) continue;

		if (line.find(':') != std::string::npos) {
			line.substr(0, line.find(':'));
		}

		if (line == ".data") { actual_mem = mem::data; continue; }
		if (line == ".prog") { actual_mem = mem::prog; continue; }
		
		if (actual_mem == mem::data)
		{
			while (line.size()) 
			{
				int pos = line.find(' ');
				std::string num;
				if (pos != -1)
				{
					num = line.substr(0, pos);
					line.erase(line.begin(), line.begin() + pos + 1);
				}
				else
				{
					num = line;
					line.clear();
				}

				//integer x{ std::stoi(num.c_str()) };

				/*for (int i = 0; i < sizeof(integer); ++i)
					vData.push_back(*(&x.c + i));*/
				vData.push_back(std::stoi(num.c_str()));
			}
		}
		else if (actual_mem == mem::prog)
		{
			std::vector<int> bin;

			switch (cmd_id(line))
			{
			case assign:
				bin = assign_str_to_bin(line);
				break;
			case add_data_to_reg:
				bin = add_data_to_reg_str_to_bin(line);
				break;
			case add_to_reg:
				bin = add_to_reg_str_to_bin(line);
				break;
			case JE:
				bin = JE_str_to_bin(line, labels);
				break;
			case JMP:
				bin = JMP_to_bin(line, labels);
				break;
			case div:
				bin = div_str_to_bin(line);
				break;
			case print:
				bin = print_str_to_bin(line);
				break;
			case end:
				bin.push_back(8);
				break;
			default:
				throw except::no_command;
			}

			for (int x : bin)
				vProgram.push_back(x);

		}
	}
}

int Emulator::cmd_id(std::string cmd)
{
	if (cmd.find("<=") != std::string::npos) return assign;
	if ((cmd.find("+=") != std::string::npos) && 
		(cmd.find("D") != std::string::npos)) return add_data_to_reg;
	if (cmd.find("+=") != std::string::npos) return add_to_reg;
	if (cmd.find("/=") != std::string::npos) return div;
	if (cmd.find("JE") != std::string::npos) return JE;
	if (cmd.find("JMP") != std::string::npos) return JMP;
	if (cmd.find("PRINT") != std::string::npos) return print;
	if (cmd.find("END") != std::string::npos) return end;

	return -1;
}

int Emulator::comand_lenght(std::string cmd)
{
	switch (cmd_id(cmd))
	{
	case assign: return 3;
	case add_data_to_reg: return 3;
	case add_to_reg: return 3;
	case JE: return 4;
	case JMP: return 2;
	case div: return 3;
	case print: return 2;
	case end: return 1;
	default:
		throw except::no_command;
	}
}

std::vector<int> Emulator::assign_str_to_bin(std::string str)
{
	std::vector<int> ret;
	ret.push_back(assign);

	ret.push_back(std::stoi(str.substr(str.find("R") + 1, str.find(' '))));
	ret.push_back(std::stoi(str.substr(str.find(' ', str.find("<=")) + 1, str.find(' ', str.find(' ', str.find("<=")) + 1))));

	return ret;
}

std::vector<int> Emulator::JE_str_to_bin(std::string str, const std::vector<label> & lab)
{
	std::vector<int> ret;
	int pos = 0;
	ret.push_back(JE);
	ret.push_back(std::stoi(str.substr(str.find("R") + 1, str.find(','))));
	pos = str.find(',', str.find(' ', str.find(",")) + 1);
	ret.push_back(std::stoi(str.substr(str.find('R', str.find(",")) + 1, pos))); 
	std::string sLabel = delete_white_char( str.substr( str.rfind(' '), str.size() ));

	for (int i = 0; i < lab.size(); ++i)
	{
		if ( lab[i].name == sLabel )
		{
			ret.push_back(lab[i].address);
			break;
		}
	}

	return ret;
}

std::vector<int> Emulator::add_data_to_reg_str_to_bin(std::string str)
{
	std::vector<int> ret;
	ret.push_back(add_data_to_reg);

	ret.push_back(std::stoi(str.substr(str.find('R') + 1, str.find(' '))));
	ret.push_back(std::stoi(str.substr(str.find("D[R") + 3, str.rfind(']'))));

	return ret;
}

std::vector<int> Emulator::add_to_reg_str_to_bin(std::string str)
{
	std::vector<int> ret;
	ret.push_back(add_to_reg);

	ret.push_back(std::stoi(str.substr(str.find('R') + 1, str.find(' '))));
	ret.push_back(std::stoi(str.substr(str.rfind(' '), str.size())));

	return ret;
}

std::vector<int> Emulator::JMP_to_bin(std::string str, const std::vector<label> & lab)
{
	std::vector<int> ret;
	ret.push_back(JMP);
	std::string sLabel = delete_white_char(str.substr(str.find(' '), str.size()));
	for (int i = 0; i < lab.size(); ++i)
	{
		if (lab[i].name == sLabel)
		{
			ret.push_back(lab[i].address);
			break;
		}
	}

	return ret;
}

std::vector<int> Emulator::div_str_to_bin(std::string str)
{
	std::vector<int> ret;
	ret.push_back(div);

	ret.push_back(std::stoi(str.substr(str.find('R') + 1, str.find(' '))));
	ret.push_back(std::stoi(str.substr(str.rfind('R') + 1, str.size())));

	return ret;
}

std::vector<int> Emulator::print_str_to_bin(std::string str)
{
	std::vector<int> ret;
	ret.push_back(print);

	ret.push_back(std::stoi(str.substr(str.rfind('R')+1, str.size())));

	return ret;
}

void Emulator::load_file(std::string file_name)
{
	std::ifstream in;
	in.open(file_name.c_str(), std::ios::in);

	if (!in.is_open()) throw except::file_read_error;

	while (!in.eof())
	{
		std::string str;
		getline(in, str);
		vListing.push_back(str);
	}

	in.close();

	parser();
}

Emulator::Emulator(std::string file_name)
{
	load_file(file_name);
	vRegisters.resize(3);
}

Emulator::~Emulator()
{
}

void Emulator::run()
{
	command_interpreter();
}

std::string delete_white_char(std::string str)
{
	for (int i = 0; i < str.size(); ++i) 
	{
		if (str[i] == '\t')
			str[i] = ' ';
		if ((i == str.size() -1) && (str[i] == ' ')) {
			str.erase(str.begin(), str.begin() + 1); i--; continue;
		}
		if ((i == 0) && (str[i] == ' ')) {
			str.erase(str.begin(), str.begin() + 1); i--; continue;
		}
		if ((str[i] == ' ') && (str[i + 1] == ' ') && (i + 1 < str.size())) {
			str.erase(str.begin() + 1, str.begin() + 2); i--; continue;
		}
	}

	return str;
}