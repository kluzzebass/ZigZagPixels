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


enum layout_t {
	ZZP_LOWER_LEFT_ROWS		=	0b000,
	ZZP_LOWER_LEFT_COLUMNS	=	0b001,
	ZZP_LOWER_RIGHT_ROWS	=	0b010,
	ZZP_LOWER_RIGHT_COLUMNS	=	0b011,
	ZZP_UPPER_LEFT_ROWS		=	0b100,
	ZZP_UPPER_LEFT_COLUMNS	=	0b101,
	ZZP_UPPER_RIGHT_ROWS	=	0b110,
	ZZP_UPPER_RIGHT_COLUMNS	=	0b111
};

#define ZZP_MESIAL_BIT		2
#define ZZP_LATERAL_BIT		1
#define ZZP_ORIENTATION_BIT	0

class ZigZagPixels {
	public:
		ZigZagPixels(Adafruit_NeoPixel *pixels, uint8_t width, uint8_t height, layout_t layout = ZZP_LOWER_LEFT_ROWS);
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

		void setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);
		void setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
		void setPixelColor(uint8_t x, uint8_t y, uint32_t c);


		// These functions simply mirror the NeoPixel library functions
		void setBrightness(uint8_t brightness);
		uint8_t getBrightness();
		void clear();

	private:
		Adafruit_NeoPixel *_pixels;

		bool _initialized;
		bool _upper;
		bool _right;
		bool _columns;

		uint8_t _width;
		uint8_t _height;

		void checkInitialization();
		uint16_t calcPixelNum(uint8_t x, uint8_t y);
};


#endif /* __ZigZagPixels_h__ */
