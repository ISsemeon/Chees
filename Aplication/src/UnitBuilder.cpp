#include <include/UnitBuilder.h>
#include <include/PawnFigure.h>

Figure* UnitFactury::makeUnit()
{
	return new PawnFigure();
}

