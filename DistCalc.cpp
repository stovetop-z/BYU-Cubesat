#include "DistCalc.h"
#include "math.h"

DistCalc::DistCalc(){
	SentTime = 0;
	ReciTime = 0;
	Distance = 0;
};

DistCalc::~DistCalc(){};

void DistCalc::SetSentTime(unsigned long inTime){
	//Serial.println("Test");
	//Serial.println(inTime);
	SentTime = inTime;
}

void DistCalc::SetReciTime(unsigned long inTime2){
	ReciTime = inTime2;
}
		
double DistCalc::GetDistance(int16_t Rssi){
	int16_t txPower = 39;
	if(Rssi < 0)
	{
		Rssi=-1*Rssi;
	}
	//Serial.print(Rssi);
	double Gain = ((double)txPower - (double)Rssi)/(10*2);		//will not give good reading if the vaule is tx and rx are less than a meter
	if(Gain < 0){Gain=-1*Gain;}
	//Serial.print("Gain: ");
	//Serial.println(Gain);				
	//float ChangTime = (ReciTime - SentTime)*0.000001;  //ms convert to seconds by 0.001 
	//Serial.println("changetime");
	//Serial.println(ChangTime);
	//unsigned long SpeedLight = 299792458;                  //in m/s

	return pow(10, Gain);
}

double DistCalc::GetDistance(){
	//Serial.print("These are the times ");						//resolution of eight microseconds for 8Mhz and 4 for 16Mhz.
	//Serial.println(SentTime);									//the times are very inaccurate and will be most usefully in space instead of now
	//Serial.println(ReciTime);									//the percision is very low, might test by rounding
	float ChangTime = (float)(ReciTime - SentTime)*0.000001;  	//us convert to seconds by 0.000001. 
	unsigned long SpeedLight = 299792458;                  		//in m/s
	return (ChangTime*SpeedLight)/2;
}