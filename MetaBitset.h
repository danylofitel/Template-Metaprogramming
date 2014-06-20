#ifndef _META_BITSET_H_
#define _META_BITSET_H_

template<unsigned char Byte>
struct MetaBitset
{
	enum
	{
		B0 = (Byte & 0x01) ? 1 : 0,
		B1 = (Byte & 0x02) ? 1 : 0,
		B2 = (Byte & 0x04) ? 1 : 0,
		B3 = (Byte & 0x08) ? 1 : 0,
		B4 = (Byte & 0x10) ? 1 : 0,
		B5 = (Byte & 0x20) ? 1 : 0,
		B6 = (Byte & 0x40) ? 1 : 0,
		B7 = (Byte & 0x80) ? 1 : 0
	};
	enum
	{
		SUM = B0 + B1 + B2 + B3 + B4 + B5 + B6 + B7
	};
};

#endif // _META_BITSET_H_