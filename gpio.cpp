#include <iostream>
#include <string>

class Ulfr
{
public:
	std::string cmd, io, pin;
	std::string sep{ "|----------------------------------------|" };

	void cls() {
		std::system("clear");
	}
	void pause() {
		std::cin.get();
	}

	void init() {
		cls();

		std::cout << sep << "\n|--{ GPIO++: Init }-------{ Sv4rtu1fr }--|\n" << sep << std::endl;
		std::cout << "|--{ Pin Control: ctrl   }---------------|" << std::endl;
		std::cout << "|--{ Pin Mode:    mode   }---------------|" << std::endl;
		std::cout << sep << "\n|--{ Select operation: "; std::cin >> cmd;

		if (cmd == "ctrl") {
			ctrl();
		}
		else if (cmd == "mode") {
			mode();
		}
		else if (cmd == "q") {
			exit(0);
		}
		else {
			std::cerr << "|--{ Error: GPIO++: Init }" << std::endl; pause(); init();
		}
	}

	void ctrl() {
		cls();
		std::cout << sep << "\n|--{ GPIO++: Control }----{ Sv4rtu1fr }--|\n" << sep << std::endl;
		std::cout << "|--{ GPIO ID: "; std::cin >> pin;
		std::cout << "|--{ GPIO Mode (1/0): "; std::cin >> io;

		cmd = "sudo gpio -g write " + pin + " " + io;
		std::system(cmd.c_str());
		init();
	}

	void mode() {
		cls();
		std::cout << sep << "\n|--{ GPIO++: Mode }-------{ Sv4rtu1fr }--|\n" << sep << std::endl;
		std::cout << "|--{ GPIO ID: "; std::cin >> pin;
		std::cout << "|--{ GPIO Mode (in/out): "; std::cin >> io;

		cmd = "sudo gpio -g mode " + pin + " " + io;
		std::system(cmd.c_str());
		init();
	}
};

int main(int argc, char *argv[]) {
	Ulfr u;
	u.init();
}