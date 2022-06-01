#include <IRremote.h>
int RECV_PIN = 8;
int product1_flag = 0;
int product2_flag = 0;
int product3_flag = 0;
int product4_flag = 0;

int p1_count = 0;
int p2_count = 0;
int p3_count = 0;
int p4_count = 0;

int p1_price = 15;
int p2_price = 20;
int p3_price = 30;
int p4_price = 50;

int sum = 0;
int count = 0;


IRrecv irrecv(RECV_PIN);
decode_results results;

// include the library code:
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  lcd.begin(16, 2);
  lcd.print("T-Hawk solutions");
  lcd.setCursor(1, 1);
  lcd.print("SMART  TROLLEY");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(1, 0);
  lcd.print("SHOW YOUR ITEM");
  
  lcd.setCursor(3, 1);
  lcd.print("ON READER");
 
  delay(2000);
  lcd.clear();
  
}

void loop() {
  
  lcd.setCursor(0, 0);
  lcd.print("ITEM IN TROLLEY");
  
  lcd.setCursor(0, 1);
  lcd.print("BILL IS:");
  
  lcd.setCursor(8, 1);
  lcd.print(sum);
  
  lcd.setCursor(12, 1);
  lcd.print("I:");
  
  lcd.setCursor(14, 1);
  lcd.print(count);
  
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    
    if(results.value==0xFD08F7)
    {
      product1_flag = 1;
      lcd.clear();
    }
    
    if(results.value==0xFD8877)
    {
      product2_flag = 1;
      lcd.clear();
    }
    
    if(results.value==0xFD48B7)
    {
      product3_flag = 1;
      lcd.clear();
    }
    
    if(results.value==0xFD28D7)
    {
      product4_flag = 1;
      lcd.clear();
    }
    
    Serial.println(results.value);
    
  }
  delay(100);
    
    while(product1_flag == 1)
    {
     
    lcd.setCursor(0, 0);
      lcd.print("PRODUCT_1");
      lcd.setCursor(0, 1);
      lcd.print("PRICE:");
      
      sum = sum + p1_price;
      count = count + 1;
      
      lcd.setCursor(6, 1);
      lcd.print(p1_price);
      lcd.setCursor(8, 1);
      lcd.print("Rs");
      
      delay(1000);
      lcd.clear();
      product1_flag = 0;
    }
    
    while(product2_flag == 1)
    {
     
    lcd.setCursor(0, 0);
      lcd.print("PRODUCT_2");
      lcd.setCursor(0, 1);
      lcd.print("PRICE:");
      lcd.setCursor(7, 1);
      lcd.print(p2_count);
      
      sum = sum + p2_price;
      count = count + 1;
      
      lcd.setCursor(6, 1);
      lcd.print(p2_price);
      lcd.setCursor(8, 1);
      lcd.print("Rs");
      
      delay(1000);
      lcd.clear();
      product2_flag = 0;
      
    }
    
    while(product3_flag == 1)
    {
     
    lcd.setCursor(0, 0);
      lcd.print("PRODUCT_3");
      lcd.setCursor(0, 1);
      lcd.print("PRICE:");
      lcd.setCursor(7, 1);
      lcd.print(p3_count);
      
      sum = sum + p3_price;
      count = count + 1;
      
      lcd.setCursor(6, 1);
      lcd.print(p3_price);
      lcd.setCursor(8, 1);
      lcd.print("Rs");
      
      delay(1000);
      lcd.clear();
      product3_flag = 0;
   
    }
    
    while(product4_flag == 1)
    {
     
    lcd.setCursor(0, 0);
      lcd.print("PRODUCT_4");
      lcd.setCursor(0, 1);
      lcd.print("PRICE:");
      lcd.setCursor(7, 1);
      lcd.print(p4_count);
      
      sum = sum + p4_price;
      count = count + 1;
      
      lcd.setCursor(6, 1);
      lcd.print(p4_price);
      lcd.setCursor(8, 1);
      lcd.print("Rs");
      
      delay(1000);
      lcd.clear();
      product4_flag = 0;
      
    }
  
}
