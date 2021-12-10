/* Mingpei Dou */
/* cs3307 */
/* 05/10/2021 */
/* Command class implements features of command.h */
#include <boost/process.hpp>
#include <iostream>
#include "command.h"

using namespace boost::process;

		// constructor for class
		Command::Command(std::string command) {
			setCommand(command);
			setHistory(command);
		}
		
		// execute method forked from boost code
		std::string Command::execute(){
			std::string outp = "";
			exitCode = 1;
			try {
				// local variables
				ipstream pipe_stream;
				std::string line;
				
				if (getCommand().compare("clear")==0)
					outp = "";
				
				else if (getCommand().compare("yes")==0||getCommand().compare("ex")==0)
					outp = "Quit spamming this shit";
				
				else if (getCommand().compare("vim")==0)
					outp = "Richtext editing not compatible with system";
				
				else {
					// utilizes getCommand() for parsing
					child c(getCommand(),(std_out & std_err) > pipe_stream);

					while (pipe_stream && std::getline(pipe_stream, line) && !line.empty()){
						outp.append(line).append("\n");
						//std::cerr << line << std::endl;
					}
					exitCode = 0;
					c.wait();
				}
			}
			catch (boost::process::process_error&e ){	// catch incorrect command
				outp = "Please enter a valid command";
			}
			return outp;
		}
		
		// getter methods
		std::string Command::getCommand(){
			return paramLine;
		}
		std::string Command::getHistory(){
			return hist;
		}
		int Command::getExitCode(){
			return exitCode;
		}
		
		// setter for command line
		void Command::setCommand(std::string command){
			paramLine = command;
		}
		
		// setter for command history
		void Command::setHistory(std::string command){
			if (!command.empty())
				hist = command;
		}
		
		// destructor (does nothing)
		Command::~Command(){
		}