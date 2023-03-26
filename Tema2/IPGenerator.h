#pragma once
#include <random>
#include "PC.h"

class IPGenerator
{
private:
	static std::string NewIP();
public:
	static std::vector<PC> GenerateIPs();
};

std::vector<PC> IPGenerator::GenerateIPs()
{
	std::vector<PC> PCs;
	int counter_PCs;
	std::cout << "Numar de calculatoare: ";
	std::cin >> counter_PCs;
	while (PCs.size() < counter_PCs)
	{
		std::string newIP = IPGenerator::NewIP();
		bool ok = true;
		for (auto x : PCs)
		{
			if (x.GetIP() == newIP)
			{
				ok = false;
			}
		}
		if (ok == true)
		{
			PCs.push_back(newIP);
		}
	}
	std::cout << "\nIP-urile calculatoarelor: ";
	for (auto x : PCs)
	{
		std::cout << "\n" << x.GetIP();
	}
	return PCs;
}

std::string IPGenerator::NewIP()
{
	std::random_device rd;  // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 255);
	std::string part1 = "192";
	std::string part2 = "168";
	std::string newGeneratedIP = part1 + "." + part2 + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen));
	return newGeneratedIP;
}
