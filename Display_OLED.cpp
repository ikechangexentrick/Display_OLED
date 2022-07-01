#include "Display_OLED.h"

Display_OLED::Display_OLED()
	: oled_display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1)
{
	memset(menu_buf, 0x0, TMPLEN);
	memset(app_msg_buf, 0x0, TMPLEN);
	memset(status_buf, 0x0, TMPLEN);
}

void Display_OLED::init()
{
	// begin() should be called in setup()
	oled_display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
	oled_display.clearDisplay();
	oled_display.setTextColor(WHITE);
	oled_display.setTextSize(1);
}

void Display_OLED::show_menu(const char *title)
{
	snprintf(menu_buf, TMPLEN, "%s", title);
}

void Display_OLED::display(std::function<void()> f)
{
	oled_display.clearDisplay();
	f();
	oled_display.display();
}

void Display_OLED::show_menu()
{
	oled_display.setCursor(0, 0);
	oled_display.print(status_buf);

	oled_display.drawFastHLine(1, TEXT_HEIGHT+TEXT_HEIGHT/2, 120, WHITE);

	oled_display.setCursor(0, 0+TEXT_HEIGHT*2);
	oled_display.setTextSize(1);
	oled_display.print(menu_buf);

	oled_display.setCursor(0, 0+TEXT_HEIGHT*3);
	oled_display.setTextSize(1);
	oled_display.print(app_msg_buf);
}

void Display_OLED::print_column(size_t column, const char *buf)
{
	oled_display.setCursor(0, column);
	oled_display.setTextSize(1);
	oled_display.print(buf);
}

void Display_OLED::draw_hline(size_t column) {
	oled_display.drawFastHLine(1, column, 120, WHITE);
}

void Display_OLED::draw_hbar(int x, int y, int w)
{
	oled_display.drawFastHLine(x, y, w, WHITE);
}

void Display_OLED::print_menu(size_t column)
{
	oled_display.setCursor(0, column);
	oled_display.setTextSize(1);
	oled_display.print(menu_buf);
}

void Display_OLED::print_app_msg(size_t column)
{
	oled_display.setCursor(0, column);
	oled_display.setTextSize(1);
	oled_display.print(app_msg_buf);
}

void Display_OLED::test()
{
	oled_display.clearDisplay();
	oled_display.setTextColor(WHITE);
	oled_display.setCursor(0, 0);
	oled_display.setTextSize(1);
	//oled_display.cp437(true);
  	for(int16_t i=0; i<256; i++) {
    	if(i == '\n') oled_display.write(' ');
    	else          oled_display.write(i);
  	}
	oled_display.display();
}
