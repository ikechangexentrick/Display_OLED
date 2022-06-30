#ifndef DISPLAY_OLED__H
#define DISPLAY_OLED__H

#include "ui_common.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>

#include "ArxTypeTraits.h"

static constexpr const char OLED_ADDRESS = 0x3C; //0x78;
static constexpr const size_t OLED_WIDTH = 128;
static constexpr const size_t OLED_HEIGHT = 64;

//  -----------------------------------------------


/*
 0123456789|123456789|
| show_status()       |
| ------------------  |
| show_menu()         |
| show_app_msg()      |
*/

class Display_OLED : public Display
{
public:
	const static size_t TMPLEN = 21;

	Display_OLED();

	void init();

	void show_menu(const char *title) override;

	template <typename... Args>
	void show_app_msg(const char *fmt, Args... args)
	{
		snprintf(app_msg_buf, TMPLEN, fmt, args...);
	}

	template <typename... Args>
	void show_status(const char *fmt, Args... args)
	{
		snprintf(status_buf, TMPLEN, fmt, args...);
	}

	void display(std::function<void()> drawing_function);

	void show_menu();
	void show_graph(const int *arr, size_t len, size_t start);

	void test(); 

	void print_column(size_t column, const char *buf);

	void draw_hline(size_t column); 
	void print_menu(size_t column);
	void print_app_msg(size_t column);

	static constexpr size_t TEXT_HEIGHT = 8;
	static constexpr size_t TEXT_WIDTH = 6;

private:
	char menu_buf[TMPLEN];
	char app_msg_buf[TMPLEN];
	char status_buf[TMPLEN];

	Adafruit_SSD1306 oled_display;
};

#endif // DISPLAY_OLED__H
