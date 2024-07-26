//Global variables
bool flag = true;
char character = 'a';
unsigned char character2 = 128; //(0-255)
byte value = 200; //0 - 255
int number = 12421; //-32768 - 32767
unsigned int number2 = 40000; //0 - 65535
long aValue = 123456789; // -2_147_483_648 - 2_147_483_647
unsigned long aValue2 = 4000000000; //0 - 4294967295.
float decimal = 3.1461; //-3.4028235E+38 - 3.4028235E+38  Precision 6 digitos (mejor opción que Double)
double decimal2 = 1.566213213;
String message = "Hello World!"; 


void setup() {
  Serial.begin(9600);

  Serial.println("Flag: " + String(flag));
  Serial.println("Character: " + String(character));
  Serial.println("Character 2: " + String(character2));
  Serial.println("Byte: " + String(value));
  Serial.println("Int: " + String(number));
  Serial.println("Unsigned Int: " + String(number2));
  Serial.println("Long: " + String(aValue));
  Serial.println("Unsigned Long: " + String(aValue2));
  Serial.println("String: " + message);

  //Redondeo por defecto en 2 decimales
  Serial.println("Float: " + String(decimal));
  Serial.println("Double: " + String(decimal2));

  //Mostrar mas decimales
  const int QUANTITY_DECIMALS_FLOAT = 5;
  const int QUANTITY_DECIMALS_DOUBLE = 6;
  Serial.println("Float with more decimals: " + String(decimal, QUANTITY_DECIMALS_FLOAT));
  Serial.println("Double with more decimals: " + String(decimal2, QUANTITY_DECIMALS_DOUBLE));
}

// put your main code here, to run repeatedly:
void loop() {
  String text = "Arduino!!";
  Serial.println(text);

  for (int i = 1; i <= 10; i++){
    Serial.println(i);
    delay(500); //0.5 segundo, es decir, medio segundo
  }

  delay(2000); // Espera 2 segundos antes de repetir todo
}
