#include <fstream>
#include <iostream>
#include <exception>

#include "text_miner.h"





int main(int argc, char** argv)
{
	try
	{
		TextMiner app;
		app.addCategory("Programming languages", cl_standart);
		app.addCategory("Frameworks", cl_standart);
		app.addCategory("Experience", cl_exp);
		app.addDictionary("Dictionary");


	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
