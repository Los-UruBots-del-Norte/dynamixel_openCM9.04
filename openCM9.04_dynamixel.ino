#include <DynamixelWorkbench.h>

#if defined(__OPENCM904__)
  #define DEVICE_NAME "3" //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#elif defined(__OPENCR__)
  #define DEVICE_NAME ""
#endif   

#define BAUDRATE  1000000
#define DXL_ID     1
#define DXL_ID2    2
#define DXL_ID3    3
#define DXL_ID4    4

int id1 = DXL_ID, id2 = DXL_ID2, id3 = DXL_ID3, id4 = DXL_ID4;

DynamixelWorkbench dxl_wb;
  
  bool result = false;

  uint8_t dxl_id = DXL_ID;
  uint8_t dxl_id2 = DXL_ID2;
  uint8_t dxl_id3 = DXL_ID3;
  uint8_t dxl_id4 = DXL_ID4;
  uint16_t model_number = 0;

void setup() {
  delay(60000);
   const char *log;
  Serial.begin(9600);
  Serial.print("Serial OK");

  result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);
  if (result == false)
  {}
  else
  {}
  result = dxl_wb.ping(dxl_id, &model_number, &log);
  if (result == false)
  {}
  else
  {}
  result = dxl_wb.wheelMode(dxl_id, 0, &log);
  if (result == false)
  {}
  else
  {}
//--------------------------------------------------------------------------
  result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);
  if (result == false)
  {}
  else
  {}
  result = dxl_wb.ping(dxl_id2, &model_number, &log);
  if (result == false)
  {}
  else
  {}

  result = dxl_wb.wheelMode(dxl_id2, 0, &log);
  if (result == false)
  {}
  else
  {}
//--------------------------------------------------------------------------

  result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);
  if (result == false)
  {}
  else
  {}

  result = dxl_wb.ping(dxl_id3, &model_number, &log);
  if (result == false)
  {}
  else
  {}

  result = dxl_wb.wheelMode(dxl_id3, 0, &log);
  if (result == false)
  {}
  else
  {}
//----------------------------------------------
result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);
  if (result == false)
  {}
  else
  {}
  result = dxl_wb.ping(dxl_id4, &model_number, &log);
  if (result == false)
  {}
  else
  {}
  result = dxl_wb.wheelMode(dxl_id4, 0, &log);
  if (result == false)
  {}
  else
  {}
}
String inChar;
String inputString = "";  // variable para almacenar los datos entrantes
int pwm_id1=0,pwm_id2=0,pwm_id3=0,pwm_id4=0;
void loop() {
   if (Serial.available()>0) {
    inChar = Serial.readString(); // Leer un caracter del puerto serie
    inputString += inChar;             // Añadirlo a la cadena de entrada

    int commaIndex1 = inputString.indexOf(',');
    int commaIndex2 = inputString.indexOf(',', commaIndex1+1);
    int commaIndex3 = inputString.indexOf(',', commaIndex2+1);

    pwm_id1 = inputString.substring(0, commaIndex1).toInt();
    pwm_id2 = inputString.substring(commaIndex1+1, commaIndex2).toInt();
    pwm_id3 = inputString.substring(commaIndex2+1, commaIndex3).toInt();
    pwm_id4 = inputString.substring(commaIndex3+1, inputString.length()-1).toInt();

    dxl_wb.goalVelocity(id1, (int32_t)pwm_id1);
    dxl_wb.goalVelocity(id2, (int32_t)pwm_id2);
    dxl_wb.goalVelocity(id3, (int32_t)pwm_id3);
    dxl_wb.goalVelocity(id4, (int32_t)pwm_id4);

    inputString = "";  // Limpiar la cadena de entrada para la siguiente lectura
  }
}