

#define SetBit(VAR,BIT)	     ( VAR |=(1 << (BIT)))
#define ClearBit(VAR,BIT)	(VAR &=	~(1 << (BIT)))
#define GetBit(VAR,BIT)	    (((VAR	>>BIT)	&  1))
#define ToggleBit(VAR,BIT)	(VAR ^= (1 << (BIT)))
