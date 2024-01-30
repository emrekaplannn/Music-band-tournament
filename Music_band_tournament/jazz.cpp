#include "jazz.h"
#include "metal.h"
#include "kpop.h"
#include "rock.h"

int JazzBand::play(MusicBand *other)
{
    double score=((this->get_talent())* ( this->get_energy())*0.1) + (this->get_fan_count());
    this->set_energy(this->get_energy()*0.94);

    KPopBand* kpop = dynamic_cast<KPopBand*>(other);
    MetalBand* metal = dynamic_cast<MetalBand*>(other);
    JazzBand* jazz = dynamic_cast<JazzBand*>(other);
    RockBand* rock = dynamic_cast<RockBand*>(other);
    
    if (kpop != nullptr) {
        score *= 0.5;
    }
    else if(jazz != nullptr || rock != nullptr){
        score *= 0.7;
    }
    else if(metal != nullptr ){
        score *= 1.3;
    }

    return score;
}

void JazzBand::rehearse(void) 
{
    this->set_energy( ((this->get_energy())*0.97));
    this->set_talent((this->get_talent()+5));  
}