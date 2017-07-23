/*
 * 策略模式的原則：
 * 1.將變動部分封裝起來。
 * 2.針對介面寫程式，不是針對實踐寫程式。
 * 3.多用合成，少用繼承。
 */
#include<iostream>
using namespace std;

class AttackBehavior {
public:
    virtual void attack() { cout << "attack" << endl; }
};

class DefendBehavior {
public:
    void defend() { cout << "defend" << endl; }
};

class FlyBehavior {
public:
    virtual void fly() { cout << "fly" << endl; }
};

class NormalAttack : public AttackBehavior {
public:
    void attack() { cout << "normal attack" << endl; }
};

class MagicAttack : public AttackBehavior {
public:
    void attack() { cout << "magic attack" << endl; }
};

class FlyWithWing : public FlyBehavior {
public:
    void fly() { cout << "flying" << endl; }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() { cout << "no fly" << endl; }
};

class Character {
protected:
    AttackBehavior *m_attackBehavior;
    DefendBehavior *m_defendBehavior;
    FlyBehavior *m_flyBehavior;
public:
    Character(AttackBehavior *, DefendBehavior *, FlyBehavior *);

    void performAttack() { m_attackBehavior->attack(); }

    void performDefend() { m_defendBehavior->defend(); }

    void performFly() { m_flyBehavior->fly(); }

    void setAttackMode(AttackBehavior *atk) { m_attackBehavior = atk; }

    void setFlyMode(FlyBehavior *fly) { m_flyBehavior = fly; }
};

Character::Character(AttackBehavior *attack, DefendBehavior *defend,
                     FlyBehavior *fly) {
    m_attackBehavior = attack;
    m_defendBehavior = defend;
    m_flyBehavior = fly;
}

class Warrior : public Character {
public:
    Warrior(AttackBehavior *attack, DefendBehavior *defend, FlyBehavior *fly)
            : Character(attack, defend, fly) {}
};

class Magician : public Character {
public:
    Magician(AttackBehavior *attack, DefendBehavior *defend, FlyBehavior *fly)
            : Character(attack, defend, fly) {}
};

class DragonRider : public Character {
public:
    DragonRider(AttackBehavior *attack, DefendBehavior *defend,
                FlyBehavior *fly) : Character(attack, defend, fly) {}
};

int main() {
    AttackBehavior *attack = new NormalAttack();
    DefendBehavior *defend = new DefendBehavior();
    FlyBehavior *fly1 = new FlyNoWay();
    FlyBehavior *fly2 = new FlyWithWing();
    Warrior myWarrior(attack, defend, fly1);
    DragonRider myDragonRider(attack, defend, fly2);
    myWarrior.performAttack();
    myDragonRider.performFly();

    AttackBehavior *attack2 = new MagicAttack();
    myDragonRider.setAttackMode(attack2);
    myDragonRider.performAttack();

    delete attack;
    delete defend;
    delete fly1;
    delete fly2;
    delete attack2;

    return 0;
}