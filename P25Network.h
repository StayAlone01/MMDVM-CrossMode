/*
 *   Copyright (C) 2009-2014,2016,2020,2021,2024 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef	P25Network_H
#define	P25Network_H

#include "Network.h"
#include "RingBuffer.h"
#include "UDPSocket.h"

#include <cstdint>
#include <string>

class CP25Network : public INetwork {
public:
	CP25Network(const std::string& localAddress, uint16_t localPort, const std::string& remoteAddress, uint16_t remotePort, bool debug);
	virtual ~CP25Network();

	virtual bool open();

	virtual bool writeRaw(CData& data);
	virtual bool writeData(CData& data);

	bool writeLDU1(const uint8_t* ldu1, const CP25Data& control, const CP25LowSpeedData& lsd, bool end);

	bool writeLDU2(const uint8_t* ldu2, const CP25Data& control, const CP25LowSpeedData& lsd, bool end);

	virtual bool read(CData& data) = 0;
	virtual bool read() = 0;

	virtual bool hasData();

	virtual void reset();

	virtual void close();

	virtual void clock(unsigned int ms);

private:
	CUDPSocket       m_socket;
	sockaddr_storage m_addr;
	size_t           m_addrLen;
	bool             m_debug;
	CRingBuffer<uint8_t> m_buffer;
	CP25Audio        m_audio;
};

#endif
