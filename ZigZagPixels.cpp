/*
 *	This file is part of the ZigZagPixels library.
 *
 *	The ZigZagPixels library is licensed under the
 *	MIT license. See the LICENSE file for details.
 *
 */
#include <ZigZagPixels.h>

ZigZagPixels::ZigZagPixels(uint8_t w, uint8_t h, ZigZagPixels::Layout l = ZigZagPixels::Layout::LowerLeftRows, uint8_t p = 6, neoPixelType t = NEO_GRB + NEO_KHZ800) :
	width(w),
	height(h),
	layout(l),
	Adafruit_NeoPixel(w * h, p, t) {
}

ZigZagPixels::ZigZagPixels(void) :
	width(1),
	height(1),
	layout(ZigZagPixels::Layout::LowerLeftRows),
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


// Private functions

// This is probably the most important function of the library.
uint16_t ZigZagPixels::calcPixelNum(uint8_t x, uint8_t y) {
	return 0;
}