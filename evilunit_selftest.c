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
 * Copyright 2015 Jon Chesterfield. All rights reserved.
 */
#include "EvilUnit.h"

static MODULE(direct)
{
  DEPENDS(direct);
  CHECK(42==42);
}

static EVILUNIT_MODULE_DECLARE(indirect_first);

static MODULE(indirect_second)
{
  DEPENDS(indirect_first);
  CHECK(2!=42);
}

static MODULE(indirect_first)
{
  DEPENDS(indirect_second);
  CHECK(1!=42);
}

static MODULE(evilunit_selftest_recursive)
{
  CHECK(1!=2);
  DEPENDS(direct);
  DEPENDS(indirect_first);
  DEPENDS(indirect_second);
}


MAIN_MODULE()
{
  DEPENDS(evilunit_selftest);
  DEPENDS(evilunit_selftest_recursive);
}
