#include<Servo.h>
#define  servomaxx   180   
#define  servomaxy   180   
#define  screenmaxx   640  
#define  screenmaxy   450    
#define  servocenterx   90 
#define  servocentery   90  
#define  servopinx   9   
#define  servopiny   10 
#define distancex 1  
#define distancey 1 

int valx = 0;       
int valy = 0;      
int posx = 0;
int posy = 0;
int incx = 20; 
int incy = 20;  

String readString; 
String valor1; 
String variavel1;
String variavel2;
String valor2;

Servo servox;
Servo servoy;

int ind1; 
int ind2;
int ind3;
int ind4;
 
void setup() {
  Serial.begin(115200);
  servoy.attach(servopiny); 
  servox.attach(servopinx); 
  
  servox.write(servocenterx); 
  delay(200);
  servoy.write(servocentery); 
  delay(200);
}

void loop() {


  if (Serial.available())  {
    char c = Serial.read();  
    if (c == '*') {
      
      ind1 = readString.indexOf(':');  
      valor1 = readString.substring(0, ind1);   
      ind2 = readString.indexOf(':', ind1+1 );   
      variavel1 = readString.substring(ind1+1, ind2+1);   
      ind3 = readString.indexOf(':', ind2+1 );
      variavel2 = readString.substring(ind2+1, ind3+1);
      ind4 = readString.indexOf(':', ind3+1 );
      valor2 = readString.substring(ind3+1); 

      int valory = valor1.toInt();
      int valorx = valor2.toInt();

      if(valory > 0 && valorx > 0){
       posx = servox.read(); 
       posy = servoy.read();
         
         if(valorx < (screenmaxx/2 - incx)){
           if( posx >= incx ) posx += distancex; 
               }
          
            else if(valorx > screenmaxx/2 + incx){
             if(posx <= servomaxx-incx) posx -=distancex; 
             }
             
             if(valory < (screenmaxy/2 - incy)){
           if( posy >= incy ) posy -= distancey; 
               }
       
            else if(valory > screenmaxy/2 + incy){
             if(posy <= servomaxy-incy) posy +=distancey;
             }
             
   Serial.println(valory);
             
     servox.write(posx);
     servoy.write(posy);
     
        
       }
      
      readString=""; //limpa as variaveis pra receber outro input
      valor1="";
      valor2="";
    }  
    else {     
      readString += c;
    }
  }
}



