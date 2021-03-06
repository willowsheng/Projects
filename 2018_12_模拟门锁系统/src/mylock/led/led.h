//#define DEBUG


#define LED_SPEED 10

#ifdef DEBUG
/*
标准5x7的字母点阵
从ascii 30 0x20 的空格开始 
*/
const unsigned char code_Fonts[][5] = {
        0x00, 0x00, 0x00, 0x00, 0x00,// ' '
        0x00, 0x00, 0x5F, 0x00, 0x00,// !
        0x00, 0x07, 0x00, 0x07, 0x00,// "
        0x14, 0x7F, 0x14, 0x7F, 0x14,// #
    	0x24, 0x2A, 0x07, 0x2A, 0x12,// $
    	0x23, 0x13, 0x08, 0x64, 0x62,// %
        0x37, 0x49, 0x55, 0x22, 0x50,// &
        0x00, 0x05, 0x03, 0x00, 0x00,// '
        0x00, 0x1C, 0x22, 0x41, 0x00,// (
        0x00, 0x41, 0x22, 0x1C, 0x00,// )
        0x08, 0x2A, 0x1C, 0x2A, 0x08,// *
        0x08, 0x08, 0x3E, 0x08, 0x08,// +
        0x00, 0x50, 0x30, 0x00, 0x00,// ,
        0x08, 0x08, 0x08, 0x08, 0x08,// -
        0x00, 0x60, 0x60, 0x00, 0x00,// .
        0x20, 0x10, 0x08, 0x04, 0x02,// /
        0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
        0x00, 0x42, 0x7F, 0x40, 0x00,// 1
        0x42, 0x61, 0x51, 0x49, 0x46,// 2
        0x21, 0x41, 0x45, 0x4B, 0x31,// 3
        0x18, 0x14, 0x12, 0x7F, 0x10,// 4
        0x27, 0x45, 0x45, 0x45, 0x39,// 5
        0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
        0x01, 0x71, 0x09, 0x05, 0x03,// 7
        0x36, 0x49, 0x49, 0x49, 0x36,// 8
        0x06, 0x49, 0x49, 0x29, 0x1E,// 9
        0x00, 0x36, 0x36, 0x00, 0x00,// :
        0x00, 0x56, 0x36, 0x00, 0x00,// ;
        0x00, 0x08, 0x14, 0x22, 0x41,// <
        0x14, 0x14, 0x14, 0x14, 0x14,// =
        0x41, 0x22, 0x14, 0x08, 0x00,// >
        0x02, 0x01, 0x51, 0x09, 0x06,// ?
        0x32, 0x49, 0x79, 0x41, 0x3E,// @
        0x7E, 0x11, 0x11, 0x11, 0x7E,// A
        0x7F, 0x49, 0x49, 0x49, 0x36,// B
        0x3E, 0x41, 0x41, 0x41, 0x22,// C
        0x7F, 0x41, 0x41, 0x22, 0x1C,// D
        0x7F, 0x49, 0x49, 0x49, 0x41,// E
        0x7F, 0x09, 0x09, 0x01, 0x01,// F
        0x3E, 0x41, 0x41, 0x51, 0x32,// G
        0x7F, 0x08, 0x08, 0x08, 0x7F,// H
        0x00, 0x41, 0x7F, 0x41, 0x00,// I
        0x20, 0x40, 0x41, 0x3F, 0x01,// J
        0x7F, 0x08, 0x14, 0x22, 0x41,// K
        0x7F, 0x40, 0x40, 0x40, 0x40,// L
        0x7F, 0x02, 0x04, 0x02, 0x7F,// M
        0x7F, 0x04, 0x08, 0x10, 0x7F,// N
        0x3E, 0x41, 0x41, 0x41, 0x3E,// O
        0x7F, 0x09, 0x09, 0x09, 0x06,// P
        0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
        0x7F, 0x09, 0x19, 0x29, 0x46,// R
        0x46, 0x49, 0x49, 0x49, 0x31,// S
        0x01, 0x01, 0x7F, 0x01, 0x01,// T
        0x3F, 0x40, 0x40, 0x40, 0x3F,// U
        0x1F, 0x20, 0x40, 0x20, 0x1F,// V
        0x7F, 0x20, 0x18, 0x20, 0x7F,// W
        0x63, 0x14, 0x08, 0x14, 0x63,// X
        0x03, 0x04, 0x78, 0x04, 0x03,// Y
        0x61, 0x51, 0x49, 0x45, 0x43,// Z
        0x00, 0x00, 0x7F, 0x41, 0x41,// [
        0x02, 0x04, 0x08, 0x10, 0x20,// "\"
        0x41, 0x41, 0x7F, 0x00, 0x00,// ]
        0x04, 0x02, 0x01, 0x02, 0x04,// ^
        0x40, 0x40, 0x40, 0x40, 0x40,// _
        0x00, 0x01, 0x02, 0x04, 0x00,// `
        0x20, 0x54, 0x54, 0x54, 0x78,// a
        0x7F, 0x48, 0x44, 0x44, 0x38,// b
        0x38, 0x44, 0x44, 0x44, 0x20,// c
        0x38, 0x44, 0x44, 0x48, 0x7F,// d
        0x38, 0x54, 0x54, 0x54, 0x18,// e
        0x08, 0x7E, 0x09, 0x01, 0x02,// f
        0x08, 0x14, 0x54, 0x54, 0x3C,// g
        0x7F, 0x08, 0x04, 0x04, 0x78,// h
        0x00, 0x44, 0x7D, 0x40, 0x00,// i
        0x20, 0x40, 0x44, 0x3D, 0x00,// j
        0x00, 0x7F, 0x10, 0x28, 0x44,// k
        0x00, 0x41, 0x7F, 0x40, 0x00,// l
        0x7C, 0x04, 0x18, 0x04, 0x78,// m
        0x7C, 0x08, 0x04, 0x04, 0x78,// n
        0x38, 0x44, 0x44, 0x44, 0x38,// o
        0x7C, 0x14, 0x14, 0x14, 0x08,// p
        0x08, 0x14, 0x14, 0x18, 0x7C,// q
        0x7C, 0x08, 0x04, 0x04, 0x08,// r
        0x48, 0x54, 0x54, 0x54, 0x20,// s
        0x04, 0x3F, 0x44, 0x40, 0x20,// t
        0x3C, 0x40, 0x40, 0x20, 0x7C,// u
        0x1C, 0x20, 0x40, 0x20, 0x1C,// v
        0x3C, 0x40, 0x30, 0x40, 0x3C,// w
        0x44, 0x28, 0x10, 0x28, 0x44,// x
        0x0C, 0x50, 0x50, 0x50, 0x3C,// y
        0x44, 0x64, 0x54, 0x4C, 0x44,// z
        0x00, 0x08, 0x36, 0x41, 0x00,// {
        0x00, 0x00, 0x7F, 0x00, 0x00,// |
        0x00, 0x41, 0x36, 0x08, 0x00,// }
        0x02, 0x01, 0x02, 0x04, 0x02,// ~
        0xff, 0xff, 0xff, 0xff, 0xff //black block// 
};
#endif

