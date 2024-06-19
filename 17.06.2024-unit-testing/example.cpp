#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Castle.h"
#include "Knight.h"

using namespace ::testing;

class ICastleMock : public ICastle {
public:
    MOCK_METHOD(void, NotifyKnightDeath, (const IKnight& knight), (override));
    MOCK_METHOD(const std::vector<std::string>&, GetBuriedKnights, (), (const, override));
};

TEST(KnightTest, IsAlive) {
    ICastleMock castle_mock;
    Knight knight("Sir True Boolean", castle_mock);

    EXPECT_TRUE(knight.IsAlive());
}

TEST(KnightTest, Dies) {
    ICastleMock castle_mock;
    Knight knight("Sir True Boolean", castle_mock);

    EXPECT_CALL(castle_mock, NotifyKnightDeath(Ref(knight))).Times(1);

    knight.Die();

    EXPECT_FALSE(knight.IsAlive());
}

TEST(CastleSirTrueBooleanTest, BuriedKnight) {
    CastleSirTrueBoolean castle("Sir True Boolean's Castle");
    Knight sir_true_boolean("Sir True Boolean", castle);
    Knight sir_william_fortesque("Sir William Fortesque", castle);

    sir_william_fortesque.Die();
    const auto& buried_knights = castle.GetBuriedKnights();

    EXPECT_EQ(buried_knights.size(), 1);
    EXPECT_EQ(buried_knights[0], sir_william_fortesque.GetName());
}
