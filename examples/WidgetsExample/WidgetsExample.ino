#include <U8g2lib.h>
#include "Widgets.h"

// Configura la pantalla para I2C
U8G2_SSD1309_128X64_NONAME0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
Widgets widgets(u8g2);

void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.clearBuffer();

  // Dibuja un medidor
  widgets.drawGauge(30, 30, 20, 75, 100);

  // Dibuja un gráfico de donut
  widgets.drawDonut(90, 30, 20, 5, 50, 100);

  // Dibuja un indicador de nivel
  widgets.drawLevelIndicator(10, 60, 20, 40, 25, 100);

  u8g2.sendBuffer();
  
  delay(1000);  // Espera un segundo antes de actualizar la pantalla
}
