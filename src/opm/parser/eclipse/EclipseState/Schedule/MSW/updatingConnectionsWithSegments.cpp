/*
  Copyright 2017 SINTEF Digital, Mathematics and Cybernetics.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <opm/parser/eclipse/EclipseState/Schedule/MSW/updatingConnectionsWithSegments.hpp>
#include "Compsegs.hpp"


namespace Opm {

    ConnectionSet updatingConnectionsWithSegments(const DeckKeyword& compsegs,
                                                  const ConnectionSet& input_connections,
                                                  const SegmentSet& segment_set)
    {
        ConnectionSet new_connection_set(input_connections);

        std::vector<Compsegs> compsegs_vector = Compsegs::compsegsFromCOMPSEGSKeyword( compsegs );
        Compsegs::processCOMPSEGS(compsegs_vector, segment_set);
        Compsegs::updateConnectionsWithSegment(compsegs_vector, new_connection_set);
        return new_connection_set;
    }
}
