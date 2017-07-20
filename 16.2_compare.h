#pragma once
/* 16.2
     ±àĞ´²¢²âÊÔcompareº¯Êı
*/

#include<string>

template<typename T> int compare(const T &v1, const T &v2)
{
	if (std::less<T>()(v1, v2)) return -1;
	if (std::less<T>()(v2, v1)) return 1;
	return 0;
}

template<unsigned N, unsigned M>
int compare_str(const char(&s1)[N], const char(&s2)[M])
{
	return strcmp(s1, s2);
	
}