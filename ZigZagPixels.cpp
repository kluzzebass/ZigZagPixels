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
) :	width(w), height(h), layout(l), origin(o), Adafruit_NeoPixel(w * h, p, t) {
}

ZigZagPixels::ZigZagPixels(void) :
	width(1), height(1),
	layout(ZigZagPixels::Layout::LowerLeftRows),
	origin(ZigZagPixels::Origin::LowerLeft),
	Adafruit_NeoPixel() {
}

void ZigZagPixels::setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b) {
	if (x >= width || y >= height) return;
	Adafruit_NeoPixel::setPixelColor(calcPixelNum(x, y), r, g, b);
}

void ZigZagPixels::setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
	if (x >= width || y >= height) return;
	Adafruit_NeoPixel::setPixelColor(calcPixelNum(x, y), r, g, b, w);
}

void ZigZagPixels::setPixelColor(uint8_t x, uint8_t y, uint32_t c) {
	if (x >= width || y >= height) return;
	Adafruit_NeoPixel::setPixelColor(calcPixelNum(x, y), c);
}

uint32_t ZigZagPixels::getPixelColor(uint8_t x, uint8_t y) {
	if (x >= width || y >= height) return 0;
	return Adafruit_NeoPixel::getPixelColor(calcPixelNum(x, y));	
}

void ZigZagPixels::debug() {
	Serial.print("Width:   ");
	Serial.println(width);
	Serial.print("Height:  ");
	Serial.println(height);
	Serial.print("Layout:  ");
	Serial.println(layout);
	Serial.print("Origin:  ");
	Serial.println(origin);
}

// Protected functions

// This is probably the most important function of the library.
uint16_t ZigZagPixels::calcPixelNum(uint8_t x, uint8_t y) {
	uint16_t n = 0;

	// Flip the coordinates around to match a LowerLeft origin;
	switch (origin) {
		default:
		case LowerLeft:
			break;
		case LowerRight:
			x = width - x - 1;
			break;
		case UpperLeft:
			y = height - y - 1;
			break;
		case UpperRight:
			x = width - x - 1;
			y = height - y - 1;
	}



	switch (layout) {
		default:
		case LowerLeftRows:
			n = width * y;
			n += (y & 1) ? width - x - 1 : x;
			break;
		case LowerLeftColumns:
			break;
		case LowerRightRows:
			break;
		case LowerRightColumns:
			x = width - x - 1;
			n = height * x;
			n += (x & 1) ? height - y - 1 : y;
			break;
		case UpperLeftRows:
			break;
		case UpperLeftColumns:
			y = height - y - 1;
			n = height * x;
			n += (x & 1) ? height - y - 1 : y;
			break;
		case UpperRightRows:
			x = width - x - 1;
			y = height - y - 1;
			n = width * y;
			n += (y & 1) ? width - x - 1 : x;
			break;
		case UpperRightColumns:
			break;
	}

	return n;
}