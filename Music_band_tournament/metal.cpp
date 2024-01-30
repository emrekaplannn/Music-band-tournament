#include "metal.h"
#include "kpop.h"
#include "jazz.h"
#include "rock.h"

int MetalBand::play(MusicBand *other)
{
    double score=((this->get_talent())* ( this->get_energy())*0.1) + (this->get_fan_count());
    this->set_energy(this->get_energy()*0.84);

    KPopBand* kpop = dynamic_cast<KPopBand*>(other);
    JazzBand* jazz = dynamic_cast<JazzBand*>(other);
    RockBand* rock = dynamic_cast<RockBand*>(other);
    
    if (kpop != nullptr) {
        score *= 0.5;
    }
    else if(jazz != nullptr){
        score *= 1.1;
    }
    else if(rock != nullptr ){
        score *= 1.5;
    }

    return score;
}

void MetalBand::rehearse(void) 
{
    this->set_energy( ((this->get_energy())*0.92));
    this->set_talent((this->get_talent()-5)); 

}