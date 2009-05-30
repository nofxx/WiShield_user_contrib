
/******************************************************************************

  Filename:		WiShield.cpp
  Description:	WiShield library file for the WiShield 1.0

 ******************************************************************************

  TCP/IP stack and driver for the WiShield 1.0 wireless devices

  Copyright(c) 2009 Async Labs Inc. All rights reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, write to the Free Software Foundation, Inc., 59
  Temple Place - Suite 330, Boston, MA  02111-1307, USA.

  Contact Information:
  <asynclabs@asynclabs.com>

   Author               Date        Comment
  ---------------------------------------------------------------
   AsyncLabs			05/01/2009	Initial version
   AsyncLabs			05/29/2009	Adding support for new library

 *****************************************************************************/

extern "C" {
  #include "types.h"
  #include "global-conf.h"
  #include "network.h"
  #include "g2100.h"
  void stack_init(void);
  void stack_process(void);
}

#include "WProgram.h"
#include "WiShield.h"

void WiShield::init()
{
	zg_init();
	attachInterrupt(0, zg_isr, LOW);

	while(zg_get_conn_state() != 1) {
		zg_drv_process();
	}

	stack_init();
}

void WiShield::run()
{
	stack_process();
	zg_drv_process();
}

WiShield WiFi;
