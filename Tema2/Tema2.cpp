#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "Jeton.h"
#include "PC.h"
#include "IPGenerator.h"

std::mutex num_mutex;

int GetPosition(std::vector<PC>& PCs, const std::string& foundIP)
{
	for (int i = 0; i < PCs.size(); i++)
	{
		if (PCs[i].GetIP() == foundIP)
			return i;
	}
	return -1;
};

void GetJeton(PC& sourcePC, PC& destinationPC, Jeton& jetonul)
{

  const std::string  message="Mesaj";
	num_mutex.lock();
	if (jetonul.CheckFree()==true)
	{
		
		jetonul.ChangeFree();
		
		
		jetonul.SetSourceIP(sourcePC.GetIP());
		jetonul.SetDestinationIP(destinationPC.GetIP());
		jetonul.SetMessage(message);
		sourcePC.SetBuffer(message);
		std::cout << "\nIP Sursa = " << jetonul.GetSourceIP() << " IP Destinatie " << jetonul.GetDestinationIP() << " " << jetonul.GetMessage();
	}
	num_mutex.unlock();
}

int main()
{
	std::vector<PC> PCs = IPGenerator::GenerateIPs();
	Jeton jetonul;

	std::random_device rd;  // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(0, PCs.size() - 1);

	int steps;
	std::cout<<"\n";
	std::cout << "\n";
	std::cout << "Scrieti de cate ori sa aiba loc transmiterea mesajului:";
	std::cin >> steps;
	int counterSteps = 0;
	int threadsGenerated = 10;
	while (counterSteps < steps)
	{
		std::vector<std::thread> threads;
		for (int i = 0; i < threadsGenerated; i++)
		{
			int indexSourcePC = dis(gen);
			int indexDestinationPC = dis(gen);
			while (indexSourcePC == indexDestinationPC)
			{
				indexDestinationPC = dis(gen);
			}
			threads.push_back(std::thread(GetJeton, std::ref(PCs[indexSourcePC]), std::ref(PCs[indexDestinationPC]), std::ref(jetonul)));
		}
		for (int i = 0; i < threads.size(); i++)
			threads[i].join();
		threads.clear();
		int startPosition = GetPosition(PCs, jetonul.GetSourceIP()),
			finalPosition = GetPosition(PCs, jetonul.GetDestinationIP());
		short ok = 0;
		for (int currentPosition = startPosition; ok != 2;)
		{
			if (currentPosition % PCs.size() == finalPosition && ok == 0)
			{
				ok = 1;
				jetonul.ChangeReachedDestination();
				PCs[currentPosition].SetBuffer(jetonul.GetMessage());
				finalPosition = startPosition;
				std::cout << "\nPC (" << currentPosition << ") IP = (" << PCs[currentPosition].GetIP() <<
					") Ajuns la destinatie.";

			}
			else if (currentPosition % PCs.size() == finalPosition && ok == 1)
			{
				ok = 2;
				jetonul.ChangeReachedDestination();
				jetonul.ChangeFree();
				jetonul.SetSourceIP("");
				jetonul.SetDestinationIP("");
				jetonul.SetMessage("");
				std::cout << "\nPC (" << currentPosition << ") IP = (" << PCs[currentPosition].GetIP() <<
					") Ajuns inapoi la sursa.\n";
			}
			else
			{
				std::cout << "\nPC (" << currentPosition << ") IP = (" << PCs[currentPosition].GetIP() <<
					") Muta jetonul.";
			}
			currentPosition = (currentPosition + 1) % PCs.size();
		}
		counterSteps++;
	}
}