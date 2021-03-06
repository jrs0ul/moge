#ifndef _CREATURE_H
#define _CREATURE_H

#include "Vectors.h"
#include "TextureLoader.h"
#include "audio/SoundSystem.h"
#include "LevelMap.h"


const float kfMaxRadius = 16.f;
const float kfGrowthIncrease = 0.09f;

class Creature{
public:
    Creature()
    : pos(0.f, 0.f, 0.f)
    , dir(0.f, 0.f, 0.f)
    , radius(16.f)
    //...
    , procreationProgress(0.f)
    , attackProgress(0.f)
    //...
    , procreating(false)
    , givesBirth(false)
    , isFemale(false)
    , isWarrior(false)
    , isBuilder(false)
    {
        movetics = 0;
        hp = 50;
        attack = 2;
        frame = 0;
        animtics = 0;
        mask = 0;
        controled = false;
        damageTics = 0;
        dead = false;
        deathProgress = 0.f;
        gaveBirth = false;
        procreationCount = 0;
        maxProcreationCount = 1;

        haveDir = false;

        for (int i = 0; i < ET_COUNT; ++i)
        {
            iTerrainBonuses[i] = 0;
        }

        pulsationProgress = 0.1f;
        pulseMultiplier = 1.f;
    }

    void draw(PicsContainer& pics, float OffsetX, float OffsetY, float ViewPortWidht, float ViewPortHeight);
    void AI(float fDeltaTime, 
            LevelMap& map,
            DArray<Creature>& creatures);

    void fight(Creature& other);
    void terraform(LevelMap& map);
    void animate();
    void Move(float fSpeed, int iMaxAreaX, int iMaxAreaY);

    void makePenguin();
    void makeGoat();
    void makeSnake();
    void makeShark();

    void makeWarrior();
    void makeBuilder();

    bool canProcreateWith(Creature* other) const;


    void attachBuffer(SoundSystem& ss, unsigned int index, unsigned int place);
    void freeSoundSource(unsigned int place);
    void playAttachedSound(unsigned int place, float volume = 1.0f);


private:
    void drawStatusBar(PicsContainer& pics, float x, float y, float current, float max, const COLOR& c);

private:
   unsigned soundSources[10];
 

public:

    Vector3D pos;
    Vector3D dir;
    float radius;

    float deathProgress;
    float pulsationProgress;
    float pulseMultiplier;
    float procreationProgress;
    float attackProgress;

    int hp;
    int attack;
    int movetics;

    int iTerrainBonuses[ET_COUNT];
 
    unsigned race;
    unsigned mask;
    unsigned frame;
    unsigned animtics;
    unsigned damageTics;

    unsigned procreationCount;
    unsigned maxProcreationCount;


    bool dead;
    bool gaveBirth;

    bool haveDir;
    bool controled;
    bool procreating;
    bool givesBirth;
    bool isFemale;
    bool isWarrior;
    bool isBuilder;

};


#endif //CREATURE_H
