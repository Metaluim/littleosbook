#include "serial.h"
#include "io.h"

void
serial_cfg_baudrate(unsigned short com, unsigned short divisor)
{
	/*
	 * Tell the serial controller that we are about to
	 * set the divisor of the baudrate. This is done
	 * by writing to the data register and interrupt
	 * enabling register. These two bytes will hold the
	 * divisor data WHILE the DLAB bit is set.
	 */
	outb(SERIAL_LINE_CMD_PORT(com), SERIAL_LINE_ENABLE_DLAB);
	outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
	outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
	outb(SERIAL_LINE_CMD_PORT(com), 0x0);
}

void
serial_cfg_line(unsigned short com)
{
	/*
	 * Line control register layout:
	 *
	 *	| 7 | 6 | 5 4 3 | 2 | 1 0 |
	 *	| d | b | pty   | s | dl  |
	 *
	 * Where:
	 *	+ d => Enables the DLAB
	 *	+ b => Enables break control
	 *	+ prty => The number of parity bits to use
	 *	+ s => The number of stop bits to use
	 *		(s = 0 equals 1, s = 1 equals 1.5 or 2)
	 *	+ dl => Describes the length of the data
	 *
	 * The most commonly used value is 8 bits lenght, no
	 * parity bit, 1 stop bit and break control disabled,
	 * i.e. 0x03.
	 */
	outb(SERIAL_LINE_CMD_PORT(com), 0x03);		
}

void
serial_cfg_buf(unsigned short com)
{
	/*
	 * Buffer config register layout:
	 *
	 *	| 7 6 | 5  | 4 | 3   | 2   | 1   | 0 |
	 *	| lvl | bs | r | dma | clt | clr | e |
	 *
	 * Where:
	 *	+ lvl => Size of the buffer in bytes
	 *	+ bs => Enables 64 byte FIFO
	 *	+ r => Reserved for future use
	 *	+ dma => DMA mode selection
	 *	+ clt => Clear the transmission FIFO
	 *	+ clr => Clear the reception FIFO
	 *	+ e => Enables or disables the FIFO buffer
	 *
	 * The default value by convention, for now, will be
	 * one which enables the FIFO, clears both buffers and
	 * uses 14 bytes of size, i.e. 0xC7.
	 */
	 outb(SERIAL_FIFO_CMD_PORT(com), 0xC7);
}

