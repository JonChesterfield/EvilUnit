/*
 * This file is part of EvilUnit.
 *
 * EvilUnit is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the 
 * Free Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * EvilUnit is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR 
 * A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more 
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License along 
 * with EvilUnit. If not, see <http://www.gnu.org/licenses/>.
 */
/*
 * Copyright Jon Chesterfield. All rights reserved.
 */
/* Define multiple implementations at once to check the symbols don't collide */

#define EVILUNIT_CONTRACT_IMPLEMENTATION_NONE_ENABLED 1
#define EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC_ENABLED 1

#ifdef __clang__
#define EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG_ENABLED 1
#elif defined(__GNUC__)
#define EVILUNIT_CONTRACT_IMPLEMENTATION_GCC_ENABLED 1
#endif

#define EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION  EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC

#include "EvilUnit.h"

MODULE(evilunit_contract)
{
  CHECK(*evilunit_contract_libc_state_depth_pointer() == 0);
  DEPENDS(evilunit_contract_none);
  DEPENDS(evilunit_contract_libc);
  DEPENDS(evilunit_contract_gcc);
  DEPENDS(evilunit_contract_clang);
  CHECK(*evilunit_contract_libc_state_depth_pointer() == 0);
}
