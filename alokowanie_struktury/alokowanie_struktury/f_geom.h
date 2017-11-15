#pragma once

#define TEST_ERROR(err) { if (error!=nullptr) *error = err; if (err != 77) return nullptr; }
#define TEST_ERROR_VALID(err) {if (error!=nullptr) *error = err; return false; }

enum class FIGURA
{
	kolo = 0,
	kwadrat,
	trojkat,
	odcinek
};

struct punkt_t {
	int x, y;
};

struct figura_t {
	FIGURA fig;
	punkt_t p[4];
	int R;
};