/*
PLEASE ENTER PASSWORD 的点阵数组
使用方法为 write(fd, PLEASE_ENTER_PASSWORD[index++], 8);
*/
const unsigned char PLEASE_ENTER_PASSWORD[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, //  
	0x00, 0x00, 0x00, 0x00, 0x00, //  

	0x7f, 0x09, 0x09, 0x09, 0x06, // P
	0x7f, 0x40, 0x40, 0x40, 0x40, // L
	0x7f, 0x49, 0x49, 0x49, 0x41, // E
	0x7e, 0x11, 0x11, 0x11, 0x7e, // A
	0x46, 0x49, 0x49, 0x49, 0x31, // S
	0x7f, 0x49, 0x49, 0x49, 0x41, // E
	0x00, 0x00, 0x00, 0x00, 0x00, //  
	0x7f, 0x49, 0x49, 0x49, 0x41, // E
	0x7f, 0x04, 0x08, 0x10, 0x7f, // N
	0x01, 0x01, 0x7f, 0x01, 0x01, // T
	0x7f, 0x49, 0x49, 0x49, 0x41, // E
	0x7f, 0x09, 0x19, 0x29, 0x46, // R
	0x00, 0x00, 0x00, 0x00, 0x00, //  
	0x7f, 0x09, 0x09, 0x09, 0x06, // P
	0x7e, 0x11, 0x11, 0x11, 0x7e, // A
	0x46, 0x49, 0x49, 0x49, 0x31, // S
	0x46, 0x49, 0x49, 0x49, 0x31, // S
	0x7f, 0x20, 0x18, 0x20, 0x7f, // W
	0x3e, 0x41, 0x41, 0x41, 0x3e, // O
	0x7f, 0x09, 0x19, 0x29, 0x46, // R
	0x7f, 0x41, 0x41, 0x22, 0x1c, // D
	
	0x00, 0x00, 0x00, 0x00, 0x00, // 
	0x00, 0x00, 0x00, 0x00, 0x00, //
};
const unsigned int LEN_PLEASE_ENTER_PASSWORD = sizeof(PLEASE_ENTER_PASSWORD)/sizeof(char) - 5;

