# Documentación de la Librería Widgets

La librería `Widgets` está diseñada para proporcionar un conjunto de widgets versátiles y fáciles de usar para pantallas OLED utilizando la librería U8g2. Incluye medidores, barras de progreso, indicadores y funcionalidades de texto animado.

## Instalación
1. Descarga el archivo [Widgets.zip](sandbox:/mnt/data/Widgets.zip).
2. En el IDE de Arduino, ve a `Sketch` -> `Include Library` -> `Add .ZIP Library...`.
3. Selecciona el archivo `Widgets.zip` y agrégalo a tus librerías de Arduino.

## Funciones
- `Widgets(U8G2 &display)`: Constructor para inicializar la pantalla.
- `void drawGauge(int x, int y, int radius, int value, int maxValue)`: Dibuja un medidor circular.
- `void drawDonut(int x, int y, int radius, int thickness, int value, int maxValue)`: Dibuja un gráfico de dona.
- `void drawLevelIndicator(int x, int y, int width, int height, int value, int maxValue)`: Dibuja un indicador de nivel vertical.
- `void drawProgressBar(int x, int y, int width, int height, int value, int maxValue)`: Dibuja una barra de progreso horizontal.
- `void drawScrollingText(const char* text, int y, int speed, int width)`: Dibuja texto desplazable.
- `void drawBlinkingText(const char* text, int x, int y, bool visible)`: Dibuja texto parpadeante.
- `void drawResizingText(const char* text, int x, int y, int size)`: Dibuja texto con tamaño cambiante.
- `void drawLED(int x, int y, bool on)`: Dibuja un LED virtual.
- `void drawBattery(int x, int y, int level)`: Dibuja un indicador de batería.
- `void drawWiFiSignal(int x, int y, int strength)`: Dibuja un indicador de señal WiFi.
- `void drawSemiCircularGauge(int x, int y, int radius, int value, int maxValue)`: Dibuja un medidor semicircular.
- `void drawNeedleGauge(int x, int y, int radius, int value, int maxValue)`: Dibuja un medidor de aguja.

## Ejemplos

### Ejemplo 1: Widgets Básicos
```cpp
#include <U8g2lib.h>
#include "Widgets.h"

// Inicializa la pantalla
U8G2_SSD1309_128X64_NONAME0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
Widgets widgets(u8g2);

void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.clearBuffer();

  // Dibuja widgets básicos
  widgets.drawGauge(30, 30, 20, 75, 100);
  widgets.drawDonut(90, 30, 20, 5, 50, 100);
  widgets.drawLevelIndicator(10, 60, 20, 40, 25, 100);
  widgets.drawProgressBar(40, 60, 60, 10, 50, 100);

  u8g2.sendBuffer();
  delay(1000);  // Actualiza cada segundo
}
```

### Ejemplo 2: Texto Animado
```cpp
#include <U8g2lib.h>
#include "Widgets.h"

// Inicializa la pantalla
U8G2_SSD1309_128X64_NONAME0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
Widgets widgets(u8g2);
bool visible = true;
int size = 1;

void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.clearBuffer();

  // Dibuja texto animado
  widgets.drawScrollingText("Texto Desplazable", 10, 1, 128);
  widgets.drawBlinkingText("Texto Parpadeante", 40, 20, visible);
  visible = !visible;
  widgets.drawResizingText("Texto Cambiante", 20, 40, size);
  size = (size % 3) + 1;

  u8g2.sendBuffer();
  delay(500);  // Actualiza cada medio segundo
}
```

### Ejemplo 3: Indicadores
```cpp
#include <U8g2lib.h>
#include "Widgets.h"

// Inicializa la pantalla
U8G2_SSD1309_128X64_NONAME0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
Widgets widgets(u8g2);
bool ledOn = true;
int batteryLevel = 75;
int wifiStrength = 2;

void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.clearBuffer();

  // Dibuja indicadores
  widgets.drawLED(20, 50, ledOn);
  ledOn = !ledOn;
  widgets.drawBattery(40, 50, batteryLevel);
  widgets.drawWiFiSignal(70, 50, wifiStrength);
  widgets.drawSemiCircularGauge(30, 30, 20, batteryLevel, 100);
  widgets.drawNeedleGauge(90, 30, 20, wifiStrength, 100);

  u8g2.sendBuffer();
  delay(1000);  // Actualiza cada segundo
}
```


