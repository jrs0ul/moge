#ifndef POPULATION_H
#define POPULATION_H

#include "Creature.h"
#include "LevelMap.h"
#include "PowerUp.h"
#include "audio/SoundSystem.h"

class Population{


public:

    void Update(float fDeltaTime,
                LevelMap& Mapas,
                SoundSystem& ss,
                PowerUpArray& PowerUps,
                int& secondsUntilImpact,
                int iScreenWidth, int iScreenHeight,
                unsigned& Player1ActiveCreature,
                unsigned& Player2ActiveCreature,
                bool startImpact,
                bool showWinner);

    Creature * get(unsigned index);
    unsigned long count(){return creatures.count();}
    void destroy();

    void nextActive(unsigned &Active, unsigned index);
    void draw(PicsContainer& pics, 
              float OffsetX, float OffsetY,
              float ViewPortWidht, float ViewPortHeight);
    void interact(unsigned interactor, SoundSystem& ss);
    void groundEffect(unsigned i, LevelMap& map);
    int  countByRace(unsigned race);
    int  FemaleCount(unsigned race);
    void create(unsigned race1, unsigned race2, SoundSystem& ss);

private:
    void Fertilize(unsigned race);
    void SpawnAFemale(unsigned race);
    void makeChild(Creature* parent);

private:
    DArray<Creature> creatures;

};


#endif //POPULATION_H
