#include "pirates24b1.h"



Ocean::Ocean()
{
    
}

Ocean::~Ocean()
{
    
}

StatusType Ocean::add_ship(int shipId, int cannons)
{
    if (shipId <= 0 || cannons < 0) {
        return StatusType::INVALID_INPUT;
    }
    Ship ship(shipId,cannons);
    bool success = m_ships.insert(shipId, ship);
    if (!success) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}



StatusType Ocean::remove_ship(int shipId)
{
    if(shipId <= 0)
        return StatusType::INVALID_INPUT;
    node<int,Ship>* current = m_ships.find(shipId);
    if(current == nullptr){
        return StatusType::FAILURE;
    }
    if(current->m_data.pirates_id.getSize() == 0){
        return StatusType::FAILURE;
    }
    m_ships.remove(shipId);
    return StatusType::SUCCESS;
}

StatusType Ocean::add_pirate(int pirateId, int shipId, int treasure)
{
    if(pirateId <= 0 || shipId <= 0)
        return StatusType::INVALID_INPUT;
    node<int,Ship>* currentShip = m_ships.find(shipId);
    if(currentShip == nullptr)
        return StatusType::FAILURE;
    node<int,shared_ptr<Pirates>>* currentPirate = m_pirates.find(pirateId);
    if(currentPirate != nullptr)
    {
        return StatusType::FAILURE;
    }
    Pirates pirate(pirateId,shipId,treasure,currentShip->m_data.getNextInOrder(),&(currentShip->m_data));
    m_pirates.insert(pirateId,make_shared<Pirates>(pirate));
    currentShip->m_data.pirates_id.insert(pirateId,make_shared<Pirates>(pirate));
    currentShip->m_data.pirates_order.insert(currentShip->m_data.getNextInOrder(),make_shared<Pirates>(pirate));
    currentShip->m_data.setNextInOrder(currentShip->m_data.getNextInOrder() + 1 );
    currentShip->m_data.pirates_treasure.insert(treasure,make_shared<Pirates>(pirate));
}

StatusType Ocean::remove_pirate(int pirateId)
{
    return StatusType::FAILURE;
}

StatusType Ocean::treason(int sourceShipId, int destShipId)
{
    return StatusType::FAILURE;
}

StatusType Ocean::update_pirate_treasure(int pirateId, int change)
{
    return StatusType::FAILURE;
}

output_t<int> Ocean::get_treasure(int pirateId)
{
    return 0;
}

output_t<int> Ocean::get_cannons(int shipId)
{
    return 0;
}

output_t<int> Ocean::get_richest_pirate(int shipId)
{
    return 0;
}

StatusType Ocean::ships_battle(int shipId1,int shipId2)
{
    return StatusType::FAILURE;
}



