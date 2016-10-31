/*
 *	This file is part of the ZigZagPixels library.
 *
 *	The ZigZagPixels library is licensed under the
 *	MIT license. See the LICENSE file for details.
 *
 */
#include <ZigZagPixels.h>

ZigZagPixels::ZigZagPixels(
	uint8_t w, uint8_t h,
	ZigZagPixels::Layout l = ZigZagPixels::Layout::LowerLeftRows,
	ZigZagPixels::Origin o = ZigZagPixels::Origin::LowerLeft,
	uint8_t p = 6, neoPixelType t = NEO_GRB + NEO_KHZ800
) :	width(w), height(h),layout(l), Adafruit_NeoPixel(w * h, p, t) {
}

ZigZagPixels::ZigZagPixels(void) :
	width(1), height(1),
	layout(ZigZagPixels::Layout::LowerLeftRows),
	origin(ZigZagPixels::Origin::LowerLeft),
	Adafruit_NeoPixel() {
}

void ZigZagPixels::setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b) {
	Adafruit_NeoPixel::setPixelColor(calcPixelNum(x, y), r, g, b);
}

void ZigZagPixels::setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
	Adafruit_NeoPixel::setPixelColor(calcPixelNum(x, y), r, g, b, w);
}

void ZigZagPixels::setPixelColor(uint8_t x, uint8_t y, uint32_t c) {
	Adafruit_NeoPixel::setPixelColor(calcPixelNum(x, y), c);
}

uint32_t ZigZagPixels::getPixelColor(uint8_t x, uint8_t y) {
	return Adafruit_NeoPixel::getPixelColor(calcPixelNum(x, y));	
}


// Protected functions

// This is probably the most important function of the library.
uint16_t ZigZagPixels::calcPixelNum(uint8_t x, uint8_t y) {
	switch (layout) {
		case LowerLeftRows:
			break;
		case LowerLeftColumns:
			break;
		case LowerRightRows:
			break;
		case LowerRightColumns:
			break;
		case UpperLeftRows:
			break;
		case UpperLeftColumns:
			break;
		case UpperRightRows:
			break;
		case UpperRightColumns:
		default:
			break;
	}
	return 0;
}