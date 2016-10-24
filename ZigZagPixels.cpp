/*
 *	This file is part of the ZigZagPixels library.
 *
 *	The ZigZagPixels library is licensed under the
 *	MIT license. See the LICENSE file for details.
 *
 */

#include <ZigZagPixels.h>

ZigZagPixels::ZigZagPixels(Adafruit_NeoPixel *pixels, uint8_t width, uint8_t height, layout_t layout) :
	_initialized(false) {
		setPixels(pixels);
		setDimensions(width, height);
		setLayout(layout);
}

ZigZagPixels::ZigZagPixels(void) :
	_pixels(NULL), _initialized(false), _upper(false), _right(false), _columns(false), _width(0), _height(0) {
}

ZigZagPixels::~ZigZagPixels() {
}

void ZigZagPixels::setPixels(Adafruit_NeoPixel *pixels) {
	_pixels = pixels;
	checkInitialization();
}

void ZigZagPixels::setDimensions(uint8_t width, uint8_t height) {
	_width = width;
	_height = height;
	checkInitialization();
}

void ZigZagPixels::setLayout(uint8_t layout) {
	_upper = (bool)(layout & (1 << ZZP_MESIAL_BIT));
	_right = (bool)(layout & (1 << ZZP_LATERAL_BIT));
	_columns = (bool)(layout & (1 << ZZP_ORIENTATION_BIT));
	checkInitialization();
}

Adafruit_NeoPixel *ZigZagPixels::getPixels() {
	return _pixels;
}

uint8_t ZigZagPixels::getWidth() {
	return _width;
}

uint8_t ZigZagPixels::getHeight() {
	return _height;
}

uint8_t ZigZagPixels::getLayout() {
	return
		(_upper << ZZP_MESIAL_BIT) |
		(_right << ZZP_LATERAL_BIT) |
		(_columns << ZZP_ORIENTATION_BIT);
}

bool ZigZagPixels::initialized() {
	return _initialized;
}


void ZigZagPixels::setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b) {
	if (_initialized) return;
	_pixels->setPixelColor(calcPixelNum(x, y), r, g, b);
}

void ZigZagPixels::setPixelColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
	if (_initialized) return;
	_pixels->setPixelColor(calcPixelNum(x, y), r, g, b, w);
}

void ZigZagPixels::setPixelColor(uint8_t x, uint8_t y, uint32_t c) {
	if (_initialized) return;
	_pixels->setPixelColor(calcPixelNum(x, y), c);
}



// These functions simply mirror the NeoPixel library functions
void ZigZagPixels::setBrightness(uint8_t brightness) {
	if (_initialized) return;
	_pixels->setBrightness(brightness);
}

uint8_t ZigZagPixels::getBrightness() {
	if (_initialized) return 255;
	return _pixels->getBrightness();
}

void ZigZagPixels::clear() {
	if (_initialized) return;
	_pixels->clear();
}

// Private functions

void ZigZagPixels::checkInitialization() {
	_initialized = false;

	if (_pixels == NULL) return;
	if (_width == 0) return;
	if (_height == 0) return;
	if ((_width * _height) != _pixels->numPixels()) return;

	_initialized = true;
}

uint16_t ZigZagPixels::calcPixelNum(uint8_t x, uint8_t y) {
	return 0;
}