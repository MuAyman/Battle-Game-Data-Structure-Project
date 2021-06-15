#include "healer.h"

void healer::incrementDist()
{
     if (Distance == MinDistance)
          Distance++;
}

void healer::Heal()
{

}
void healer::ifHealing()
{
    if ((!(Frosted || Killed))&& Distance <=2) { Heal(); }
}
