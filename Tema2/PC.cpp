#include "PC.h"

void PC::SetIP(const std::string& IP)
{
	this->m_IP = IP;
}

void PC::SetBuffer(const std::string& buffer)
{
	this->m_buffer = buffer;
}

std::string PC::GetIP()
{
	return m_IP;
}



PC::PC()
{
	this->m_IP = "";
	
}

PC::PC(const std::string& IP)
{
	this->m_IP = IP;
	
}
