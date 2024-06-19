#pragma once

#include <string>
#include <vector>

class IKnight;

class ICastle {
public:
    virtual ~ICastle() = default;
    virtual void NotifyKnightDeath(const IKnight& knight) = 0;
    virtual const std::vector<std::string>& GetBuriedKnights() const = 0;
};

class CastleSirTrueBoolean : public ICastle {
public:
    CastleSirTrueBoolean(std::string name);

    void NotifyKnightDeath(const IKnight& knight) override;
    const std::vector<std::string>& GetBuriedKnights() const override;

private:
    std::string name_;
    std::vector<std::string> buried_knights_;
};
