#include <fstream>
#include <iostream>
#include <exception>

#include "text_miner.h"


const std::string PL = "Programming languages";
const std::string FW = "Frameworks";
const std::string EX = "Experience";
const std::string OT = "Other tools";




int main(int argc, char** argv)
{
	try
	{

		/*
		 * Tests for TextMiner - success
		 */
		TextMiner app;
		app.addCategory(PL, cl_standart);
		app.addCategory(FW, cl_standart);
		app.addCategory(EX, cl_standart);
		app.addCategory(OT, cl_exp);
		app.addDictionary("Dictionary.json");

		app.removeCategory(OT);

		app.process("input_file.json");



		/*
		 * Tests for Storage - success
		 */
		Storage st;
		st.addCateg(PL);
		st.addCateg(FW);
		st.addCateg(EX);
		st.addCateg(OT);
		st.removeCateg(OT);
		st.addWordInCateg("Java", PL);
		st.addWordInCateg("C++", PL);
		st.addWordInCateg("Pascal", PL);
		st.removeWordFromCateg("Pascal", PL);

		// false calls
		st.addWordInCateg("WTF", "NoName");
		st.removeCateg("WTF");

		std::cout << st.getWordCateg("Java") << std::endl;
		std::cout << st.getWordCateg("Borya") << std::endl;



	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
