
#include <ZigZagPixels.h>

ZigZagPixels::ZigZagPixels(Adafruit_NeoPixel *pixels, uint8_t width, uint8_t height, layout_t layout = ZZP_LOWER_LEFT_ROWS) :
	initialized(false) {
		setPixels(pixels);
		setDimensions(width, height);
		setLayout(layout);
}

ZigZagPixels::ZigZagPixels(void) :
	pixels(NULL), initialized(false), upper(false), right(false), columns(false), width(0), height(0) {
}

ZigZagPixels::~ZigZagPixels() {
}

void ZigZagPixels::setPixels(Adafruit_NeoPixel *pixels) : pixels(pixels) {
	checkInitialization();
}

void ZigZagPixels::setDimensions(uint8_t width, uint8_t height) : width(width), height(height) {
	checkInitialization();
}

void ZigZagPixels::setLayout(uint8_t layout) {
	upper = (bool)(layout & (1 << ZZP_MESIAL_BIT));
	right = (bool)(layout & (1 << ZZP_LATERAL_BIT));
	columns = (bool)(layout & (1 << ZZP_ORIENTATION_BIT));
	checkInitialization();
}

Adafruit_NeoPixel *ZigZagPixels::getPixels() {
	return pixels;
}

uint8_t ZigZagPixels::getWidth() {
	return width;
}

uint8_t ZigZagPixels::getHeight() {
	return height;
}

uint8_t ZigZagPixels::getLayout() {
	return
		(upper << ZZP_MESIAL_BIT) |
		(right << ZZP_LATERAL_BIT) |
		(columns << ZZP_ORIENTATION_BIT);
}

bool ZigZagPixels::initialized() {
	return initialized;
}

void ZigZagPixels::checkInitialization() {
	initialized = false;

	if (pixels == NULL) return;
	if (width == 0) return;
	if (height == 0) return;
	if ((width * height) != pixels.numPixels()) return;

	initialized = true;
}

