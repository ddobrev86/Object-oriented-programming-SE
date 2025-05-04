#pragma once
#include "Pixel.h"

enum class PictureFilter
{
	GREYSCALE,
	MONOCHROME,
	NEGATIVE,
	NORMAL
};

class Picture
{
	private:
		Pixel** canvas;
		size_t size;
		PictureFilter filter;

		void free();
		void copyFrom(const Picture& other);
		void moveFrom(Picture&& other);

	public:
		Picture(size_t size);
		Picture(size_t size, const Pixel** canvas, PictureFilter filter);
		Picture(const Picture& other);
		Picture& operator=(const Picture& other);
		Picture(Picture&& other) noexcept;
		Picture& operator=(Picture&& other) noexcept;
		~Picture();

		void changePixel(size_t xPos, size_t yPos, size_t r, size_t g, size_t b);

		void greyscale();
		void monochrome();
		void negative();

		friend std::ostream& operator<<(std::ostream& os, const Picture& obj);
};

