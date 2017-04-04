#include "..\headers\Logger.h"
#include <SDL.h>
#include <fstream>
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")
Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::ClearLogIfNeeded()
{
	std::ofstream logFile;
	if (PathFileExists("log.txt"))
		logFile.open("log.txt", std::fstream::out | std::fstream::trunc);

	logFile.close();
	logFile.clear();
}

void Logger::Log(std::string message)
{
	std::ofstream logFile("log.txt", std::fstream::out | std::fstream::app);
	message += "\n";
	logFile.write(message.c_str(), message.length());
	logFile.close();
	logFile.clear();
}

void Logger::LogError(std::string description)
{
	std::ofstream logFile("log.txt", std::fstream::out | std::fstream::app);
	std::string finalMessage{ "ERROR: " + description + "\n   "};

	logFile.write(finalMessage.c_str(), finalMessage.length());
	logFile.close();
	logFile.clear();
}

void Logger::LogErrorSDL(std::string description)
{
	std::ofstream logFile("log.txt", std::fstream::out | std::fstream::app);

	std::string errorSDL{ SDL_GetError() };
	if (errorSDL == "")
		errorSDL = "SDL ERROR NULL";
	std::string finalMessage{ "ERROR: " + description + "\n   " + "SDL Error: " + errorSDL + "\n"};

	logFile.write(finalMessage.c_str(), finalMessage.length());
	logFile.close();
	logFile.clear();
}