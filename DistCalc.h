#ifndef DISTCALC_H_
#define DISTCALC_H_ 

#include<Arduino.h>
using namespace std;

class DistCalc {
	private:
		unsigned long SentTime;
		unsigned long ReciTime;
		double Distance;

	public:
		DistCalc();
		~DistCalc();
		
		void SetSentTime(unsigned long inTime);
		void SetReciTime(unsigned long inTime2);
		double GetDistance(int16_t Rssi);
		double GetDistance();
};

#endif