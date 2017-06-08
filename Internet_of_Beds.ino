//include librairies
#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BLEBattery.h"
#include "HX711.h"

// define pin of the adafruit feather 34u2 BLE
#define VBATPIN           A9
#define BLUEFRUIT_SPI_CS  8
#define BLUEFRUIT_SPI_IRQ 7
#define BLUEFRUIT_SPI_RST 4 
#define HX_DOUT           2
#define HX_SCK            3

/* ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST */
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);
//declare battery service
Adafruit_BLEBattery battery(ble);
//declare the Hx711 adc
HX711 scale(HX_DOUT, HX_SCK);

//declare variable use in the sketch
int32_t IoBServiceId;
int32_t IoBMeasureCharId;
int bat;
long adc_value;

//at every startup, the nRF51822 is reset and 2 GATT services are created :
// IoB that published the adc value (24 bits)
// battery that published the battery level (0-100%)
void setup(void)
{
  //Start and reset the nRF51822
  ble.begin(false);// if true=>verbose mode
  ble.factoryReset() ;
  ble.echo(false);
  ble.sendCommandCheckOK(F("AT+GAPDEVNAME=Internet of Beds"));

  //Add special service id 4242
  ble.sendCommandWithIntReply( F("AT+GATTADDSERVICE=UUID=0x4242"), &IoBServiceId);
  ble.sendCommandWithIntReply( F("AT+GATTADDCHAR=UUID=0x1010, PROPERTIES=0x10, MIN_LEN=1, MAX_LEN=4, VALUE=69"), &IoBMeasureCharId);
   
  ble.reset();
  
  battery.begin(true);

}

void loop(void)
{
  scale.power_up();  //turn on the adc
  
  adc_value = scale.read(); // read the value from hx711  
  if (adc_value<0){
    adc_value=0; // make the value positive and ignore negatives values
  }
  
  /* Command is sent when \n (\r) or println is called */
  /* AT+GATTCHAR=CharacteristicID,value */
  ble.print( F("AT+GATTCHAR=") );
  ble.print( IoBMeasureCharId );
  ble.print( F(",") );
  ble.println(adc_value);
  
 
  bat = map(analogRead(VBATPIN),512,658,0,100);  //read and convert battery voltage
  battery.update(bat); //send battery level

  scale.power_down(); // turn off the adc

  delay(1000);
}
