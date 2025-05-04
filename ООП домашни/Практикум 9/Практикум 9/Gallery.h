#pragma once
#include "Picture.h"

class Gallery
{
private:
	static const size_t INITITAL_CAPACITY;

	Picture** pictures;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const Gallery& other);
	void moveFrom(Gallery&& other);

	void resize(size_t newCap);

public:
	Gallery();
	Gallery(const Gallery& other);
	Gallery& operator=(const Gallery& other);
	Gallery(Gallery&& other) noexcept;
	Gallery& operator=(Gallery&& other) noexcept;
	~Gallery();

	void addPicture(Picture* pic);
	void addPicture(Picture& pic);

	void removeAt(size_t index);
	void filterPictureAt(size_t index, PictureFilter filter);
	void filterAll(PictureFilter filter);

	const Picture& operator[](size_t index) const;
	Picture& operator[](size_t index);

	friend std::ostream& operator<<(std::ostream& os, const Gallery& obj);
};

