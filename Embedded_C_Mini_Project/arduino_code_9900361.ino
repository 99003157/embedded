#include<SPI.h>

volatile boolean info;
volatile int Slave_data;


void setup()

{
  Serial.begin(9600);
 
pinMode(MISO, OUTPUT);

  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  info = false;

  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
  }

ISR (SPI_STC_vect)                        //Inerrrput routine function
{
  Slave_data = SPDR;         // Value received from master 
  info = true;                        //Sets received as True 
   
}

void loop()
{ if(info)                            
  {
 delay(500);
 Serial.println(Slave_data);
      if(Slave_data==0)
      {
       
               Serial.println("Please maintain social distancing \n");
      }
      else if(Slave_data==1)
        {
               Serial.println("Way clear\n");
        }
      else
      {
               Serial.println("Sensor value is less than 500\n");
                   
      }
}
}
