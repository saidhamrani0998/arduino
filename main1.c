// bare metal programming of a seven segment display LED,  Everything seems to work just fine except for some digits, I'll look into it later.
// The problem is between digital pin 11 and 12, they get mixed up for no reason, I don't know if it's a software problem or the cables that are not well wired.

void displayDigit(uint8_t digit);

int main(void) {
  DDRD |= B11001100; 
  DDRB |= B00000111; 

  while(1) {
    for(int i = 0; i < 10; i++) {
      displayDigit(i);
      _delay_ms(1000);
    }
  }
}

void displayDigit(uint8_t digit) {
  switch(digit) {
    case 0:
      PORTD = B11000100;
      PORTB = B00000111;
      break;
    case 1:
      PORTD = B10000000;
      PORTB = B00000001;
      break;
    case 2:
      PORTD = B11001000; // Adjusted bits 2 and 3
      PORTB = B00000110;
      break;
    case 3:
      PORTD = B11001000; // Adjusted bits 2 and 3
      PORTB = B00000011;
      break;
    case 4:
      PORTD = B10001100;
      PORTB = B00000001;
      break;
    case 5:
      PORTD = B01001100;
      PORTB = B00000011;
      break;
    case 6:
      PORTD = B01001100;
      PORTB = B00000111;
      break;
    case 7:
      PORTD = B11000000;
      PORTB = B00000001;
      break;
    case 8:
      PORTD = B11001100;
      PORTB = B00000111;
      break;
    case 9:
      PORTD = B11001100;
      PORTB = B00000011;
      break;
  }
}
