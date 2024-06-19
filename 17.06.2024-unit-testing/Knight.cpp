#include "Knight.h"

#include "Castle.h"

Knight::Knight(std::string name, ICastle& castle) 
    : name_(name)
    , lifes_(5)
    , castle_(castle) {}

bool Knight::IsAlive() const {
    return lifes_ > 0;
}

void Knight::Die() {
    lifes_ = 0;
    castle_.NotifyKnightDeath(*this);
}

const std::string& Knight::GetName() const {
    return name_;
}

