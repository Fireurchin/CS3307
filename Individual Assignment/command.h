/* Mingpei Dou */
/* cs3307 */
/* 05/10/2021 */
/* Command header initializes features to aid in command reading and output capture */
#ifndef COMMAND_CLASS_H
#define COMMAND_CLASS_H
#include <iostream>

class Command{
	private:
		std::string paramLine, hist; // history
		int exitCode; // exit code
	
    public:
		Command (std::string command);	// Constructor
		std::string execute(); // throws error
		std::string getCommand(); // returns command
		std::string getHistory();	// returns command history
		int getExitCode();	// returns exit code
		void setCommand(std::string command);	// set command
		void setHistory(std::string command); // sets command history
		~Command();	// Destructor
};
#endif 