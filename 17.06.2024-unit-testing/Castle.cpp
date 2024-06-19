#include "Castle.h"

#include "Knight.h"

CastleSirTrueBoolean::CastleSirTrueBoolean(std::string name) 
    : name_(name) {}

void CastleSirTrueBoolean::NotifyKnightDeath(const IKnight& knight) {
    buried_knights_.emplace_back(knight.GetName());
}

const std::vector<std::string>& CastleSirTrueBoolean::GetBuriedKnights() const {
    return buried_knights_;
}
