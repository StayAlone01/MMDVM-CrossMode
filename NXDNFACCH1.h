/*
*   Copyright (C) 2018,2024 by Jonathan Naylor G4KLX
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

#if !defined(NXDNFACCH1_H)
#define	NXDNFACCH1_H

#include <cstdint>

class CNXDNFACCH1 {
public:
	CNXDNFACCH1(const CNXDNFACCH1& facch);
	CNXDNFACCH1();
	~CNXDNFACCH1();

	bool decode(const uint8_t* data, unsigned int offset);

	void encode(uint8_t* data, unsigned int offset) const;

	void getData(uint8_t* data) const;
	void getRaw(uint8_t* data) const;

	void setData(const uint8_t* data);
	void setRaw(const uint8_t* data);

	CNXDNFACCH1& operator=(const CNXDNFACCH1& facch);

private:
	uint8_t* m_data;
};

#endif
