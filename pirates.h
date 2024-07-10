//
// Created by Waseem on 06/07/2024.
//

#ifndef WET1_PIRATES_H
#define WET1_PIRATES_H
class Ship;
#include "ship.h"

class Pirates {
private:
    int m_piratesID;
    int m_shipID;
    int m_treasure;
    int m_order;
    Ship* m_source_ship;
public:
    Pirates(int pID, int sID, int tr)
            : m_piratesID(pID), m_shipID(sID), m_treasure(tr), m_order(-1),m_source_ship(nullptr) {}
    Pirates(int pID, int sID, int tr,int ord,Ship* ship)
            : m_piratesID(pID), m_shipID(sID), m_treasure(tr), m_order(ord),m_source_ship(ship) {}
    ~Pirates() = default;

    int getPirateID() const { return m_piratesID; }
    int getShipID() const { return m_shipID; }
    int getTreasure() const { return m_treasure; }
    int getOrder() const { return m_order; }
    Ship* getSourceShip9() const {return m_source_ship;}

    void setPirateID(int pID) { m_piratesID = pID; }
    void setShipID(int sID) { m_shipID = sID; }
    void setTreasure(int tr) { m_treasure = tr; }
    void setOrder(int ord) { m_order = ord; }
    void setSourceShip(Ship* ship){ m_source_ship = ship;}
};

#endif //WET1_PIRATES_H
