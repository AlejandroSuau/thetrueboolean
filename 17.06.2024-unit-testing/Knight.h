#pragma once

#include <string>

class ICastle;

class IKnight {
public:
    virtual ~IKnight() = default;
    virtual bool IsAlive() const = 0;
    virtual void Die() = 0;
    virtual const std::string& GetName() const = 0;
};

class Knight : public IKnight {
public:
    Knight(std::string name, ICastle& castle);

    bool IsAlive() const override;
    void Die() override;
    const std::string& GetName() const override;

private:
    const std::string name_;
    int lifes_;
    ICastle& castle_;
};