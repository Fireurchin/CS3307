// main method, code forked from boost
int main (int argc, char* argv[]) {
	std::string lowCommand;	// initial variables
	
	// repeat until termination
	while (lowCommand.compare("terminate")!=0) {
		std::cout << "Enter Command (or enter terminate to exit): ";
		getline (std::cin,lowCommand);
		
		// if command blank
		if (lowCommand.empty()) std::cout << "Invalid Command: Empty Blocks Cannot Be Parsed" << std::endl;
		
		else {
			Command command(lowCommand); // command declaration
			command.execute();
		}
	}
}