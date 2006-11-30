/*
 * PyMite - A flyweight Python interpreter for 8-bit microcontrollers and more.
 * Copyright 2002 Dean Hall
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __SEQ_H__
#define __SEQ_H__
/**
 * Sequence Header
 *
 * Log
 * ---
 *
 * 2006/11/29   #59: Improve bytecode UNPACK_SEQUENCE
 */


/**
 * Compares two sequences for equality
 *
 * @param   pobj1 Ptr to first sequence.
 * @param   pobj2 Ptr to second sequence.
 * @return  C_SAME if the seuqences are equivalent, C_DIFFER otherwise.
 */
int8_t seq_compare(pPmObj_t pobj1, pPmObj_t pobj2);

/**
 * Returns the length of the sequence
 *
 * @param   pobj Ptr to  sequence.
 * @param   r_index Return arg, length of sequence
 * @return  Return status
 */
PmReturn_t seq_getLength(pPmObj_t pobj, int16_t *r_index);

/**
 * Returns the object from sequence[index]
 *
 * @param   pobj Ptr to sequence object to get object from
 * @param   index Int index into the sequence
 * @param   r_pobj Return arg, object from sequence
 * @return  Return status
 */
PmReturn_t seq_getSubscript(pPmObj_t pobj, int16_t index, pPmObj_t *r_pobj);

#endif /* __SEQ_H__ */