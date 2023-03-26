#pragma once
#include <string>
class Jeton
{
public:
	Jeton();
	void SetSourceIP(const std::string& sourceIP);
	void SetDestinationIP(const std::string& destinationIP);
	void SetMessage(const std::string& message);
	std::string GetSourceIP();
	std::string GetDestinationIP();
	std::string GetMessage();
	bool CheckFree();
	bool CheckReachedDestination();
	void ChangeFree();
	void ChangeReachedDestination();


private:
	std::string m_sourceIP;
	std::string m_destinationIP;
	std::string m_message;
	bool m_free;
	bool m_reachedDestination;
};

