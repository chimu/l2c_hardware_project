unsigned char display[4];

unsigned segIterator = 0;


/*

                   64
				 ______
				|      |
				|      |
			  32|      |16
				|  8   |
				|------|
				|      |
				|      |
			   1|      |4
				|  2   |
                 ------

*/

//Charmap is offset by 48
char charMap[50] = {

	1+2+4+16+64+32,					//0
	16+4,							//1
	2+1+8+16+64,					//2
	64+16+8+4+2,					//3
	32+8+16+4,						//4
	64+32+8+4+2,					//5
	64+32+8+4+2+1,					//6
	64+16+4,						//7
	127,							//8
	126,							//9
	0,								//derp
	0,								//derp
	0,								//derp
	0,								//derp
	0,								//derp
	0,								//derp
	0,								//derp
	127-2,							//A
	32+1+2+4+8,						//B
	64+32+1+2,						//C
	1+2+4+8+16,						//D
	64+32+8+1+2,					//E
	64+32+8+1,						//F
	2+4+16+8+32+64,					//G
	32+1+4+8,						//H
	32+1,							//I
	16+4+2,							//J
	32+1+8,							//K
	32+1+2,							//L
	1+32+64+16+4,					//M
	1+8+4,							//N
	1+2+4+8,						//O
	1+32+64+16+8,					//P
	32+64+16+8+4,					//Q
	1+8,							//R
	64+32+8+4+2,					//S
	1+32+64,						//T
	1+2+4,							//U
	1+2+4+16+32,					//V
	0,								//W
	32+16+1+4+8,					//X
	32+8+16+4+2,					//Y
	2+1+8+16+64						//Z
};




void setSegment(int segment, char character)
{
	if (segment >= 0 && segment < 4 && character >= 48 && character < 98) display[segment]=charMap[character-48];
	else display[segment] = 0;
}

void setDisplay(char* string)
{
	int i;
	for (i = 0; i < 4; i++) setSegment(i,string[i]);
}

void displayStep()
{
	segIterator++;
	if (segIterator > 4) segIterator = 0;
	
	//Set the LEDs of the segment
	AT91F_PIO_SetOutput( AT91C_BASE_PIOA, 255<<8) ;
	AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, (display[segIterator])<<8) ;
	
	//Select the segment to output on
	AT91F_PIO_SetOutput( AT91C_BASE_PIOA, 1<<((segIterator-1)%4+4)) ;
	AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, 1<<(segIterator+4)) ;
}


