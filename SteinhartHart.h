/**
 * SteinhartHart.h - Library for interacting with NTC thermistors
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SteinhartHart_h
#define SteinhartHart_h

#include <inttypes.h>


class SteinhartHart {
	public:	
		/**
		 * The reading pin has to be specified.
		 * If no other parameters are given default values will be used.
		 * These values are for a NTC 10k thermistor with a 10k resistor
		 * put in parallel.
		 */
		SteinhartHart(
			double a = 1.527551024e-3, 
			double b = 2.420058629e-4, 
			double c = -0.3883901682e-7) :
			_a(a), _b(b), _c(c) {};

		double getTempKelvin(double r);
		double getTempCelsius(double r);
		double getTempFahrenheit(double r);

		double steinhartHart(double r);
		
	private:
		// Manufacturing constants
		double _a;
		double _b;
		double _c;
};

#endif