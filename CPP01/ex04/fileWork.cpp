#include "fileWork.hpp"

fileWork::fileWork(std::string fileName, std::string s1, std::string s2)
    : fileName(fileName), s1(s1), s2(s2) // connects each parameter to its corresponding attribute.
{
}

void fileWork::replaceStrings()
{
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return;
    }

    std::ifstream inputFile(fileName.c_str()); //create an ifstream called inputFile and open the file whose name is inside argv[1].
    if (!inputFile)
    {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }

    std::string outputFileName = fileName + ".replace";
    std::ofstream outputFile(outputFileName.c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Could not create output file "
                  << outputFileName << std::endl;
        return;
    }

    std::string content;
	char c;
	while (inputFile.get(c))
    	content += c;
    //std::getline(inputFile, content, '\0');

    std::size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    outputFile << content;

    inputFile.close();
    outputFile.close();
}