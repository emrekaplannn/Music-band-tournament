#include "rock.h"
#include "metal.h"
#include "kpop.h"
#include "jazz.h"

int RockBand::play(MusicBand *other)
{
    double score=((this->get_talent())* ( this->get_energy())*0.1) + (this->get_fan_count());
    this->set_energy(this->get_energy()*0.9);

    KPopBand* kpop = dynamic_cast<KPopBand*>(other);
    MetalBand* metal = dynamic_cast<MetalBand*>(other);
    JazzBand* jazz = dynamic_cast<JazzBand*>(other);
    RockBand* rock = dynamic_cast<RockBand*>(other);
    
    if (kpop != nullptr) {
        score *= 0.5;
    }
    else if(jazz != nullptr ){
        score *= 0.8;
    }
    else if(metal != nullptr ){
        score *= 1.4;
    }

    return score;}

void RockBand::rehearse(void) 
{
    this->set_energy( ((this->get_energy())*0.95));
    this->set_talent((this->get_talent()+10));  
}