/*
 *	This file is part of the ZigZagPixels library.
 *
 *	The ZigZagPixels library is licensed under the
 *	MIT license. See the LICENSE file for details.
 *
 */

#ifndef __ZigZagPixels_h__
# define __ZigZagPixels_h__

#include <Adafruit_NeoPixel.h>

// The default is rows, starting in the lower left corner, so there's no need
// to define these as anything but 0.
#define ZZP_ROWS 0b000
#define ZZP_LEFT 0b000
#define ZZP_BOTTOM 0b000

#define ZZP_COLUMNS 0b001
#define ZZP_RIGHT 0b010
#define ZZP_TOP 0b100

enum layout_t {
	ZZP_LOWER_LEFT_ROWS		=	0b000,
	ZZP_LOWER_LEFT_COLUMNS	=	0b001,
	ZZP_LOWER_RIGHT_ROWS	=	0b010,
	ZZP_LOWER_RIGHT_COLUMNS	=	0b011,
	ZZP_UPPER_LEFT_ROWS		=	0b100,
	ZZP_UPPER_LEFT_COLUMNS	=	0b101,
	ZZP_UPPER_RIGHT_ROWS	=	0b110,
	ZZP_UPPER_RIGHT_COLUMNS	=	0b111
}



class ZigZagPixels {
	public:
		ZigZagPixels(Adafruit_NeoPixel *pixels, uint8_t width, uint8_t height, uint8_t layout = 0);
		ZigZagPixels(void);
		~ZigZagPixels();

		void setPixels(Adafruit_NeoPixel *pixels);
		void setDimensions(uint8_t width, uint8_t height);
		void setLayout(uint8_t layout);

		Adafruit_NeoPixel *getPixels();
		uint8_t getWidth();
		uint8_t getHeight();
		uint8_t getLayout();
	
		bool initialized();


	private:
		Adafruit_NeoPixel *pixels;

		bool initialized;
		bool upper;
		bool right;
		bool columns;

		uint8_t width;
		uint8_t height;

		void checkInitialization();
}


#endif /* __ZigZagPixels_h__ */
