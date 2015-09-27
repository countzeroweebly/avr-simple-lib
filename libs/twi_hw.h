#define START           0x08    //START has been transmitted
#define REP_START       0x10
#define MT_DATA_ACK     0x28

//Master Transmitter staus codes
#define MT_ADR_ACK      0x18    //SLA+W has been tramsmitted and ACK received
#define MT_ADR_NACK     0x20    //SLA+W has been tramsmitted and NACK received

#define MT_DATA_ACK     0x28    //Data byte has been tramsmitted and ACK received
#define MT_DATA_NACK    0x30    //Data byte has been tramsmitted and NACK received
#define MT_ARB_LOST     0x38    //Arbitration lost in SLA+W or data bytes

#define WRITE           0x00
#define READ            0x01

#define READ_END        0x01
#define READ_NOEND      0x00

#define RTC             0xD0

uint8_t read_i2c(uint8_t END);
uint8_t send_i2c(uint8_t value);
uint8_t start_i2c(uint8_t d_adr);
inline void stop_i2c();
inline void init_twi();

