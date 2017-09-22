#include "catch.hpp"
#include "../dejt/InterestTable.h"


TEST_CASE("Test Interest table")
{
    InterestTable it1, it2;

    // Add interests
    it1.add("sport");
    it1.add("programmering");
    it1.add("Film");
    it1.add("");
    it1.add("RESA");

    it2.add("mat");
    it2.add("sport");
    it2.add("");
    it2.add("");
    it2.add("Resa");
    it2.add("dans");
    it2.add("sport");
    it2.add("film");

    // Should match {"sport", "resa", "film"} = 3

    SECTION("Test compare")
    {
        REQUIRE(it1.numberOfCommonInterests(it2) == 3);
    }
}
