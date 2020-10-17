#pragma once

#include <inttypes.h>

typedef uint8_t  rb_angle8;
typedef uint16_t rb_angle16;
typedef uint32_t rb_angle32;

typedef rb_angle8  rb_uq0_8;
typedef rb_angle16 rb_uq0_16;
typedef rb_angle32 rb_uq0_32;

typedef int8_t  rb_q1_7;
typedef int16_t rb_q1_15;
typedef int32_t rb_q1_31;

// This is a LUT routine, but it demonstrates coalescion pretty well.
rb_q1_7 rb_sin8_lut( rb_angle8 x, rb_q1_7 * lut )
{
	_Bool negative = 0;
	if ( x > 0x7F )
	{
		negative = 1;
		x &= 0x7F;
	}
	if ( x > 0x3F ) x = 0x7F - x;

	return negative ? -lut[ x ]: lut[ x ];
}




