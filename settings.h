#pragma once
#include <fstream>
#include <iostream>
#include <string>

std::fstream configExist(std::string path, std::string fileType)
{
	std::string cPath = "../" + path + fileType;
	std::fstream stream;
	
	stream.open(cPath);

	if (!stream.fail())
	{
		return stream;
	}
	else
	{
		return stream; // should create a new text file
	}


}

template<typename T>
void writeToFile(std::fstream stream, T data) 
{
	stream << data + "\n"; // writes to the file and makes newline
}

std::string getData(std::fstream stream)
{
	int L = stream.tellg();
	char* buf = new char[L];
	stream.read(buf,L);
	std::string read(buf);
	return buf;
}