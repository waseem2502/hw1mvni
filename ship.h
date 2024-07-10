//
// Created by Waseem on 06/07/2024.
//

#ifndef WET1_SHIP_H
#define WET1_SHIP_H
#include "pirates.h"
#include "AVLTree.h"
#include <memory>
using namespace std;

class Ship{
private:
    int m_shipId;
    int m_cannons;
    int m_nextInOrder;
    int m_coinDiff;

public:
    AVLTree<int,shared_ptr<Pirates>> pirates_id;
    AVLTree<int,shared_ptr<Pirates>> pirates_order;
    AVLTree<int,shared_ptr<Pirates>> pirates_treasure;

    //needs to add 2 AVL trees here , update constructor and destructor
    Ship(int sID, int can)
            : m_shipId(sID), m_cannons(can), m_nextInOrder(0), m_coinDiff(0) {

    }

    int getShipID() const { return m_shipId; }
    int getCannons() const { return m_cannons; }
    int getNextInOrder() const { return m_nextInOrder; }
    int getCoinDeff() const { return m_coinDiff; }


    void setShipID(int sID) { m_shipId = sID; }
    void setCannons(int can) { m_cannons = can; }
    void setNextInOrder(int next) { m_nextInOrder = next; }
    void setCoinDeff(int coinDiff) { m_coinDiff = coinDiff; }
};
#endif //WET1_SHIP_H
