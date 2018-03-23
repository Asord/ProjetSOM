#pragma once
typedef unsigned char uchar; // 1 octet
typedef unsigned short ushort; // 2 octet
typedef unsigned int uint; // 4 octet
typedef unsigned long ulong; // 8 octet

#define DYN_FREE(dynamic_obj) if(dynamic_obj != nullptr) { delete dynamic_obj; dynamic_obj = nullptr; }
#define DYN_FREE_A(dynamic_lst) if(dynamic_lst != nullptr) { delete[] dynamic_lst; dynamic_lst = nullptr; }
