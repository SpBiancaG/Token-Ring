#pragma once
#include <string>

class PC
{
public:
	void SetIP(const std::string& IP);
	void SetBuffer(const std::string& buffer);
	std::string GetIP();
	
	PC();
	PC(const std::string& IP);
private:
	std::string m_IP;
	std::string m_buffer;
};

