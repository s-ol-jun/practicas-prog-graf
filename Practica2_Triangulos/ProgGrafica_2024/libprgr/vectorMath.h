#pragma once
#define M_PI 3.14159265358979323846
#include <iostream>

namespace libPRGR {
	typedef struct {
		union {
			struct {
				float x, y, z, w;
			};
			struct {
				float r, g, b, a;
			};
			float data[4];
		};
	} vector4f;

	typedef struct {
		union {
			float mat2D[4][4];
			float mat1[16];
			vector4f rows[4];
		};
	} matrix4x4f;

	inline float operator* (vector4f v1, vector4f v2) {
		float res = v1.x * v2.x + 
					v1.y * v2.y + 
					v1.z * v2.z + 
					v1.w * v2.w;
		return res;
	}

	inline vector4f operator* (matrix4x4f m1, vector4f v1) {
		vector4f res = { 0, 0, 0, 0 };

		for (int i = 0; i < 4; i++) {
			res.data[i] = m1.rows[i] * v1;
		}
		return res;
	}

	/*inline std::ostream operator<<(std::ostream& os, vector4f v1) {
		os << "{" << v1.data[0] << ", " << v1.data[1] << ", " << v1.data[2] << ", " << v1.data[3] << ", " << "}\n";
		return os;
	}*/

	inline float toRadians(float angle) {
		return angle * M_PI / (180.0);
	}

	inline matrix4x4f makeTranslate(float x, float y, float z) {
		matrix4x4f mat4x4 = {
		.rows = { { 1, 0, 0, x },
				  { 0, 1, 0, y },
				  { 0, 0, 1, z },
				  { 0, 0, 0, 1 }
		}
		};
		return mat4x4;
	}
}