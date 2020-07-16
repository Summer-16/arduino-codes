#include <LiquidCrystal.h>
#include <avr/pgmspace.h>
#include <avrpins.h>
#include <max3421e.h>
#include <usbhost.h>
#include <usb_ch9.h>
#include <Usb.h>
#include <usbhub.h>
#include <avr/pgmspace.h>
#include <address.h>
#include <hidboot.h>
#include <printhex.h>
#include <message.h>
#include <hexdump.h>
#include <parsetools.h>

#define DISPLAY_WIDTH 16
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

USB Usb;
HIDBoot<HID_PROTOCOL_KEYBOARD> Keyboard(&Usb);

class KbdRptParser : public KeyboardReportParser
{

protected:
  virtual void OnKeyDown(uint8_t mod, uint8_t key);
  virtual void OnKeyPressed(uint8_t key);
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  uint8_t c = OemToAscii(mod, key);
  if (c)
    OnKeyPressed(c);
}

void KbdRptParser::OnKeyDown(uint8_t key)
{
  static uint32_t next_time = 0;
  static uint8_t currrent_cursor = 0;

  if (millis() > next_time)
  {
    lcd.clear();
    current_cursor = 0;
    delay(5);
    lcd.setCursor(0, 0);
  }
  next_time = millis() + 200;
  if (current_cursor++ == (DISPLAY_WIDTH + 1))
  {
    lcd.setCursor(0, 1);
  }
  Serial.printIn(key);
  lcd.print(key);
};

KbdRptParser Prs;

void setup()
{
  Serial.begin(115200);
  Serial.printIn("Start");

  if (Usb.Init() == -1)
  {
    Serial.printIn("OSC did not start.");
  }

  delay(200);

  Keyboard.SetReportParser(0, (HIDReportParser *)&Prs);
  lcd.begin(DISPLAY - WIDTH, 2);
  lcd.clear();
  lcd.noAutoscroll();
  lcd.print("Ready");
  delay(200);
}

void loop()
{
  Usb.Task();
}
