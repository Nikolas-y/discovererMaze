// simulator_life.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "map.h"
#include "discoverer.h"
#include "WorldTime.cpp"
using namespace chrono;
using namespace std;
int main()
{
    milliseconds C { 123 };
    seconds B{ 1 };
    std::cout << (B + C).count() << std::endl;
    system_clock ::time_point start(system_clock::now());
    
    
    Cmapping a;
    a.generate(4, 4);   
    a.info();
    //std::this_thread::sleep_for(milliseconds(3000));
    RobotDiscoverer* b = new RobotDiscoverer;
    thread th([&]()
        {
            EventTime d;
            d.object.push_back(b);
                while (true)
                {
                    d.HappenedTime();
                }
        }
    );
    b->scouting(a);
    b->Print_Memory();

    system_clock::time_point end(system_clock::now());
    std::cout << duration_cast<milliseconds>(end - start).count() << std::endl;
    th.join();
}
