#pragma once
#include <string>
class Logger
{
public:
	Logger();
	~Logger();
	void ClearLogIfNeeded();
	void Log(std::string message);
	void LogError(std::string description);
	void LogErrorSDL(std::string description);
};
