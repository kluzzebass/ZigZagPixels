/*
 *	This file is part of the ZigZagPixels library.
 *
 *	The ZigZagPixels library is licensed under the
 *	MIT license. See the LICENSE file for details.
 *
 */

#ifndef __ZigZagPixels_h__
# define __ZigZagPixels_h__

#ifdef __AVR__
  #include <avr/power.h>
#endif

#include <Adafruit_NeoPixel.h>

#define ZZP_MESIAL_BIT		2
#define ZZP_LATERAL_BIT		1
#define ZZP_ORIENTATION_BIT	0

class ZigZagPixels : public Adafruit_NeoPixel {
	public:
		enum Layout {
			LowerLeftRows		=	0b000,
			LowerLeftColumns	=	0b001,
			LowerRightRows		=	0b010,
			LowerRightColumns	=	0b011,
			UpperLeftRows		=	0b100,
			UpperLeftColumns	=	0b101,
			UpperRightRows		=	0b110,
			UpperRightColumns	=	0b111
		};

		enum Origin {
			LowerLeft			=	0b00,
			LowerRight			=	0b01,
			UpperLeft			=	0b10,
			UpperRight			=	0b11
		};

		ZigZagPixels(uint8_t w, uint8_t h, ZigZagPixels::Layout l, ZigZagPixels::Origin o, uint8_t p, neoPixelType t);
		ZigZagPixels(void);

		void setWidth(uint8_t w) { width = w; };
		void setHeight(uint8_t h) { height = h; };
		void setLayout(Layout l) { layout = l; };
		void setLayout(Origin o) { origin = o; };

		uint8_t getWidth() { return width; };
		uint8_t getHeight() { return height; };
		Layout getLayout() { return layout; };
		Origin getOrigin() { return origin; };

		void setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);
		void setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
		void setPixelColor(uint8_t x, uint8_t y, uint32_t c);

		uint32_t getPixelColor(uint8_t x, uint8_t y);

		void debug();

	protected:
		uint8_t width;
		uint8_t height;
		ZigZagPixels::Layout layout;
		ZigZagPixels::Origin origin;

		uint16_t calcPixelNum(uint8_t x, uint8_t y);
};


#endif /* __ZigZagPixels_h__ */
