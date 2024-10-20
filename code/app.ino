#include <LiquidCrystal.h>

// LCD EKRAN PİN AYARLAMALARI
LiquidCrystal ekran(12, 11, 5, 4, 3, 2);

void setup()
{
    // PROGRAM YÜKLENDİGİNDE GİRİŞ ÇIKIŞ AYARLAMALAR
  ekran.begin(16, 2); 
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);
}

void loop()
{
    // MESAFE VE SÜREYE GÖRE EKRAN KONTROLÜ
 	int sure=pulseIn(7,1);
  	int mesafe=(sure/2)/28.97;
  	digitalWrite(7,1); 
    delay(1);
	digitalWrite(7,0);
  	
  if(mesafe<50){
    ekran.clear();
  	ekran.setCursor(0,0);
    ekran.print("DIKKAT EDIN");
  }
  
  if(mesafe>50){
  	ekran.clear();
  	ekran.setCursor(0,1);
    ekran.print("MESAFENIZ :");
    ekran.print(mesafe);
    ekran.setCursor(5,1);
  }
                
}