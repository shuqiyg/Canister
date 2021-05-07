/* W04 DIY
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 02-11-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#include "cstring.h"

namespace sdds {
	void strCpy(char* des, const char* src) {
		int index = 0;
		while (src[index] != '\0') {
			des[index] = src[index];
			index++;
		}
		des[index] = '\0';
	}
	void strnCpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; i < len + 1; i++) {
			if ((i == len) && src[len] != '\0') {
				des[len] = '\0';
				break;
			}
			des[i] = src[i];
			if (des[i] == '\0') {
				break;
			}
		}
	}
	int strCmp(const char* s1, const char* s2) {
		int index = 0;
		while (s1[index] != '\0' || s2[index] != '\0') {
			if (s1[index] > s2[index]) return 1;
			if (s1[index] < s2[index]) return -1;
			index++;
		}
		return 0;
	}
	int strnCmp(const char* s1, const char* s2, int len) {
		int i;
		for (i = 0; i < len; i++) {
			if (s1[i] > s2[i]) return 1;
			if (s1[i] < s2[i]) return -1;
		}
		return 0;
	}
	int strLen(const char* s) {
		int i, count = 0;
		for (i = 0; s[i] != '\0'; i++) {
			count++;
		}
		return count;
	}
	const char* strStr(const char* str1, const char* str2) {
		int len_1 = strLen(str1);
		int len_2 = strLen(str2);
		int shift_len_2 = len_2;
		int i, j = 0, k = 0;
		while (shift_len_2 <= len_1) {
			int count = 0;
			for (i = 0; i < len_2; i++, j++) {
				if (str1[j] == str2[i]) {
					count++;
				}
			}
			if (count == len_2) {
				return &str1[k];
			}
			j = ++k, shift_len_2++;
		}
		char* nomatch = nullptr;
		return nomatch;
	}
	void strCat(char* des, const char* src) {
		int len_src = strLen(src);
		int len_des = strLen(des);
		int i;
		for (i = 0; i <= len_src; i++) {
			des[len_des] = src[i];
			if (src[i] == '\0') break;
			len_des++;
		}
	}
}