const unsigned char CHANGING_PASSWORD_PLEASE_INPUT_OLD_PASSWORD[] = {
	0x3e, 0x41, 0x41, 0x41, 0x22, 	// C
	0x7f, 0x8, 0x8, 0x8, 0x7f, 	// H
	0x7e, 0x11, 0x11, 0x11, 0x7e, 	// A
	0x7f, 0x4, 0x8, 0x10, 0x7f, 	// N
	0x3e, 0x41, 0x41, 0x51, 0x32, 	// G
	0x0, 0x41, 0x7f, 0x41, 0x0, 	// I
	0x7f, 0x4, 0x8, 0x10, 0x7f, 	// N
	0x3e, 0x41, 0x41, 0x51, 0x32, 	// G
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x7f, 0x9, 0x9, 0x9, 0x6, 	// P
	0x7e, 0x11, 0x11, 0x11, 0x7e, 	// A
	0x46, 0x49, 0x49, 0x49, 0x31, 	// S
	0x46, 0x49, 0x49, 0x49, 0x31, 	// S
	0x7f, 0x20, 0x18, 0x20, 0x7f, 	// W
	0x3e, 0x41, 0x41, 0x41, 0x3e, 	// O
	0x7f, 0x9, 0x19, 0x29, 0x46, 	// R
	0x7f, 0x41, 0x41, 0x22, 0x1c, 	// D
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x7f, 0x9, 0x9, 0x9, 0x6, 	// P
	0x7f, 0x40, 0x40, 0x40, 0x40, 	// L
	0x7f, 0x49, 0x49, 0x49, 0x41, 	// E
	0x7e, 0x11, 0x11, 0x11, 0x7e, 	// A
	0x46, 0x49, 0x49, 0x49, 0x31, 	// S
	0x7f, 0x49, 0x49, 0x49, 0x41, 	// E
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x0, 0x41, 0x7f, 0x41, 0x0, 	// I
	0x7f, 0x4, 0x8, 0x10, 0x7f, 	// N
	0x7f, 0x9, 0x9, 0x9, 0x6, 	// P
	0x3f, 0x40, 0x40, 0x40, 0x3f, 	// U
	0x1, 0x1, 0x7f, 0x1, 0x1, 	// T
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x3e, 0x41, 0x41, 0x41, 0x3e, 	// O
	0x7f, 0x40, 0x40, 0x40, 0x40, 	// L
	0x7f, 0x41, 0x41, 0x22, 0x1c, 	// D
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x7f, 0x9, 0x9, 0x9, 0x6, 	// P
	0x7e, 0x11, 0x11, 0x11, 0x7e, 	// A
	0x46, 0x49, 0x49, 0x49, 0x31, 	// S
	0x46, 0x49, 0x49, 0x49, 0x31, 	// S
	0x7f, 0x20, 0x18, 0x20, 0x7f, 	// W
	0x3e, 0x41, 0x41, 0x41, 0x3e, 	// O
	0x7f, 0x9, 0x19, 0x29, 0x46, 	// R
	0x7f, 0x41, 0x41, 0x22, 0x1c, 	// D
	0x0, 0x36, 0x36, 0x0, 0x0, 	// :
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x0, 0x0, 0x0, 0x0, 0x0, 	// 
};
const unsigned int LEN_CHANGING_PASSWORD_PLEASE_INPUT_OLD_PASSWORD = sizeof(CHANGING_PASSWORD_PLEASE_INPUT_OLD_PASSWORD)/sizeof(char) - 5;

