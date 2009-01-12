// photo.h -- Leaf photosynthesis component parameters.
// 
// Copyright 2005 Per Abrahamsen and KVL.
//
// This file is part of Daisy.
// 
// Daisy is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser Public License as published by
// the Free Software Foundation; either version 2.1 of the License, or
// (at your option) any later version.
// 
// Daisy is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser Public License for more details.
// 
// You should have received a copy of the GNU Lesser Public License
// along with Daisy; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#ifndef PHOTO_H
#define PHOTO_H

#include "model.h"
#include <vector>

class CanopyStandard;
class Phenology;
class Log;
class Treelog;
class Block;
class AttributeList;
class Units;
class Syntax;

class Photo : public ModelLogable
{
  // Content.
public:
  static const char *const component;
  symbol library_id () const;
private:
  double min_PAR_;              // Minimumm PAR at top of canopy. [W/m^2]

  // Simulation.
public:
  virtual double min_PAR () const; // Minimumm PAR at top of canopy. [W/m^2]
  virtual double assimilate (const Units& units,
                             const double ABA_xylem, const double rel_hum, 
			     const double CO2_atm, double Ta, double Tc, double Tl, 
			     const double cropN,
                             const std::vector<double>& PAR,
                             const std::vector<double>& PAR_Height,
                             double PAR_LAI, 
			     const std::vector<double>& fraction,
                             double dt,
                             CanopyStandard& canopy,
                             Phenology& development, Treelog&) = 0;

  virtual double stomata_conductance() const = 0; // [mol m^-2 s^-1]
  virtual void clear ();
  virtual void output (Log&) const = 0;

  // Create and Destroy.
public:
  virtual bool handle_N_stress () const = 0;
  virtual bool handle_water_stress () const = 0;
  Photo (Block&);
  ~Photo ();
};

#endif // PHOTO_H
