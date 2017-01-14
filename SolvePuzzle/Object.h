#pragma once

class Object
{
public:
	Object();
	Object(int width, int height);
	~Object();

protected:
	virtual void clear()
	{
		memset(bytes, '0', sizeof(bytes));
	}

	void put(const char* shape)
	{
		size_t len = strlen(shape);
		if (len > sizeof(bytes)) {
			std::cerr << "too big shape." << std::endl;
			exit(1);
		}
		if (len != width * height) {
			std::cerr << "invalid shape." << std::endl;
			exit(1);
		}

		strcpy_s(bytes, shape);
	}

	virtual void rotate(Object& dst) const;

public:
	inline char at(int x, int y) const { return bytes[y * width + x]; }
	inline char& at(int x, int y) { return bytes[y * width + x]; }

	inline int get_width() const { return width; }
	inline int get_height() const { return height; }

	void print() const;

private:
	int width;
	int height;

	char bytes[128];
};