const unsigned char NEW_PASSWORD[] = {
	0x7f, 0x4, 0x8, 0x10, 0x7f, 	// N
	0x7f, 0x49, 0x49, 0x49, 0x41, 	// E
	0x7f, 0x20, 0x18, 0x20, 0x7f, 	// W
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x7f, 0x9, 0x9, 0x9, 0x6, 	// P
	0x7e, 0x11, 0x11, 0x11, 0x7e, 	// A
	0x46, 0x49, 0x49, 0x49, 0x31, 	// S
	0x46, 0x49, 0x49, 0x49, 0x31, 	// S
	0x7f, 0x20, 0x18, 0x20, 0x7f, 	// W
	0x3e, 0x41, 0x41, 0x41, 0x3e, 	// O
	0x7f, 0x9, 0x19, 0x29, 0x46, 	// R
	0x7f, 0x41, 0x41, 0x22, 0x1c, 	// D
	0x0, 0x36, 0x36, 0x0, 0x0, 	// :
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x0, 0x0, 0x0, 0x0, 0x0, 	// 
};
const unsigned int LEN_NEW_PASSWORD = sizeof(NEW_PASSWORD)/sizeof(char) - 5;

const unsigned char REPEAT_PASSWORD[] = {
	0x7f, 0x9, 0x19, 0x29, 0x46, 	// R
	0x7f, 0x49, 0x49, 0x49, 0x41, 	// E
	0x7f, 0x9, 0x9, 0x9, 0x6, 	// P
	0x7f, 0x49, 0x49, 0x49, 0x41, 	// E
	0x7e, 0x11, 0x11, 0x11, 0x7e, 	// A
	0x1, 0x1, 0x7f, 0x1, 0x1, 	// T
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x7f, 0x4, 0x8, 0x10, 0x7f, 	// N
	0x7f, 0x49, 0x49, 0x49, 0x41, 	// E
	0x7f, 0x20, 0x18, 0x20, 0x7f, 	// W
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x7f, 0x9, 0x9, 0x9, 0x6, 	// P
	0x46, 0x49, 0x49, 0x49, 0x31, 	// S
	0x7f, 0x20, 0x18, 0x20, 0x7f, 	// W
	0x0, 0x36, 0x36, 0x0, 0x0, 	// :
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
	0x0, 0x0, 0x0, 0x0, 0x0, 	//  
};
const unsigned int LEN_REPEAT_PASSWORD = sizeof(REPEAT_PASSWORD)/sizeof(char) - 5;

const unsigned char PSW_CORRECT_BLOCK[] = {
	0x03, 0x04, 0x78, 0x04, 0x03,// Y
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char PSW_WRONG_BLOCK[] = {
	0x7F, 0x04, 0x08, 0x10, 0x7F,// N
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

//输入密码时的进度条
const unsigned char PSW_INPUTING_BLOCK[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
};

/*
TEST_BLOCK 开机时测试是否有不亮的led
write(fd, TEST_BLOCK[index++], 10);
*/
const unsigned char TEST_BLOCK[10] = {
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};

const unsigned char LED_SLEEP_BLOCK[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};