// a home assistant to check humidity and temperature values of your home and verify you if something went wrong.

// use macros instead of variables when using repeated answers for readability and constant values
//#define _CRT_SECURE_NO_WARNINGS
#define _HIGH_TEMP "Your home is too hot"
#define _IDEAL_TEMP "Your home is warm"
#define _LOW_TEMP "Your home is a little bit cold"
#define _FREEZING_TEMP "Your home is so cold"
#define _HIGH_HUMIDITY "humidity level is so high"
#define _IDEAL_HUMIDITY "humidity level is ideal"
#define _LOW_HUMIDITY "humidity level is so low"
#include <stdio.h>

int main()
{
	int temp;
	int humidity;

	printf("Enter the home temperature and relative humidity (above 0, except 0) as an integer: \n");
	scanf_s("%i %i", &temp, &humidity);
	printf("\n");

	// relative humidity value can not reach 0 in present air conditions, this situation must be excluded
	// use #ifndef and #endif to do this
#ifdef humidity <= 0 || humidity > 100
	printf("Enter a humidity value between 0 and 100, except 0.");
#endif

	// provide answers to every combination of the current temp and humidity categories
	if (temp >= 35 && humidity >= 0 && humidity < 30)
		printf("%s and %s. You had better boot the air conditioner and increase humidity.\n", _HIGH_TEMP, _LOW_HUMIDITY);
	else if (temp >= 35 && humidity >= 30 && humidity <= 60)
		printf("%s but %s. Turn the air conditioner on and keep that humidity level stable.\n", _HIGH_TEMP, _IDEAL_HUMIDITY);
	else if (temp >= 35 && humidity > 60 && humidity <= 100)
		printf("%s and %s. Start using air conditioner for dehumidification and decreasing the temp.\n", _HIGH_TEMP, _HIGH_HUMIDITY);

	else if (temp >= 20 && temp < 35 &&humidity >= 0 && humidity < 30)
		printf("%s but %s.\n", _IDEAL_TEMP, _LOW_HUMIDITY);
	else if (temp >= 20 && temp < 35 && humidity >= 30 && humidity <= 60)
		printf("%s and %s. Enjoy!\n", _IDEAL_TEMP, _IDEAL_HUMIDITY);
	else if (temp >= 20 && temp < 35 && humidity > 60 && humidity <= 100)
		printf("%s but %s. Consider using a dehumidifier.\n", _IDEAL_TEMP, _HIGH_HUMIDITY);

	else if (temp >= 10 && temp < 20)
		printf("%s and %s. Wear something keeps you warm.\n", _LOW_TEMP, _LOW_HUMIDITY);
	else if (temp >= 10 && temp < 20 && humidity >= 30 && humidity <= 60)
		printf("%s but %s. Wear something made for such weathers.\n", _LOW_TEMP, _IDEAL_HUMIDITY);
	else if (temp >= 10 && temp < 20 && humidity > 60 && humidity <= 100)
		printf("%s and %s. You can use your air conditioner for both heat and dehumidification\n", _LOW_TEMP, _HIGH_HUMIDITY);

	else if (temp < 10)
		printf("%s and %s. Keep your home warm and moist!.\n", _FREEZING_TEMP, _LOW_HUMIDITY);
	else if (temp < 10 && humidity >= 30 && humidity <= 60)
		printf("%s but %s. Consider using a calorifer.\n", _FREEZING_TEMP, _IDEAL_HUMIDITY);
	else if (temp < 10 && humidity > 60 && humidity <= 100)
		printf("%s and %s. It is time to use an air conditioner to keep your home dry and warm.\n", _FREEZING_TEMP, _HIGH_HUMIDITY);

}