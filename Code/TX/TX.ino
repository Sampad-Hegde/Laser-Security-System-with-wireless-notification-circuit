#include <SPI.h>
#include <RH_NRF24.h>

// Pin Numbers:
int ce_pin = 7;
int csn_pin = 8;

int ldr_pin = A1;



RH_NRF24 nrf24(ce_pin, csn_pin);


// Data packet
struct Data
{
  unsigned int intensity;
  int sig; 
};

Data d;


void setup() 
{
  Serial.begin(9600);
  
  if (!nrf24.init())
  {
    Serial.println("init failed");
  }
    
    
  if (!nrf24.setChannel(1))
  {
    Serial.println("setChannel failed");
  }
    
  
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
  {
    Serial.println("setRF failed"); 
  }
}


void loop()
{
  d.intensity = analogRead(ldr_pin);
  
  if (d.intensity > 880)
  {
    d.sig = 0;
  }
  else
  {
    d.sig = 1;
  }
  
  nrf24.send((uint8_t*)&d, sizeof(Data));
  //h1 Serial.println(d.intensity);

  delay(200);
}
