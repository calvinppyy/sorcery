#ifndef allCard_h
#define allCard_h

#include "minion.h"
#include "spell.h"
#include "ritual.h"
#include "enchantment.h"

class AirElemental: public Minion {
    public:
        void playCard() override;
};

class EarthElemental: public Minion {
    public:
        void playCard() override;
};

class BoneGolem: public Minion {
    public:
        void playCard() override;
};

class FireElemental: public Minion {
    public:
        void playCard() override;
};

class PotionSeller: public Minion {
    public:
        void playCard() override;
};

class NovicePyromancer: public Minion {
    public:
        void playCard() override;
};

class ApprenticeSummoner: public Minion {
    public:
        void playCard() override;
};

class MasterSummoner: public Minion {
    public:
        void playCard() override;
};

#endif
