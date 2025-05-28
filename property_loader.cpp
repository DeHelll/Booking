#include "property_loader.h"
#include <vector>
void loadSampleProperties(RentalSys& system)
{
    system.addHouse(std::make_unique<House>("123 Main St", 350));
    system.addHouse(std::make_unique<House>("456 Oak Ave", 275));
    system.addHouse(std::make_unique<House>("789 Pine Rd", 420));
    system.addHouse(std::make_unique<House>("101 Maple Ln", 310));
    system.addHouse(std::make_unique<House>("202 Cedar Dr", 400));
    system.addHouse(std::make_unique<House>("303 Birch Ct", 290));
    system.addHouse(std::make_unique<House>("404 Walnut Pl", 450));
    system.addHouse(std::make_unique<House>("505 Spruce Blvd", 325));
    system.addHouse(std::make_unique<House>("606 Redwood St", 380));
    system.addHouse(std::make_unique<House>("707 Ash Ave", 260));
    system.addHouse(std::make_unique<House>("808 Palm Cir", 330));
    system.addHouse(std::make_unique<House>("909 Juniper Way", 410));
}
}
