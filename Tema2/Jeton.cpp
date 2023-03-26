#include "Jeton.h"

Jeton::Jeton()
{
	m_sourceIP = "";
	m_destinationIP = "";
	m_message = "";
	m_free = true;
	m_reachedDestination = false;
}

void Jeton::SetSourceIP(const std::string& sourceIP)
{
	this->m_sourceIP = sourceIP;
}

void Jeton::SetDestinationIP(const std::string& destinationIP)
{
	this->m_destinationIP = destinationIP;
}

void Jeton::SetMessage(const std::string& message)
{
	this->m_message = message;
}

std::string Jeton::GetSourceIP()
{
	return m_sourceIP;
}

std::string Jeton::GetDestinationIP()
{
	return m_destinationIP;
}

std::string Jeton::GetMessage()
{
	return m_message;
}

bool Jeton::CheckFree()
{
	return m_free;
}

bool Jeton::CheckReachedDestination()
{
	return m_reachedDestination;
}

void Jeton::ChangeFree()
{
	this->m_free = !this->m_free;
}

void Jeton::ChangeReachedDestination()
{
	this->m_reachedDestination = !this->m_reachedDestination;
}
