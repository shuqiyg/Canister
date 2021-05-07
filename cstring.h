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
#ifndef _CSTRING_H_
#define _CSTRING_H_

namespace sdds {
	void strCpy(char* des, const char* src);

	void strnCpy(char* des, const char* src, int len);

	int strCmp(const char* s1, const char* s2);

	int strnCmp(const char* s1, const char* s2, int len);

	int strLen(const char* s);

	const char* strStr(const char* str1, const char* str2);

	void strCat(char* des, const char* src);
}
#endif


