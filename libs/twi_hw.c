#include <util/twi.h>
#include <twi_hw.h>

inline void init_twi()
{
	TWBR = (F_CPU / 100000UL - 16)/2; // TWI bitrate
}

uint8_t send_i2c(uint8_t value)
{
        TWDR = value;
        TWCR = (1<<TWINT) | (1<<TWEN);

        while(!(TWCR & (1<<TWINT))) {};

        return ((TWSR & 0xF8) != MT_ADR_ACK) ? 1 : 0;
}

uint8_t start_i2c(uint8_t d_adr)
{
        TWCR=(1<<TWINT) | (1<<TWSTA) | (1<<TWEN); // START
        while (!(TWCR & (1<<TWINT))) {};

        uint8_t twst; twst = (TWSR & 0xF8); // check value of TWI Status Register. Mask prescaler bits.
        if ((twst != START) && (twst != REP_START))
                return 1;
        uint8_t ret; ret=send_i2c(d_adr);
        return ret;
};

inline void stop_i2c()
{
        TWCR=(1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

uint8_t read_i2c(uint8_t END)
{
        if (END)
                TWCR = (1<<TWINT)|(1<<TWEN);
        else
                TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);

        while(!(TWCR & (1<<TWINT)));

        return TWDR; // return data
}

