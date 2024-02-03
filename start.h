#include <iostream>
#include "hotel.h"

using namespace std;

void startHotel()
{
	Hotel* hotel = new Hotel("Fri-Chicks");
	hotel->MainMenu();
}