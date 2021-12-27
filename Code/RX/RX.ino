#include <SPI.h>
#include <RH_NRF24.h>

// Pin Numbers:
int ce_pin = 7;
int csn_pin = 8;

int indicator_pin = 2;
int button = 3;

volatile byte notification_state = LOW;


RH_NRF24 nrf24(7,8);



struct Data
{
  unsigned int intensity;
  int sig; 
};

Data d;


void notified()
{
  notification_state = LOW;
}


void setup() 
{
  Serial.begin(9600);

  pinMode(indicator_pin, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(button), notified, FALLING);
  
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
  if (nrf24.available())
  {
    uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (nrf24.recv(buf, &len))
    {
      memcpy( &d, buf, sizeof( Data ) );
      
    }

    if(d.sig == 1)
    {
      notification_state = HIGH;
    }

    Serial.print("INTENSITY : ");
    Serial.print(d.intensity);
    Serial.print(" SIGNAL: ");
    Serial.println(d.sig);
  }

  if (notification_state == HIGH)
  {
    digitalWrite(indicator_pin,HIGH);
    delay(500);
    digitalWrite(indicator_pin,LOW);
    delay(200);
  }
}
