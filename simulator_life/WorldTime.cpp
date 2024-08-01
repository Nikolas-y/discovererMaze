#include "discoverer.h"
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
class EventTime
{
public:
	vector <Adiscoverer*> object;

	void HappenedTime()
	{
		for (int i = 0; i < object.size(); ++i)
		{
			system_clock::time_point t(system_clock::now());
			object[i]->DoTick(t);
		}

	}
};